#ifndef HTTP_SERVER_H
#define HTTP_SERVER_H

#include "Calculator.h"
#include <string>

class HttpServer {
private:

    // Save calculation history
    static void saveHistory(
        const std::string& operation,
        double result
    );

public:

    // Start the web server
    void start();
};

#endif