class Solution {
public:
    int maxArea(vector<int>& heights) {
        int leftIdx = 0;
        int rightIdx = heights.size() - 1;
        int maxLeftIdx = 0;
        int maxArea = 0;
        while(leftIdx < rightIdx) {
            int area = min(heights[leftIdx], heights[rightIdx]) * (rightIdx - leftIdx);
            maxArea = max(area, maxArea);
            if(heights[leftIdx] <=  heights[rightIdx]) {
                leftIdx++;
            }   else if(heights[leftIdx] > heights[rightIdx]) {
                rightIdx--;
            }
        }
        return maxArea;
    }
};
