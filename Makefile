CXX=g++
CPPFLAGS=-W -Wall -std=c++17 -g
OUTDIR:= bin

all: hash-utilities.o main string-or-hexstring

hash-utilities.o: hash-utilities.cpp
	g++ $(CPPFLAGS) -c hash-utilities.cpp -lssl -lcrypto

main: hash-utilities.o main.cpp
	g++ $(CPPFLAGS) -o $(OUTDIR)/$@ main.cpp hash-utilities.o -lssl -lcrypto

string-or-hexstring: hash-utilities.o string-or-hexstring.cpp
	g++ $(CPPFLAGS) -o $(OUTDIR)/$@ string-or-hexstring.cpp hash-utilities.o -lssl -lcrypto
