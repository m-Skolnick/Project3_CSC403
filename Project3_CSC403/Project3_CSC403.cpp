#include <iostream>
#include <fstream>
#include <string>


using namespace std;

int main() {

	string fileName;
	//cout << "Please enter the name of an input file: " << endl;
	//cin >> fileName; // ************************************NEED TO UNDO THIS BEFORE SUBMITTING

	ifstream inFile("inputFile.txt");
	char ch1, ch2;
	int int1, int2;
	while (!inFile.eof()) {
		ch1 = inFile.get();
		ch2 = inFile.get();
		int1 = ch1;
		int2 = ch2;

		int1 = int1 & 0xf0;
		int1 = (int1 >> 4);

		switch (int1) {
		case 0:
			cout << "add ";
			break;
		case 1:
			cout << "sub ";
			break;
		case 2:
			cout << "jmp ";
			int1 = int1 & 0x0f;
			int2 = int1 + int2;
			cout << int2;
			//int2 = int2 & 0xf;
			break;
		case 3:
			cout << "je ";
			break;
		case 4:
			cout << "jne ";
			break;
		case 5:
			cout << "jl ";
			break;
		case 6:
			cout << "jg ";
			break;
		case 7:
			cout << "cmp ";
			int1 = int1 & 0x0f;
			int2 = int1 + int2;
			cout << int2;
			break;
		}

	}
	



	return 0;
}