#include "logging.h"
#include <iostream>

using namespace std;

void Logging::logRequest(const string& request) {
    cout << "[RPC Info] Request: " << request << endl;
}

void Logging::logResponse(const string& response) {
    cout << "[RPC Info] Response: " << response << endl;
}
