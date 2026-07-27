class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
        bool ifZero = false;
        int cnt = 0;
        for(int i : nums){
            if(i == 0){
                ifZero = true;
                cnt++;
            }
            else product *= i;
        }
        if(!ifZero){
            for(int i = 0;i<nums.size();i++){
                nums[i] = product/nums[i];
            }
        }else{
            for(int i = 0;i<nums.size();i++){
                if(nums[i] == 0 && cnt == 1) nums[i] = product;
                else nums[i] = 0;
            }    
        }
        return nums;
    }
};
