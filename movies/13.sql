SELECT DISTINCT(name) FROM people
JOIN stars ON people.id = stars.person_id
WHERE stars.movie_id IN
(
    SELECT m1.id FROM movies AS m1
    JOIN stars ON m1.id = stars.movie_id
    JOIN people AS p ON p.id = stars.person_id
    WHERE p.name = "Kevin Bacon" AND p.birth = 1958
)
AND people.name != "Kevin Bacon"
;