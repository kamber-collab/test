#include "logging.h"
#include <iostream>

using namespace std;

void Logging::logRequest(const string& request) {
    cout << "[Info] Request: " << request << endl;
}

void Logging::logResponse(const string& response) {
    cout << "[Info] Response: " << response << endl;
}
