//Day 7: Handy Haversnacks
#include <bits/stdc++.h>

using namespace std;

string getBag(stringstream &in) {
    if (in.eof()) return "";
    string curr, temp;
    in >> curr >> temp;
    return curr + " " + temp;
}

void ignoreStrings(stringstream &in, int n) {
    string a;
    while (n--) {
        if (in.eof()) return;
        in >> a;
    }
}

void getInput(vector<vector<int>> &ady, vector<vector<pair<int, int>>> &ady2) {
    int n = 2;
    map<string, int> bags;
    bags["shiny gold"] = 1;
    ady.push_back({});
    ady.push_back({});
    ady2.push_back({});
    ady2.push_back({});

    ifstream in("inputs/7-input.txt");
    for (string buf; getline(in, buf);) {
        stringstream str(buf);
        string curr = getBag(str);
        if (bags.count(curr) == 0) {
            bags[curr] = n; 
            ady.push_back({});
            ady2.push_back({});
            n++;
        }

        ignoreStrings(str, 2);
        str >> buf;
        if (buf == "no") {
            ignoreStrings(str, 2);
            continue;
        }

        while (!str.eof()) {
            string inside = getBag(str);
            if (bags.count(inside) == 0) {
                bags[inside] = n;
                ady.push_back({});
                ady2.push_back({});
                n++;
            }
            ady[bags[inside]].push_back(bags[curr]);
            ady2[bags[curr]].push_back({bags[inside], stoi(buf)});
            ignoreStrings(str, 1);
            if (!str.eof()) str >> buf;
        }
    }
    in.close();
}

int solveP1(const vector<vector<int>> &ady) {
    int n = (int)ady.size();

    queue<int> q;
    vector<bool> visit(n);
    q.push(1);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        if (visit[curr]) continue;
        visit[curr] = true;

        for (auto a : ady[curr]) {
            if (!visit[a]) q.push(a);
        }
    }
    
    int ans = 0;
    for (auto v : visit) {
        if (v) ans++;
    }
    return ans - 1;
}

long long solveP2(const vector<vector<pair<int, int>>> &ady, int start) {
    long long ans = 0;
    for (auto a : ady[start]) {
        ans += a.second * solveP2(ady, a.first);
        ans += a.second; 
    }
    return ans;
}

int main() {
    vector<vector<int>> ady;
    vector<vector<pair<int, int>>> ady2;
    getInput(ady, ady2);

    cout << "P1: " << solveP1(ady) << '\n';
    cout << "P2: " << solveP2(ady2, 1) << '\n';
}