class Solution {
public:
    int findMin(vector<int> &nums) {
        int minimum = nums.at(0);
        for(int num : nums) {
            minimum = min(minimum, num);
        }
        return minimum;
    }
};
