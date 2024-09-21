#include <iostream>
#include <sstream>

#include "server_rpc.h"
#include "server_app.h"

/*
    This Class actually implements the functionality of the Server side
    of the RPC which includes parsing string to get the function and parameters
    and also disapatching, that is calling the right function to be invoked.
*/

// Constructor
ServerRPC::ServerRPC(ProtocolFormat& protocolFormat, Logging& logging)
    : protocolFormat(protocolFormat), logging(logging) {}


// Not needed on the Server side.
void ServerRPC::setCallback(RPCCallback callback) {
}

string ServerRPC::handleRequest(const string& request) {
    logging.logRequest(request);

    string functionName, params;
    protocolFormat.deserialize(request, functionName, params);

    string result;

    // Instantiate the Server app class to invoke functions.
    ServerApp serverApp(this);

    // Forward the function call to the application layer
    if (functionName == "hello") {
        result = serverApp.hello();
    } else if (functionName == "add") {
        int a, b;
        sscanf(params.c_str(), "%d,%d", &a, &b);
        result = serverApp.add(a, b);
    } else {
        result = "Error: Function not implemented on the server";
    }

    logging.logResponse(result);
    
    return result;
}

// Not needed on the server side
string ServerRPC::callRemoteFunction(const string& functionName, const string& params) {
    return {};
}

// Not needed on the server side
string ServerRPC::callRemoteFunction(const string& functionName, const int a, const int b) {
    return {};
}
