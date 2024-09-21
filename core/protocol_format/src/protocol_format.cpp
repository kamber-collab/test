#include <sstream>

#include "protocol_format.h"

using namespace std;

/*
    The format for serialization and deserialization : fnName| param1,param2.
*/

string TextProtocolFormat::serialize(const string& functionName, const string& params) {
    return functionName + "|" + params;
}

void TextProtocolFormat::deserialize(const string& request, string& functionName, string& params) {
    stringstream ss(request);
    getline(ss, functionName, '|');
    getline(ss, params);
}
