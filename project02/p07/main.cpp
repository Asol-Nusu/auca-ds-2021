//RUNTIME ERROR
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

            if(problemStatus == 'C'){
                if(isExistingContestant != end(contestants)){
                    //сущ человек решал эту проблему раньше в incorrectProblems vector
                    auto isPrevIncorrectProblem = find_if(begin((*isExistingContestant).mSubmittedIncorrectProblems), end((*isExistingContestant).mSubmittedIncorrectProblems), [problemNumber](const IProblem &problem){
                        return problemNumber == problem.mNumber;
                    });

                    if(isPrevIncorrectProblem != end((*isExistingContestant).mSubmittedIncorrectProblems)){
                        // >> прежняя incorrect сейчас correct
                        //решенная проблема может быть сабмитнута еще раз
                        if((*isPrevIncorrectProblem).mStatus == 'I'){
                            (*isPrevIncorrectProblem).mStatus = 'C';
                            (*isExistingContestant).mTotalSolvedProblems++;
                            (*isPrevIncorrectProblem).calculateFinalPenaltyTime();
                            (*isExistingContestant).mTotalPenaltyTime += (*isPrevIncorrectProblem).mFinalPenaltyTime;
                            (*isExistingContestant).mTotalPenaltyTime += penaltyTime;
                        }
                    }else{
                        //сущ человек решил новую проблему
                        (*isExistingContestant).mTotalSolvedProblems++;
                        (*isExistingContestant).mTotalPenaltyTime += penaltyTime;
                    }
                    
                }else{
                    //новый человек решил новую проблему
                    //у него никаких историй нет
                    contestants.push_back(Contestant(contestantName));
                    contestants.back().mTotalSolvedProblems++;
                    contestants.back().mTotalPenaltyTime += penaltyTime;
                }
            }else if(problemStatus == 'I'){
                if(isExistingContestant != end(contestants)){
                    auto isPrevIncorrectProblem = find_if(begin((*isExistingContestant).mSubmittedIncorrectProblems), end((*isExistingContestant).mSubmittedIncorrectProblems), [problemNumber](const IProblem &problem){
                        return problemNumber == problem.mNumber;
                    }); //but it's still incorrect
                    if(isPrevIncorrectProblem != end((*isExistingContestant).mSubmittedIncorrectProblems)){
                        (*isPrevIncorrectProblem).mNOfSubmissions++;
                    }
                }else{
                    //новый человек сабмитнул неправильно решенную проблему 
                    //у него никаких историй нет
                    contestants.push_back(Contestant(contestantName));
                    contestants.back().mSubmittedIncorrectProblems.push_back(IProblem(problemNumber));
                    contestants.back().mSubmittedIncorrectProblems.back().mNOfSubmissions++;
                }
            }else{
                if(isExistingContestant != end(contestants)){ 
                }else{
                    //new person
                    contestants.push_back(Contestant(contestantName));
                }
            }
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