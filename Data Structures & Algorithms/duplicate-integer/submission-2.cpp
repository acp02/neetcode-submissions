class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_map<int,int> maps;
        for(int i = 0; i < nums.size(); i++) {
            int num = nums.at(i);
            if(maps.contains(num)) return true;
            else maps[num] = 0;
        }
        return false;
    }
};