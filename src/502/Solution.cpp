// My version
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        auto comp1 = [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first > b.first) return true;
            else if (a.first == b.first && a.second < b.second) return true;
            return false;
        };
        auto comp2 = [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.second < b.second) return true;
            return false;
        };

        // pair<capital, profits>
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp1)> q1; // complete set
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp2)> q2; // temporary set

        for (int i = 0; i != profits.size(); ++i)
            q1.push(make_pair(capital[i], profits[i]));
        
        for (int i = 0; i != k; ++i) {
            // push qualified project to temporary set
            while (!q1.empty() && q1.top().first <= w) {
                q2.push(q1.top());
                q1.pop();
            }

            // choose the project with highest profit
            if (q2.empty()) return w; // if no qualified project, end
            w += q2.top().second;
            q2.pop();
        }

        return w;
    }
};

// Community version
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital){
        ios_base::sync_with_stdio(false);
        int ans = w;
        priority_queue<int> maxheap;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minheap;
        for(int i = 0; i < profits.size(); i++){
            if(capital[i] <= w) maxheap.push(profits[i]);
            else minheap.push({capital[i], profits[i]});
        }
        while(k-- && (!maxheap.empty() || !minheap.empty())) {
            while (!minheap.empty() && minheap.top().first <= ans){
                maxheap.push(minheap.top().second);
                minheap.pop();
            }
            if (!maxheap.empty()){
                ans += maxheap.top();
                maxheap.pop();
            }
        }
        return ans;
    }
};
