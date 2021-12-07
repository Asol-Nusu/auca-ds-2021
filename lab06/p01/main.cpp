#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;
void p0101(){
    int a[] = {3, 1, 20, 4, 7, 0, 5};
    vector<int> v = {3, 1, 20, 4, 7, 0, 5};

    //Linear Search
    auto itArray = find(begin(a), end(a), 20);

    if(itArray != end(a)){
        cout << "position of 20 is " << itArray - begin(a) << endl;
    }else{
        cout << "20 not found" << endl;
    }

    auto itVector = find(begin(v), end(v), -1);
    if(itVector != end(v)){
        cout << "position of -1 is " << itVector - begin(v) << endl;
    }else{
        cout << "-1 not found" << endl;
    }
}

int main(){
    p0101();
}