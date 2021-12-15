//ACCEPTED
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
    RopeSegment(const int length)
        : mLength(length), mColor('?')
        //resulting rope's color doesn't matter
    {
    }
};

//Use sort, accumulate
int main()
{
    iostream::sync_with_stdio(false); 
    int tests;
    cin >> tests;
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
            //Sorting blue ropes (max -> min)
            sort(begin(blueRopes), end(blueRopes), [](const RopeSegment &r1, const RopeSegment &r2)
            {
                return r1.mLength > r2.mLength;
            });

            //Sorting red ropes (max -> min)
            sort(begin(redRopes), end(redRopes), [](const RopeSegment &r1, const RopeSegment &r2)
            {
                return r1.mLength > r2.mLength;
            });


            vector<RopeSegment> minVector;
            auto maxVectorIndex = blueRopes.begin(); //assignment is NOT true, it's to avoid compilation error
            if(redRopes.size() > blueRopes.size()){
                minVector = blueRopes;
                maxVectorIndex = redRopes.begin();
            }else{
                minVector = redRopes;
                maxVectorIndex = blueRopes.begin();
            }
            RopeSegment baseRope = RopeSegment(0, '?');

            RopeSegment resultingRope = accumulate(begin(minVector), end(minVector), baseRope, [&maxVectorIndex](const RopeSegment &initRope, const RopeSegment &ropeSegment)
                {
                    /*
                    baseRope is not gonna change
                    initRope will be constantly changing and accumulating all values (eventually returned value)
                    */
                        int newLength = initRope.mLength + ropeSegment.mLength + (*maxVectorIndex).mLength - 2;
                        maxVectorIndex++;

                        
                        return RopeSegment(newLength);
                });
            
            cout << "Case #" << test << ": " << resultingRope.mLength << "\n";
        } 
    }
} 