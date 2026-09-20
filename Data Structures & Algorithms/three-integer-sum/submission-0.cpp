#include <ranges>
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(auto [i, a] : std::views::enumerate(nums)) { // i is index, a is value nums[i]
            if(i > 0 && a == nums[i - 1]) continue;

            // Now i have the base integer, time to find the remaining two integers that make the result = 0
            int left = i + 1;
            int right = nums.size() - 1;
            while(left < right) {
                int threeSum = a + nums[left] + nums[right];
                if(threeSum > 0) right--;
                else if(threeSum < 0) left++;
                else {
                    ans.push_back({a, nums[left], nums[right]});
                    left++;
                    while(nums[left] == nums[left -1 ] && left < right) left++;
                }
            }
        }
        return ans;
    }
};
