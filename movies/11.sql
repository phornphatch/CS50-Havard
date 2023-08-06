SELECT title FROM movies
    JOIN ratings ON movies.id = ratings.movie_id
    JOIN stars ON ratings.movie_id = stars.movie_id
    JOIN people AS p ON p.id = stars.person_id
    WHERE p.name = "Chadwick Boseman"
    ORDER BY ratings.rating DESC
    LIMIT 5;