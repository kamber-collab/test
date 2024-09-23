#include <iostream>
#include <sstream>

#include "server_app.h"


using namespace std;

ServerApp::ServerApp(RPCInterface* rpc) : rpc(rpc) {}

// Handle RPC requests.
void ServerApp::handleIncomingRequest(const string& request) {
    string response = rpc->handleRequest(request);
    cout << "Server response: " << response << endl;
}

// Server return based on the task for hello.
string ServerApp::hello() {
    return "Greetings";
}

// Server return for adding two numbers.
string ServerApp::add(int a, int b) {
    return to_string(a + b);
}
