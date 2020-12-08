//Day 8: Handheld Halting
#include <bits/stdc++.h>

using namespace std;

void getInput(vector<string> &operations) {
    ifstream in("inputs/8-input.txt");
    for (string buf; getline(in, buf);) {
        operations.push_back(buf);
    }
    in.close();
}

void execute(const string &op, int &acc, int &opPtr) {
    string type = op.substr(0, 3);
    int num = stoi(op.substr(4));
    if (type == "acc") {
        acc += num;
        opPtr++;
    }
    else if (type == "jmp") {
        opPtr += num;
    }
    else if (type == "nop") {
        opPtr++;
    }
}

int solveP1(const vector<string> &operations) {
    int n = (int)operations.size();
    int acc = 0, curr = 0;
    vector<bool> executed(n, false);

    while (!executed[curr]) {
        executed[curr] = true;
        execute(operations[curr], acc, curr);
    }

    return acc;
}

int halts(const vector<string> &operations, vector<bool> executed, int swapIndex, int acc) {
    int n = (int)operations.size();
    int curr = swapIndex;

    while (!executed[curr]) {
        if (curr == swapIndex) {
            string type = operations[curr].substr(0, 3);
            string num = operations[curr].substr(4);
            executed[curr] = true;
            if (type == "nop") {
                execute("jmp " + num, acc, curr);
            }
            else {
                execute("nop " + num, acc, curr);
            }
        }
        else {
            executed[curr] = true;
            execute(operations[curr], acc, curr);
        }
        if (curr >= n) 
            return acc;
    }

    return -1;
}

int solveP2(const vector<string> &operations) {
    int n = (int)operations.size();
    int acc = 0, curr = 0;
    vector<bool> executed(n, false);

    while (!executed[curr]) {
        string type = operations[curr].substr(0, 3);
        if (type == "nop" || type == "jmp") {
            int temp = halts(operations, executed, curr, acc);
            if (temp != -1) {
                return temp;
            }
        }
        executed[curr] = true;
        execute(operations[curr], acc, curr);
    }
    return -1;
}

int main() {
    vector<string> operations;
    getInput(operations);

    cout << "P1: " << solveP1(operations) << '\n';
    cout << "P2: " << solveP2(operations) << '\n';
}