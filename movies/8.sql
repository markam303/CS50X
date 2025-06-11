SELECT name
FROM people
WHERE people.id IN
(
    SELECT person_id
    FROM stars
    WHERE movie_id =
    (
        SELECT movies.id
        from movies
        WHERE title
        LIKE 'Toy Story%'
    )
);
