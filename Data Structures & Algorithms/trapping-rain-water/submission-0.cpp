class Solution {
public:
    int trap(vector<int>& height) {
        int area = 0;

        int l = 0,r = height.size()-1;
        int lMax = 0,rMax = 0;
        while(l <= r){
            if(height[l] <= height[r]){
                if(height[l] < lMax){
                    area += (lMax - height[l]);
                }else{
                    lMax = height[l];
                }
                l++;
            }else{
                if(height[r] < rMax){
                    area += (rMax - height[r]);
                }else{
                    rMax = height[r];
                }
                r--;
            }
        }

        return area;
        
    }
};
