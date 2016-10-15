#include <iostream>
#include <fstream>
#include <cstdlib>

//This makes the default data file

int main() {

	std::ofstream fout;
	fout.open("data");
	for(int i = 0; i < 20; ++i) {
		for(int j = 0; j < 3; ++j) {
			fout << 1 << ' ';
		}
		fout << std::endl;
	}

	return 0;
}
