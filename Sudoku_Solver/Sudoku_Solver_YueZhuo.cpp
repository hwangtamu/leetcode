#include <vector>
#include <set>
#include <string.h>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    set<string> vis;
    bool **row;
    bool **col;
    bool **grid;

    bool dfs(string &state, int &size)
    {
        bool flag = true;
        vis.insert(state);

        //cout << state << endl;

        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                int gindex = i / 3 * 3 + j / 3;
                int sindex = i * size + j;
                if (state[sindex] == '.') {
                    flag = false;
                    for (int k = 0; k < size; ++k) {
                        if (row[i][k] || col[j][k] || grid[gindex][k]) continue;
                        state[sindex] = '0' + k;
                        if (vis.count(state))
                            continue;
                        row[i][k] = true;
                        col[j][k] = true;
                        grid[gindex][k] = true;
                        if (dfs(state, size))
                            return true;
                        row[i][k] = false;
                        col[j][k] = false;
                        grid[gindex][k] = false;
                    }
                    state[sindex] = '.';
                    return false;
                }
            }
        }

        if (flag)
            return true;
        return false;
    }

    void solveSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vis.clear();
        int size = (int)board.size();
        row = new bool *[size];
        col = new bool *[size];
        grid = new bool *[size];
        for (int i = 0; i < size; ++i) {
            row[i] = new bool[size];
            col[i] = new bool[size];
            grid[i] = new bool[size];
            memset(row[i], false, sizeof(bool) * size);
            memset(col[i], false, sizeof(bool) * size);
            memset(grid[i], false, sizeof(bool) * size);
        }


        string state(size * size, '0');

        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                char val = board[i][j];
                // convert vector to string
                state[i * size + j] = val;
                if (val == '.') continue;

                row[i][val - '0'] = true;
                col[j][val - '0'] = true;
                grid[i / 3 * 3 + j / 3][val - '0'] = true;
            }
        }

        dfs(state, size);

        // convert string to vector
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j)
                board[i][j] = state[i * size + j];
        }

        for (int i = 0; i < size; ++i) {
            delete []row[i];
            delete []col[i];
            delete []grid[i];
        }
        delete []row;
        delete []col;
        delete []grid;
    }
};

int main()
{
    Solution s;
    vector<vector<char> > board;
    string a[9] = {"..46789..","67.......","198342567",
    "8597.....","42.853791","713...856",
    "961537...","28...9635","34528...."};
    board.clear();
    for (int i = 0; i < 9; ++i) {
        vector<char> tmp;
        tmp.clear();
        board.push_back(tmp);
        for (int j = 0; j < 9; ++j)
            board[i].push_back(a[i][j]);
    }
    s.solveSudoku(board);
    return 0;
}
