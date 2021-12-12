//ACCEPTED
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
    
    for(int i = 0; i < nOfJobDescriptions; i++){
        int sum = 0;
        string descriptionWord;
        cin >> descriptionWord;
        while(descriptionWord != "."){
            auto result = lower_bound(begin(skills), end(skills), descriptionWord, [](const Skill &skill, const string &word)
            {
                return skill.mName < word;
            });

            if(result != end(skills) && (*result).mName == descriptionWord){ //if it's found
                //l_b returns an iterator to an element that is not only equal but also greater
                sum += (*result).mValue;
            }

            //reading next word
            cin >> descriptionWord;
        }

        //printing the result
        cout << sum << "\n";
    }
} 