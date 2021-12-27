//ACCEPTED
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

struct Submission{
    int mContestant;
    int mProblem;
    int mPenaltyTime;
    char mProblemStatus;

    Submission(const string &input){
        istringstream streamInput(input);
        streamInput >> mContestant >> mProblem >> mPenaltyTime >> mProblemStatus;
    }
};

using Problem = pair<bool, int>;
//solved and nOfAttempts

struct Contestant{
    int mNumber;
    int mTotalSolvedProblems;
    int mTotalPenaltyTime;
    bool mHadAtLeastOneSubmission;
    vector<Problem> mProblems;

    Contestant(int number)
        : mNumber(number), mTotalSolvedProblems(0), mTotalPenaltyTime(0), mHadAtLeastOneSubmission(false), mProblems(9)
    {
    }

    void processSubmission(const Submission submission){
        mHadAtLeastOneSubmission = true;
        if(mProblems[submission.mProblem - 1].first){
            return;
        }

        if(submission.mProblemStatus == 'C'){
            mTotalSolvedProblems++;
            mProblems[submission.mProblem - 1].first = true;
            mTotalPenaltyTime += submission.mPenaltyTime + mProblems[submission.mProblem - 1].second;
        }else if(submission.mProblemStatus == 'I' ){
            mProblems[submission.mProblem - 1].second += 20;
        }
    } 
};

struct CmpByTeamNumber{
    bool operator()(const Contestant &c1, const Contestant &c2){
        return c1.mNumber < c2.mNumber;
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
    cin >> tests >> ws;

    for(int test = 0; test < tests; test++){
        vector<Contestant> contestants;
        for(int i = 1; i <= 100; i++){
            contestants.emplace_back(i);
        }

        //Submissions
        for(string input; getline(cin, input) && !input.empty();){
            Submission submission(input);
            contestants[submission.mContestant - 1].processSubmission(submission);
        } 

        sort(begin(contestants), end(contestants), CmpByACMRules());

        if(test != 0){
            cout << "\n";
        }
        for(auto &contestant : contestants){
            if(contestant.mHadAtLeastOneSubmission){
                cout << contestant.mNumber << " " << contestant.mTotalSolvedProblems << " " << contestant.mTotalPenaltyTime << "\n";
            }
        }
    }
} 
