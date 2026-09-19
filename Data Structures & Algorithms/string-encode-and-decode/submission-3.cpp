class Solution {
public:

    string encode(vector<string>& strs) {
        string ans = "";
        for(string str : strs) {
            ans += to_string(str.size()) + '#' + str; // size + '#' <- added these two variables before the word starts
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int pos = 0;
        while(pos < s.size()) {
            int j = pos;
            while(s[j] != '#') j++; // so it can get 2digit, 10digit of length of word
            int length = stoi(s.substr(pos, j - pos));
            string word = s.substr(j + 1, length); // use substr to get the whole word, j + 1 is the first character after '#', length is the number of char to acquire
            ans.push_back(word);
            pos = j + 1 + length;
        }
        return ans;
    }
};
