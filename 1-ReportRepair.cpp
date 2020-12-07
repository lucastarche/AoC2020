//Day 1: Report Repair
#include <bits/stdc++.h>

using namespace std;

void getInput(vector<int> &nums) {
    ifstream in("inputs/1-input.txt");
    for (int i; in >> i;) {
        nums.push_back(i);
    }
    in.close();
}

//Part 1:
//2-SUM problem, but it asks for the product of the two summands. 
//Runs in O(n log n) instead of O(n^2) thanks to sorting.
int solveP1(const vector<int> &nums, int target) {
    int n = (int)nums.size();

    int lptr = 0, rptr = n - 1;
    for (int sum = nums[lptr] + nums[rptr]; sum != target; sum = nums[lptr] + nums[rptr]) {
        if (lptr >= rptr) break;
        if (sum > target) {
            rptr--;
        }
        else {
            lptr++;
        }
    }

    if (nums[lptr] + nums[rptr] == target)
        return (nums[lptr] * nums[rptr]);
    return -1;
}

//Part 2:
//3-SUM problem, answer is idem as P1.
//Runs in O(n^2) instead of O(n^3) thanks to 2-SUM optimization.
//Fun fact: k-SUM problem is NP-Hard
int solveP2(const vector<int> &nums, int target) {
    int n = (int)nums.size();

    for (int i = 0; i < n; i++) {
        int ans = solveP1(nums, target - nums[i]);
        if (ans != -1) return nums[i] * ans;
    }

    return -1;
}

int main() {
    vector<int> nums;
    getInput(nums);
    if (nums.empty()) {
        cerr << "Couldnt open file" << '\n';
        return 1;
    }

    sort(nums.begin(), nums.end());

    cout << "P1: " << solveP1(nums, 2020) << '\n';
    cout << "P2: " << solveP2(nums, 2020) << '\n';
}