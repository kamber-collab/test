#ifndef SERVER_TRANSPORT_H
#define SERVER_TRANSPORT_H

#include "transport_interface.h"
#include "rpc_interface.h"

/*
    Implements Serverside transport Portocol.
*/

using namespace std;

class ServerTransport : public TransportInterface {
public:
    ServerTransport(RPCInterface* rpc);
    void setCallback(TransportCallback callback) override;
    string sendRequest(const string& request) override;

private:
    RPCInterface* rpcHandler;
};

#endif // SERVER_TRANSPORT_H
