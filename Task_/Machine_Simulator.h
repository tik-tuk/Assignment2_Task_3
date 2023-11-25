#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;


class Machine_Simulator
{
private :
	int Counter = 0 , Done = 0 ;
	vector <string> instructions;
	vector <int> Rigesters , Memory;
public :
	Machine_Simulator();
	void Take_input();
	void Step_By_Step();
	void Excute();
	int Get_Address(string s);
	void Run();
	void Print_Registers();
	void Print_Memory();
	void Reset();
};

