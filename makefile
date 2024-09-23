# Master make file
# Always build everything
.PHONY: all common core application rpc_demo clean

# Global Compiler and FLags
CXX = g++
CXXFLAGS = -std=c++11

# Final application
all: rpc_demo

# Logging first compile
common:
	$(MAKE) -C common CXX=$(CXX) CXXFLAGS=$(CXXFLAGS)

# Core library second
core: common
	$(MAKE) -C core CXX=$(CXX) CXXFLAGS=$(CXXFLAGS)

# Application library
application: core
	$(MAKE) -C application CXX=$(CXX) CXXFLAGS=$(CXXFLAGS)

# Complie all libs first and then link to the main
rpc_demo: common core application
	$(CXX) $(CXXFLAGS) main.cpp -Iapplication/include -Icore/rpc/include -Icore/transport/include -Icore/protocol_format/include -Icommon/include \
		-Lcore -lcore -Lapplication -lapp -Lcommon -lcommon -o rpc_demo

clean:
	$(MAKE) -C common clean
	$(MAKE) -C core clean
	$(MAKE) -C application clean
	rm -f rpc_demo rpc_demo.o
