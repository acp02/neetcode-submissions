class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int,int> map;
        for(int i = 0; i < nums.size(); i++) {
            map[nums[i]] = i; // {value, index}
        }
        for(int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];
            if(map.contains(diff) && map[diff] != i) {
                if(map[diff] > i) return {i, map[diff]};
                else return {map[diff], i};
            }
        }
        return {};
    }
};
