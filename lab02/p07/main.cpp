//ACCEPTED
#include <bits/stdc++.h> 
#include <algorithm> 
template <typename C>
int sz(const C &c) { 
    return static_cast<int>(c.size()); 
}

using namespace std; 

//channels [0, 99]

int main()
{
    iostream::sync_with_stdio(false); 
    int currentChannel; 
    int goToChannel;
    while(cin >> currentChannel >> goToChannel){
        if(currentChannel == -1 && goToChannel == -1){
            break;
        }
        int minChannel = min(currentChannel, goToChannel) + 1;
        int maxChannel = max(currentChannel, goToChannel) + 1;

        int timesToPress = min(100 + minChannel - maxChannel, maxChannel - minChannel);
        cout << abs(timesToPress) << endl;
    }
} 

