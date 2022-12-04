-- Keep a log of any SQL queries you execute as you solve the mystery.
-- Theft took place on July 28
-- Theft took place on Humphrey Street

-- tables:
--    airports              crime_scene_reports   people
--    atm_transactions      flights               phone_calls
--    bakery_security_logs  interviews
--    bank_accounts         passengers

-- to start the investigation, I will check the crime scene reports with the given information
SELECT description FROM crime_scene_reports WHERE month = 7 AND day = 28 AND street = "Humphrey Street";
-- "Theft of the CS50 duck took place at 10:15am at the
-- Humphrey Street bakery. Interviews were conducted today
-- with three witnesses who were present at the time -
-- each of their interview transcripts mentions the bakery."

-- since the interviews mentioned the bakery, I will look for activity within the bakery at 10:15 AM on that date
SELECT activity FROM bakery_security_logs WHERE month = 7 AND day = 28 AND hour = 10 AND minute = 15;
    -- There were two entrances and two exits

-- next I'll check the interviews to read their transcripts on the same day
SELECT transcript FROM interviews WHERE month = 7 AND day = 28;
    -- "Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away. If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.
    -- I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.
    -- As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket."

-- I will check the license plate of those that left the parking lot at 10:15 on 7/28
SELECT license_plate, hour, minute, activity FROM bakery_security_logs WHERE month = 7 AND day = 28;
    --  | 5P2BI95       | 10   | 16     | exit     | X
    --  | 94KL13X       | 10   | 18     | exit     |
    --  | 6P58WS2       | 10   | 18     | exit     | X
    --  | 4328GD8       | 10   | 19     | exit     |
    --  | G412CB7       | 10   | 20     | exit     | X
    --  | L93JTIZ       | 10   | 21     | exit     |
    --  | 322W7JE       | 10   | 23     | exit     |
    --  | 0NTHK55       | 10   | 23     | exit       X

-- I found the names of the people who were making withdrawals from the atm on Legget Street during this time by using the following query:

SELECT name FROM people
JOIN bank_accounts ON bank_accounts.person_id = people.id
JOIN atm_transactions ON atm_transactions. account_number = bank_accounts.account_number
WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = "Leggett Street" AND transaction_type = "withdraw";

    --Bruce   |
 --   | Diana   |
  --  | Brooke  |
   -- | Kenny   |
  --  | Iman    |
   -- | Luca    |
   -- | Taylor  |
   -- | Benista |

--I will now find their license plates and match them with the previous data
SELECT license_plate FROM people WHERE name = "Bruce";
    -- The following Match:
--    | L93JTIZ       | Iman    |
 --   | 4328GD8       | Luca    |
 --   | 322W7JE       | Diana   |
 --   | 94KL13X       | Bruce

 --finds which IDs match for calls, less than a minute, on the same date
 SELECT name FROM people JOIN phone_calls ON people.phone_number = phone_calls.caller WHERE month = 7 AND day = 28 AND year = 2021 AND duration < 60;
 -- Bruce, Diana, check who the receiver is
 -- (367) 555-5533 (BRUCE) | (375) 555-8161 (ROBIN)
 -- (770) 555-1861 (DIANA) | (725) 555-3243 (PHILIP)

 --find the earliest flight out of fiftyville
 SELECT hour, minute FROM flights WHERE origin_airport_id = 8 AND month = 7 AND day = 28;

 --earlist flight is at 13:49, find the flight id and match it to the flight id of the passengers onboard to see each person's passport number and see which corresopnds with the diana or bruce
 SELECT id, hour, minute FROM flights WHERE origin_airport_id = 8 AND month = 7 AND day = 28;
 --id is 6
 SELECT passport_number FROM passengers WHERE flight_id = 6;
 SELECT passport_number, name FROM people WHERE name = "Robin" OR name = "Philip";

 -- Philip's name does not match and Robin's name does not come up, we can assume Bruce and Robin are the thieves
 SELECT destination_airport_id FROM flights  WHERE id = 6;
 -- the destination flight id is 4, meaning nyc