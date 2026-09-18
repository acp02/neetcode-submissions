class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> stringMap;
        for(string str : strs) {
            string key = str;
            sort(key.begin(), key.end());
            stringMap[key].push_back(str);
        }
        vector<vector<string>> ans;
        for(auto [key, vString] : stringMap) {
            ans.push_back(vString);
        }
        return ans;
    }
};
