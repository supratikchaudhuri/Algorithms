#include<bits/stdc++.h>
using namespace std;

struct Activity {
    int start, end, index;
};

bool compare(Activity a, Activity b) {
    return a.end < b.end;
}

void maxMeetings(int start[], int end[], int n) {
    Activity arr[n];
    for(int i = 0; i < n; i++) {
        arr[i].start = start[i];
        arr[i].end = end[i];
        arr[i].index = i+1;
    }
    
    sort(arr, arr+n, compare);
    
    int count = 1, i = 0;//first activity is always included
    cout<<arr[i].index<<" ";
    
    for(int j = 1; j < n; j++) {
        if(arr[j].start >= arr[i].end) {
            cout<<arr[j].index<<" ";
            count++;
            i = j;
        }
    }
    cout<<endl;
    cout<<"total meetings = "<< count;
}

int main() {
	//code
    // int start[] = {1,3,0,5,8,5};
    // int end[] =   {2,4,6,7,9,9};
    int start[] = {75250,50074,43659,8931,11273,27545,50879,77924};
    int end[] ={112960,114515,81825,93424,54316,35533,73383,160252};
    int n = sizeof(start)/sizeof(start[0]); 
	maxMeetings(start, end, n);
}