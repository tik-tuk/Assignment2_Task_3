#pragma once
#include <bits/stdc++.h>
using namespace std;


class Machine_Simulator
{
private :
	int Counter = 0 , Done = 0 ;
	vector <string> Rigesters;
	vector<string> Memory , instructions ;
	string IR;
	int Get_Address(string s);
	int Excute();
public :
	Machine_Simulator();
	string Get_IR();
	int Program_Counter();
	void Take_input(string file_name);
	int Step_By_Step();
	void Run();
	void Print_Registers();
	void Print_Memory();
	void Reset();
};

