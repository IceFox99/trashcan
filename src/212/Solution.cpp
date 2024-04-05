// My version, Time-Limit-Exceeded
class Solution {
public:
    void helper_tail(const vector<vector<char>>& board, int i, int j,
     const string& word, int index, map<char, set<pair<int, int>>>& dict, bool* found) {
        if (index == word.size()) {
            *found = true;
            return;
        }

        if (*found || dict[word[index]].empty()) return;

        for (int bi = max(i - 1, 0); bi < min(i + 2, (int)board.size()); ++bi) {
            for (int bj = max(j - 1, 0); bj < min(j + 2, (int)board[0].size()); ++bj) {
                if ((bi == i && bj == j) || ((bi - i) * (bj - j) != 0)) continue;
                if (*found) return;
                pair<int, int> coor = make_pair(bi, bj);
                if (dict[word[index]].find(coor) != dict[word[index]].end()) {
                    dict[word[index]].erase(coor);

                    helper_tail(board, bi, bj, word, index + 1, dict, found);

                    dict[word[index]].insert(coor);
                }
            }
        }
    }

    bool helper(const vector<vector<char>>& board, const string& word, 
     map<char, set<pair<int, int>>>& dict) {
        bool found = false;
        if (dict[word[0]].empty()) return found;

        for (int i = 0; i != dict[word[0]].size(); ++i) {
            if (found) return found;
            pair<int, int> coor = *(next(dict[word[0]].begin(), i));
            dict[word[0]].erase(coor);

            helper_tail(board, coor.first, coor.second, word, 1, dict, &found);

            dict[word[0]].insert(coor);
        }

        return found;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        map<char, set<pair<int, int>>> dict;
        vector<string> res;
        for (int i = 0; i != board.size(); ++i) {
            for (int j = 0; j != board[0].size(); ++j)
                dict[board[i][j]].insert(make_pair(i, j));
        }

        for (const auto& str : words) {
            if (helper(board, str, dict))
                res.push_back(str);
        }

        return res;
    }
};

// Community version with trie + backtracking
class Trie {
public:
    array<Trie*, 26> _next{};
    bool _word = false;
    int _cnt = 0;
    ~Trie() {
        for (auto p : _next)
            delete p;
    }
    void insert(const string &s) {
        auto p = this;
        for (char c : s) {
            auto &q = p->_next[c - 'a'];
            p = q ? q : q = new Trie();
            p->_cnt++;
        }
        p->_word = true;
    }
    void erase(const string &s) {
        auto p = this;
        for (char c : s) {
            p = p->_next[c - 'a'];
            p->_cnt--;
        }
        p->_word = false;
    }
};
class Solution {
    void backtrack(vector<vector<char>>& board, int u, int v, Trie *node) {
        if (u < 0 || u >= board.size() || v < 0 || v >= board[u].size() || !board[u][v])
            return;
        char ch = board[u][v];
        node = node->_next[ch - 'a'];
        if (!node || !node->_cnt)
            return;
        board[u][v] = 0;
        path += ch;
        if (node->_word) {
            trie.erase(path);
            ans.push_back(path);
        }
        backtrack(board, u + 1, v, node);
        backtrack(board, u - 1, v, node);
        backtrack(board, u, v + 1, node);
        backtrack(board, u, v - 1, node);
        path.pop_back();
        board[u][v] = ch;
    }
    Trie trie;
    string path;
    vector<string> ans;
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m = board.size(), n = board[0].size();
        for (string &w : words)
            trie.insert(w);
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                backtrack(board, i, j, &trie);
        return ans;
    }
};

// Bad guy using trick of testcase analysis, but super fast
struct Trie {
    Trie* child[26] = {0};
    bool end = false;
};

class Solution
{
	public:
		bool dfs(int i, int j, int k, vector<vector < char>> &board, string &search, int &row, int &col)
		{
			if (i == search.size())
				return true;
			if (j >= 0 and j < row and k >= 0 and k < col)
			{
				if (board[j][k] != search[i])
					return false;
				char realChild = board[j][k];
				board[j][k] = '$';
				bool ans = dfs(i + 1, j + 1, k, board, search, row, col) ||
					dfs(i + 1, j - 1, k, board, search, row, col) ||
					dfs(i + 1, j, k + 1, board, search, row, col) ||
					dfs(i + 1, j, k - 1, board, search, row, col);
				board[j][k] = realChild;
				return ans;
			}
			else
				return false;
		}
	vector<string> findWords(vector<vector < char>> &board, vector< string > &words)
	{
		int row = board.size();
		int col = board[0].size();
		vector<string> ans;
		vector<vector<pair<int, int>>> vecp(27);
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
				vecp[board[i][j] - 'a'].push_back({ i, j });
		}
		int start = 0;
		int end = 0;
		for (auto element: words)
		{
			if (element[0] == 'a')
				start++;
			if (element[element.size() - 1] == 'a')
				end++;
		}
		bool checkReverse = false;
		if (start > end)
		{
			checkReverse = true;
			for (int i = 0; i < words.size(); i++)
				reverse(words[i].begin(), words[i].end());
		}
		for (auto search: words)
		{
			bool flag = false;
			for (auto element: vecp[search[0] - 'a'])
			{
				flag = dfs(0, element.first, element.second, board, search, row, col);
				if (flag)
				{
					if (checkReverse)
						reverse(search.begin(), search.end());

					ans.push_back(search);
					break;
				}
			}
		}
		return ans;
	}
};
