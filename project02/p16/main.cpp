#include <bits/stdc++.h> 

template <typename C>
int sz(const C &c) { 
    return static_cast<int>(c.size()); 
}

using namespace std; 

enum class Event{
    Departure, Arrival
};

//sort, pair<int, Event>, where Event: enum class Event {Departure, Arrival}
//2013-2016
int main()
{
    iostream::sync_with_stdio(false); 
    int tests;
    cin >> tests;
    for(int test = 0; test < tests; test++){
        int nOfBookings;
        int roomCleaningTime;
        cin >> nOfBookings >> roomCleaningTime; //in mins

        for(int i = 0; i < nOfBookings; i++){
            string reservationCode;
            
        }

    }
} 