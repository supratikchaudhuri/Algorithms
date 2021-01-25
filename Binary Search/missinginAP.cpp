#include<iostream> 
using namespace std; 

class Solution { 
    public:
    int search(int arr[], int low, int high, int diff) { 
        // There must be two elements to find the missing 
        if (high <= low) 
            return INT_MAX; 
    
        int mid = low + (high - low) / 2; 
    
        // The element just after the middle element is missing. 
        // The arr[mid+1] must exist, because we return when 
        // (low == high) and take floor of (high-low)/2 
        if (arr[mid + 1] - arr[mid] != diff) 
            return (arr[mid] + diff); 
    
        // The element just before mid is missing 
        if (mid > 0 && arr[mid] - arr[mid - 1] != diff) 
            return (arr[mid - 1] + diff); 
    
        // If the elements till mid follow AP, then recur  for right half 
        if (arr[mid] == arr[0] + mid * diff) 
            return search(arr, mid + 1, high, diff); 
    
        // Else recur for left half 
        return search(arr, low, mid - 1, diff); 
    } 

    int findMissing(int arr[], int n)  { 
        int diff = (arr[n - 1] - arr[0]) / n; 
        return search(arr, 0, n - 1, diff); 
    } 
}; 
  
// Driver Code 
int main() { 
    Solution ob; 
    int arr[] = {3, 9, 15, 27, 33, 39}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    cout << "The missing element is " 
         << ob.findMissing(arr, n); 
    return 0; 
}  
  