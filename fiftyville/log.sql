-- Keep a log of any SQL queries you execute as you solve the mystery.
-- Check what tables are included in fiftyville.db and their schema
.table
.schema
-- Find crimes committed at that street, at that day - found ID of CRIME = 295
SELECT * FROM crime_scene_reports WHERE street = "Humphrey Street" AND day = 28;
-- Check if there are clues in interviews, which we know were 3 that day and all of them mention bakery
SELECT * FROM interviews WHERE day = 28 AND month = 7;
-- We know that the thief was withdrawing money earlier that day at Leggett St
-- We want to have a list of people (and their numbers), all who was withdrawing money at that time and location
-- We know that thief is on this list
SELECT name, phone_number, license_plate FROM people WHERE id IN
(
    SELECT person_id
    FROM bank_accounts
    JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number
    WHERE atm_transactions.day = 28
    AND atm_transactions.month = 7
    AND atm_transactions.transaction_type = 'withdraw'
    AND atm_transactions.atm_location = 'Leggett Street'
);
-- Now I want to know, what is the earliest flight on the day of 29th of July
SELECT * FROM flights WHERE day = 29 AND month = 7 ORDER BY hour;
-- We want to know what's the name of airport with id = 4
SELECT city FROM airports WHERE id = 4;
-- Thief flew to New York City. Now checking list of passengers of that flight (with id = 36)
SELECT name FROM people WHERE passport_number IN
(
    SELECT passport_number
    FROM passengers
    JOIN flights ON passengers.flight_id = flights.id
    WHERE flights.id = 36
);
-- We have a common names from both lists: Kenny, Taylor, Luca, Bruce
SELECT * FROM phone_calls WHERE day = 28 AND month = 7 AND duration < 60;
-- Compared phone numbers of passengers on board with people who were calling that day: we still have 3 name inc. Kenny, Taylor and Bruce
-- Now I am checking who left parking lot of bakery at that time and comparing license plates
SELECT name, phone_number, license_plate FROM people WHERE license_plate IN
(
    SELECT license_plate
    FROM bakery_security_logs
    WHERE day = 28 AND month = 7 AND hour = 10 AND activity = 'exit'
);
-- We are left with 2 names: Taylor, Bruce
SELECT hour, minute, license_plate FROM bakery_security_logs WHERE day = 28 AND month = 7 AND hour = 10 AND activity = 'exit';
-- We now know that Taylor left parking lot at 10:35 and Bruce at 10:18, I think Bruce did it as testimonies said, the call was within 10 min from 10:15
-- We know what's phone number of Bruce (367)555-5533, now let's find out whose number was on receiver side
SELECT name FROM people WHERE phone_number = '(375) 555-8161';
-- Accomplice is Robin
