class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while(left <= right) {
            // Base Case
            int mid = (left + right) / 2;
            if(nums[mid] == target) return mid;

            // left portion
            if(nums[left] <= nums[mid]) {
                if(target < nums[left] || target > nums[mid]) {
                    left = mid + 1;
                }   else {
                    right = mid - 1;
                }
            } else {
                // right portion
                if(target < nums[mid] || target > nums[right]) {
                    right = mid - 1;
                }   else {
                    left = mid + 1;
                }
            }
        }
        return -1;
    }
};
