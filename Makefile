all:
	c++ -std=c++11 -I include ./src/*.cpp -o tablice

debug:
	c++ -g -std=c++11 -I include ./src/*.cpp -o tablice

