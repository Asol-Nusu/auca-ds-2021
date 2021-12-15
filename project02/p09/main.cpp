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

    RopeSegment(const int length, const char color)
        : mLength(length), mColor(color)
    {
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

        vector<RopeSegment> blueRopes;
        vector<RopeSegment> redRopes;

        for(int segment = 0; segment < nOfRopeSegments; segment++){
            string rawInput;
            cin >> rawInput;
            if(rawInput.back() == 'B'){
                blueRopes.push_back(RopeSegment(rawInput));
            }else{
                redRopes.push_back(RopeSegment(rawInput));
            }
        }
        if(blueRopes.empty() || redRopes.empty()){
            cout << "Case #" << test << ": 0\n";
        }else{
            
        }
        
        // RopeSegment baseRope = RopeSegment(ropes.front().mLength, ropes.front().mColor);
        // ropes.erase(ropes.begin()); 

        // char checkerColor = baseRope.mColor;
        //Blue ones will be at the beginning 
        sort(begin(ropes), end(ropes), [](const RopeSegment &r1, const RopeSegment &r2)
            {
                return r1.mColor < r2.mColor;
            });

        // sort(begin(ropes), end(ropes), [](const RopeSegment &r1, const RopeSegment &r2)
        //     {
        //         if(r1.mColor != checkerColor){
        //             checkerColor = r1.mColor;
        //             return true;
        //         }else{
        //             checkerColor = r2.mColor;
        //             return false;
        //         }
        //     });
        
        // cout << "Rope's length is " << baseRope.mLength << ". Rope's color is " << baseRope.mColor << "\n";
        // for(auto rope : ropes){
        //     cout << "Rope's length is " << rope.mLength << ". Rope's color is " << rope.mColor << "\n";
        // }
        //cout << "baseRope's length is " << baseRope.mLength << "and its color is " << baseRope.mColor << "\n"; 

        // RopeSegment resultingRope = accumulate(begin(ropes), end(ropes), baseRope, [](const RopeSegment &initRope, const RopeSegment &ropeSegment){
        //     /*
        //     baseRope is not gonna change
        //     initRope will be constantly changing and accumulating all values (eventually returned value)

        //     **baseRope will be returned if the vector is empty
        //     */
        //     if(initRope.mColor != ropeSegment.mColor){
        //         cout << "FIRST ENTRY: here is the initRope's length: " << initRope.mLength << " and the initRope's color " << initRope.mColor <<   " and it's ropeSegment's length " << ropeSegment.mLength << " and the ropeSegment's color " << ropeSegment.mColor << "\n";
        //         int newLength = initRope.mLength + ropeSegment.mLength;
        //         char newColor = ropeSegment.mColor;

        //         return RopeSegment(newLength, newColor);
        //     }else{
        //         //only same color
        //         return initRope;
        //     }    
        // });
        // cout << "resultingRope.mLength is " << resultingRope.mLength << " and its color is " << resultingRope.mColor << "\n";
        // if(nOfRopeSegments == 1){
        //     cout << "Case #" << test << ": 0\n";
        // }else{
        //     cout << "Case #" << test << ": " << resultingRope.mLength << "\n";
        // }
        
    }
} 