#ifndef SERVER_APP_H
#define SERVER_APP_H

#include "rpc_interface.h"


/*
    The server class actually implement the functionality of add 
    and hello. It accepts the RPC request and responds the computed
    output or data.
*/

using namespace std;

class ServerApp {
public:
    ServerApp(RPCInterface* rpc);   
    void handleIncomingRequest(const string& request);

    string hello();
    string add(int a, int b);

private:
    RPCInterface* rpc;
};

#endif // SERVER_APP_H
