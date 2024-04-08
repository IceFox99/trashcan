// My version
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if (points.size() == 1) return 1;
        map<array<int, 3>, vector<int>> lines;
        int res = 2;
        array<int, 3> init{ points[0][1] - points[1][1], points[1][0] - points[0][0], 
            points[1][0] * points[0][1] - points[0][0] * points[1][1] };
        lines[init].push_back(0); lines[init].push_back(1);
        for (int i = 2; i != points.size(); ++i) {
            set<int> used;
            for (auto& l : lines) {
                if (points[i][0] * l.first[0] + points[i][1] * l.first[1] == l.first[2]) {
                    lines[l.first].push_back(i);
                    for (auto index : l.second) used.insert(index);
                    res = max(res, (int)l.second.size());
                }
            }

            for (int j = 0; j != i; ++j) {
                if (used.find(j) == used.end()) {
                    array<int, 3> arr{ points[i][1] - points[j][1], points[j][0] - points[i][0], 
                        points[j][0] * points[i][1] - points[i][0] * points[j][1] };
                    lines[arr].push_back(i); lines[arr].push_back(j);
                }
            }
        }

        return res;
    }
};

// Community version
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;
        int mx = 2;
        for (int i=0; i<n; i++) {
            map<double, int> mp;
            for (int j=i+1; j<n; j++) {
                double y = (points[j][1] - points[i][1]);
                double x = (points[j][0] - points[i][0]);
                double slope = DBL_MAX;
                if (x != 0) slope = y*1.0/x;
                mp[slope]++;
            }
            for (auto pr: mp) mx = max(mx, pr.second+1);
        }
        return mx;
    }
};
