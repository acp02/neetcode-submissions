class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> stringMap;
        for(string str : strs) {
            vector<int> charCount(26);
            for(char s : str) {
                charCount[s - 'a']++;
            }
            if(stringMap.contains(charCount)) {
                stringMap[charCount].push_back(str);
            }   else {
                vector<string> vecString = {str};
                stringMap[charCount] = vecString;
            }
        }

        vector<vector<string>> ans;
        for(auto element : stringMap) {
            ans.push_back(element.second);
        }
        return ans;
    }
};
