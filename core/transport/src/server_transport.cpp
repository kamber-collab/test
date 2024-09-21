#include "server_transport.h"


/*
    Server Side transport method tranfer text param to RPC handler.
*/
ServerTransport::ServerTransport(RPCInterface* rpc) : rpcHandler(rpc) {}

// Not needed on the server side.
void ServerTransport::setCallback(TransportCallback callback) {
}

// Forward request received to RPC on server side.
std::string ServerTransport::sendRequest(const std::string& request) {
    return rpcHandler->handleRequest(request);
}
