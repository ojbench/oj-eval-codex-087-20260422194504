CC:=g++
CXX:=g++
CXXFLAGS:=-O2 -pipe -std=gnu++14
LDFLAGS:=

all: code

code: main.cpp
	  -o  $< 

clean:
	rm -f code *.o

.PHONY: all clean
