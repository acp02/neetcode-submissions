class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(), 1);
        int prefix = 1;
        for(int i = 0; i < nums.size(); i++) {
            ans[i] = prefix; // ans = [1, 2, 8]
            prefix *= nums[i]; // e.g. nums = [2, 4, 3], prefix = [1, 2, 8]
        }
        int postfix = 1;
        for(int i = nums.size() - 1; i >= 0; i--) {
            ans[i] *= postfix; // ans = [12, 6, 8]
            postfix *= nums[i]; // e.g. nums = [2, 4, 3], postfix = [12, 3, 1]
        }
        return ans;
    }
};
