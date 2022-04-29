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
    string str, sub;
    bool bFlag;
    fin >> str;
    fin >> sub;
    for (int i = 0; i < str.size() - sub.size() + 1; ++i) {
        bFlag = false;
        for (int j = 0; j < sub.size(); ++j) {
            if (str[i + j] != sub[j]) {
                bFlag = true;
                break;
            }
        }
        if (!bFlag) {
            fout << i << " ";
        }
    }
    fin.close();
    fout.close();
    system("pause");
    return 0;
}
