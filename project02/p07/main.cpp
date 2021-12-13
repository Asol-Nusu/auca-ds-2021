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
struct Contestant{
    string mName;
    int nOfSolvedProblems = 0;
    int penaltyTime = 0;

    Contestant(const string &name)
        : mName(name)
    {
    }
};

struct Sumbission{
    int nOfSolvedProblems; //only if judged correct
    int penaltyTime = 0;
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

    //Submissions

} 