#include "Machine_Simulator.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

Machine_Simulator::Machine_Simulator()
{
	for (int i = 0; i < 256; i++)
		Memory[i] = 0;
	instructions.resize(256 , 0);
	instructions.resize(256);
	Rigesters.resize(16 , 0);
}

void Machine_Simulator::Take_input()
{
	string s; 
	while (cin >> s) {
		string first = "" ;
		first += s[2];
		first += s[3];
		string second = "" ;
		second += s[4];
		second += s[5];
		instructions[Counter++] = first;
		instructions[Counter++] = second;
	}
}

void Machine_Simulator::Step_By_Step()
{
	
}

int Machine_Simulator::Get_Address(string s)
{
	int x = 0, y = 0 ;
	if (isalpha(s[0])) {
		x += s[0] - 'A';
		x += 10;
	}
	else {
		x += s[0] - '0';
	}
	if (isalpha(s[1])) {
		y += s[1] - 'A';
		y += 10;
	}
	else {
		y += s[1] - '0';
	}
	return x * 16 + y - 1;
}
void Machine_Simulator::Excute()
{
	if (instructions[Done][0] == '1') {
		int x = Get_Address(instructions[Done + 1]);
		Rigesters[instructions[Done][1]] = Memory[x];
	}
	else if (instructions[Done][0] == '2') {
		int x = instructions[Done + 1][0] - '0';
		x = x * 10 + instructions[Done + 1][1] - '0';
		Rigesters[instructions[Done][1] - '0'] = x;
	}
	else if (instructions[Done][0] == '3') {
		if (instructions[Done + 1] == "00") {
			cout << Rigesters[instructions[Done][1] - '0'] << endl ;
		}
		else {
			int x = Get_Address(instructions[Done + 1]);
			Memory[x] = Rigesters[instructions[Done][1] - '0'];
		}
	}
	else if (instructions[Done][0] == '4') {
		Rigesters[instructions[Done + 1][1] - '0'] = Rigesters[instructions[Done + 1][0] - '0'];
	}
	else if (instructions[Done][0] == '5') {

	}
	else if (instructions[Done][0] == '6') {

	}
	else if (instructions[Done][0] == 'B') {

	}
	else if (instructions[Done][0] == 'C') {

	}
}


void Machine_Simulator::Run()
{

}

void Machine_Simulator::Print_Registers()
{

}

void Machine_Simulator::Print_Memory()
{

}

void Machine_Simulator::Reset()
{

}
