#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int smallestIndex(vector<int> &nums);
    int sumOfDigits(int n);

};

int main() {
    Solution solution1;
    int len;
    vector<int> nums;

    cout << "input len: ";
    cin >> len;
    nums.resize(len);

    cout << "input nums vector: ";
    for(int i=0; i < len; i++) {
        cin >> nums[i];
    }
    cout << solution1.smallestIndex(nums) << "\n";

    return 0;
}

int Solution::smallestIndex(vector<int> &nums) {   

    int ans = -1;
    for(int i=0; i<nums.size(); i++) {
        int temp = sumOfDigits(nums[i]);
        if(i == temp) {
            ans = i;
            break;
        }
    }
    return ans;
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
