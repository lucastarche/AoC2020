//Day 9: Encoding Error
#include <bits/stdc++.h>

using namespace std;

void getInput(vector<long long> &nums) {
    ifstream in("inputs/9-input.txt");
    for (long long num; in >> num;) {
        nums.push_back(num);
    }
    in.close();
}

long long solveP1(const vector<long long> &nums, int preamble) {
    int n = (int)nums.size();
    
    deque<long long> curr;
    for (int i = 0; i < preamble; i++) {
        curr.push_back(nums[i]);
    }

    for (int i = preamble; i < n; i++) {
        long long num = nums[i];
        bool valid = false;
        for (int j = 0; j < preamble; j++) {
            for (int k = j + 1; k < preamble; k++) {
                if (curr[j] + curr[k] == num) valid = true;
            }
        }

        if (!valid) return num;

        curr.push_back(num);
        curr.pop_front();
    }
    return 0LL;
}

long long solveP2(const vector<long long> &nums) {
    int n = (int)nums.size();
    long long target = solveP1(nums, 25);

    int lptr = 0, rptr = 0;
    long long curr = 0;
    while (rptr < n) {
        if (curr == target) {
            return 
                *min_element(nums.begin() + lptr, nums.begin() + rptr) + 
                *max_element(nums.begin() + lptr, nums.begin() + rptr);
        }
        else if (curr < target) {
            curr += nums[rptr];
            rptr++;
        }
        else {
            curr -= nums[lptr];
            lptr++;
        }
    }

    return 0LL;
}

int main() {
    vector<long long> nums;
    getInput(nums);

    cout << "P1: " << solveP1(nums, 25) << '\n';
    cout << "P2: " << solveP2(nums) << '\n';
}