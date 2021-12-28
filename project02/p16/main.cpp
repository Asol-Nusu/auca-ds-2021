#include <bits/stdc++.h> 

template <typename C>
int sz(const C &c) { 
    return static_cast<int>(c.size()); 
}

using namespace std; 
using Booking = pair<long, long>;

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
    cout << "Yes, it's a leap year\n";

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
        if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12){
            result += 31 * 24 * 60;
        }else if(m == 2){
            int days = isLeapYear ? 29 : 28;
            result += days * 24 * 60;
        }else{
            result += 30 * 24 * 60;
        }
    }

    //Day
    int intDay = stoi(day);
    for(int i = 1; i < intDay; i++){
        result += 24 * 60;
    }

    //Time
    long timeMins = stoi(hours)*60 + stoi(mins);
    result += timeMins;
    
    cout << result << endl;
    return result;
}

Booking processInput(const string &rawInput, int roomCleaningTime){
    istringstream streamInput(rawInput);
    long arrivalMins;
    long departureMins;

    string reservationCode;
    string arrivalDate;
    string arrivalTime;
    string departureDate;
    string departureTime;
    streamInput >> reservationCode >> arrivalDate >> arrivalTime >> departureDate >> departureTime;
    arrivalMins = convertToMins(arrivalDate, arrivalTime);
    departureMins = convertToMins(departureDate, departureTime);
    departureMins += roomCleaningTime;

    return make_pair(arrivalMins, departureMins);
}

bool needSeparateRoom(const vector<Booking> &bookingsWithRoom, const Booking &booking){
    
    for(int i = 0; i < sz(bookingsWithRoom); i++){
        if(bookingsWithRoom[i].second <= booking.first){
            return false;
        }
    }

    return true;
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

        vector<Booking> bookings;
        for(int i = 0; i < nOfBookings; i++){
            string rawInput;
            getline(cin, rawInput);
            Booking result = processInput(rawInput, roomCleaningTime);
            bookings.push_back(result);
        }

        sort(begin(bookings), end(bookings), [](const Booking &b1, const Booking &b2){
            //first-come-first-serve
            return b1.first < b2.first;
        });

        vector<Booking> bookingsWithRoom;
        bookingsWithRoom.push_back(bookings.back());

        int minNOfRooms = 1;
        for(int i = 1; i < sz(bookings); i++){
            if(needSeparateRoom(bookingsWithRoom, bookings[i])){
                bookingsWithRoom.push_back(bookings[i]);
                minNOfRooms++;
            }
        }

        cout << minNOfRooms << "\n";
    }
} 

/*
arrivalDate (Y/M/D) -> mins
arrivalTime (h/m) -> mins + cleaning 

departureDate
departureTime
*/