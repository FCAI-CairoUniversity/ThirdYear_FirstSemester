-- Date: 2025-06-10

-- SQL script to create a database and a table
CREATE DATABASE Company_DB;
USE Company_DB;

-- Creating a table named Employees
CREATE TABLE Employees (
    ID INT PRIMARY KEY IDENTITY(1,1),
    FirstName NVARCHAR(50),
    LastName NVARCHAR(50),
);

-- Inserting sample data into the Employees table
INSERT INTO Employees (FirstName, LastName) 
    VALUES ('Mohammed', 'Atef'),
           ('Mostafa', 'Mahmoud'),
           ('Mohammed', 'Ahmed'),
           ('George', 'Malak');

-- Declaring variables and a table to hold cursor results
DECLARE @ID INT, @FirstName NVARCHAR(50), @LastName NVARCHAR(50);
DECLARE @table TABLE (ID INT, FullName NVARCHAR(150));

-- Declaring a cursor to select data from the Employees table
DECLARE EmployeeCursor CURSOR FOR (
    SELECT ID, FirstName, LastName FROM Employees
);

-- Opening the cursor and fetching data
OPEN EmployeeCursor;
FETCH NEXT FROM EmployeeCursor INTO @ID, @FirstName, @LastName;

-- Looping through the cursor results
WHILE @@FETCH_STATUS = 0
BEGIN
    INSERT INTO @table (ID, FullName) 
        VALUES (@ID, @FirstName + ' ' + @LastName);
    
    -- Fetching the next row
    FETCH NEXT FROM EmployeeCursor INTO @ID, @FirstName, @LastName;
END

-- Closing and deallocating the cursor
CLOSE EmployeeCursor;
DEALLOCATE EmployeeCursor;

-- Selecting data from the temporary table
SELECT * FROM @table;