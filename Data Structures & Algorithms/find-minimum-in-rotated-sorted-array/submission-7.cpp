class Solution {
public:
    int findMin(vector<int> &nums) {
        int ans = nums.front();
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right) {
            if(nums[left] < nums[right]) { // finished, if true, means the array/subarray is a sorted array
                ans = min(ans, nums[left]); // e.g. [3, 4, 5, 1, 2], think about what if '1' is in position 0, 1, 2, 3 or 4??  [5, 1, 2, 3, 4], [4, 5, 1, 2, 3]
                return ans;
            }
            int mid = (left + right) / 2;
            ans = min(ans, nums[mid]);
            if(nums[mid] >= nums[left]) left = mid + 1;
            else right = mid - 1;
        }
        return ans;
    }
};
