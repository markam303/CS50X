SELECT DISTINCT(name)
FROM people
WHERE people.id IN
(
    SELECT person_id
    FROM directors
    WHERE directors.movie_id IN
    (
        SELECT movie_id
        FROM ratings
        WHERE ratings.rating >= 9.0
    )
);
