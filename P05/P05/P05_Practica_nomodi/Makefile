CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

# Solo necesitamos main.cc, el resto se incluye mediante los .h
SRCS = main.cc
OBJS = $(SRCS:.cc=.o)

TARGET = bin/ordenador

all: $(TARGET)

$(TARGET): $(OBJS) | bin
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

bin:
	mkdir -p bin

clean:
	rm -f *.o $(TARGET)
	rm -rf bin

.PHONY: all clean