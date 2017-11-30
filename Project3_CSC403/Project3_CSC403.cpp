/* Author: Micaiah Skolnick
   Date:   11/29/17
   */
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;
char ch1, ch2;
int int1, int2;

int getConstant() {
	int constant = int1 & 0x0f;
	constant = (constant << 8);
	constant = constant + int2;
	return constant;
}
string getFirstRegister() {
	string reg = "register";
	int rValue = int1 & 0x0C;
	rValue = (rValue >> 2);
	switch (rValue) {
	case 0:
		reg = "r0";
		break;
	case 1:
		reg = "r1";
		break;
	case 2:
		reg = "r2";
		break;
	case 3:
		reg = "r3";
		break;
	}
	return reg;
}
string getSecondValue() {
	string returnVal = "register";
	int secondOperand = int1 & 0x03;
	int secondRegister;
	int offset;
	switch (secondOperand) {
	case 0:
		returnVal = to_string(int2);
		returnVal.insert(0, ",");
		break;
	case 1:
		secondRegister = int2 & 0x03;
		switch (secondRegister) {
		case 0:
			returnVal = ",r0";
			break;
		case 1:
			returnVal = ",r1";
			break;
		case 2:
			returnVal = ",r2";
			break;
		case 3:
			returnVal = ",r3";
			break;
		}		
		break;
	case 2:
		offset = int2;
		returnVal = to_string(int2);
		returnVal.insert(0,",[");
		returnVal.append("]");
		break;
	case 3:
		secondRegister = int2 & 0x03;
		switch (secondRegister) {
		case 0:
			returnVal = ",[r0]";
			break;
		case 1:
			returnVal = ",[r1]";
			break;
		case 2:
			returnVal = ",[r2]";
			break;
		case 3:
			returnVal = ",[r3]";
			break;
		}
		break;
	}
	return returnVal;
}

int main() {

	string fileName;
	cout << "Please enter the name of an input file: " << endl;
	cout << ">>> ";
	cin >> fileName; // Read the filename
	ifstream inFile(fileName);
	int constant;
	while (!inFile.eof()) {		
		ch1 = inFile.get();
		ch2 = inFile.get();
		int1 = ch1;
		int2 = ch2;		
		int opcode = int1 & 0xf0;
		opcode = (opcode >> 4);		
		switch (opcode) {
		case 0:
			cout << "add ";
			cout << getFirstRegister();
			cout << getSecondValue() << endl;
			break;
		case 1:
			cout << "sub ";
			cout << getFirstRegister();
			cout << getSecondValue() << endl;
			break;
		case 2:
			cout << "jmp ";
			cout << getConstant() << endl;
			break;
		case 3:
			cout << "je  ";
			cout << getConstant() << endl;
			break;
		case 4:
			cout << "jne ";
			cout << getConstant() << endl;
			break;
		case 5:
			cout << "jl  ";
			cout << getConstant() << endl;
			break;
		case 6:
			cout << "jg  ";
			cout << getConstant() << endl;
			break;
		case 7:
			cout << "cmp ";
			cout << getFirstRegister();
			cout << getSecondValue() << endl;
			break;
		case 8:
			cout << "dsp ";
			cout << getFirstRegister() << endl;
			break;
		case 9:
			cout << "mov ";
			cout << getFirstRegister();
			cout << getSecondValue() << endl;
			break;
		case 10:
			cout << "mul ";
			cout << getFirstRegister();
			cout << getSecondValue() << endl;
			break;
		case 11:
			cout << "div ";
			cout << getFirstRegister();
			cout << getSecondValue() << endl;
			break;
		case 12:
			cout << "shr ";
			cout << getFirstRegister();
			cout << getSecondValue() << endl;
			break;
		case 13:
			cout << "sar ";
			cout << getFirstRegister();
			cout << getSecondValue() << endl;
			break;
		case 14:
			cout << "shl ";
			cout << getFirstRegister();
			cout << getSecondValue() << endl;
			break;
		case 15:
			cout << "nop " << endl;
			break;
		}
	}
	return 0;
}