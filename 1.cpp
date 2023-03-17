#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Sample {
    string name;
    int age;

    Sample(string name, int age) {
        this->name = name;
        this->age = age;
    } 
};

int main() {
    vector<Sample*> A;
    vector<string> names = {"sam", "rob", "tom", "eric", "lisa"};

    for(int i = 0; i < 5; i++) {
        A.push_back(new Sample(names[i], i + 25));
        
    }

    for(auto s : A) {
        cout<<s->name<<" "<<s->age<<endl;
    }

    Sample s = new Sample("Diane", 48);
    cout<<"\n\n\n"<<s.name<<"    "<<s.age;

}


