class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> numSet(nums.begin(), nums.end());
        unordered_set<int> explored;
        int ans = 0;
        for(int num : numSet) {
            if(explored.contains(num)) continue;
            explored.insert(num);
            int length = 1;
            int next = num + 1;
            for(int num2 : numSet) {
                if (explored.contains(num2)) continue;
                else if(num2 == next) {
                    length++;
                    next++;
                    explored.insert(num2);
                }   else break;
            }
            if(length > ans) ans = length;
        }
        return ans;
    }
};
