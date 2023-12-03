#include <iostream>
#include "Machine_Simulator.h"
#include <fstream>
#include <istream>
#include <ostream>

using namespace std;

int main()
{
    Machine_Simulator m;
    int s; 
    while (true) {
        cout << "1 For New Program." << endl ;
        cout << "2 For Excute the Program." << endl;
        cout << "3 For Display Data." << endl;
        cout << "0 For Exit Program." << endl;
        cin >> s;
        if (s == 0)
            break;
        if (s == 1) {
            m.Reset();
            cout << "Enter input file name : ";
            string s; cin >> s;
            m.Take_input(s);
        }
        if (s == 3) {
            cout << "1 For Display Memory." << endl;
            cout << "2 For Display Registers." << endl;
            cout << "3 For Display IR." << endl;
            cout << "4 For Display Program Counter." << endl;
            int x; cin >> x;
            if (x == 1) {
                m.Print_Memory();
            }
            else if (x == 2) {
                m.Print_Registers();
            }
            else if (x == 3) {
                cout << "IR = " << m.Get_IR() << endl;
            }
            else {
                cout << "Counter = " << m.Program_Counter() << endl;
            }
        }
        if (s == 2) {
            while (1) {
                cout << "1 For Run." << endl;
                cout << "2 For Step by Step." << endl;
                int x; cin >> x;
                if (x == 1) {
                    m.Run();
                    break;
                }
                else {
                    int x = m.Step_By_Step();
                    if (!x) {
                        break;
                    }
                }
            }
        }
    }
}