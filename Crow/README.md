# Calculator Web Service

A moderate-level RESTful Calculator Web Service built using **C++** and the **Crow HTTP framework**.

The application provides calculator operations through HTTP API endpoints and returns results in JSON format.

## Features

- Addition
- Subtraction
- Multiplication
- Division
- Modulus
- Power
- Square Root
- Percentage
- Input validation
- Division by zero handling
- Modulus by zero handling
- Negative square root handling
- Calculation history
- JSON API responses
- File-based history storage

## Technologies Used

- C++
- Crow HTTP Framework
- REST API
- JSON
- MSYS2 / UCRT64
- Git & GitHub

## Project Structure

```text
Calculator-Web-Service/
│
├── Crow/
│
├── data/
│   └── history.txt
│
├── src/
│   ├── main.cpp
│   ├── Calculator.h
│   ├── Calculator.cpp
│   ├── HttpServer.h
│   └── HttpServer.cpp
│
├── .gitignore
└── README.md