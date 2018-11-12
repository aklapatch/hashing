all:
	g++ -g -Og main.cpp -o program.exe

opt:
	g++  -O2 main.cpp -o opt_program.exe

prof:
	g++ -pg -O2 main.cpp -o opt_program.exe