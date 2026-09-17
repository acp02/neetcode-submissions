class Solution {
public:
    int hammingWeight(uint32_t n) {
        int weight = 0;
        while(n) {
            n = n & (n-1); // check the video
            weight++;
        }
        return weight;
    }
};
