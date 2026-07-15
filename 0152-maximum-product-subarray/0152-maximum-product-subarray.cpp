class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        // vector<vector<int>>dp(n,vector<int>(2,1));
        //   dp[0][1]=nums[0];
        //   for(int i=1;i<n;i++){
        //      dp[i][0] =  max(dp[i-1][0],dp[i-1][1]);
        //      dp[i][1] =    nums[i]* max (dp[i-1][0],dp[i-1][1]);
        //   }
        //    return dp[n-1][1];
        int c =1;
        int ans =nums[0];
        int p=1;
        int s =1;
        for(int i=0;i<n;i++){
             if(p==0) p=1;
             if(s==0) s=1;

             p*=nums[i];
             s*= nums[n-i-1];
              ans = max({ans,s,p});
        }
         return ans;
        
    }
};