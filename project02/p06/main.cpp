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
    string mName;
    int rank; //to be calculated

    int gamesPlayed;
    
    int wins;
    int losses; 
    int ties;

    int goalsScored; 
    int goalsAgainst;
    int goalDifference;//их голы - чужие голы
    
    int totalPoints;
    
    Team(string name)
        : mName(name)
    {
    }
};

int main()
{
    iostream::sync_with_stdio(false); 
    int nOfTournaments;
    cin >> nOfTournaments;

    for(int tour = 0; tour < nOfTournaments; tour++){
        //Tournament Description
        string tournamentName; 
        int nOfTeams;
        vector<Team> teams;

        cin >> tournamentName >> nOfTeams;
        for(int team = 0; team < nOfTeams; team++){
            string teamName; //no ‘#’ and ‘@’
            cin >> teamName;
            teams.push_back(Team(teamName));
        }

        int nOfGamesPlayed;
        /*
        game results
        team_name_1#goals1@goals2#team_name_2
        */
        for(int game = 0; game < nOfGamesPlayed; game++){
            
        }
    }
} 