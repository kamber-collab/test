# Master make file
# Always build everything
.PHONY: all common  application rpc_demo clean

# Global Compiler and FLags
CXX = g++
CXXFLAGS = -std=c++11

# Final application
all: rpc_demo

# Logging first compile
common:
	$(MAKE) -C common CXX=$(CXX) CXXFLAGS=$(CXXFLAGS)

# Application library
application:
	$(MAKE) -C application CXX=$(CXX) CXXFLAGS=$(CXXFLAGS)

# Complie all libs first and then link to the main
rpc_demo: common application
	$(CXX) $(CXXFLAGS) main.cpp -Iapplication/include -Icommon/include \
	-Lapplication -lapp -Lcommon -lcommon -o rpc_demo

clean:
	$(MAKE) -C common clean
	$(MAKE) -C application clean
	rm -f rpc_demo rpc_demo.o
