class Solution {
public:
    int missingNumber(vector<int>& nums) {
        set<int> numSet;
        for(int i = 0; i <= nums.size(); i++) {
            numSet.insert(i);
        }
        for(int i = 0; i < nums.size(); i++) {
            numSet.erase(nums[i]);
        }
        return *numSet.begin();
    }
};
