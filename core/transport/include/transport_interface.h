#ifndef TRANSPORT_INTERFACE_H
#define TRANSPORT_INTERFACE_H

#include <string>
#include <functional>

/*
    The transport interface implements the data tranfer fake method
    from client to server side and back. The reason to declare it
    as an Interface it to again allow for flexibitly in choosing and
    adding the type of protocol.
*/

using namespace std;
// Function Pointer Callback
using TransportCallback = function<std::string(const string&)>;

class TransportInterface {
public:
    virtual ~TransportInterface() = default;
    virtual void setCallback(TransportCallback callback) = 0;
    virtual string sendRequest(const string& request) = 0;
};

#endif // TRANSPORT_INTERFACE_H
