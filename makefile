
# Always build everything
.PHONY: all common rpc_demo clean

# Compiler and FLags
CXX = g++
CXXFLAGS = -std=c++11

# Final application
all: rpc_demo

# Logging first compile
common:
	$(MAKE) -C common CXX=$(CXX) CXXFLAGS=$(CXXFLAGS)

rpc_demo: common
	$(CXX) $(CXXFLAGS) main.cpp -Icommon/include \
	-Lcommon -lcommon -o rpc_demo


clean:
	$(MAKE) -C common clean
	rm -f rpc_demo rpc_demo.o
