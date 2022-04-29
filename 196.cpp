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
    int n, x = 0, y = 0, now = 1, dir = 1;
    vector<vector<int>> vec;
    fin >> n;
    for (int i = 0; i < n; ++i) {
        vector<int> need;
        for (int j = 0; j < n; ++j) {
            need.push_back(0);
        }
        vec.push_back(need);
    }
    vec[0][0] = now++;
    while (now != n * n + 1) {
        if (dir == 1) {
            if (x + 1 < n) {
                if (vec[y][x + 1] == 0) {
                    vec[y][++x] = now++;
                }
                else {
                    dir = 2;
                }
            }
            else {
                dir = 2;
            }
        }
        else if (dir == 2) {
            if (y + 1 < n) {
                if (vec[y + 1][x] == 0) {
                    vec[++y][x] = now++;
                }
                else {
                    dir = 3;
                }
            }
            else {
                dir = 3;
            }
        }
        else if (dir == 3) {
            if (x - 1 >= 0) {
                if (vec[y][x - 1] == 0) {
                    vec[y][--x] = now++;
                }
                else {
                    dir = 4;
                }
            }
            else {
                dir = 4;
            }
        }
        else {
            if (y - 1 >= 0) {
                if (vec[y - 1][x] == 0) {
                    vec[--y][x] = now++;
                }
                else {
                    dir = 1;
                }
            }
            else {
                dir = 1;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            fout << vec[i][j] << " ";
        }
        fout << endl;
    }
    fin.close();
    fout.close();
    system("pause");
    return 0;
}
