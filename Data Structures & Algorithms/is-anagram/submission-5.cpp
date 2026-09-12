class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        std::vector<int> char_vector(26);
        for(int i = 0; i < s.size(); i++) {
            char_vector[s.at(i) - 'a'] ++;
            char_vector[t.at(i) - 'a'] --;
        }
        for(int num : char_vector) {
            if(num != 0) return false;
        }
        return true;
    }
};
