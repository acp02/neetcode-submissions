class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> numSet(nums.begin(), nums.end());
        int ans = 0;
        for(int num : nums) {
            int length = 0;
            if(!numSet.contains(num - 1)) {
                length = 1;
                int next = num;
                while(numSet.contains(next + 1)) {
                    length++;
                    next++;
                }
            }
            ans = max(ans, length);
        }
        return ans;
    }
};
