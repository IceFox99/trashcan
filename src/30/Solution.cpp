// My version
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int len = words[0].length(); // length of each word
        int ws = words.size();
        int size = len * ws; // length of one window
        std::vector<int> res;
        if (s.length() < size)
            return res;
        std::unordered_map<std::string, int> m;
        for (const auto &s : words)
            ++m[s];

        bool b = false; // true means not matching
        std::string str;
        std::unordered_map<std::string, int> temp(m.size());
        for (int i = 0; i < s.size() - len + 1; i+=len) {
            for (int j = 0; j != size; j+=len) {
                str = s.substr(i + j, len);
                if (m.find(str) == m.end()) {
                    b = true;
                    break;
                }
                ++temp[str];
                if (temp[str] > m[str]) {
                    b = true;
                    break;
                }
            }
            if (!b)
                res.push_back(i);            
            b = false;
            temp.clear();
        }
        return res;
    }
};

// Community answer
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
		if (words.empty())return result;
		unordered_map<string, int> counts, record;
		for (string word : words) {
			counts[word]++;
		}
		int len = words[0].size(), num = words.size(), sl = s.size();
		for (int i = 0; i < len; ++i) {
			int left = i, sum = 0;
            record.clear();
			for (int j = i; j <= sl - len; j+=len) {
				string word = s.substr(j, len);
				if (counts.count(word)) {
					record[word]++;
                    sum++;
                    while (record[word] > counts[word])
                    {
                        //remove the most left word
                        record[s.substr(left, len)]--;
                        left += len;
                        sum--;
                    }
					if (sum == num) 
						result.push_back(left);
				}
				else
				{
					record.clear();
					sum = 0;
					left = j + len;
				}
			}
		}
		return result;
    }
};
