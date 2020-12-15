//Day 15: Rambunctious Recitation
#include <bits/stdc++.h>

using namespace std;

const vector<int> input = {6,3,15,13,1,0};

int solveP1() {
    map<int, int> time;
    int curr = 1;
    for (int i = 0; i < (int)input.size() - 1; i++) {
        time[input[i]] = curr;
        curr++;
    }

    int num = input[(int)input.size() - 1];
    for (curr; curr < 2020; curr++) {
        if (time.count(num) == 0) {
            time[num] = curr;
            num = 0;
        }
        else {
            int buf = num;
            num = curr - time[num];
            time[buf] = curr;
        }
    }

    return num;
}

int solveP2() {
    vector<int> time(30000000);
    //Number will never exceed the turn number, given the nature of how the numbers are generated (difference of two turns).
    int curr = 1;
    for (int i = 0; i < (int)input.size() - 1; i++) {
        time[input[i]] = curr;
        curr++;
    }

    int num = input[(int)input.size() - 1];
    for (curr; curr < 30000000; curr++) {
        if (time[num] == 0) {
            time[num] = curr;
            num = 0;
        }
        else {
            int buf = num;
            num = curr - time[num];
            time[buf] = curr;
        }
    }

    return num;
}

int main() {
    cout << "P1: " << solveP1() << '\n';
    cout << "P2: " << solveP2() << '\n';
}