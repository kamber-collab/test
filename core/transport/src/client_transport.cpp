#include "client_transport.h"


using namespace std;

ClientTransport::ClientTransport() {}

// Set the call back from client side 
void ClientTransport::setCallback(TransportCallback callback) {
    transportCallback = callback;
}

// Tranfer from RPC to transport on the server side.
string ClientTransport::sendRequest(const string& request) {
    if (transportCallback) {
        return transportCallback(request);
    }
    return "Error: Transport callback not set.";
}
