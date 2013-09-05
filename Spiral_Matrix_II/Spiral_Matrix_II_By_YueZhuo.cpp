class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ans;
        for (int i = 0; i < n; ++i) {
            vector<int> row;
            row.clear();
            for (int j = 0; j < n; ++j)
                row.push_back(0);
            ans.push_back(row);
        }

        bool **vis = new bool *[n];
        for (int i = 0; i < n; ++i) {
            vis[i] = new bool[n];
            memset(vis[i], false, sizeof(bool) * n);
        }
        //printf("%d\n", vis[0][0]);

        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        int sx = 0, sy = -1;
        int nx, ny;
        int dir = 0;
        for (int i = 0; i < n * n; ++i) {
            nx = sx + dx[dir];
            ny = sy + dy[dir];
            //printf("%d %d\n", nx, ny);
            if (nx < 0 || nx == n || ny < 0 || ny == n || vis[nx][ny]) {
                dir = (dir + 1) % 4;
                nx = sx + dx[dir];
                ny = sy + dy[dir];
            }
            ans[nx][ny] = i + 1;
            vis[nx][ny] = true;
            sx = nx;
            sy = ny;
        }

        for (int i = 0; i < n; ++i)
            delete vis[i];
        delete vis;

        return ans;
    }
};
