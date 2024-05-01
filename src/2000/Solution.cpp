// My version
class Solution {
public:
    string reversePrefix(string word, char ch) {
        for (int i = 0; i != word.size(); ++i) {
            if (word[i] == ch) {
                for (int j = 0; j != (i + 1) / 2; ++j)
                    swap(word[j], word[i - j]);
                break;
            }
        }
        return word;
    }
};
