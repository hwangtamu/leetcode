class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int size = (int)board[0].size();
        bool *u = new bool[size];
        int i, j;
        int grid_size = (int)sqrt(size);

        for (i = 0; i < size; ++i) {
            memset(u, false, sizeof(bool) * size);
            for (j = 0; j < size; ++j) {
                if (board[i][j] == '.') continue;
                int x = board[i][j] - '1';
                if (u[x])
                    break;
                u[x] = true;
            }
            if (j < size)
                break;
        }
        if (i < size) {
            delete[] u;
            return false;
        }

        for (i = 0; i < size; ++i) {
            memset(u, false, sizeof(bool) * size);
            for (j = 0; j < size; ++j) {
                if (board[j][i] == '.') continue;
                int x = board[j][i] - '1';
                if (u[x])
                    break;
                u[x] = true;
            }
            if (j < size)
                break;
        }
        if (i < size) {
            delete[] u;
            return false;
        }


        int p, q;
        for (i = 0; i < size; i += grid_size) {
            for (j = 0; j < size; j += grid_size) {
                memset(u, false, sizeof(bool) * size);
                for (p = 0; p < grid_size; ++p) {
                    for (q = 0; q < grid_size; ++q) {
                        if (board[i + p][j + q] == '.') continue;
                        int x = board[i + p][j + q] - '1';
                        if (u[x])
                            break;
                        u[x] = true;
                    }
                    if (q < grid_size)
                        break;
                }
                if (p < grid_size)
                    break;
            }
            if (j < size)
                break;
        }

        if (i < size) {
            delete[] u;
            return false;
        }

        delete[] u;

        return true;
    }
};
