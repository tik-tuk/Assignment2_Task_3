#include "Machine_Simulator.h"
#include <iostream>
#include <vector>
#include <string>
#include <ostream>
#include <fstream>
#include <istream>
using namespace std;

Machine_Simulator::Machine_Simulator()
{
	Memory.resize(256 , 0);
	for (int i = 0; i < 256; i++)
		Memory[i] = 0;
	instructions.resize(256);
	Rigesters.resize(16 , 0);
}

string Machine_Simulator::Get_IR()
{
	return IR;
}

int Machine_Simulator::Program_Counter()
{
	return Counter;
}

void Machine_Simulator::Take_input()
{
	cout << "Enter the name of file of instructions : ";
	string filename; cin >> filename;
	fstream infile(filename);
	while (!infile.eof()) {
		string s; 
		getline(infile, s);
		string first = "";
		first += s[2];
		first += s[3];
		string second = "";
		second += s[4];
		second += s[5];
		instructions[Counter++] = first;
		instructions[Counter++] = second;
	}
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
	return x * 16 + y ;
}
void Machine_Simulator::Excute()
{
	IR = instructions[Done] + instructions[Done + 1];
	if (instructions[Done][0] == '1') {
		int x = Get_Address(instructions[Done + 1]);
		Rigesters[instructions[Done][1] - '0'] = Memory[x];
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
		Rigesters[instructions[Done][1] - '0'] = Rigesters[instructions[Done + 1][0] - '0'] + Rigesters[instructions[Done + 1][1] - '0'];
	}
	else if (instructions[Done][0] == '6') {
		Rigesters[instructions[Done][1] - '0'] = Rigesters[instructions[Done + 1][0] - '0'] + Rigesters[instructions[Done + 1][1] - '0'];
	}
	else if (instructions[Done][0] == 'B') {
		if (Rigesters[instructions[Done][1] - '0'] == Rigesters[0]) {
			Done = Get_Address(instructions[Done + 1]);
		}
	}
	else if (instructions[Done][0] == 'C') {
		return;
	}
}

int Machine_Simulator::Step_By_Step()
{
	if (Done >= Counter || instructions[Done] == "C0" && instructions[Done + 1] == "00")
		return 0;
	else {
		Excute(); 
		cout << "Memory : " << endl ;
		this->Print_Memory();
		this->Print_Registers();
		Done += 2;
		return 1;
	}
}

void Machine_Simulator::Run()
{
	for (Done; Done < Counter; Done += 2){
		if (instructions[Done] == "C0" && instructions[Done + 1] == "00")
			break;
		Excute();
	}
}

void Machine_Simulator::Print_Registers()
{
	for (int i = 0; i < 16; i++) {
		if (i < 10) {
			cout << "Register " << i << " = " << Rigesters[i] << endl ;
		}
		else {
			cout << "Register " << char('A' + i - 10) << " = " << Rigesters[i] << endl;
		}
	}
}

void Machine_Simulator::Print_Memory()
{
	for (int i = 0; i < 256; i++) {
		if (i % 16 == 0)
			cout << endl;
		cout << Memory[i] << " ";
	}
	cout << endl;
}

void Machine_Simulator::Reset()
{
	for (int i = 0; i < 256; i++)
		Memory[i] = 0;
	for (int i = 0; i < 16; i++)
		Rigesters[i] = 0;
}
