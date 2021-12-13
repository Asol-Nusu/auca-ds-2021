/*
Contestant 
    int name;
    int nOfSolvedProblems;
    int penaltyTime = 0;

Submission
    string contestantName;
    int problemNumber;
    int time;
    int problemStatus;

sort(contestants);
*/
#include <bits/stdc++.h> 

template <typename C>
int sz(const C &c) { 
    return static_cast<int>(c.size()); 
}

using namespace std; 
//for submitted Incorrect Problems
struct IProblem{
    int mNumber;

    int mNOfSubmissions = 0;
    char mStatus = 'I';
    int mFinalPenaltyTime = 0;

    IProblem(const int &problemNumber)
        : mNumber(problemNumber)
    {
    }
    //if it eventually got 'correct' status:
    void calculateFinalPenaltyTime(){
        if(mStatus == 'C'){
            mFinalPenaltyTime = 20*mNOfSubmissions;
        }
    }
};

struct Contestant{
    int mName;
    vector<IProblem> mSubmittedIncorrectProblems; //if some were correct, aoutomatically calculating (no problem)
    
    int mTotalSolvedProblems = 0;
    int mTotalPenaltyTime = 0;

    Contestant(const int &name)
        : mName(name)
    {
    }
};


struct CmpByTeamNumber{

};
struct CmpByACMRules{
    /*
    1) by the number of problems solved (the more the better)
    2) then by decreasing amounts of penalty time
    If two or more contestants are tied in both problems solved and
    penalty time, 
    they are displayed in order of increasing team numbers.
    */

};

//use find_if, sort
int main()
{
    iostream::sync_with_stdio(false); 
    int tests;
    cin >> tests;
    cin.ignore(10000, '\n');
    
    for(int test = 0; test < tests; test++){
        vector<Contestant> contestants;
        //Submissions
        int contestantName;
        while(cin >> contestantName){
            int problemNumber;
            int penaltyTime;
            char problemStatus;
            cin >> problemNumber >> penaltyTime >> problemStatus;

            auto isExistingContestant = find_if(begin(contestants), end(contestants), [contestantName](const Contestant contestant){
                return contestant.mName == contestantName;
            });

            if(isExistingContestant != end(contestants)){
                
            }
            if(problemStatus == 'C'){

            }else if(problemStatus == 'I'){

            }
        }
    }
    
} 