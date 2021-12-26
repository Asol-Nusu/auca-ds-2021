#include <bits/stdc++.h> 

template <typename C>
int sz(const C &c) { 
    return static_cast<int>(c.size()); 
}

using namespace std; 
struct Problem{
    int mNumber;
    char mStatus;
    int mPenaltyTime;

    int mNOfSubmissions = 0;
    bool mWasPreviouslyIncorrect = false;

    Problem(int problemNumber, char status, int penaltyTime)
        : mNumber(problemNumber), mStatus(status), mPenaltyTime(penaltyTime)
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
    
    void addSubmission(Problem &problem){
        auto problemSubmittedBefore = find_if(begin(problems), end(problems), [&problem](const Problem &problemElement){
                return problem.mNumber == problemElement.mNumber;
            });

        if(problemSubmittedBefore != end(problems)){
            if(problem.mStatus == 'C'){
                if((*problemSubmittedBefore).mStatus == 'I'){
                    (*problemSubmittedBefore).mWasPreviouslyIncorrect = true;
                    (*problemSubmittedBefore).mPenaltyTime = problem.mPenaltyTime;
                    (*problemSubmittedBefore).mStatus = 'C';
                }else if((*problemSubmittedBefore).mStatus == 'R' || (*problemSubmittedBefore).mStatus == 'U' || (*problemSubmittedBefore).mStatus == 'E'){
                    (*problemSubmittedBefore).mPenaltyTime = problem.mPenaltyTime;
                    (*problemSubmittedBefore).mStatus = 'C';
                }
            }else if(problem.mStatus == 'I'){
                problem.mNOfSubmissions++;
            }
        }else{
            if(problem.mStatus == 'I'){
                problem.mNOfSubmissions++;
            }
            problems.push_back(problem);
        }    
    }

    pair<int, int> calculateStandings(){
        int mTotalSolvedProblems = 0;
        int mTotalPenaltyTime = 0;
        for(auto problem : problems){
            if(problem.mStatus == 'C'){
                mTotalSolvedProblems++;
                mTotalPenaltyTime += problem.mPenaltyTime;

                if(problem.mWasPreviouslyIncorrect){
                    mTotalPenaltyTime += 20*problem.mNOfSubmissions;
                }
            }
        }

        return make_pair(mTotalSolvedProblems, mTotalPenaltyTime);
    }
};

struct CmpByTeamNumber{
    bool operator()(const Contestant &c1, const Contestant &c2){
        return c1.mName < c2.mName;
    }
};

struct CmpByACMRules{
   bool operator()(Contestant &c1, Contestant &c2){
       pair<int, int> result1 = c1.calculateStandings();
       pair<int, int> result2 = c2.calculateStandings();

       if(result1.first != result2.first){
           return result1.first > result2.first;
       }else{
           if(result1.second != result2.second){
               return result1.second < result2.second;
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

            auto isExistingContestant = find_if(begin(contestants), end(contestants), [contestantName](const Contestant &contestant){
                return contestant.mName == contestantName;
            });

            if(isExistingContestant != end(contestants)){
                Problem p = Problem(problemNumber, problemStatus, penaltyTime);
                (*isExistingContestant).addSubmission(p);
            }else{
                Contestant newContestant = Contestant(contestantName);
                Problem p = Problem(problemNumber, problemStatus, penaltyTime);
                newContestant.addSubmission(p);
                contestants.push_back(newContestant);
            }

            //Sorting contestants
            sort(begin(contestants), end(contestants), CmpByACMRules());

            //printing
            for(auto contestant : contestants){
                cout << contestant.mName << " " << contestant.calculateStandings().first << " " << contestant.calculateStandings().second << "\n";
            }

            //To avoid Presentation Error
            if(test != tests - 1){
                cout << "\n";
            }
        }
    }
} 