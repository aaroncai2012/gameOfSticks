/*


Game of Sticks
by Aaron Cai


*/


#include <iostream>
#include <cstdlib>
#include <fstream>

//modifies data in the case that the AI wins
void record(int data[][3], int log[]) {
	
	for(int i = 0; i < 20; i++) {
		if(log[i] != 0){
			++data[i][log[i] - 1];
		}
	}
	std::ofstream fout;
	fout.open("data");
	for(int i = 0; i < 20; ++i) {
		for(int j = 0; j < 3; ++j) {
			fout << data[i][j] << ' ';
		}
		fout << std::endl;
	}

}

//returns a number of sticks to take based on the number of sticks on the board
int decide(int sticks, int data[][3]) {

	int total = 0;
	for(int i = 0; i < 3; ++i) {
		total = data[sticks][i] + total;
	}
	int decision = (rand() % total);
	if(decision < data[sticks][0]) { return 1; }
	else if ((total - decision) <= data[sticks][2]) { return 3; }
	else { return 2; }

}

void trainAI(int iterations) {

	int sticks;
	std::ifstream fin;
	fin.open("data");
	int data[20][3];
	bool turn;
	int log1[20];
	int log2[20];
	for(int i = 0; i < 20; ++i) {
		for(int j = 0; j < 3; ++j) {
			fin >> data[i][j];
		}
	}
	fin.close();
	for(int i = 0; i < iterations; ++i) {
		turn = true;
		sticks = true;
		for(int i = 0; i < 20; ++i) { log1[i] = 0; }
		for(int i = 0; i < 20; ++i) { log2[i] = 0; }
		while (sticks > 0) {
			
		}
	}

}

//resets data file
void resetData() {
	
	std::ofstream fout;
	fout.open("data");
	for(int i = 0; i < 20; ++i) {
		for(int j = 0; j < 3; ++j) {
			fout << 1 << ' ';
		}
		fout << std::endl;
	}	
	fout.close();	

}

void runGame() {

	//initializing variables
	int sticks = 20;
	std::ifstream fin;
	fin.open("data");
	int data[20][3];
	for(int i = 0 ; i < 20; ++i) {
		for(int j = 0; j < 3; ++j) {
			fin >> data[i][j];
		}
	}	
	fin.close();

	bool isPlayerTurn = true;
	int option = 3;
	int log[20];	for(int i = 0; i < 20; ++i) { log[i] = 0; }

	//introduction
	std::cout << "Welcome to the game of sticks!" << std::endl;
	std::cout << "Would you like to play against a friend (option 1) or the computer (option 2)?" << std::endl;

	while(option != 1 && option != 2){
		std::cout << "Which option do you take (1-2)?";
		std::cin >> option;
		std::cout << std::endl;
	}
	
	//vs player
	if (option == 1) {
		while(sticks > 0) {
			int input = 4;
			while (input > 3 || input < 0) {
				std::cout << "There are " << sticks << " sticks on the board." << std::endl;
				std::cout << "Player ";
				if(isPlayerTurn) { std::cout << "1"; }
				else { std::cout << "2"; }
				std::cout << ": How many sticks do you take? (1-3) ";
				std::cin >> input;
				std::cout << std::endl;
			}
			sticks = sticks - input;
			isPlayerTurn = !isPlayerTurn;	
		}

		std::cout << "Player ";
		if(isPlayerTurn) { std::cout << "1"; }
		else { std::cout << "2"; }
		std::cout << " wins!" << std::endl;
	}

	//vs ai
	else {
		while (sticks > 0) {
			isPlayerTurn = true;
			int input = 4;
			while (input > 3 || input < 0) {
				std::cout << "There are " << sticks << " sticks on the board." << std::endl;
				std::cout << "Player: How many sticks do you take (1-3) ";
				std::cin >> input;
				std::cout << std::endl;
			}
			sticks = sticks - input;
			if (sticks > 0) { 
				int decision = decide(sticks, data);
				log[sticks] = decision;
				sticks = sticks - decision; 
				isPlayerTurn = false; 
				std::cout << std::endl << "The AI takes " << decision << " sticks." << std::endl;
			}
		}
		if(!isPlayerTurn) { std::cout << "Player wins!" << std::endl; }
		else { 
			std::cout << "AI wins!" << std::endl; 
			record(data, log);
		}
	}

}

int main() {

	runGame();
	return 0;
}
