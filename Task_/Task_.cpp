
#include <iostream>

#include "Machine_Simulator.h"

using namespace std;


int main()
{
    Machine_Simulator m;
    m.Take_input();
    m.Run();
    m.Print_Registers();
    m.Print_Memory();
}