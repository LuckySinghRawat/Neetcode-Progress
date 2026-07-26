class Solution {
public:
    int pivotIndex(vector<int>& nums) {
    int n = nums.size();
    
    vector<int> ps(n+1,0);
    for(int i = 1;i <= n;i++){
        ps[i] = ps[i-1] + nums[i-1];
    }

    for(int i = 1;i<=n;i++){
        int leftSum,rightSum;
        leftSum = ps[i-1] - ps[0];
        rightSum = ps[n] - ps[i];
        if(rightSum == leftSum)return i-1;
    }

    return -1;

    }
};
/*
0 -9 0 2

*/