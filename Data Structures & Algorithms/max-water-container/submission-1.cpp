class Solution {
public:
    int maxArea(vector<int>& heights) {
        int leftIdx = 0;
        int rightIdx = heights.size() - 1; // start with largest width
        int maxLeftIdx = 0;
        int maxArea = 0;
        while(leftIdx < rightIdx) {
            int area = min(heights[leftIdx], heights[rightIdx]) * (rightIdx - leftIdx);
            maxArea = max(area, maxArea);
            if(heights[leftIdx] <=  heights[rightIdx]) { // we want to know if larger height is possible, then in next iteration we will compare its area to the current maxArea
                leftIdx++;
            }   else if(heights[leftIdx] > heights[rightIdx]) {
                rightIdx--;
            }
        }
        return maxArea;
    }
};
