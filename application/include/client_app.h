#ifndef CLIENT_APP_H
#define CLIENT_APP_H

#include "rpc_interface.h"


/* 
    The Class fakes a UI implementation which implements the task given
    applications hello and add. As there are many variants of the RPC protocol
    itself an interface class will be created for allowing flexibility to add
    either a simple or a complex RPC to be added here. Thus this call constructor
    takes in the RPCInterface as an argument for later calling functions.
*/

class ClientApp {
public:
    ClientApp(RPCInterface* rpc);

    void hello();
    void add(int a, int b);

private:
    RPCInterface* rpc;
};

#endif // CLIENT_APP_H
