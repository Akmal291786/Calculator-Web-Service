# Calculator Web Service

A moderate-level RESTful Calculator Web Service built using C++ and the Crow HTTP framework.

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
- Error handling
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

## API Endpoints

| Method | Endpoint | Example |
|---|---|---|
| GET | `/` | `http://localhost:8080/` |
| GET | `/add` | `/add?a=10&b=5` |
| GET | `/subtract` | `/subtract?a=10&b=5` |
| GET | `/multiply` | `/multiply?a=10&b=5` |
| GET | `/divide` | `/divide?a=10&b=5` |
| GET | `/modulus` | `/modulus?a=10&b=3` |
| GET | `/power` | `/power?a=2&b=3` |
| GET | `/sqrt` | `/sqrt?value=25` |
| GET | `/percentage` | `/percentage?value=200&percent=10` |
| GET | `/history` | `/history` |

## Example

### Addition

Request:

`http://localhost:8080/add?a=10&b=5`

Response:

```json
{
  "operation": "addition",
  "a": 10,
  "b": 5,
  "result": 15
}