class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        std::unordered_map<char,int> s_maps;
        for(char c : s) {
            if(s_maps.contains(c)) s_maps[c] += 1;
            else s_maps[c] = 1;
        }
        for(char c : t) {
            if(s_maps.contains(c)) s_maps[c] -= 1;
            else return false;
        }
        for(const auto& [key, value] : s_maps) {
            if(value != 0) return false;
        }
        return true;
    }
};
