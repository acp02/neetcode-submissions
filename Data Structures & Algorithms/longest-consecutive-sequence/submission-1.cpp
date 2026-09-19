class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> ans;
        unordered_set<int> explored;
        sort(nums.begin(), nums.end());
        int length = 1;
        for(int num : nums) {
            if(explored.contains(num)) continue;
            explored.insert(num);
            int upper = num + 1;
            int lower = num - 1;
            for(int num2 : nums) {
                if(explored.contains(num2)) continue;
                if(num2 == upper) {
                    explored.insert(num2);
                    upper++;
                    length++;
                } else if(num2 == lower) {
                    explored.insert(num2);
                    lower--;
                    length++;
                }
            }
            ans.insert(length);
            length = 1;
        }
        if(!ans.empty()) return *ans.rbegin();
        else return 0;
    }
};
