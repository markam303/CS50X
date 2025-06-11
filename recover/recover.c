// Recover jpgs from memory card

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// number of bytes in header
const int BUFFER_SIZE = 512;

int main(int argc, char *argv[])
{
    // check if there is exactly one file
    if (argc != 2)
    {
        printf("Provide exactly one image to recover.\n");
        return 1;
    }

    // open file
    FILE *memory = fopen(argv[1], "r");
    if (memory == NULL)
    {
        // if cannot be opened, tell the user
        printf("Could not open file.\n");
        return 1;
    }

    //
    // read file first while there's still data to read
    uint8_t buffer[BUFFER_SIZE];
    FILE *img = NULL;
    int fileNo = 0;
    char filename[8];

    while (fread(buffer, sizeof(uint8_t), BUFFER_SIZE, memory) == 512)
    {
        // when start new JPEG - below is HEADER which starts every JPEG file
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            // if first JPEG
            // close open img if any previously opened
            if (img != NULL)
            {
                fclose(img);
            }

            // create new JPEG file
            sprintf(filename, "%03i.jpg", fileNo);
            img = fopen(filename, "w");
            fileNo++;
        }

        // if jpg is open, write buffer into it
        if (img != NULL)
        {
            if (fwrite(buffer, sizeof(uint8_t), BUFFER_SIZE, img) != BUFFER_SIZE)
            {
                printf("Error writing to file.\n");
                return 1;
            }
        }
    }

    // close any files left open
    if (img != NULL)
    {
        fclose(img);
    }

    fclose(memory);
    return 0;
}
