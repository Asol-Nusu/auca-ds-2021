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

    Contestant(const int &name)
        : mName(name)
    {
    }
    
    int mTotalSolvedProblems = 0;
    int mTotalPenaltyTime = 0;
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
//use find_if, sort
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

            auto isExistingContestant = find_if(begin(contestants), end(contestants), [contestantName](const Contestant &contestant){
                return contestant.mName == contestantName;
            });

            /*if person exists*/if(isExistingContestant != end(contestants)){
                auto didWorkOnThisProblem = find_if(begin((*isExistingContestant).problems), end((*isExistingContestant).problems), [problemNumber](const Problem &problem){
                        return problemNumber == problem.mNumber;
                    });

                if(didWorkOnThisProblem != end((*isExistingContestant).problems)){
                    if(problemStatus == 'C'){
                        if((*didWorkOnThisProblem).mStatus == 'R' || (*didWorkOnThisProblem).mStatus == 'U' || (*didWorkOnThisProblem).mStatus == 'E' || (*didWorkOnThisProblem).mStatus == ' '){
                            (*didWorkOnThisProblem).mStatus = 'C';
                            (*didWorkOnThisProblem).mPenaltyTime = penaltyTime;
                        }else if((*didWorkOnThisProblem).mStatus == 'I'){
                            (*didWorkOnThisProblem).mWasPreviouslyIncorrect = true;
                            (*didWorkOnThisProblem).mStatus = 'C';
                            (*didWorkOnThisProblem).mPenaltyTime = penaltyTime;
                        }
                    }else if(problemStatus == 'I'){
                        (*didWorkOnThisProblem).mNOfSubmissions++;
                    }


                }else{
                    (*isExistingContestant).problems.push_back(Problem(problemNumber));
                    if(problemStatus == 'C'){
                        (*isExistingContestant).problems.back().mStatus = 'C';
                        (*isExistingContestant).problems.back().mPenaltyTime = penaltyTime;
                    }else if(problemStatus == 'I'){
                        (*isExistingContestant).problems.back().mStatus = 'I';
                        (*isExistingContestant).problems.back().mNOfSubmissions++;
                    }
                } 

            /* if doesn't person exist*/}else{
                contestants.push_back(Contestant(contestantName));
                if(problemStatus == 'C'){
                    contestants.back().problems.push_back(Problem(problemNumber));
                    contestants.back().problems.back().mStatus = 'C';
                    contestants.back().problems.back().mPenaltyTime = penaltyTime;
                }else if(problemStatus == 'I'){
                    contestants.back().problems.push_back(Problem(problemNumber));
                    contestants.back().problems.back().mStatus = 'I';
                    contestants.back().problems.back().mNOfSubmissions++;
                }else{
                    //U, E, R
                    contestants.back().problems.push_back(Problem(problemNumber));
                    contestants.back().problems.back().mStatus = problemStatus;
                }
            }
        }

        //Calculate Standings
        for(auto contestant : contestants){
            int contestantSolvedPs = 0;
            int contestantPenaltyTime = 0;
            for(auto problem : contestant.problems){
                if(problem.mStatus == 'C'){
                    contestantSolvedPs++;
                    contestantPenaltyTime += problem.mPenaltyTime;

                    if(problem.mWasPreviouslyIncorrect){
                        contestantPenaltyTime += 20*problem.mNOfSubmissions;
                    }
                }
            }
            contestant.mTotalSolvedProblems = contestantSolvedPs;
            contestant.mTotalPenaltyTime = contestantPenaltyTime;
            cout << "Total Solved problems: " << contestant.mTotalSolvedProblems << "\n";
            cout << "Total penalty time: " << contestant.mTotalPenaltyTime << "\n";
        }
        //Sorting contestants
        sort(begin(contestants), end(contestants), CmpByACMRules());

        //printing
        for(auto contestant : contestants){
            cout << contestant.mName << " " << contestant.mTotalSolvedProblems << " " << contestant.mTotalPenaltyTime << "\n";
        }

        //To avoid Presentation Error
        if(test != tests - 1){
            cout << "\n";
        }
    } 
} 