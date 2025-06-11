// Wait for the DOM to be fully loaded
document.addEventListener('DOMContentLoaded', function() {
    // dark mode toggle
    const themeToggle = document.getElementById('theme-toggle');
    const savedTheme = localStorage.getItem('theme');

    if (savedTheme === 'dark') {
        themeToggle.classList.add('btn-dark')
    } else {
        themeToggle.classList.add('btn-light')
    }


    if (themeToggle) {
        themeToggle.addEventListener('click', function() {
            document.body.classList.toggle('dark-mode');
            themeToggle.classList.toggle('btn-light');
            themeToggle.classList.toggle('btn-dark');

            // store user's preference
            if (document.body.classList.contains('dark-mode')) {
                localStorage.setItem('theme', 'dark');
                themeToggle.textContent = 'Toggle Light Mode';
            } else {
                localStorage.setItem('theme', 'light');
                themeToggle.textContent = 'Toggle Dark Mode';
            }
        });

        // Check for saved theme pref

        if (savedTheme === 'dark') {
            document.body.classList.add('dark-mode');
            themeToggle.textContent = 'Toggle Light Mode';
        }
    }

    // Visitor counter
    const visitorCounter = document.getElementById('visitor-counter');
    if (visitorCounter) {
        // get stored count to 0
        let count = localStorage.getItem('visitorCount') || 0;
        // incr count
        count = parseInt(count) + 1;
        // update display
        visitorCounter.textContent = `Visitors: ${count}`;
        // store updated count
        localStorage.setItem('visitorCount', count);
    }

    const projects = [
        {
            title: 'Problem Set 0: Scratch',
            description: 'Learn basic programming concepts like loops and conditionals using a visual interface.'
        },
        {
            title: 'Problem Set 1: Hello, Mario (Less/More), Cash/Credit',
            description: 'Understand C syntax, data types, and control structures.'
        },
        {
            title: 'Problem Set 2: Scrabble, Readability, Caesar/Substitution',
            description: 'Learn how to analyze text, apply algorithms, and implement encryption techniques.'
        },
        {
            title: 'Problem Set 3: Sort, Plurality, Runoff/Tideman',
            description: 'Practice handling elections with multiple candidates and determining winners based on vote counts.'
        },
        {
            title: 'Problem Set 4: Volume, Filter (Less/More), Recover',
            description: 'Learn how to manipulate image data and apply algorithms to recover deleted files.'
        },
        {
            title: 'Problem Set 5: Inheritance, Speller',
            description: 'Practice loading data into memory and searching for matches efficiently.'
        },
        {
            title: 'Problem Set 6: Hello (Python), Mario (Less/More) (Python), Cash/Credit (Python), Readability (Python), DNA',
            description: 'Learn Python basics, text analysis, and game development.'
        },
        {
            title: 'Problem Set 7: Songs, Fiftyville, Movies',
            description: 'Learn how to design and query databases using SQL.'
        },
        {
            title: 'Problem Set 8: Trivia, Homepage',
            description: 'Practice web development skills including creating interactive user interfaces with front-end tools.'
        },
        {
            title: 'Problem Set 9: Birthdays, Finance',
            description: 'Learn how to build web applications with Flask, handling user data and financial transactions.'
        },

    ]

    // portfolio project details
    const projectButtons = document.querySelectorAll('.project-details');
    if (projectButtons.length > 0) {
        projectButtons.forEach((button, index) => {
            const project = projects[index]

            button.addEventListener('click', function() {
                const projectId = this.getAttribute('data-id');
                const modalBody = document.getElementById('projectModalBody');

                // Simulate loading project details
                modalBody.innerHTML = `
                    <h4>${project.title}</h4>
                    <p>${project.description}</p>
                    `;
                // show the modal
                $('#projectModal').modal('show');
            });
        });
    }

    // contact form handling
    const contactForm = document.getElementById('contact-form');
    if (contactForm) {
        contactForm.addEventListener('submit', function(event) {
            event.preventDefault();

            // get form values
            const name = document.getElementById('name').value;
            const email = document.getElementById('email').value;
            const message = document.getElementById('message').value;

            // send this data to a server
            console.log('Form submitted:', { name, email, message });

            // show success msg
            document.getElementById('form-success').style.display = 'block';

            // reset form
            contactForm.reset();

            // Hide success message after 5 seconds
            setTimeout(function() {
                document.getElementById('form-success').style.display ='none';
            }, 5000);
        });
    }
});
