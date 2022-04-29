#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <cstdlib>
#include <algorithm>

using namespace std;



int main() {
    ifstream fin("D:/Desktop/INPUT.txt");
    ofstream fout("D:/Desktop/OUTPUT.txt");
    int n, need, now = 0, cnt = 1, ans = 0;
    bool bFlag = true;
    string action = "=";
    vector<int> vec;
    fin >> n;
    for (int i = 0; i < n; ++i) {
        fin >> need;
        vec.push_back(need);
    }
    while (now != n - 1) {
        if (action == ">") {
            if (vec[now] > vec[now + 1]) {
                cnt++;
                action = "<";
            }
            else {
                ans = max(ans, cnt);
                bFlag = true;
            }
        }
        else {
            if (vec[now] < vec[now + 1]) {
                cnt++;
                action = ">";
            }
            else {
                ans = max(ans, cnt);
                bFlag = true;
            }
        }
        if (bFlag) {
            if (vec[now + 1] > vec[now]) {
                action = ">";
            }
            else {
                action = "<";
            }
            cnt = 2;
            bFlag = false;
        }
        now++;
    }
    ans = max(ans, cnt);
    fout << ans;
    fin.close();
    fout.close();
    system("pause");
    return 0;
}