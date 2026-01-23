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
    int countOf1s = 0;

    for(int rightPointer=0; rightPointer<n; rightPointer++) {

        // cout << "leftPointer = " << leftPointer << "\n";
        // cout << "rightPointer = " << rightPointer << "\n";
        
        if(arr[rightPointer] == 0) {
            zerosCanBeFlippedCount += 1;    
        }
        
        if(arr[rightPointer] == 1) {
            countOf1s += 1;
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
            
            if(arr[leftPointer] == 1) {
                // cout << "arr[leftPointer] == 1\n";
                // cout << "executing countOf1s -= 1; ...\n"; 
                countOf1s -= 1;
            }
            leftPointer += 1;
        }

        int currentWindowLength = countOf1s + zerosCanBeFlippedCount;
        maxWindowLength = max(maxWindowLength, currentWindowLength); 
    }

    cout << maxWindowLength << "\n";
    return;
}

// 1 0 1
// 0 1 1
// 1 1 0
// 0 0 0 
