#include "Machine_Simulator.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

Machine_Simulator::Machine_Simulator()
{
	Memory.resize(256);
	Rigesters.resize(16);
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
		Memory[Counter++] = first;
		Memory[Counter++] = second;
	}
}

void Machine_Simulator::Excute_Step_By_Step()
{

}
