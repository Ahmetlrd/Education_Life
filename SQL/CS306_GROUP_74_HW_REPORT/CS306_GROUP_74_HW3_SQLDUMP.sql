
-- CS306_GROUP_74_HW3_SQLDUMP.sql
-- Create database and use it
DROP DATABASE IF EXISTS cs306_db;
CREATE DATABASE cs306_db;
USE cs306_db;

-- Table definitions
CREATE TABLE Passenger (
    passenger_id INT PRIMARY KEY,
    f_name CHAR(50),
    l_name CHAR(50),
    sex CHAR(10),
    passport_number INT,
    phone INT
);

CREATE TABLE Airline (
    airline_id INT PRIMARY KEY,
    name CHAR(50),
    country CHAR(50),
    iata_code CHAR(10),
    contact_email CHAR(100)
);

CREATE TABLE Airport (
    airport_id INT PRIMARY KEY,
    name CHAR(50),
    city CHAR(50),
    country CHAR(50),
    iata_code CHAR(10)
);

CREATE TABLE Aircraft (
    aircraft_id INT PRIMARY KEY,
    model CHAR(50),
    manufacturer CHAR(50),
    capacity INT,
    airline_id INT,
    FOREIGN KEY (airline_id) REFERENCES Airline(airline_id) ON DELETE CASCADE
);

CREATE TABLE Flight (
    flight_id INT PRIMARY KEY,
    flight_number INT,
    airline_id INT,
    departure_airport_id INT,
    arrival_airport_id INT,
    departure_time DATETIME,
    arrival_time DATETIME,
    aircraft_id INT,
    status CHAR(15),
    FOREIGN KEY (airline_id) REFERENCES Airline(airline_id) ON DELETE CASCADE,
    FOREIGN KEY (departure_airport_id) REFERENCES Airport(airport_id) ON DELETE CASCADE,
    FOREIGN KEY (arrival_airport_id) REFERENCES Airport(airport_id) ON DELETE CASCADE,
    FOREIGN KEY (aircraft_id) REFERENCES Aircraft(aircraft_id) ON DELETE CASCADE
);

CREATE TABLE Ticket (
    ticket_id INT PRIMARY KEY,
    passenger_id INT,
    flight_id INT,
    seat_number CHAR(10),
    class CHAR(15),
    price DECIMAL(10,2),
    FOREIGN KEY (passenger_id) REFERENCES Passenger(passenger_id) ON DELETE CASCADE,
    FOREIGN KEY (flight_id) REFERENCES Flight(flight_id) ON DELETE CASCADE
);

CREATE TABLE Crew (
    crew_id INT PRIMARY KEY,
    first_name CHAR(50),
    last_name CHAR(50),
    role CHAR(50),
    airline_id INT,
    FOREIGN KEY (airline_id) REFERENCES Airline(airline_id) ON DELETE CASCADE
);

CREATE TABLE Baggage (
    ticket_id INT,
    weight DECIMAL(5,2),
    bag_number INT,
    extra_fee DECIMAL(10,2),
    PRIMARY KEY (ticket_id, bag_number),
    FOREIGN KEY (ticket_id) REFERENCES Ticket(ticket_id) ON DELETE CASCADE
);

CREATE TABLE assigned_to (
    flight_id INT,
    crew_id INT,
    role CHAR(20),
    PRIMARY KEY (flight_id, crew_id),
    FOREIGN KEY (flight_id) REFERENCES Flight(flight_id) ON DELETE CASCADE,
    FOREIGN KEY (crew_id) REFERENCES Crew(crew_id) ON DELETE CASCADE
);


-- Insert mock data

-- Passenger table
INSERT INTO Passenger (passenger_id, f_name, l_name, sex, passport_number, phone)
VALUES
(1, 'Ahmet', 'Binbasi', 'M', 123431789, 5321269567),
(2, 'Ayse', 'Kaya', 'F', 987654321, 5429876543),
(3, 'Mehmet', 'Demir', 'M', 456789123, 5554567891),
(4, 'Zeynep', 'Çelik', 'F', 789456123, 5307894561),
(5, 'Emre', 'Kaymak', 'M', 321654987, 5453216549),
(6, 'Fatma', 'Koc', 'F', 654321789, 5326543217),
(7, 'Aydin', 'Yilmaz', 'M', 147258369, 5501472583),
(8, 'Horison', 'Grass', 'F', 963852741, 5319638527),
(9, 'Burak', 'Arslan', 'M', 258963147, 5342589631),
(10, 'Ceylin', 'Erdogan', 'F', 852741963, 5388527419);

-- Airline table
INSERT INTO Airline (airline_id, name, country, iata_code, contact_email)
VALUES
(1, 'Turkish Airlines', 'Turkey', 'THY', 'info@thy.com'),
(2, 'Pegasus', 'Turkey', 'PGS', 'info@flypgs.com'),
(3, 'AnadoluJet', 'Turkey', 'AJT', 'info@anadolujet.com'),
(4, 'SunExpress', 'Turkey', 'SXS', 'info@sunexpress.com'),
(5, 'Lufthansa', 'Germany', 'LH', 'info@lufthansa.com'),
(6, 'Emirates', 'UAE', 'EK', 'info@emirates.com'),
(7, 'Qatar Airways', 'Qatar', 'QR', 'info@qatarairways.com'),
(8, 'British Airways', 'UK', 'BA', 'info@britishairways.com'),
(9, 'Air France', 'France', 'AF', 'info@airfrance.com'),
(10, 'Delta Airlines', 'USA', 'DL', 'info@delta.com');

-- Aircraft table
INSERT INTO Aircraft (aircraft_id, model, manufacturer, capacity, airline_id)
VALUES
(1, 'Boeing 737', 'Boeing', 180, 1),
(2, 'Airbus A320', 'Airbus', 160, 2),
(3, 'Boeing 777', 'Boeing', 350, 1),
(4, 'Embraer E190', 'Embraer', 114, 3),
(5, 'Airbus A321', 'Airbus', 190, 2),
(6, 'Boeing 787', 'Boeing', 296, 4),
(7, 'Airbus A350', 'Airbus', 314, 5),
(8, 'Bombardier CRJ900', 'Bombardier', 90, 6),
(9, 'Boeing 747', 'Boeing', 410, 7),
(10, 'ATR 72', 'ATR', 78, 8);

-- Airport table
INSERT INTO Airport (airport_id, name, city, country, iata_code)
VALUES
(1, 'Istanbul Airport', 'Istanbul', 'Turkey', 'IST'),
(2, 'Sabiha Gokcen Airport', 'Istanbul', 'Turkey', 'SAW'),
(3, 'Esenboga Airport', 'Ankara', 'Turkey', 'ESB'),
(4, 'Adnan Menderes Airport', 'Izmir', 'Turkey', 'ADB'),
(5, 'Antalya Airport', 'Antalya', 'Turkey', 'AYT'),
(6, 'Trabzon Airport', 'Trabzon', 'Turkey', 'TZX'),
(7, 'Dalaman Airport', 'Mugla', 'Turkey', 'DLM'),
(8, 'Milas-Bodrum Airport', 'Mugla', 'Turkey', 'BJV'),
(9, 'Gaziantep Airport', 'Gaziantep', 'Turkey', 'GZT'),
(10, 'Erzurum Airport', 'Erzurum', 'Turkey', 'ERZ');

-- Flight table
INSERT INTO Flight (flight_id, flight_number, airline_id, departure_airport_id, arrival_airport_id, departure_time, arrival_time, aircraft_id, status)
VALUES
(1, 1001, 1, 1, 3, '08:00', '09:30', 1, 'Scheduled'),
(2, 1002, 2, 2, 4, '10:00', '11:45', 2, 'Scheduled'),
(3, 1003, 3, 3, 5, '13:30', '15:00', 4, 'Delayed'),
(4, 1004, 1, 4, 1, '16:00', '18:10', 3, 'Scheduled'),
(5, 1005, 2, 5, 2, '19:00', '20:40', 5, 'Cancelled'),
(6, 1006, 3, 6, 2, '06:45', '08:15', 1, 'Scheduled'),
(7, 1007, 1, 7, 3, '09:20', '11:00', 2, 'Scheduled'),
(8, 1008, 2, 8, 4, '12:10', '14:05', 3, 'Delayed'),
(9, 1009, 3, 9, 5, '15:30', '17:00', 4, 'Scheduled'),
(10, 1010, 1, 10, 1, '21:15', '23:00', 5, 'Cancelled');

-- Ticket table
INSERT INTO Ticket (ticket_id, passenger_id, flight_id, seat_number, class, price)
VALUES
(1, 1, 1, '12A', 'Economy', 1200.50),
(2, 2, 2, '5B', 'Business', 3200.75),
(3, 3, 3, '7C', 'Economy', 900.00),
(4, 4, 4, '10D', 'First', 4500.00),
(5, 5, 5, '15E', 'Economy', 1400.30),
(6, 6, 6, '3F', 'Economy', 1100.20),
(7, 7, 7, '8A', 'Business', 3500.50),
(8, 8, 8, '14C', 'Economy', 950.75),
(9, 9, 9, '2B', 'First', 4800.00),
(10, 10, 10, '19D', 'Economy', 1300.90);

-- Crew table
INSERT INTO Crew (crew_id, first_name, last_name, role, airline_id)
VALUES
(1, 'Ali', 'Ozkan', 'Pilot', 1),
(2, 'Mehmet', 'Yildirim', 'Flight Attendant', 2),
(3, 'Zeynep', 'Kara', 'Engineer', 3),
(4, 'Fatih', 'Demir', 'Pilot', 1),
(5, 'Elif', 'Sahin', 'Flight Attendant', 2),
(6, 'Ahmet', 'Celik', 'Pilot', 3),
(7, 'Burcu', 'Aydin', 'Flight Attendant', 1),
(8, 'Cem', 'Gunes', 'Engineer', 2),
(9, 'Derya', 'Tas', 'Flight Attendant', 3),
(10, 'Emre', 'Kurt', 'Pilot', 2);

-- Baggage table
INSERT INTO Baggage (ticket_id, weight, bag_number, extra_fee)
VALUES
(1, 23.5, 1, 0.00),
(1, 18.0, 2, 0.00),
(3, 27.2, 1, 50.00),
(4, 30.0, 2, 75.00),
(5, 20.5, 1, 0.00),
(6, 25.0, 1, 0.00),
(7, 29.8, 2, 60.00),
(8, 15.3, 1, 0.00),
(9, 33.5, 3, 90.00),
(10, 22.0, 1, 0.00);

-- assigned_to table
INSERT INTO assigned_to (flight_id, crew_id)
VALUES
(1, 1),
(2, 2),
(3, 3),
(4, 4),
(5, 5),
(6, 6),
(7, 7),
(8, 8),
(9, 9),
(10, 10);


-- Trigger: CancelFlightIfNoTickets
DELIMITER //
CREATE TRIGGER CancelFlightIfNoTickets
AFTER DELETE ON Ticket
FOR EACH ROW
BEGIN
    IF NOT EXISTS (SELECT * FROM Ticket WHERE flight_id = OLD.flight_id) THEN
        UPDATE Flight SET status = 'Cancelled' WHERE flight_id = OLD.flight_id;
    END IF;
END//
DELIMITER ;

-- Trigger: ReactivateFlightIfTicketAdded
DELIMITER //
CREATE TRIGGER ReactivateFlightIfTicketAdded
AFTER INSERT ON Ticket
FOR EACH ROW
BEGIN
    IF (SELECT status FROM Flight WHERE flight_id = NEW.flight_id) = 'Cancelled' THEN
        UPDATE Flight SET status = 'On Time' WHERE flight_id = NEW.flight_id;
    END IF;
END//
DELIMITER ;

-- Trigger: PreventOverbooking
DELIMITER //
CREATE TRIGGER PreventOverbooking
BEFORE INSERT ON Ticket
FOR EACH ROW
BEGIN
    DECLARE capacity INT;
    DECLARE sold_tickets INT;
    SELECT A.capacity INTO capacity
    FROM Flight F
    JOIN Aircraft A ON F.aircraft_id = A.aircraft_id
    WHERE F.flight_id = NEW.flight_id;

    SELECT COUNT(*) INTO sold_tickets
    FROM Ticket
    WHERE flight_id = NEW.flight_id;

    IF sold_tickets >= capacity THEN
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'Flight is fully booked!';
    END IF;
END//
DELIMITER ;

-- Trigger: AutoCalculateExtraBaggageFee
DELIMITER //
CREATE TRIGGER AutoCalculateExtraBaggageFee
BEFORE INSERT ON Baggage
FOR EACH ROW
BEGIN
    IF NEW.weight > 25 THEN
        SET NEW.extra_fee = (NEW.weight - 25) * NEW.extra_fee;
    ELSE
        SET NEW.extra_fee = 0;
    END IF;
END//
DELIMITER ;

-- Stored Procedure: GetPassengerFlights
DELIMITER //
CREATE PROCEDURE GetPassengerFlights(IN input_passenger_id INT)
BEGIN
    SELECT
        T.ticket_id,
        F.flight_number,
        A.name AS airline,
        DA.name AS departure_airport,
        AA.name AS arrival_airport,
        F.departure_time,
        F.arrival_time,
        T.seat_number,
        T.class,
        T.price
    FROM Ticket T
    JOIN Flight F ON T.flight_id = F.flight_id
    JOIN Airline A ON F.airline_id = A.airline_id
    JOIN Airport DA ON F.departure_airport_id = DA.airport_id
    JOIN Airport AA ON F.arrival_airport_id = AA.airport_id
    WHERE T.passenger_id = input_passenger_id;
END//
DELIMITER ;

-- Stored Procedure: AssignCrewToFlight
DELIMITER //
CREATE PROCEDURE AssignCrewToFlight(
    IN input_flight_id INT,
    IN input_crew_id INT,
    IN input_role VARCHAR(50)
)
BEGIN
    INSERT INTO assigned_to (flight_id, crew_id, role)
    VALUES (input_flight_id, input_crew_id, input_role);
END//
DELIMITER ;

-- Stored Procedure: GetFlightSummary
DELIMITER //
CREATE PROCEDURE GetFlightSummary(IN input_flight_id INT)
BEGIN
    SELECT
        F.flight_id,
        F.flight_number,
        F.status,
        A.model AS aircraft_model,
        A.capacity AS aircraft_capacity,
        (SELECT COUNT(*) FROM Ticket WHERE flight_id = input_flight_id) AS total_tickets_sold,
        (SELECT COUNT(DISTINCT passenger_id) FROM Ticket WHERE flight_id = input_flight_id) AS total_passengers,
        (SELECT IFNULL(SUM(price), 0) FROM Ticket WHERE flight_id = input_flight_id) AS total_revenue,
        (SELECT COUNT(*) FROM Baggage B JOIN Ticket T ON B.ticket_id = T.ticket_id WHERE T.flight_id = input_flight_id) AS total_baggage_items,
        (SELECT COUNT(*) FROM assigned_to WHERE flight_id = input_flight_id) AS total_crew_assigned
    FROM Flight F
    JOIN Aircraft A ON F.aircraft_id = A.aircraft_id
    WHERE F.flight_id = input_flight_id;
END//
DELIMITER ;
