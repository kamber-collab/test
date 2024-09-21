.PHONY: all clean

INCLUDES = -Irpc/include -Iprotocol_format/include -Itransport/include -I../common/include -I../application/include

SOURCES = rpc/src/client_rpc.cpp rpc/src/server_rpc.cpp \
          transport/src/client_transport.cpp transport/src/server_transport.cpp \
          protocol_format/src/protocol_format.cpp

OBJECTS = $(SOURCES:.cpp=.o)

LIBRARY = libcore.a

all: $(LIBRARY)

$(LIBRARY): $(OBJECTS)
	ar rcs $(LIBRARY) $(OBJECTS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(LIBRARY)
