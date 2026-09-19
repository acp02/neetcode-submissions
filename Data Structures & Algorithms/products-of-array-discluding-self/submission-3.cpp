class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(), 1);
        int prefix = 1;
        for(int i = 0; i < nums.size(); i++) {
            ans[i] = prefix; // [1, 2, 8]
            prefix *= nums[i]; // e.g. [2, 4, 3]
        }
        int postfix = 1;
        for(int i = nums.size() - 1; i >= 0; i--) {
            ans[i] *= postfix;
            postfix *= nums[i];
        }
        return ans;
    }
};
