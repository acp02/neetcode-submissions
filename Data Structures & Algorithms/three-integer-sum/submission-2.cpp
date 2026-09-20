#include <ranges>
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(auto [i, a] : std::views::enumerate(nums)) { // i is index, a is value nums[i]
            if(i > 0 && a == nums[i - 1]) continue; // find the base integer but we don't want it to be the same as previous one, e.g. nums[0] = 2 = nums[1]

            // Now i have the base integer, time to find the remaining two integers that make the result = 0
            int left = i + 1;
            int right = nums.size() - 1;
            while(left < right) {
                int threeSum = a + nums[left] + nums[right];
                if(threeSum > 0) right--; // since we sort the vector, right-- means nums[right] is smaller, so the result closer to 0
                else if(threeSum < 0) left++; // left++ means nums[left] is bigger
                else {
                    ans.push_back({a, nums[left], nums[right]}); // result is zero
                    left++; // check if there's other combination, so result also = 0
                    while(nums[left] == nums[left - 1] && left < right) left++; // if nums[left] == nums[left - 1], means the combination will be the same as previous one, and we don't want that
                }
            }
        }
        return ans;
    }
};
