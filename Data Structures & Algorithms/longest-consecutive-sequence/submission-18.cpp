class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> numSet(nums.begin(), nums.end());
        int ans = 0;
        for(int num : nums) {
            if(!numSet.contains(num - 1)) {
                int length = 1;
                while(numSet.contains(num + length)) {
                    length++;
                }
                ans = max(ans, length);
            }
        }
        return ans;
    }
};
