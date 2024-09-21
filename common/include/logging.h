#ifndef LOGGING_H
#define LOGGING_H

#include <string>

using namespace std;

class Logging {
public:
    void logRequest (const string& request);
    void logResponse (const string& response);
};

#endif // LOGGING_H
