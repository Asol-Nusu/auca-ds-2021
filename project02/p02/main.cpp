/*
 Each job description is terminated by a line containing a period.
*/
#include <bits/stdc++.h> 
#include <string>

template <typename C>
int sz(const C &c) { 
    return static_cast<int>(c.size()); 
}

using namespace std;

struct Skill{
    string mName;
    int mValue;

    Skill(const string &name, double value)
    : mName(name), mValue(value)
    {
    }

    bool operator()() const{

    }
};

int main()
{
    iostream::sync_with_stdio(false); 

    int nOfSkills;
    int nOfJobDescriptions;
    
    cin >> nOfSkills >> nOfJobDescriptions;
    vector<Skill> skills;

    for(int i = 0; i < nOfSkills; i++){
        string skillName;
        int skillValue;
        cin >> skillName >> skillValue;
        skills.push_back(Skill(skillName, skillValue));
    }
    sort(begin(skills), end(skills), [](const Skill &skill1, const Skill &skill2){
        return skill1.mName < skill2.mName;
    });

    int sum = 0;
    for(int i = 0; i < nOfJobDescriptions; i++){
        string word;
        cin >> word;
        while(word != "."){
            
            cin >> word;
        }
    }
    /*
    1) Sort a vector of skills based on names
    2) lower_bound(begin(skills), end(skills), each_job_word)
    */
} 