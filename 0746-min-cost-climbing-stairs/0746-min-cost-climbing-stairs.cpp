class Solution {
public:
int rec(vector<int>&cost,int i,vector<int>&dp){
 if(i>=cost.size()) return 0;
 if(dp[i]!=-1) return dp[i];
  return dp[i]=min(rec(cost,i+1,dp),rec(cost,i+2,dp))+cost[i];
}
    int minCostClimbingStairs(vector<int>& cost) {
        // vector<int>dp(cost.size()+1,-1);
        // return min(rec(cost,0,dp),rec(cost,1,dp));
        vector<int>dp(cost.size()+1,0);
     
        for(int i=2;i<=cost.size();i++){
            dp[i] = min(dp[i-1]+cost[i-1],dp[i-2]+cost[i-2]);
        }
         return dp[cost.size()];

    }
};