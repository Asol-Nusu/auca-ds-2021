#include <bits/stdc++.h> 

template <typename C>
int sz(const C &c) { 
    return static_cast<int>(c.size()); 
}

using namespace std; 
struct Contestant{
    int mName;
    vector<Problem> problems; //correct с первого раза + the ones which got eventually correct
    int mTotalSolvedProblems = 0;
    int mTotalPenaltyTime = 0;

    Contestant(const int &name)
        : mName(name)
    {
    }
    
    void addSubmission(){
        
    }
};

struct CmpByTeamNumber{
    bool operator()(const Contestant &c1, const Contestant &c2){
        return c1.mName < c2.mName;
    }
};

struct CmpByACMRules{
   bool operator()(const Contestant &c1, const Contestant &c2){
       if(c1.mTotalSolvedProblems != c2.mTotalSolvedProblems){
           return c1.mTotalSolvedProblems > c2.mTotalSolvedProblems;
       }else{
           if(c1.mTotalPenaltyTime != c2.mTotalPenaltyTime){
               return c1.mTotalPenaltyTime < c2.mTotalPenaltyTime;
           }
       }

       //the last possible case
       CmpByTeamNumber obj = CmpByTeamNumber();
       return obj(c1, c2);
   }
};

vector<string> makeGoodValues(const string &input){
    vector<string> result;
    istringstream ss(input);

    string word; // for storing each word
    while (ss >> word) 
    {
        result.push_back(word);
    }

    return result;
}

int main()
{
    iostream::sync_with_stdio(false); 
    int tests;
    cin >> tests;
    cin.ignore(10000, '\n');
    string trash;
    getline(cin, trash); //FOR CORRECT READING

    for(int test = 0; test < tests; test++){
        vector<Contestant> contestants;
        
        //Submissions
        string input;
        while(getline(cin, input) && !input.empty()){
            vector<string> goodResult = makeGoodValues(input);
            int contestantName = stoi(goodResult[0]);
            int problemNumber = stoi(goodResult[1]);
            int penaltyTime = stoi(goodResult[2]);
            char problemStatus = goodResult[3].at(0);
        }
    }
} 