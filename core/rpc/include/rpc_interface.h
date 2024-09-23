#ifndef RPC_INTERFACE_H
#define RPC_INTERFACE_H

#include <string>
#include <functional>


/*
    The Idea is to define an Interface calls which would help is selecting
    simple, advanced or any other variant of the RPC like a building blocks.
    Defines all the virtual functions which client and server side would
    implement to mimic the functionality of RPC.
*/
using namespace std;

// Create function pointer with a type name
using RPCCallback = function<string(const string&)>;

class RPCInterface {
public:
    virtual ~RPCInterface() = default;

    // Set RPC call back function.
    virtual void setCallback(RPCCallback callback) = 0;

    // RPC for hello client side
    virtual string callRemoteFunction(const string& functionName, const string& params) = 0;
    // RPC for add clinet side
    virtual string callRemoteFunction(const string& functionName, const int a, const int b) = 0;
    
    // handle request for the server side
    virtual string handleRequest(const string& request) = 0;
};

#endif // RPC_INTERFACE_H
