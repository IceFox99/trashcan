// My version
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        auto index = find(wordList.begin(), wordList.end(), endWord);
        if (index == wordList.end()) return 0;
        vector<string> deepest;
        deepest.reserve(wordList.size());

        deepest.push_back(*index);
        wordList.erase(index);

        auto compStr = [](const string& A, const string& B) -> bool {
            int diff = 0;
            for (int i = 0; i != A.length(); ++i) {
                if (A[i] != B[i]) ++diff;
                if (diff > 1) return false;
            }
            return true;
        };
        
        int res = 2, s;
        do {
            s = wordList.size();
            vector<string> temp(deepest);
            deepest.clear();
            for (const auto& s : temp) {
                if (compStr(beginWord, s)) return res;
                for (int i = 0; i != wordList.size(); ++i) {
                    if (compStr(s, wordList[i])) {
                        deepest.push_back(wordList[i]);
                        wordList.erase(wordList.begin() + i);
                        --i;
                    }
                }
            }

            ++res;
        } while (s != wordList.size());

        return 0;
    }
};

// Community version
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end()), head, tail, *phead, *ptail;
        if (dict.find(endWord) == dict.end()) {
            return 0;
        }
        head.insert(beginWord);
        tail.insert(endWord);
        int ladder = 2;
        while (!head.empty() && !tail.empty()) {
            if (head.size() < tail.size()) {
                phead = &head;
                ptail = &tail;
            } else {
                phead = &tail;
                ptail = &head;
            }
            unordered_set<string> temp;
            for (auto it = phead -> begin(); it != phead -> end(); it++) {    
                string word = *it;
                for (int i = 0; i < word.size(); i++) {
                    char t = word[i];
                    for (int j = 0; j < 26; j++) {
                        word[i] = 'a' + j;
                        if (ptail -> find(word) != ptail -> end()) {
                            return ladder;
                        }
                        if (dict.find(word) != dict.end()) {
                            temp.insert(word);
                            dict.erase(word);
                        }
                    }
                    word[i] = t;
                }
            }
            ladder++;
            phead -> swap(temp);
        }
        return 0;
    }
};
