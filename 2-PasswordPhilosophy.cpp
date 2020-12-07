//Day 2: Password Philosophy
#include <bits/stdc++.h>

using namespace std;

struct Query {
    int min, max;
    char letter;
    string password;
};

void getInput(vector<Query> &tasks) {
    ifstream in("inputs/2-input.txt");
    for (string buf; getline(in, buf);) {
        Query q;
        stringstream bufStream(buf);
        bufStream >> q.min >> q.max >> q.letter;
        bufStream.ignore(2); //We ignore semicolon and space
        getline(bufStream, q.password, ' ');
        q.max = -q.max; //This is because it is taking 1-2 as 1, -2
        tasks.push_back(q);
    }
    in.close();
}

//Part 1: Straightforward. Runs in O(n*q), where n is the length of the strings, and q is the amount of queries. 
int solveP1(const vector<Query> &tasks) {
    int ans = 0;
    for (auto query : tasks) {
        int count = 0;
        for (auto i : query.password) {
            if (i == query.letter) count++;
        }

        if (count >= query.min && count <= query.max) ans++;
    }

    return ans;
}

//Part 2: easier, apparently. Also faster. Runs in O(q).
int solveP2(const vector<Query> &tasks) {
    int ans = 0;
    for (auto query : tasks) {
        int count = 0;
        if (query.password[query.min - 1] == query.letter) count++;
        if (query.password[query.max - 1] == query.letter) count++;

        if (count == 1) ans++;
    }
    return ans;
}

int main() {
    vector<Query> tasks;
    getInput(tasks);
    if (tasks.empty()) {
        cerr << "Couldnt open file" << '\n';
        return 1;
    }

    cout << "P1: " << solveP1(tasks) << '\n';
    cout << "P2: " << solveP2(tasks) << '\n';
}