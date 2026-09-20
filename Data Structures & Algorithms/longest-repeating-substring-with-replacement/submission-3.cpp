class Solution {
public:
    int characterReplacement(string s, int k) {
        // this question's basically asking in that particular window, we are replacing all other characters except the most frequency one, so we get the largest substring.
        int arr[26] = {}; // 26 alphabets
        int left = 0;
        int ans = 0;
        for(int right = 0; right < s.size(); right++) {
            arr[s[right] - 'A']++;
            while ((right - left + 1) - ranges::max(arr) > k) { // Remember the equation: (Length of Window) - (Max Frequency of characters) > k, means need to shrink the window, ask Gemini for example
                arr[s[left] - 'A']--;
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
