class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            ans += i - nums[i]; // Imagine [0,1,2] - [0,1,3]
        }
        return ans;
    }
};
