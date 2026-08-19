#include "HttpServer.h"

#include "../Crow/include/crow.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;


// ============================================================
// Save Calculation History
// ============================================================

void HttpServer::saveHistory(
    const string& operation,
    double result
) {
    ofstream file("data/history.txt", ios::app);

    if (file) {
        file << operation
             << " = "
             << result
             << "\n";

        file.close();
    }
}


// ============================================================
// Common Error Response
// ============================================================

crow::response errorResponse(
    int statusCode,
    const string& message
) {
    crow::json::wvalue error;

    error["error"] = message;

    return crow::response(
        statusCode,
        error.dump()
    );
}


// ============================================================
// Validate Numeric Input
// ============================================================

bool isValidNumber(const string& value) {

    try {

        size_t position = 0;

        stod(value, &position);

        return position == value.length();

    } catch (...) {

        return false;
    }
}


// ============================================================
// Start Web Server
// ============================================================

void HttpServer::start() {

    crow::SimpleApp app;


    // ========================================================
    // HOME
    // ========================================================

    CROW_ROUTE(app, "/")
    ([]() {

        crow::json::wvalue response;

        response["service"] = "Calculator Web Service";
        response["status"] = "running";
        response["version"] = "1.0";

        return crow::response(
            200,
            response.dump()
        );
    });


    // ========================================================
    // ADDITION
    // ========================================================

    CROW_ROUTE(app, "/add")
    ([](const crow::request& req) {

        auto a = crow::query_string(req.url_params).get("a");
        auto b = crow::query_string(req.url_params).get("b");

        if (!a || !b) {

            return errorResponse(
                400,
                "Missing parameters. Use /add?a=10&b=5"
            );
        }

        if (!isValidNumber(a) || !isValidNumber(b)) {

            return errorResponse(
                400,
                "Invalid numeric input"
            );
        }

        double num1 = stod(a);
        double num2 = stod(b);

        Calculator calculator;

        double result = calculator.add(num1, num2);

        HttpServer::saveHistory(
            "add(" + string(a) + "," + string(b) + ")",
            result
        );

        crow::json::wvalue response;

        response["operation"] = "addition";
        response["a"] = num1;
        response["b"] = num2;
        response["result"] = result;

        return crow::response(
            200,
            response.dump()
        );
    });


    // ========================================================
    // SUBTRACTION
    // ========================================================

    CROW_ROUTE(app, "/subtract")
    ([](const crow::request& req) {

        auto a = crow::query_string(req.url_params).get("a");
        auto b = crow::query_string(req.url_params).get("b");

        if (!a || !b) {

            return errorResponse(
                400,
                "Missing parameters. Use /subtract?a=10&b=5"
            );
        }

        if (!isValidNumber(a) || !isValidNumber(b)) {

            return errorResponse(
                400,
                "Invalid numeric input"
            );
        }

        double num1 = stod(a);
        double num2 = stod(b);

        Calculator calculator;

        double result = calculator.subtract(num1, num2);

        HttpServer::saveHistory(
            "subtract(" + string(a) + "," + string(b) + ")",
            result
        );

        crow::json::wvalue response;

        response["operation"] = "subtraction";
        response["a"] = num1;
        response["b"] = num2;
        response["result"] = result;

        return crow::response(
            200,
            response.dump()
        );
    });


    // ========================================================
    // MULTIPLICATION
    // ========================================================

    CROW_ROUTE(app, "/multiply")
    ([](const crow::request& req) {

        auto a = crow::query_string(req.url_params).get("a");
        auto b = crow::query_string(req.url_params).get("b");

        if (!a || !b) {

            return errorResponse(
                400,
                "Missing parameters. Use /multiply?a=10&b=5"
            );
        }

        if (!isValidNumber(a) || !isValidNumber(b)) {

            return errorResponse(
                400,
                "Invalid numeric input"
            );
        }

        double num1 = stod(a);
        double num2 = stod(b);

        Calculator calculator;

        double result = calculator.multiply(num1, num2);

        HttpServer::saveHistory(
            "multiply(" + string(a) + "," + string(b) + ")",
            result
        );

        crow::json::wvalue response;

        response["operation"] = "multiplication";
        response["a"] = num1;
        response["b"] = num2;
        response["result"] = result;

        return crow::response(
            200,
            response.dump()
        );
    });


    // ========================================================
    // DIVISION
    // ========================================================

    CROW_ROUTE(app, "/divide")
    ([](const crow::request& req) {

        auto a = crow::query_string(req.url_params).get("a");
        auto b = crow::query_string(req.url_params).get("b");

        if (!a || !b) {

            return errorResponse(
                400,
                "Missing parameters. Use /divide?a=10&b=5"
            );
        }

        if (!isValidNumber(a) || !isValidNumber(b)) {

            return errorResponse(
                400,
                "Invalid numeric input"
            );
        }

        double num1 = stod(a);
        double num2 = stod(b);

        if (num2 == 0) {

            return errorResponse(
                400,
                "Division by zero is not allowed"
            );
        }

        Calculator calculator;

        double result = calculator.divide(num1, num2);

        HttpServer::saveHistory(
            "divide(" + string(a) + "," + string(b) + ")",
            result
        );

        crow::json::wvalue response;

        response["operation"] = "division";
        response["a"] = num1;
        response["b"] = num2;
        response["result"] = result;

        return crow::response(
            200,
            response.dump()
        );
    });


    // ========================================================
    // MODULUS
    // ========================================================

    CROW_ROUTE(app, "/modulus")
    ([](const crow::request& req) {

        auto a = crow::query_string(req.url_params).get("a");
        auto b = crow::query_string(req.url_params).get("b");

        if (!a || !b) {

            return errorResponse(
                400,
                "Missing parameters. Use /modulus?a=10&b=3"
            );
        }

        if (!isValidNumber(a) || !isValidNumber(b)) {

            return errorResponse(
                400,
                "Invalid numeric input"
            );
        }

        int num1 = stoi(a);
        int num2 = stoi(b);

        if (num2 == 0) {

            return errorResponse(
                400,
                "Modulus by zero is not allowed"
            );
        }

        Calculator calculator;

        int result = calculator.modulus(num1, num2);

        HttpServer::saveHistory(
            "modulus(" + string(a) + "," + string(b) + ")",
            result
        );

        crow::json::wvalue response;

        response["operation"] = "modulus";
        response["a"] = num1;
        response["b"] = num2;
        response["result"] = result;

        return crow::response(
            200,
            response.dump()
        );
    });


    // ========================================================
    // POWER
    // ========================================================

    CROW_ROUTE(app, "/power")
    ([](const crow::request& req) {

        auto a = crow::query_string(req.url_params).get("a");
        auto b = crow::query_string(req.url_params).get("b");

        if (!a || !b) {

            return errorResponse(
                400,
                "Missing parameters. Use /power?a=2&b=3"
            );
        }

        if (!isValidNumber(a) || !isValidNumber(b)) {

            return errorResponse(
                400,
                "Invalid numeric input"
            );
        }

        double num1 = stod(a);
        double num2 = stod(b);

        Calculator calculator;

        double result = calculator.power(num1, num2);

        HttpServer::saveHistory(
            "power(" + string(a) + "," + string(b) + ")",
            result
        );

        crow::json::wvalue response;

        response["operation"] = "power";
        response["a"] = num1;
        response["b"] = num2;
        response["result"] = result;

        return crow::response(
            200,
            response.dump()
        );
    });


    // ========================================================
    // SQUARE ROOT
    // ========================================================

    CROW_ROUTE(app, "/sqrt")
    ([](const crow::request& req) {

        auto value =
            crow::query_string(req.url_params).get("value");

        if (!value) {

            return errorResponse(
                400,
                "Missing parameter. Use /sqrt?value=25"
            );
        }

        if (!isValidNumber(value)) {

            return errorResponse(
                400,
                "Invalid numeric input"
            );
        }

        double num = stod(value);

        if (num < 0) {

            return errorResponse(
                400,
                "Square root of a negative number is not allowed"
            );
        }

        Calculator calculator;

        double result = calculator.squareRoot(num);

        HttpServer::saveHistory(
            "sqrt(" + string(value) + ")",
            result
        );

        crow::json::wvalue response;

        response["operation"] = "square root";
        response["value"] = num;
        response["result"] = result;

        return crow::response(
            200,
            response.dump()
        );
    });


    // ========================================================
    // PERCENTAGE
    // ========================================================

    CROW_ROUTE(app, "/percentage")
    ([](const crow::request& req) {

        auto value =
            crow::query_string(req.url_params).get("value");

        auto percent =
            crow::query_string(req.url_params).get("percent");

        if (!value || !percent) {

            return errorResponse(
                400,
                "Missing parameters. Use /percentage?value=200&percent=10"
            );
        }

        if (!isValidNumber(value) ||
            !isValidNumber(percent)) {

            return errorResponse(
                400,
                "Invalid numeric input"
            );
        }

        double num = stod(value);
        double pct = stod(percent);

        Calculator calculator;

        double result =
            calculator.percentage(num, pct);

        HttpServer::saveHistory(
            "percentage(" +
            string(value) +
            "," +
            string(percent) +
            ")",
            result
        );

        crow::json::wvalue response;

        response["operation"] = "percentage";
        response["value"] = num;
        response["percent"] = pct;
        response["result"] = result;

        return crow::response(
            200,
            response.dump()
        );
    });


    // ========================================================
    // CALCULATION HISTORY
    // ========================================================

    CROW_ROUTE(app, "/history")
    ([]() {

        ifstream file("data/history.txt");

        if (!file) {

            return crow::response(
                200,
                "{\"status\":\"success\",\"message\":\"No calculation history found\"}"
            );
        }

        vector<string> history;

        string line;

        while (getline(file, line)) {

            if (!line.empty()) {
                history.push_back(line);
            }
        }

        file.close();

        crow::json::wvalue response;

        response["status"] = "success";

        response["count"] =
            static_cast<int>(history.size());

        for (size_t i = 0;
             i < history.size();
             i++) {

            response["history"][i] =
                history[i];
        }

        return crow::response(
            200,
            response.dump()
        );
    });


    // ========================================================
    // START SERVER
    // ========================================================

    cout << "========================================\n";
    cout << "       CALCULATOR WEB SERVICE\n";
    cout << "========================================\n";

    cout << "Server running on http://localhost:8080\n";

    app.port(8080)
       .multithreaded()
       .run();
}