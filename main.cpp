#include <iostream>

// Common
#include "logging.h"

// APP
#include "client_app.h"
#include "server_app.h"

// RPC
#include "client_rpc.h"
#include "server_rpc.h"
#include "protocol_format.h"

// Transport
#include "client_transport.h"
#include "server_transport.h"

using namespace std;

int main() {

    Logging logging;
    TextProtocolFormat protocolFormat;

    // Server
    ServerRPC serverRPC(protocolFormat, logging);
    ServerTransport serverTransport(&serverRPC);
    ServerApp serverApp(&serverRPC);

    // Client
    ClientRPC clientRPC(protocolFormat, logging);
    ClientTransport clientTransport;

    // Register transport callback on the client to use server request
    clientTransport.setCallback([&serverTransport](const string& request) {
        return serverTransport.sendRequest(request);
    });

    // Register the transport callback to RPC for the client
    clientRPC.setCallback([&clientTransport](const string& request) {
        return clientTransport.sendRequest(request);
    });

    // Client application
    ClientApp clientApp(&clientRPC);

    cout << "Client::hello:: " << endl;
    clientApp.hello();

    cout << "\nClient::add:: " << endl;
    clientApp.add(5, 3);

    return 0;
}