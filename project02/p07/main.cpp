/*
Contestants = 100 (max)
Problems = 9 (max)
*/
#include <bits/stdc++.h> 

template <typename C>
int sz(const C &c) { 
    return static_cast<int>(c.size()); 
}

using namespace std; 

struct Problem{
    int mNumber;
    char mStatus = ' ';

    int mNOfSubmissions = 0;
    bool mWasPreviouslyIncorrect = false;

    int mPenaltyTime = 0;
    

    Problem(const int &problemNumber)
        : mNumber(problemNumber) 
    {
    }
};

struct Contestant{
    int mName;
    vector<Problem> problems; //correct с первого раза + the ones which got eventually correct
    int mTotalSolvedProblems = 0;
    int mTotalPenaltyTime = 0;

    Contestant(const int &name)
        : mName(name)
    {
    }
    
};

struct Submission{
    int mContestant;
    int mProblem;
    int mPenaltyTime;
    char mProblemStatus;

    Submission(const string &input){
        istringstream streamInput(input);
        streamInput >> mContestant >> mProblem >> mPenaltyTime >> mProblemStatus;
    }
}

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


//use find_if, sort
int main()
{
    iostream::sync_with_stdio(false); 

    int tests;
    cin >> tests;
    for(int test = 0; test < tests; test++){
        vector<Contestant> contestants;
        
        //Submissions
        for(string input; getline(cin, input) && !input.empty();){
            Submission submission(input);

        } 
} 