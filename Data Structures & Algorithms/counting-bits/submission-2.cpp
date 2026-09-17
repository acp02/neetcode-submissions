class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> bitVector;
        int offset = 0;
        int newOffset = 1;
        bitVector.push_back(0);
        for(int i = 1; i <= n; i++) {
            int num = 0;
            if(i == newOffset) { // like 2, 4, 8, 16 -> only have 1 bit
                offset = newOffset;
                newOffset *= 2;
                bitVector.push_back(1);
            }   else { // refer to the previous data processed
                num = 1 + bitVector[i - offset];
                bitVector.push_back(num);
            }
        }
        return bitVector;
    }
};
