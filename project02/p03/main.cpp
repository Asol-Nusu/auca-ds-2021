/*
Point of interest image coding 

 a grid of letters from ‘A’ to ‘Z’, 
 each letter representing one pixel

 The same letters -> the same pixels -> the same region
 The region with maximum number of letters is to be considered 
 as the most important region.

 Important Letter - M bytes
 Non-important letter - N bytes 
*/
#include <bits/stdc++.h> 
  
template <typename C>
int sz(const C &c) { 
    return static_cast<int>(c.size()); 
}

using namespace std; 
struct Region{
    friend bool operator== (const Region &lhs, const Region &rhs);
    char mLetter;
    int mCount = 0;

    Region(const char &letter)
    : mLetter(letter)
    {
        mCount++;
    }
};
bool operator==(const Region &a, const Region &b){
    return a.mLetter == b.mLetter;
}

int main()
{
    iostream::sync_with_stdio(false); 
    int tests;
    cin >> tests;
    for(int i = 0; i < tests; i++){
        int rows;
        int columns;
        int mBytes;
        int nBytes;
        cin >> rows >> columns >> mBytes >> nBytes;
        vector<Region> regions;

        //Reading the grid
        for(int row = 0; row < rows; row++){
            for(int column = 0; column < columns; column++){
                char letter;
                cin >> letter;

                auto isExistingRegion = find(begin(regions), end(regions), Region(letter));
                if(isExistingRegion != end(regions)){ //if it's an existing element
                
                }
                regions.push_back(Region(letter));
            }
        }
    }
} 