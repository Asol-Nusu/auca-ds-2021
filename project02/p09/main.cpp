/*
build the longest loop of rope while alternating colors.
𝑆  segments and each segment will either be blue (𝐵) or red (𝑅).

- Alternate between colors
- If only one color, output 0
- --*-- (knot consumes 0.5 cm from each rope)
*/
#include <bits/stdc++.h> 
#include <string>

template <typename C>
int sz(const C &c) { 
    return static_cast<int>(c.size()); 
}

using namespace std; 
struct RopeSegment{
    int length;
    char color;

    RopeSegment(const string &rawInput)
        : color(rawInput.back())
    {
        //1 ≤ 𝐿 ≤ 100 and colors is R or B
        string sLength;
        for(auto c : rawInput){
            if(c != color){
                sLength.push_back(c);
            }
        }
        length = stoi(sLength);
    }
};

//Use sort, accumulate
int main()
{
    iostream::sync_with_stdio(false); 
    int tests;
    cin >> tests;
    cout << "noftests is " << tests << "\n";
    for(int test = 1; test <= tests; test++){
        int nOfRopeSegments;
        cin >> nOfRopeSegments;

        vector<RopeSegment> ropes;
        for(int segment = 0; segment < nOfRopeSegments; segment++){
            string rawInput;
            cin >> rawInput;
            ropes.push_back(RopeSegment(rawInput));
        }



        cout << "Case #" << test << ": " << "\n";
    }
} 