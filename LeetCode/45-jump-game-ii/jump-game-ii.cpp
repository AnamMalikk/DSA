class Solution {
public:
// int solve(vector<int>& nums,int index,int jump){
//     if(index==nums.size()-1) return jump;

//     int mini=INT_MAX;
//     for(int i=1;i<=nums[index];i++){
//         mini=min(mini,solve(nums,index+i,jump+1));
//     }
// return mini;
// }

// int solve2(vector<int>& nums,int index,int jump,vector<vector<int>>& dp){

//     if(index==nums.size()-1) return jump;
// if(dp[index][jump]!=-1) return dp[index][jump];
//     int mini=INT_MAX;
//     for(int i=1;i<=nums[index];i++){
//         if(index+i<nums.size())
//         mini=min(mini,solve2(nums,index+i,jump+1,dp));
//     }
// return dp[index][jump]=mini;

// }

// int solve2(vector<int>& nums,int index,vector<int>& dp){
// if(index>=nums.size()-1) return 0;

// if(dp[index]!=-1) return dp[index];
// int mini=INT_MAX;
// for(int i=1;i<=nums[index];i++){
//     int jump=solve2(nums,index+i,dp);
//     if(jump!=INT_MAX) mini=min(mini,1+jump);
// }
// return dp[index]=mini;
// }
int solve3(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, INT_MAX);
    dp[n-1] = 0;

    for(int index = n - 2; index >= 0; index--) {
        for(int i = 1; i <= nums[index]; i++) {
            if(index + i < n && dp[index + i] != INT_MAX) {
                dp[index] = min(dp[index], 1 + dp[index + i]);
            }
        }
    }

    return dp[0];
}


    int jump(vector<int>& nums){
        // vector<vector<int>> dp(nums.size()+1,vector<int>(nums.size()+1,-1));
    //     vector<int> dp(nums.size()+1,-1);
    // return solve2(nums,0,dp);
return solve3(nums);
    }
};