/*


Game of Sticks
by Aaron Cai

*/


#include <iostream>
#include <cstdlib>
#include <fstream>

struct log {

	int data[20][3];

};

//returns a number of sticks to take based on the number of sticks on the board
int decide(int sticks, log data) {

	int total = 0;
	for(int i = 0; i < 3; ++i) {
		total = data.data[sticks - 1][i] + total;
	}
	int decision = (rand() % total);
	if(decision < data.data[sticks - 1][0]) { return 1; }
	else if ((total - decision) <= data.data[sticks - 1][2]) { return 3; }
	else { return 2; }

}

log trainAI(int iterations) {

	int sticks;
	log data;
	log record[2];
	for(int i = 0; i < 20; ++i) {
		for(int j = 0; j < 3; ++j) {
			data.data[i][j] = 1;
		}
	}
	bool turn;
	int decision;
	for(int i = 0; i < iterations; ++i) {
		for(int i = 0; i < 20; ++i) {
			for(int j = 0; j < 3; ++j) {
				record[0].data[i][j] = 0;
				record[1].data[i][j] = 0;
			}
		}	
		turn = true;
		sticks = 20;


		while (sticks > 0) {
			decision = decide(sticks, data);
			record[turn].data[sticks - 1][decision - 1]++;  
			sticks = sticks - decision;
			turn = !turn;
		}
		
	
		for(int i = 0; i < 20; ++i) {
			for(int j = 0; j < 3; ++j) {
				if(record[turn].data[i][j]) {
					data.data[i][j]++;
				}
			}
		}
	}

	return data;
}

void runGame() {

	//initializing variables
	int sticks = 20;
	bool isPlayerTurn = true;
	int option = 4;

	//introduction
	std::cout << "Welcome to the game of sticks!" << std::endl;
	std::cout << "Options:" << std::endl;
	std::cout << " Play against a friend (1)" << std::endl;
	std::cout << " Play against the computer (2)" << std::endl;
	std::cout << " Play against the trained computer (3)" << std::endl;

	while(option != 1 && option != 2 && option != 3){
		std::cout << "Which option do you take (1-3)?";
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
	if(option == 2) {
		log data;
		log record;
		for(int i = 0 ; i < 20; ++i) {
			for(int j = 0; j < 3; ++j) {
				data.data[i][j] = 1;
				record.data[i][j] = 1;
			}
		}	

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
				record.data[sticks][decision]++;
				sticks = sticks - decision; 
				isPlayerTurn = false; 
				std::cout << std::endl << "The AI takes " << decision << " sticks." << std::endl;
			}
		}
		if(!isPlayerTurn) { std::cout << "Player wins!" << std::endl; }
		else { 
			std::cout << "AI wins!" << std::endl; 
		}
	}

	//vs trained AI
	else { 
		log data;
		std::cout << "Training AI..." << std::endl;
		data = trainAI(500);
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
				sticks = sticks - decision; 
				isPlayerTurn = false; 
				std::cout << std::endl << "The AI takes " << decision << " sticks." << std::endl;
			}
		}
		if(!isPlayerTurn) { std::cout << "Player wins!" << std::endl; }
		else { 
			std::cout << "AI wins!" << std::endl; 
		}
	}

}

int main() {
//	log test;
//	test = trainAI(50);
	runGame();
	return 0;
}
