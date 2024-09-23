#include <iostream>

#include "client_rpc.h"


/*
    This Class implements the Clinet  side RPC and overides the virtual
    functions from the RPCInterface class and sets the callbacks.
*/
using namespace std;

ClientRPC::ClientRPC(ProtocolFormat& protocolFormat, Logging& logging)
    : protocolFormat(protocolFormat), logging(logging) {}

void ClientRPC::setCallback(RPCCallback callback) {
    rpcCallback = callback;
}

string ClientRPC::callRemoteFunction(const string& functionName, const string& params) {
    string request = protocolFormat.serialize(functionName, params);
    logging.logRequest(request);

    if (rpcCallback) {
        string response = rpcCallback(request);
        logging.logResponse(response);
        return response;
    }
    
    return "Error: RPC callback not set.";
}

string ClientRPC::callRemoteFunction(const string& functionName, const int a, const int b) {
    string params = to_string(a) + "," + std::to_string(b);
    string request = protocolFormat.serialize(functionName, params);
    logging.logRequest(request);

    if (rpcCallback) {
        string response = rpcCallback(request);
        logging.logResponse(response);
        return response;
    }
    
    return "Error: RPC callback not set.";
}

// Server Side RPC functionality
string ClientRPC::handleRequest(const string& request) {
    return {};
}
