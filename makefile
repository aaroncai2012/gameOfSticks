compile : source.cpp
	g++ $^ -o game.exe

clean : source.cpp
	rm game.exe 
