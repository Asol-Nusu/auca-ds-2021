#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    //cin - character input
    //cout - character output
    
    const int kNameWidth = 30;
    const int kAverageWidth = 40;
    cout << setfill('.') << fixed;
    for (string name; cin >> name;) //cin (attempt to read) ~ boolean
    { 
        double sum = 0;
        int numberOfGrades = 0; 
        for(int grade; cin >> grade;){
            sum += grade;
            ++numberOfGrades;
        }
        if(numberOfGrades != 0){
            cout << left << setw(kNameWidth) << name << "|" << right << setw(kAverageWidth) << setprecision(2) << sum / numberOfGrades << "\n";
        }else{
            cout << left << setw(kNameWidth) << name << "|" << right << setw(kAverageWidth + 1) << "no data\n";
        }
        cin.clear(); 
    }
}

//CTRL-Z to exit 
