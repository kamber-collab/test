
# Always build everything
.PHONY: all rpc_demo clean

# Compiler and FLags
CXX = g++
CXXFLAGS = -std=c++11

# Final application
all: rpc_demo



rpc_demo:
	$(CXX) $(CXXFLAGS) main.cpp -o rpc_demo


clean:
	rm -f rpc_demo rpc_demo.o
