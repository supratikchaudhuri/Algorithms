#include<bits/stdc++.h>
using namespace std;

// O(log.min(x, y))
class Solution {
public:
    double findMedianSortedArrays(vector<int>& x, vector<int>& y) {
        if(x.size() > y.size()){
            auto temp = x;
            x = y;
            y = temp;
        }
        
        int lo = 0, hi = x.size(), combinedLength = x.size() + y.size();
        
        while(lo <= hi){
            // cout<<lo<<" "<<hi<<endl;
            int partX = (lo + hi) / 2;
            //partitionX + partitionY = Combined Length
            //LeftX + LeftY == RightX + RightY
            int partY = (combinedLength + 1) / 2 - partX;   //+1 deals with all odd and even length
            
            double leftX = partX == 0 ? INT_MIN : x[partX-1];
            double rightX = partX == x.size() ? INT_MAX : x[partX];
            
            double leftY = partY == 0 ? INT_MIN : y[partY-1];
            double rightY = partY == y.size() ? INT_MAX : y[partY];
            
            //FOUND PARTITIONING ELEMENTS
            if(leftX <= rightY and leftY <= rightX){
                double median;
                if(combinedLength & 1)
                    median = max(leftX, leftY) * 1.0;
                else{
                    median = (max(leftX, leftY) + min(rightX, rightY)) / 2.0;
                    // cout<<"-----"<<endl;
                    // cout<<max(leftX, leftY)<<"   "<< min(rightX, rightY);
                }
                return median;
            }
            //NEED TO MOVE LEFT of X
            else if(leftX > rightY)
                hi = partX - 1;
            //NEED TO MOVE RIGHT of X
            else
                lo = partX + 1;
        }
        return -1.0;
    }
};


int main() {
    Solution ob;
    //tushar roy examples
    vector<int> vec1 = {1,3,8,9,15}, vec2 = {11,11,18,19,21,25};
    vector<int> vec3 = {23,26,31,35}, vec4 = {3,5,7,9,11,16};   //edge case example
    vector<int> vec5 = {1,2,9,10}, vec6 = {-1,0,0,2};

    double ans1 = ob.findMedianSortedArrays(vec1, vec2);
    double ans2 = ob.findMedianSortedArrays(vec3, vec4);
    double ans3 = ob.findMedianSortedArrays(vec5, vec6);

    cout<<ans1<<endl;
    cout<<ans2<<endl;
    cout<<ans3<<endl;
    return 0;
}