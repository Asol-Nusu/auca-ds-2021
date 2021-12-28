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
/*
2013 - common
2014 - common
2015 - common
2016 - leap
*/
long convertToMins(string &date, string &time){
    replace(date.begin(), date.end(), '-', ' ');
    istringstream dateStream(date);
    string year;
    string month;
    string day;
    dateStream >> year >> month >> day;

    replace(time.begin(), time.end(), ':', ' ');
    istringstream timeStream(time);
    string hours;
    string mins;
    timeStream >> hours >> mins;

    //Calculate
    long result = 0;
    //Year
    bool isLeapYear = false;
    if((stoi(year) % 4 == 0 && stoi(year) % 100 != 0) || (stoi(year) % 400 == 0)){
        isLeapYear = true;
    }

    cout << isLeapYear << endl;
    if(year == "2013"){
        result += 0;
    }else if(year == "2014"){
        result = 365 * 24 * 60;
    }else if(year == "2015"){
        result = (365 * 24 * 60) * 2;
    }else{
        //2016
        result = (365 * 24 * 60) * 3;
    }

    //Month 
    int intMonth = stoi(month);
    for(int m = 1; m < intMonth; m++){
        switch(m){
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
            result += 31 * 24 * 60;
            break;

            case 2:
            int days = isLeapYear ? 29 : 28;
            result += days * 24 * 60;
            break;

            default:
            result += 30 * 24 * 60;
        }
    }

    //Day
    
    

    return 0;
}

pair<long, long> processInput(const string &rawInput, int roomCleaningTime){
    istringstream streamInput(rawInput);
    long arrivalMins;
    long departureMins;

    string reservationCode;
    string arrivalDate;
    string arrivalTime;
    string departureDate;
    string departureTime;
    streamInput >> reservationCode >> arrivalDate >> arrivalTime >> departureDate >> departureTime;

    return make_pair(arrivalMins, departureMins);
}

int main()
{
    iostream::sync_with_stdio(false); 
    int tests;
    cin >> tests;
    for(int test = 0; test < tests; test++){
        int nOfBookings;
        int roomCleaningTime;
        cin >> nOfBookings >> roomCleaningTime; //in mins
        cin.ignore(10000, '\n');


        for(int i = 0; i < nOfBookings; i++){
            string rawInput;
            getline(cin, rawInput);
            pair<long, long> result = processInput(rawInput, roomCleaningTime);
        }

        int minNOfRooms;

        //cout << minNOfRooms << "\n";
    }
} 

/*
arrivalDate (Y/M/D) -> mins
arrivalTime (h/m) -> mins + cleaning 

departureDate
departureTime
*/