//Day 4: Passport Processing
#include <bits/stdc++.h>

using namespace std;

void getInput(vector<string> &passports) {
    ifstream in("4-input.txt");
    if (passports.empty()) passports.push_back("");
    for (string buf; getline(in, buf);) {
        if (buf == "") { 
            passports.push_back(buf);
        }
        else {
            int n = (int)passports.size();
            passports[n - 1] += buf + ' ';
        }
    }
    in.close();
}

//Part 1: its OK, not too much of a hassle.
int solveP1(const vector<string> &passports) {
    vector<string> required = {
        "byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"
    };

    sort(required.begin(), required.end());

    int ans = 0;
    for (auto p : passports) {
        stringstream in(p);
        vector<string> currElems;
        for (string buf; getline(in, buf, ' ');) {
            string curr = buf.substr(0, 3);
            if (curr != "cid") currElems.push_back(curr);
        }

        sort(currElems.begin(), currElems.end());
        if (required == currElems) ans++;
    }
    return ans;
}

bool isValid(const string &curr) {
    string type = curr.substr(0, 3);
    if (type == "byr") {
        int year = stoi(curr.substr(4));
        if (year >= 1920 && year <= 2002) return true;
        return false;
    }
    else if (type == "iyr") {
        int year = stoi(curr.substr(4));
        if (year >= 2010 && year <= 2020) return true;
        return false;
    }
    else if (type == "eyr") {
        int year = stoi(curr.substr(4));
        if (year >= 2020 && year <= 2030) return true;
        return false;
    }
    else if (type == "hgt") {
        string height = curr.substr(4);
        string numBuf = "", measureBuf = "";
        for (int i = 0; i < (int)height.size(); i++) {
            if (height[i] >= '0' && height[i] <= '9') 
                numBuf += height[i];
            else
                measureBuf += height[i];
        }

        int num = stoi(numBuf);
        if (measureBuf == "cm") {
            if (num >= 150 && num <= 193) return true;
        }
        else if (measureBuf == "in") {
            if (num >= 59 && num <= 76) return true;
        }
        return false;
    }
    else if (type == "hcl") {
        string color = curr.substr(4);
        if (color[0] != '#') return false;
        for (int i = 1; i < (int)color.size(); i++) {
            if (color[i] >= '0' && color[i] <= '9') continue;
            if (color[i] >= 'a' && color[i] <= 'f') continue;
            return false;
        }
        return true;
    }
    else if (type == "ecl") {
        string color = curr.substr(4);
        if (color == "amb" || color == "blu" || color == "brn" || color == "gry" || 
            color == "grn" || color == "hzl" || color == "oth") {
            return true;
        }
        return false;
    }
    else if (type == "pid") {
        string PID = curr.substr(4);
        if ((int)PID.size() == 9) return true;
        return false;
    }
    return true;
}

//Part 2: Ugly as heck if/else chain.
int solveP2(const vector<string> &passports) {
    vector<string> required = {
        "byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"
    };

    sort(required.begin(), required.end());

    int ans = 0;
    for (auto p : passports) {
        stringstream in(p);
        vector<string> currElems;
        bool valid = true;
        for (string buf; getline(in, buf, ' ');) {
            string curr = buf.substr(0, 3);
            if (curr != "cid") currElems.push_back(curr);
            if (!isValid(buf)) valid = false;
        }

        sort(currElems.begin(), currElems.end());
        if (required == currElems && valid) ans++;
    }
    return ans;
}

int main() {
    vector<string> passports;
    getInput(passports);

    cout << "P1: " << solveP1(passports) << '\n';
    cout << "P2: " << solveP2(passports) << '\n';
}