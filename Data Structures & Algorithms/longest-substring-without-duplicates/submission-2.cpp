class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> mp; // key: character, value: index
        int left = 0, ans = 0;
        for(int right = 0; right < s.size(); right++) {
            if(mp.contains(s[right])) {
                left = max(mp[s[right]] + 1, left);
            }
            mp[s[right]] = right;
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
