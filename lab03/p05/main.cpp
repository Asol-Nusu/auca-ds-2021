#include <bits/stdc++.h>   
template <typename C>
int sz(const C &c) { 
    return static_cast<int>(c.size()); 
}

using namespace std;

class Computer{
    vector<int> registers;
    vector<int> memory;
    int instructionPointer;

    void runCommand2(int d1, int d2){
        registers[d1] = d2;
        instructionPointer++;
    }
    public:
    Computer()
        : registers(10, 0), memory(1000, 0), instructionPointer(0)
    {
    }

    void readCommands(istream &input){
        int curPos = 0; //currentPosition
        for(string line; getline(input, line) && !line.empty();){
            memory[curPos] = stoi(line);
            ++curPos;
        }
    }

    int run(){
        int result = 0;
        while(memory[instructionPointer] != 100){
            int t = memory[instructionPointer];

            int d2 = t % 10;
            t /= 10;
            int d1 = t % 10;
            t /= 10;
            int d0 = t % 10;

            switch(d0){
                case 2:
                runCommand2(d1, d2);
                break;
            }
            result++;
        }

        return result;
    }
};

int main()
{
    iostream::sync_with_stdio(false); 
    int tests;
    cin >> tests >> ws;
    Computer computer;
    computer.readCommands(cin);
    cout << computer.run() << "\n";
}