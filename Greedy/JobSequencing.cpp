// GFG has n^2 soln
#include<bits/stdc++.h>
using namespace std;

struct Job {
    int id, deadline, profit;
};

bool compare(Job a, Job b){
    return a.deadline < b.deadline;
}

void jobSchedule(Job arr[], int n) {
    sort(arr, arr+n, compare);
	    
	priority_queue<int, vector<int>, greater<int>> pq;
	
    cout<<"JOBS -"<<endl;
    for(int i = 0; i < n; i++)
        cout<<arr[i].deadline<<" "<<arr[i].profit<<endl;
    //initalizing job with 1 so only job with delaline 1 will be selected at fisrt
	int last_deadline = 0, profit = 0, jobs = 0;

	for(int i = 0; i < n; i++){
	    if(arr[i].deadline > last_deadline) {
            jobs++;
            profit += arr[i].profit;
            last_deadline = arr[i].deadline;
            pq.push(arr[i].profit);
        }
        else {//this deadline can only be same as the prev items deadline not less
            int prev_profit = pq.top();
            
            if(prev_profit < arr[i].profit) {
                pq.pop();   //remove prev profit
                profit -= prev_profit;
                profit += arr[i].profit;
                pq.push(arr[i].profit);
            } 
        }
	}
	cout<<"Total jobs: "<< jobs<< " " <<"Profit: " << profit << endl; 
}

int main() {
    Job arr[] = {{1,2,100},{2,1,19},{3,2,27},{4,1,25},{5,3,15}};
    jobSchedule(arr, 5);
	return 0;
}


// int jobs = 1, profit = 0;
// for(int i = 0; i < n; i++){
// 	    if(arr[i].deadline >= jobs){//choosing job with next greater deadline
// 	        jobs ++;
// 	        profit += arr[i].profit;
// 	        pq.push(arr[i].profit);
// 	    }
// 	    else if(arr[i].profit > pq.top()){//if we have a job with same deadline we check for its profit
// 	        profit -= pq.top();
// 	        pq.pop();
// 	        profit += arr[i].profit;
// 	        pq.push(arr[i].profit);
// 	    }
// 	}