class Solution {
public:
     int rec(int i,int j,vector<int>&a,vector<vector<int>>&dp){
        if(i>j) return 0;
         if(i==j) return  dp[i][j]=a[i];
         if(dp[i][j]!=-1) return dp[i][j];
          int take = a[i] -rec(i+1,j,a,dp);
          int ntake = a[j] - rec(i,j-1,a,dp);
            return  dp[i][j]= max(take,ntake);
     }
    bool stoneGame(vector<int>& piles) {
          int sum =0;
          for(auto&i:piles) sum += i;
          vector<vector<int>>dp(piles.size(),vector<int>(piles.size(),-1));
          int x = rec(0,piles.size()-1,piles,dp);
           return x>=0;
    }
};