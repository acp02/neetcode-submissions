class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        std::vector<int> char_vector(26);
        for(int i = 0; i < s.size(); i++) {
            char_vector[s.at(i) - 'a'] ++;
            char_vector[t.at(i) - 'a'] --;
        }
        for(int i = 0; i < char_vector.size(); i++) {
            if(char_vector[i] != 0) return false;
        }
        return true;
    }
};
