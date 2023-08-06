 SELECT title FROM movies
 WHERE movies.id IN
(
    SELECT m1.id FROM movies AS m1
    JOIN stars ON m1.id = stars.movie_id
    JOIN people AS p ON p.id = stars.person_id
    WHERE p.name = "Bradley Cooper"
)
AND
id IN
(
    SELECT m2.id FROM movies AS m2
    JOIN stars ON m2.id = stars.movie_id
    JOIN people AS p ON p.id = stars.person_id
    WHERE p.name = "Jennifer Lawrence"
);