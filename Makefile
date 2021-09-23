all: main
main: main.cpp
	g++ -o main.exe main.cpp ./lib/libkissfft-float.lib -I./inc