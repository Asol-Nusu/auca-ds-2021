//ERROR
/*
tournament name, team names and games played 
outputs the tournament standings
*/
#include <bits/stdc++.h> 

template <typename C>
int sz(const C &c) { 
    return static_cast<int>(c.size()); 
}

using namespace std; 
struct Team{
    friend bool operator== (const Team &lhs, const Team &rhs);
    string mName;

    int mGamesPlayed;
    
    int mWins;
    int mLosses; 
    int mTies;

    int mGoalsScored; 
    int mGoalsAgainst;
    int mGoalDifference = mGoalsScored - mGoalsAgainst;//их голы - чужие голы //calculated inside
    
    int mTotalPoints = mWins * 3 + mTies * 1; //calculated inside
    
    Team(string name)
        : mName(name)
    {
    }
};
bool operator==(const Team &a, const Team &b){
    return a.mName == b.mName;
}

struct CmpByName{
    //Lexicographic order
    bool operator()(const Team &t1, const Team &t2){
        return t1.mName < t2.mName;
    }
};

struct CmpByResult{
    bool operator()(const Team &t1, const Team &t2){
        if(t1.mTotalPoints != t2.mTotalPoints){
            return t1.mTotalPoints > t2.mTotalPoints;
        }else{
            if(t1.mWins != t2.mWins){
                return t1.mWins > t2.mWins;
            }else{
                if(t1.mGoalDifference != t2.mGoalDifference){
                    return t1.mGoalDifference > t2.mGoalDifference;
                }else{
                    if(t1.mGoalsScored != t2.mGoalsScored){
                        return t1.mGoalsScored > t2.mGoalsScored;
                    }else{
                        if(t1.mGamesPlayed != t2.mGamesPlayed){
                            return t1.mGamesPlayed < t2.mGamesPlayed;
                        }else{
                            CmpByName();
                        }
                    }
                }
            }
        }
    }
};

int main()
{
    iostream::sync_with_stdio(false); 
    int nOfTournaments;
    cin >> nOfTournaments;
    cin.ignore(10000, '\n'); //cin reads until a space, so \n is left
    cout << "TEST: number of tournaments is " << nOfTournaments << "\n";

    for(int tour = 0; tour < nOfTournaments; tour++){
        //Tournament Description
        string tournamentName; 
        int nOfTeams;
        vector<Team> teams;

        getline(cin, tournamentName);
        cin >> nOfTeams;
        cout << "TEST: tournaments name is " << tournamentName << "\n";
        cout << "TEST: nOfTeams is " << nOfTeams << "\n";

        for(int team = 0; team < nOfTeams; team++){
            string teamName; //no ‘#’ and ‘@’
            cin >> teamName;
            cout << "TEST: teamName is " << teamName << "\n";
            teams.push_back(Team(teamName));
        }

        int nOfGamesPlayed;
        cin >> nOfGamesPlayed;
        cin.ignore(10000, '\n');
        cout << "TEST: nOfGamesPlayed is " << nOfGamesPlayed << "\n";
        /*
        game results
        team_name_1#goals1@goals2#team_name_2
        */
        for(int game = 0; game < nOfGamesPlayed; game++){
            string input;
            getline(cin, input);

            //scannign team1Name
            string team1Name;
            int index = 0;
            while(input.at(index) != '#'){
                team1Name.push_back(input.at(index));
                index++;
            }

            //scanning team1goals
            index++;
            string s1Goals;
            while(input.at(index) != '@'){
                s1Goals.push_back(input.at(index));
                index++;
            }
            int team1Goals = stoi(s1Goals);

            //scanning team2goals
            index++;
            string s2Goals;
            while(input.at(index) != '#'){
                s2Goals.push_back(input.at(index));
                index++;
            }
            int team2Goals = stoi(s2Goals);

            //scanning team2Name
            index++;
            string team2Name;
            while(index != sz(input)){
                team2Name.push_back(input.at(index));
                index++;
            }

            //Working with formed teams
            //It's guaranteed it'll find the team
            auto team1 = find(begin(teams), end(teams), Team(team1Name));
            (*team1).mGamesPlayed++;
            (*team1).mGoalsScored += team1Goals;
            (*team1).mGoalsAgainst += team2Goals;

            auto team2 = find(begin(teams), end(teams), Team(team2Name));
            (*team2).mGamesPlayed++;
            (*team2).mGoalsScored += team2Goals;
            (*team2).mGoalsAgainst += team1Goals;

            if(team1Goals > team2Goals){
                (*team1).mWins++;
                (*team2).mLosses++;
            }else if(team1Goals < team2Goals){
                (*team2).mWins++;
                (*team1).mLosses++;
            }else{
                (*team1).mTies++;
                (*team2).mTies++;
            }
        }

        //Ranking (sorting)
        sort(begin(teams), end(teams), CmpByResult());

        //Printing the final result
        cout << tournamentName << "\n";
        for(int team = 0; team < nOfTeams; team++){
            cout << (team + 1) << ") " << teams[team].mName << " " << teams[team].mTotalPoints << "p, " << teams[team].mGamesPlayed << "g (" << teams[team].mWins << "-" << teams[team].mTies << "-" << teams[team].mLosses << "), " << teams[team].mGoalDifference << "gd (" << teams[team].mGoalsScored << "-" << teams[team].mGoalsAgainst << ")\n"; 
        }
    }
} 