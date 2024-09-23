.PHONY: all clean

INCLUDES = -Iinclude

SOURCES = src/logging.cpp

OBJECTS = $(SOURCES:.cpp=.o)

LIBRARY = libcommon.a

all: $(LIBRARY)

$(LIBRARY): $(OBJECTS)
	ar rcs $(LIBRARY) $(OBJECTS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(LIBRARY)
