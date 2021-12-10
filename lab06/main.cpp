#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <string>

#include "../au/algol.hpp"

using namespace std;
struct Student{
    string mName;
    double mGpa;
            
    Student(const string &name, double gpa)
    : mName(name), mGpa(gpa)
    {
    }
};

//support call operator: T t; t()
struct IsEven{
    bool operator()(int value) const{
        return value % 2 == 0;
    }
};

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

void p0102(){
    int a[] = {3, 1, 20, 4, 7, 0, 5};
    vector<int> v = {3, 1, 20, 4, 7, 0, 5};

    //Linear Search
    auto itArray = auFind(begin(a), end(a), 20);

    if(itArray != end(a)){
        cout << "position of 20 is " << itArray - begin(a) << endl;
    }else{
        cout << "20 not found" << endl;
    }

    auto itVector = auFind(begin(v), end(v), -1);
    if(itVector != end(v)){
        cout << "position of -1 is " << itVector - begin(v) << endl;
    }else{
        cout << "-1 not found" << endl;
    }
}
void p0201(){
    vector<int> v = {3, 1, 20, 4, 7, 0, 5};
    
    //Linear Search
    auto itVector = find_if(begin(v), end(v), IsEven());
   
    if(itVector != end(v)){
        cout << "position of the first even number is " << itVector - begin(v) << endl;
        cout << "the number is " << *itVector << endl;
    }else{
        cout << "even numbers are not found" << endl;
    }
}

void p0202(){
    vector<int> v = {3, 1, 20, 4, 7, 0, 5};
    
    auto itVector = auFindIf(begin(v), end(v), IsEven());
   
    if(itVector != end(v)){
        cout << "position of the first even number is " << itVector - begin(v) << endl;
        cout << "the number is " << *itVector << endl;
    }else{
        cout << "even numbers are not found" << endl;
    }

    //Lambda Expression
    auto itVector2 = auFindIf(begin(v), end(v), [](int value)
        {return value % 2 == 0;});
   
    if(itVector2 != end(v)){
        cout << "position of the first even number is " << itVector2 - begin(v) << endl;
        cout << "the number is " << *itVector2 << endl;
    }else{
        cout << "even numbers are not found" << endl;
    }
}
struct CmpByGPA{
    bool operator()(const Student &s1, const Student &s2){
        return s1.mGpa < s2.mGpa;
    }
};
void p06(){
    vector<Student> students;
    string name; 
    double gpa;
    while(cin >> name >> gpa){
        students.emplace_back(name, gpa);
    }
    sort(begin(students), end(students), [](const Student &s1, const Student &s2)
    {return s1.mName < s2.mName;});

    for(const auto &s : students){
        cout << "{" << s.mName << ", " << s.mGpa << "}" << endl;
    }

    cout << " ---- " << endl;

    sort(begin(students), end(students), CmpByGPA());

    for(const auto &s : students){
        cout << "{" << s.mName << ", " << s.mGpa << "}" << endl;
    }
}

void p10(){
    vector<int> v = {1, 4, 5, 10, 12, 20, 25, 40};
    for(int x; cin >> x;){
        cout << (binary_search(begin(v), end(v), x) ? "yes" : "no") << endl;
    }

}


int main(){
    //p0101();
    //p0102();
    //p0201();
    //p0202();
    //p06();
    p10();
}