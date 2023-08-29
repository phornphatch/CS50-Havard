CREATE TABLE
    cash_histories (
        id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
        amount NUMERIC,
        user_id INTEGER,
        FOREIGN KEY (user_id) REFERENCES users(id)
    );