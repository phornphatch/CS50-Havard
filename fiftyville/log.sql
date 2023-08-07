-- Keep a log of any SQL queries you execute as you solve the mystery.

SELECT description FROM crime_scene_reports WHERE month = 7 AND day = 28 AND street = 'Humphrey Street';
-- id = 295
-- Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery. Interviews were conducted today with three witnesses who were present at the time – each of their interview transcripts mentions the bakery.

SELECT * FROM interviews WHERE month = 7 AND day = 28 AND year = 2021 AND transcript LIKE "%bakery%";
-- | 161 | Ruth    | 2021 | 7     | 28  | Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away. If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.                                                          |
-- | 162 | Eugene  | 2021 | 7     | 28  | I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.                                                                                                 |
-- | 163 | Raymond | 2021 | 7     | 28  | As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket. |

-- According to Ruth interviews `the thief get into a car in the bakery parking lot and drive away`
-- after 10:15am, exit
SELECT name FROM bakery_security_logs
    JOIN people ON bakery_security_logs.license_plate = people.license_plate
    WHERE month = 7 AND day = 28 AND year = 2021 AND hour = 10 AND minute > 15 AND minute < 25 AND activity = "exit";
--  Vanessa | Bruce| Barry| Luca | Sofia| Iman | Diana| Kelsey
-- +-----+------+-------+-----+------+--------+----------+---------------+--------+---------+----------------+-----------------+---------------+
-- | id  | year | month | day | hour | minute | activity | license_plate |   id   |  name   |  phone_number  | passport_number | license_plate |
-- +-----+------+-------+-----+------+--------+----------+---------------+--------+---------+----------------+-----------------+---------------+
-- | 260 | 2021 | 7     | 28  | 10   | 16     | exit     | 5P2BI95       | 221103 | Vanessa | (725) 555-4692 | 2963008352      | 5P2BI95       |
-- | 261 | 2021 | 7     | 28  | 10   | 18     | exit     | 94KL13X       | 686048 | Bruce   | (367) 555-5533 | 5773159633      | 94KL13X       |
-- | 262 | 2021 | 7     | 28  | 10   | 18     | exit     | 6P58WS2       | 243696 | Barry   | (301) 555-4174 | 7526138472      | 6P58WS2       |
-- | 263 | 2021 | 7     | 28  | 10   | 19     | exit     | 4328GD8       | 467400 | Luca    | (389) 555-5198 | 8496433585      | 4328GD8       |
-- | 264 | 2021 | 7     | 28  | 10   | 20     | exit     | G412CB7       | 398010 | Sofia   | (130) 555-0289 | 1695452385      | G412CB7       |
-- | 265 | 2021 | 7     | 28  | 10   | 21     | exit     | L93JTIZ       | 396669 | Iman    | (829) 555-5269 | 7049073643      | L93JTIZ       |
-- | 266 | 2021 | 7     | 28  | 10   | 23     | exit     | 322W7JE       | 514354 | Diana   | (770) 555-1861 | 3592750733      | 322W7JE       |
-- | 267 | 2021 | 7     | 28  | 10   | 23     | exit     | 0NTHK55       | 560886 | Kelsey  | (499) 555-9472 | 8294398571      | 0NTHK55       |
-- +-----+------+-------+-----+------+--------+----------+---------------+--------+---------+----------------+-----------------+---------------+


-- According to Eugene interviews
-- `Earlier this morning, before I arrived at Emma's bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.`
SELECT name FROM atm_transactions
    JOIN bank_accounts ON atm_transactions.account_number = bank_accounts.account_number
    JOIN people ON people.id = bank_accounts.person_id
    WHERE month = 7 AND day = 28 AND year = 2021 AND atm_location = "Leggett Street" AND transaction_type = "withdraw";
-- Bruce / | Diana / | Brooke X | Kenny X | Iman / | Luca / | Taylor X | Benista X
-- +-----+----------------+------+-------+-----+----------------+------------------+--------+----------------+-----------+---------------+--------+---------+----------------+-----------------+---------------+
-- | id  | account_number | year | month | day |  atm_location  | transaction_type | amount | account_number | person_id | creation_year |   id   |  name   |  phone_number  | passport_number | license_plate |
-- +-----+----------------+------+-------+-----+----------------+------------------+--------+----------------+-----------+---------------+--------+---------+----------------+-----------------+---------------+
-- | 267 | 49610011       | 2021 | 7     | 28  | Leggett Street | withdraw         | 50     | 49610011       | 686048    | 2010          | 686048 | Bruce   | (367) 555-5533 | 5773159633      | 94KL13X       |
-- | 336 | 26013199       | 2021 | 7     | 28  | Leggett Street | withdraw         | 35     | 26013199       | 514354    | 2012          | 514354 | Diana   | (770) 555-1861 | 3592750733      | 322W7JE       |
-- | 269 | 16153065       | 2021 | 7     | 28  | Leggett Street | withdraw         | 80     | 16153065       | 458378    | 2012          | 458378 | Brooke  | (122) 555-4581 | 4408372428      | QX4YZN3       |
-- | 264 | 28296815       | 2021 | 7     | 28  | Leggett Street | withdraw         | 20     | 28296815       | 395717    | 2014          | 395717 | Kenny   | (826) 555-1652 | 9878712108      | 30G67EN       |
-- | 288 | 25506511       | 2021 | 7     | 28  | Leggett Street | withdraw         | 20     | 25506511       | 396669    | 2014          | 396669 | Iman    | (829) 555-5269 | 7049073643      | L93JTIZ       |
-- | 246 | 28500762       | 2021 | 7     | 28  | Leggett Street | withdraw         | 48     | 28500762       | 467400    | 2014          | 467400 | Luca    | (389) 555-5198 | 8496433585      | 4328GD8       |
-- | 266 | 76054385       | 2021 | 7     | 28  | Leggett Street | withdraw         | 60     | 76054385       | 449774    | 2015          | 449774 | Taylor  | (286) 555-6063 | 1988161715      | 1106N58       |
-- | 313 | 81061156       | 2021 | 7     | 28  | Leggett Street | withdraw         | 30     | 81061156       | 438727    | 2018          | 438727 | Benista | (338) 555-6650 | 9586786673      | 8X428L0       |
-- +-----+----------------+------+-------+-----+--------------

-- According to Raymond interviews
-- `As the thief was leaving the bakery, they called someone who talked to them for less than a minute. `
SELECT name AS caller_name FROM phone_calls
    JOIN people ON people.phone_number = phone_calls.caller
    WHERE month = 7 AND day = 28 AND year = 2021 AND duration < 60;
-- Caller_name: Sofia X | Kelsey X | Bruce / | Kelsey X | Taylor X | Diana /  | Carina X | Kenny X | Benista  X |

SELECT name AS receiver_name FROM phone_calls
    JOIN people ON people.phone_number = phone_calls.receiver
    WHERE month = 7 AND day = 28 AND year = 2021 AND duration < 60;
-- receiver_name: Jack   | Larry  | Robin  | Melissa| James  | Philip | Jacqueline    |Doris  | Anna

-- According to Raymond interviews
-- `In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket.`
SELECT * FROM flights
    JOIN airports ON flights.origin_airport_id = airports.id
    JOIN passengers ON passengers.flight_id = flights.id
    JOIN people ON people.passport_number = passengers.passport_number
    WHERE month = 7 AND day = 29 AND year = 2021 AND airports.full_name LIKE "%Fiftyville%" AND name = "Diana"
    ORDER BY flights.hour AND flights.minute;
--  Gloria  | Kristina| Douglas | Diana /  | Christian |Michael | Ethan   | Charles | Dennis  | Jose
-- | Jennifer  |Brandon   |Matthew   |Emily     |Douglas   |Jordan    |Doris     |Sofia     |Bruce /
-- |Edward    |Kelsey    |Taylor    |Kenny     |Luca      |Daniel    |Carol     |Rebecca   |Sophia
--  |Heather   |Marilyn   |Richard   |Thomas    |Brooke    |Larry     |Steven    |John      |Pamela    |Melissa

-- Diana 16:00

SELECT * FROM flights
    JOIN airports ON flights.origin_airport_id = airports.id
    JOIN passengers ON passengers.flight_id = flights.id
    JOIN people ON people.passport_number = passengers.passport_number
    WHERE month = 7 AND day = 29 AND year = 2021 AND airports.full_name LIKE "%Fiftyville%" AND name = "Bruce"
    ORDER BY flights.hour AND flights.minute;
-- Bruce 8:00 /

-- find Bruce distination
SELECT * FROM flights
    JOIN airports ON flights.destination_airport_id = airports.id
    JOIN passengers ON passengers.flight_id = flights.id
    JOIN people ON people.passport_number = passengers.passport_number
    WHERE month = 7 AND day = 29 AND year = 2021 AND airports.full_name LIKE "%Fiftyville%" AND name = "Bruce";