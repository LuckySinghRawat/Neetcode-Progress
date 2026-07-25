class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxArea = 0;

        int i = 0,j = heights.size()-1;
        while(i<=j){
            maxArea = max(maxArea,(j-i)*min(heights[i],heights[j]));
            if(heights[i] < heights[j])i++;
            else j--;
            
        }

        return maxArea;
    }
};
