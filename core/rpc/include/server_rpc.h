#ifndef SERVER_RPC_H
#define SERVER_RPC_H

#include "rpc_interface.h"
#include "protocol_format.h"
#include "logging.h"

/*
    Extends the RPC interface class and overides the functions.
    Implements the functions needed for server side of operations only.
*/

using namespace std;

class ServerRPC : public RPCInterface {
public:
    ServerRPC(ProtocolFormat& protocolFormat, Logging& logging);
    void setCallback(RPCCallback callback) override;
    string callRemoteFunction(const string& functionName, const string& params) override;
    string callRemoteFunction(const string& functionName, const int a, const int b) override;
    string handleRequest(const string& request) override;

private:
    ProtocolFormat& protocolFormat;
    Logging& logging;
};

#endif // SERVER_RPC_H
