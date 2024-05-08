// My version
class Solution {
public:
    int dp(map<char, set<int>> &dic, vector<vector<int>> &memo, 
        const string &ring, int curr, const string &key, int beg) {
        if (beg == key.size())
            return 0;
        if (memo[beg][curr] != -1)
            return memo[beg][curr];

        int min_sum = INT_MAX;
        for (auto index : dic[key[beg]]) {
            int distance = min(abs(index - curr), (int)ring.size() - abs(index - curr));
            min_sum = min(min_sum, distance + dp(dic, memo, ring, index, key, beg + 1));
        }
        memo[beg][curr] = min_sum;
        return min_sum;
    }

    int findRotateSteps(string ring, string key) {
        map<char, set<int>> dic;
        vector<vector<int>> memo(key.size(), vector<int>(ring.size(), -1));
        for (int i = 0; i != ring.size(); ++i)
            dic[ring[i]].insert(i);
        return dp(dic, memo, ring, 0, key, 0) + key.size();
    }
};

// Community version
class Solution {
public:
    int dp[101][101];
    int helper(string& key,vector<vector<int>>& v,int i,int j,int n)
    {
        if(j==key.length()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int minSteps=INT_MAX;
        int ch=key[j]-'a';
        for(auto x:v[ch])
        {
            int steps=0;
            if(x>=i)
            steps=min(x-i,(i+n)-x);
            else 
            steps=min(i-x,(x+n)-i);
            int nextSteps=helper(key,v,x,j+1,n);
            minSteps=min(minSteps,steps+nextSteps);
        }
        return dp[i][j]=1+minSteps;
    }
    int findRotateSteps(string ring, string key) {
        memset(dp,-1,sizeof(dp));
        vector<vector<int>> pos(26);
        int n=ring.length();
        for(int i=0;i<n;++i)
        pos[ring[i]-'a'].push_back(i);
        return helper(key,pos,0,0,n);
    }
};
