// moving sliding-window approach

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
    int forLoopIteration = 0;

    for(rightPointer=0; rightPointer<n;) {
        
        // cout << "for-loop iteration starts:\n";
        if(forLoopIteration == 20) {break;}
        // cout << "for-loop iteration = " << forLoopIteration << "\n";
        // cout << "leftPointer = " << leftPointer << "\n";
        // cout << "rightPointer = " << rightPointer << "\n";
        
        if(arr[rightPointer] == 0) {
            zerosCanBeFlippedCount += 1;    
        }

        // cout << "zerosCanBeFlippedCount = " << zerosCanBeFlippedCount << "\n";

        if(zerosCanBeFlippedCount > k) {
            
            // cout << "zerosCanBeFlippedCount > k \n";
            // cout << "moving leftPointer...\n";
            
            // cout << "executing leftPointer += 1; ...\n";

            if(arr[leftPointer] == 0) {
                // cout << "arr[leftPointer] == 0\n";
                // cout << "reducing zerosCanBeFlippedCount...\n";
                // cout << "executing zerosCanBeFlippedCount -= 1; ...";
                zerosCanBeFlippedCount -= 1;
                // cout << "done.\n";
                // cout << "zeroesCanBeFlippedCount = " 
                //     << zerosCanBeFlippedCount << "\n";
            }

            
            leftPointer += 1;
            // cout << "done\n";

            // cout << "leftPointer = " << leftPointer << "\n";
            // cout << "rightPointer = " << rightPointer << "\n";
            // cout << "zeroesCanBeFlippedCount = " 
            //         << zerosCanBeFlippedCount << "\n";
        
        }

    
        int currentWindowLength = rightPointer - leftPointer + 1;
        maxWindowLength = max(maxWindowLength, currentWindowLength); 
        // cout << "currentWindowLength = " 
        //             << currentWindowLength << "\n";

        // cout << "maxWindowLength = " 
        //             << maxWindowLength << "\n";

        // cout << "zeroesCanBeFlippedCount = " 
        //             << zerosCanBeFlippedCount << "\n";

        // cout << "incrementing variable forLoopIteration...\n";
        // cout << "incrementing variable rightPointer...\n";
        forLoopIteration += 1;
        rightPointer += 1;
        // cout << "forLoopIteration = " << forLoopIteration << "\n";
        // cout << "rightPointer = " << rightPointer << "\n";
        
        // cout << "zeroesCanBeFlippedCount = " 
        //             << zerosCanBeFlippedCount << "\n";
        // cout << "for-loop iteration ends.\n\n";
    }

    
    cout << "maxWindowLength = " << maxWindowLength << "\n";
    // cout << "leftPointer = " << leftPointer << "\n";
    // cout << "rightPointer = " << rightPointer << "\n";
    return;
}
