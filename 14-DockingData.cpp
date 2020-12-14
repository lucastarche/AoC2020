#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
LL solveP1() {
    map<LL, LL> memory;
    ifstream in("inputs/14-input.txt");

    string mask;

    for (string buf; getline(in, buf);) {
        if (buf[3] == 'k') {
            mask = buf.substr(7); //"mask = " has length 7
            reverse(mask.begin(), mask.end());
        }
        else {
            string indexStr, valStr;
            int i = 4;
            for (i; buf[i] != ']'; i++) {
                indexStr += buf[i];
            }
            i += 4;
            for (i; i < (int)buf.size(); i++) {
                valStr += buf[i];
            }

            LL val = stoll(valStr);
            for (int j = 0; j < (int)mask.size(); j++) {
                if (mask[j] == 'X') continue;
                if (mask[j] == '1') {
                    val |= 1LL<<j;
                }
                else {
                    val &= ~(1LL<<j);
                }
            }

            memory[stoll(indexStr)] = val;
        }
    }

    LL ans = 0LL;
    for (auto a : memory) {
        ans += a.second;
    }
    return ans; 
}

string toBinary(string indexStr) {
    LL idx = stoll(indexStr);
    string res = "";
    while (idx > 0LL) {
        if (idx % 2LL == 0LL) {
            res.push_back('0');
        }
        else {
            res.push_back('1');
        }
        idx /= 2LL;
    }

    while ((int)res.size() < 36) res.push_back('0');
    return res;
}

void setVal(string index, LL val, map<LL, LL> &memory) {
    LL idx = 0LL;
    for (int i = 0; i < (int)index.size(); i++) {
        if (index[i] == '0') continue;
        if (index[i] == '1') idx |= 1LL<<i;
        else {
            index[i] = '1';
            setVal(index, val, memory);
            index[i] = '0';
        }
    }
    memory[idx] = val;
}

LL solveP2() {
    map<LL, LL> memory;
    ifstream in("inputs/14-input.txt");

    string mask;

    for (string buf; getline(in, buf);) {
        if (buf[3] == 'k') {
            mask = buf.substr(7); //"mask = " has length 7
            reverse(mask.begin(), mask.end());
        }
        else {
            string indexStr, valStr;
            int i = 4;
            for (i; buf[i] != ']'; i++) {
                indexStr += buf[i];
            }
            i += 4;
            for (i; i < (int)buf.size(); i++) {
                valStr += buf[i];
            }

            indexStr = toBinary(indexStr);
            
            for (int j = 0; j < (int)mask.size(); j++) {
                if (mask[j] == '0') continue;
                indexStr[j] = mask[j];
            }

            LL val = stoll(valStr);
            setVal(indexStr, val, memory);
        }
    }

    LL ans = 0LL;
    for (auto a : memory) {
        ans += a.second;
    }
    return ans; 
}

int main() {
    cout << "P1: " << solveP1() << '\n';
    cout << "P2: " << solveP2() << '\n';
}