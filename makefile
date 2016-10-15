compile : source.cpp
	g++ $^ -o game.exe

clean : source.cpp
	rm game.exe 

setup : data.cpp
	g++ $^ -o setup.exe
