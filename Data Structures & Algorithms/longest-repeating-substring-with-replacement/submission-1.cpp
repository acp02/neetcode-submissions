class Solution {
public:
    int characterReplacement(string s, int k) {
        // this question's basically asking in that particular window, we are replacing all other characters except the most frequency one, so we get the largest substring.
        unordered_map<char, int> mp; // key: character, value: index
        int left = 0;
        int ans = 0;
        int maxf = 0;
        for(int right = 0; right < s.size(); right++) {
            mp[s[right]] += 1;
            maxf = max(maxf, mp[s[right]]);
            while((right - left + 1) - maxf > k ) {
                mp[s[left]] --;
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
