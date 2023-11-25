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
	string IR;
	int Get_Address(string s);
	void Excute();
public :
	Machine_Simulator();
	string Get_IR();
	int Program_Counter();
	void Take_input();
	int Step_By_Step();
	void Run();
	void Print_Registers();
	void Print_Memory();
	void Reset();
};

