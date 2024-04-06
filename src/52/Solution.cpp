// My version
class Solution {
public:
    void dfs(vector<int>& board, int row, int num) {
        for (int i = 0; i != row; ++i) {
            if (board[i] == num || abs(board[i] - num) == row - i)
                return;
        }

        if (row == board.size() - 1) {
            ++result;
            return;
        }

        board[row] = num;
        for (int i = 0; i != board.size(); ++i)
            dfs(board, row + 1, i);
    }

    int totalNQueens(int n) {
        vector<int> board(n);

        for (int i = 0; i != n / 2; ++i)
            dfs(board, 0, i);
        result *= 2;

        if (n % 2 == 1)
            dfs(board, 0, (n + 1) / 2 - 1);
        return result;
    }
private:
    int result;
};
