class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> bitVector;
        for(int i = 0; i <= n; i++) {
            int bit = 0;
            int num = i;
            while(num) {
                num = num & (num-1);
                bit++;
            }
            bitVector.push_back(bit);
        }
        return  bitVector;
    }
};
