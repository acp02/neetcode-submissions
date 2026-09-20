class Solution {
public:
    int findMin(vector<int> &nums) {
        // Binary Search Algorithm
        sort(nums.begin(), nums.end());
        return nums[0];
    }
};
