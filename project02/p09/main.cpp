/*
build the longest loop of rope while alternating colors.
𝑆  segments and each segment will either be blue (𝐵) or red (𝑅).

- Alternate between colors
- If only one color, output 0
- --*-- (knot consumes 0.5 cm from each rope)

accumulate() 
The result of accumulating 
init and all the elements in the range [first,last).
*/
#include <bits/stdc++.h> 
#include <string>

template <typename C>
int sz(const C &c) { 
    return static_cast<int>(c.size()); 
}

using namespace std; 
struct RopeSegment{
    int mLength;
    char mColor;

    RopeSegment(const string &rawInput)
        : mColor(rawInput.back())
    {
        //1 ≤ 𝐿 ≤ 100 and colors is R or B
        string sLength;
        for(auto c : rawInput){
            if(c != mColor){
                sLength.push_back(c);
            }
        }
        mLength = stoi(sLength);
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

        //Sort ropes based on lenght (from max to min)
        sort(begin(ropes), end(ropes), [](const RopeSegment &r1, const RopeSegment &r2)
        {
            return r1.mLength > r2.mLength;
        });

        RopeSegment resultingRope = accumulate(begin(ropes), end(ropes), 0, [](const RopeSegment &baseRope, const RopeSegment &ropeSegment){

        });

        cout << "Case #" << test << ": " << "\n";
    }
} 