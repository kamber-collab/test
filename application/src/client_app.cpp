#include <iostream>

#include "client_app.h"

/*
    Implements the functions hello and add -> only like a UI.
    Actual functionality lies on the server.
    Calls the rpc Interface function to mimic rpc call.
    prints the response.
*/

using namespace std;

ClientApp::ClientApp(RPCInterface* rpc) : rpc(rpc) {}

void ClientApp::hello() {
    string response = rpc->callRemoteFunction("hello", "");
    cout << "Server -> Client response:: " << response << endl;
}

void ClientApp::add(int a, int b) {
    string response = rpc->callRemoteFunction("add",  a, b);
    cout << "Server -> Client response:: " << response << endl;
}
