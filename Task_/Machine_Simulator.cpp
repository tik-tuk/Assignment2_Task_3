#include "Machine_Simulator.h"

using namespace std;

Machine_Simulator::Machine_Simulator()
{
	instructions.resize(256);
	Memory.resize(256);
	for (int i = 0; i < 256; i++)
		Memory[i] = "0";
	Rigesters.resize(16, "0");
}

string Machine_Simulator::Get_IR()
{
	return IR;
}

int Machine_Simulator::Program_Counter()
{
	return Counter;
}

void Machine_Simulator::Take_input(string file_name)
{
	fstream file;
	file.open(file_name);
	string s;
	while (getline(file , s)){
		string first = "";
		first += s[2];
		first += s[3];
		string second = "";
		second += s[4];
		second += s[5];
		instructions[Counter++] = first;
		instructions[Counter++] = second;
	}
	file.close();
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
int Machine_Simulator::Excute()
{
	IR = Memory[Done] + Memory[Done + 1];
	if (Memory[Done][0] == '1') {
		int x = Get_Address(Memory[Done + 1]);
		Rigesters[Memory[Done][1] - '0'] = Memory[x];
	}
	else if (Memory[Done][0] == '2') {
		int x = Memory[Done + 1][0] - '0';
		x = x * 10 + Memory[Done + 1][1] - '0';
		Rigesters[Memory[Done][1] - '0'] = to_string(x);
	}
	else if (Memory[Done][0] == '3') {
		if (Memory[Done + 1] == "00") {
			cout << Rigesters[Memory[Done][1] - '0'] << endl ;
		}
		else {
			int x = Get_Address(Memory[Done + 1]);
			Memory[x] = Rigesters[Memory[Done][1] - '0'];
		}
	}
	else if (Memory[Done][0] == '4') {
		Rigesters[Memory[Done + 1][1] - '0'] = Rigesters[Memory[Done + 1][0] - '0'];
	}
	else if (Memory[Done][0] == '5') {
		int x = 0;
		for (int i = 0; i < Rigesters[Memory[Done + 1][0] - '0'].size(); i++)
			x = x * 10 + Rigesters[Memory[Done + 1][0] - '0'][i] - '0';
		int y = 0;
		for (int i = 0; i < Rigesters[Memory[Done + 1][1] - '0'].size(); i++)
			y = y * 10 + Rigesters[Memory[Done + 1][1] - '0'][i] - '0';
		x += y;
		Rigesters[Memory[Done][1] - '0'] = to_string(x);
	}
	else if (Memory[Done][0] == '6') {
		int x = 0;
		for (int i = 0; i < Rigesters[Memory[Done + 1][0] - '0'].size(); i++)
			x = x * 10 + Rigesters[Memory[Done + 1][0] - '0'][i] - '0';
		int y = 0;
		for (int i = 0; i < Rigesters[Memory[Done + 1][1] - '0'].size(); i++)
			y = y * 10 + Rigesters[Memory[Done + 1][1] - '0'][i] - '0';
		x += y;
		Rigesters[Memory[Done][1] - '0'] = to_string(x);
	}
	else if (Memory[Done][0] == 'B') {
		if (Rigesters[Memory[Done][1] - '0'] == Rigesters[0]) {
			Done = Get_Address(Memory[Done + 1]);
		}
	}
	else if (Memory[Done][0] == 'C') {
		return 1 ;
	}
	return 0;
}

int Machine_Simulator::Step_By_Step()
{
	Memory[Done] = instructions[Done];
	Memory[Done + 1] = instructions[Done + 1];
	int x = Excute(); 
	cout << "Memory : " << endl ;
	this->Print_Memory();
	this->Print_Registers();
	Done += 2;
	return !x;
}

void Machine_Simulator::Run()
{
	for (Done; Done < Counter; Done += 2){
		Memory[Done] = instructions[Done];
		Memory[Done + 1] = instructions[Done + 1];
		if (Memory[Done] == "C0" && Memory[Done + 1] == "00")
			break;
		int x = Excute();
		if (x)
			break;
	}
	Machine_Simulator::Print_Memory();
	Machine_Simulator::Print_Registers();
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
		Memory[i] = "0";
	for (int i = 0; i < 16; i++)
		Rigesters[i] = "0";
}
