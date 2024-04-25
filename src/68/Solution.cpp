// My version
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        string temp;
        vector<string> line { words[0] };
        int width = words[0].length(), length = width;
        for (int i = 1; i != words.size(); ++i) {         
            // Finish one line
            if (width + words[i].length() + 1 > maxWidth) {
                temp = line[0];
                int spaces = maxWidth - length;
                if (line.size() > 1) {
                    int space_len = spaces / (line.size() - 1);
                    int extra = spaces % (line.size() - 1);
                    for (int j = 1; j != line.size(); ++j) {
                        temp.append(space_len + ((extra-- > 0) ? 1 : 0), ' ');
                        temp.append(line[j]);
                    }
                }
                temp.append(maxWidth - temp.length(), ' ');
                res.push_back(temp);

                line.clear();
                line.push_back(words[i]);
                width = length = words[i].length();
                continue;
            }

            line.push_back(words[i]);
            width += (words[i].length() + 1);
            length += words[i].length();
        }

        temp = line[0];
        for (int i = 1; i != line.size(); ++i)
            temp.append(std::string(" ") + line[i]);
        temp.append(maxWidth - temp.length(), ' ');
        res.push_back(temp);
        return res;
    }
};
