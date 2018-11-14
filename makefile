all:
	g++ -g main.cpp -o program.exe

opt:
	g++  -O2 main.cpp -o opt_program.exe