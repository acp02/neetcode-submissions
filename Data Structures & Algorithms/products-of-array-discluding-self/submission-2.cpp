class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int total = 1;
        int zero = 0;
        vector<int> ans;
        for(int num : nums) {
            if(num != 0) total *= num;
            else if (num == 0) zero++; // count the number of zero in nums
        }
        for(int num : nums) { // 3 cases: non-zero, only 1 zero, or more than 1 zero
            if(zero == 0) ans.push_back(total / num);
            else if (zero == 1 && num != 0) ans.push_back(0);
            else if (zero == 1 && num == 0) ans.push_back(total);
            else ans.push_back(0); // more than 1 zero, everything is 0
        }
        return ans;
    }
};
