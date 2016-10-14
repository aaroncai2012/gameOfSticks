#include <iostream>
#include <cstdlib>

//returns a number of sticks to take based on the number of sticks on the board
int decide(int sticks) {

	

}
void runGame(int sticks){

	bool isPlayerTurn = true;
	int option = 3;
	int log[20];
	for(int i = 0; i < 20; ++i) { log[i] = 0; }

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

}

int main(){

	runGame(20);	

	return 0;
}
