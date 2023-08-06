CREATE TABLE houses (
    id INTEGER,
    house TEXT,
    PRIMARY KEY(id)
);

CREATE TABLE house_assignments (
    student_id INTEGER,
    house_id INTEGER
);

INSERT INTO houses (house) SELECT DISTINCT(house) FROM students;

SELECT * FROM houses;

