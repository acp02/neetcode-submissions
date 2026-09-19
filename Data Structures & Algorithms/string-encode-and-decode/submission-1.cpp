class Solution {
public:

    string encode(vector<string>& strs) {
        string ans = "";
        for(string str : strs) {
            ans += to_string(str.size()) + '#' + str;
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int pos = 0;
        while(pos < s.size()) {
            int j = pos;
            while(s[j] != '#') j++;
            int length = stoi(s.substr(pos, j - pos));
            string word = s.substr(j + 1, length);
            ans.push_back(word);
            pos = j + 1 + length;
        }
        return ans;
    }
};
