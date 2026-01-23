// Approach-1: shrinking Sliding Window
// Uses a while loop
// optimized code by removing variable countOf1s calculations

#include <bits/stdc++.h>
using namespace std;

void solve(vector<int>& arr, int& n, int& k);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> arr;
    int n, k;
    cin >> n >> k;
    arr.resize(n);

    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    // cout << "you entered: ";
    // for(int i=0; i<n; i++) {
    //     cout << arr[i] << " ";
    // }
    // cout << "\n";

    solve(arr, n, k);
    return 0;
}

void solve(vector<int>& arr, int& n, int& k) {

    int maxWindowLength = 0;
    int zerosCanBeFlippedCount = 0;
    int leftPointer = 0;
    int rightPointer = 0;
    
    for(rightPointer=0; rightPointer<n; rightPointer++) {

        // cout << "leftPointer = " << leftPointer << "\n";
        // cout << "rightPointer = " << rightPointer << "\n";
        
        if(arr[rightPointer] == 0) {
            zerosCanBeFlippedCount += 1;    
        }

        // cout << "zerosCanBeFlippedCount = " << zerosCanBeFlippedCount << "\n";
        // cout << "countOf1s = " << countOf1s << "\n";
        

        while(zerosCanBeFlippedCount > k) {
            
            // cout << "zerosCanBeFlippedCount > k \n";
            // cout << "executing leftPointer += 1; ...\n";

            if(arr[leftPointer] == 0) {
                // cout << "arr[leftPointer] == 0\n";
                // cout << "executing zerosCanBeFlippedCount -= 1; ...\n";  
                zerosCanBeFlippedCount -= 1; 
                 
            }
            
            
            leftPointer += 1;
        }

    
        int currentWindowLength = rightPointer - leftPointer + 1;
        maxWindowLength = max(maxWindowLength, currentWindowLength); 
    }

    cout << maxWindowLength << "\n";
    return;
}



