#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

int smallestIndex(vector<int> &nums);
int sumOfDigits(int n);
bool comparePairs(const std::pair<int, int>& a, const std::pair<int, int>& b);

};

int main() {
    Solution solution1;
    int len;
    vector<int> nums;
    cin >> len;
    nums.resize(len);
    for(int i=0; i < len; i++) {
        cin >> nums[i];
    }
    cout << solution1.smallestIndex(nums) << "\n";

    return 0;
}

int Solution::smallestIndex(vector<int> &nums) {   
    map<int, int> M;
    for(int i=0; i<nums.size(); i++) {
        M[i] = nums[i];
    }
    // for(auto i: M) {
    //     cout << i.first << ": " << i.second << "\n";
    // }
    
    map<int, int> sumMap;
    for(int i=0; i<nums.size(); i++) {
        int temp = sumOfDigits(nums[i]);
        sumMap[nums[i]] = temp;
    }

    // Copy map elements to a vector of pairs
    vector<pair<int, int>> mapVector(sumMap.begin(), sumMap.end());

    // Sort the vector using the custom comparison function
    sort(mapVector.begin(), mapVector.end(), comparePairs);

    cout << "mapVector[0]= " << mapVector[0].second << "\n";

    return -1;
}

int Solution::sumOfDigits(int n) {
    int sum = 0;
    while (n != 0) {

        // Extract the last digit
        int last = n % 10;

        // Add last digit to sum
        sum += last;

        // Remove the last digit
        n /= 10;
    }
    return sum;
}

// Define a comparison function to sort pairs by their second element (value)
bool Solution::comparePairs(const std::pair<int, int>& a, const std::pair<int, int>& b) {
    return a.second < b.second;
}
