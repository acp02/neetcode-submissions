class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> numSet(nums.begin(), nums.end());
        int ans = 0;
        for(int num : nums) {
            if(!numSet.contains(num - 1)) { // since we sort it by creating a set, the starting integer has no value smaller than itself
                int length = 1;
                while(numSet.contains(num + length)) { // counting the consecutive integer
                    length++;
                }
                ans = max(ans, length);
            }
        }
        return ans;
    }
};
