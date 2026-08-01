class Solution {
public:


int rec(int i,int j,vector<int>nums,vector<vector<int>>&dp){


    if(i>j) return 0;
    if(i==j) return dp[i][j]= nums[i];
    if(dp[i][j]!=-1) return dp[i][j];
    int take = nums[i] +   min(rec(i+2,j,nums,dp),rec(i+1,j-1,nums,dp));
    int nottake = nums[j] + min(rec(i+1,j-1,nums,dp),rec(i,j-2,nums,dp));

     return  dp[i][j]= max(take,nottake);
}
    bool predictTheWinner(vector<int>& nums) {
          
 int n = nums.size();
 vector<vector<int>>dp(n,vector<int>(n,-1));
           int x =   rec(0,nums.size()-1,nums,dp);
           int sum =0;
           for(auto&i:nums)sum+=i;
           return 2*x>=sum;

    }
};