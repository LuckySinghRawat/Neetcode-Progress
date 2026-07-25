class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ans = 0;

        int j = 2;
        for(int i = 2;i < nums.size();i++){
            if(nums[j-2] != nums[i]){
                nums[j++] = nums[i];
            }
        }

        return j;
    }
};