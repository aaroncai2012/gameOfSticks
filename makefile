compile : source.cpp
	g++ $^ -o game.exe

clean : source.cpp
	rm *.exe 

reset : data.cpp
	g++ $^ -o reset.exe
