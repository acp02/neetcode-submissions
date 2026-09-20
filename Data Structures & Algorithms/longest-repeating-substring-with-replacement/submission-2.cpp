class Solution {
public:
    int characterReplacement(string s, int k) {
        int arr[26] = {};
        int left = 0;
        int ans = 0;
        for(int right = 0; right < s.size(); right++) {
            arr[s[right] - 'A']++;
            while ((right - left + 1) - ranges::max(arr) > k) {
                arr[s[left] - 'A']--;
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
