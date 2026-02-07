# the compiler to use
CXX = g++
CXXFLAGS = -Wall -Werror -std=c++11

all: client

client: client.o stack.o
	$(CXX) $^ -o $@

client.o: client.cpp stack.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

stack.o: stack.cpp stack.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o client
