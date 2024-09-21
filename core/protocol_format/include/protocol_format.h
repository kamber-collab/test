#ifndef PROTOCOL_FORMAT_H
#define PROTOCOL_FORMAT_H

#include <string>

/*
    The Idea to implement this as a Virtual class is to allow for
    mulitpple variants of the RPC message types, texts, binaries,
    JSON etc.
*/

using namespace std;

class ProtocolFormat {
public:
    virtual ~ProtocolFormat() = default;

    virtual string serialize(const string& functionName, const string& params) = 0;
    virtual void deserialize(const string& request, string& functionName, string& params) = 0;
};


/*
    This class implements a very simple string based information passing between the
    RPC and transport layer.
*/

class TextProtocolFormat : public ProtocolFormat {
public:
    string serialize(const string& functionName, const string& params) override;
    void deserialize(const string& request, string& functionName, string& params) override;
};

#endif // PROTOCOL_FORMAT_H
