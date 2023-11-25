#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;


class Machine_Simulator
{
private :
	int Counter = 0;
	vector <string> Memory , Rigesters;
	map<string, int> m;
public :
	Machine_Simulator();
	void Take_input();
	void Excute_Step_By_Step();
	void Run();
	void Print_Registers();
	void Print_Memory();
};

