class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int size = nums.size();
        for(int i = 0; i < size; i++) {
            int check = nums.at(i);
            for(int j = i + 1; j < size; j++) {
                int num2 = nums.at(j);
                if(check == num2) return true;
            }
        }
        return false;
    }
};