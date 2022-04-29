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
    int k, m, p, h;
    vector<pair<int, int>> vec;
    pair<int, int> need;
    fin >> k >> m;
    for (int i = 0; i < m; ++i) {
        fin >> p >> h;
        need.first = h;
        need.second = p;
        vec.push_back(need);
    }
    sort(vec.begin(), vec.end());
    for (int i = 0; i < m; ++i) {
        if (k == vec[i].second) {
            k = vec[i].second + 1;
        }
        else if (k == vec[i].second + 1) {
            k = vec[i].second;
        }
    }
    fout << k;
    fin.close();
    fout.close();
    system("pause");
    return 0;
}