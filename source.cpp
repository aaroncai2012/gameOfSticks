#include <iostream>
#include <cstdlib>

void runGame(int sticks){

	bool isPlayerTurn = true;
	
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

int main(){

	runGame(20);	

	return 0;
}
