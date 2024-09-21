.PHONY: all clean

INCLUDES = -I../common/include -Iinclude

SOURCES = src/client_app.cpp src/server_app.cpp

OBJECTS = $(SOURCES:.cpp=.o)

LIBRARY = libapp.a

all: $(LIBRARY)

$(LIBRARY): $(OBJECTS)
	ar rcs $(LIBRARY) $(OBJECTS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(LIBRARY)
