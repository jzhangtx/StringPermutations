StringPermutations: StringPermutations.o
	g++ -g -o StringPermutations.exe StringPermutations.o -pthread    

StringPermutations.o: StringPermutations/StringPermutations.cpp
	g++ -g  -c -pthread StringPermutations/StringPermutations.cpp
