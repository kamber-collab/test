#ifndef CLIENT_RPC_H
#define CLIENT_RPC_H

#include "rpc_interface.h"
#include "protocol_format.h"
#include "logging.h"


/*
    This class Impelemtns the RPC for client side and overides the interfaces
    class for RPC similar to the server RPC.
*/

using namespace std;

class ClientRPC : public RPCInterface {
public:
    ClientRPC(ProtocolFormat& protocolFormat, Logging& logging);
    void setCallback(RPCCallback callback) override;
    std::string callRemoteFunction(const std::string& functionName, const std::string& params) override;
    string callRemoteFunction(const string& functionName, const int a, const int b) override;
    std::string handleRequest(const std::string& request) override;

private:
    RPCCallback rpcCallback;
    ProtocolFormat& protocolFormat;
    Logging& logging;
};

#endif // CLIENT_RPC_H
