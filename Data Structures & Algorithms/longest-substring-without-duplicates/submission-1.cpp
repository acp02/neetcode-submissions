class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<int> cSet;
        int left = 0, ans = 0;
        for(int right = 0; right < s.size(); right++) {
            while(cSet.contains(s[right])) {
                cSet.erase(s[left]);
                left++;
            }
            cSet.insert(s[right]);
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
