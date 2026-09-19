class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> numMap;
        for(int num : nums) {
            numMap[num]++;
        }
        vector<vector<int>> freqVector(nums.size()+1);
        for(auto& [val, freq] : numMap) {
            freqVector[freq].push_back(val); // freqVector[freq] does not create new space automatically, need initialize its size first
        }
        vector<int> ans;
        for(int i = freqVector.size() - 1; i >= 0; i--) {
            for(int j : freqVector[i]) {
                if(ans.size() == k) return ans;
                ans.push_back(j);
            }
        }
        return ans;
    }
};
