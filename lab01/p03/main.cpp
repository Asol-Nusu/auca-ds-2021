#include <iostream>
#include <string>

using namespace std;

int main()
{
    string name;
    int grade;

    //cin - character input
    while (cin >> name >> grade) //cin ~ boolean
    {
        cout << name << " " << grade << "\n"; // cout - character output
    }
}

//CTRL-Z to exit 
