class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<pair<int, int>> flips;
        int neigh = 0;
        for (int i = 0; i != m; ++i) {
            for (int j = 0; j != n; ++j) {
                for (int x = max(0, i - 1); x != min(i + 2, m); ++x) {
                    for (int y = max(0, j - 1); y != min(j + 2, n); ++y)
                        neigh += board[x][y];
                }
                neigh -= board[i][j];
                if (board[i][j]) {
                   if (neigh < 2 || neigh > 3)
                        flips.push_back(make_pair(i, j));
                }
                else {
                    if (neigh == 3)
                        flips.push_back(make_pair(i, j));
                }
                neigh = 0;
            }
        }

        for (auto &e : flips)
            board[e.first][e.second] = 1 - board[e.first][e.second];
    }
};
