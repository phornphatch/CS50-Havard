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

INSERT INTO house_assignments SELECT students.id as student_id, houses.id as house_id from houses JOIN students ON students.house = houses.ho
use;

SELECT * from house_assignments

