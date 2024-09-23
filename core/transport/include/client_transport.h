#ifndef CLIENT_TRANSPORT_H
#define CLIENT_TRANSPORT_H

#include "transport_interface.h"

/*
    Implements Clinet side transport Portocol.
*/

using namespace std;

class ClientTransport : public TransportInterface {
public:
    ClientTransport();
    void setCallback(TransportCallback callback) override;
    string sendRequest(const string& request) override;

private:
    TransportCallback transportCallback;
};

#endif // CLIENT_TRANSPORT_H
