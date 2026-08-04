class Solution {
public:

int rec(vector<int>&a,int i,vector<int>&dp){
    if(i>=a.size()) return 0;
    if(dp[i]!=INT_MIN) return dp[i];
    int score =0;
    int ans = INT_MIN;
   for(int k=0;k<3 && i+k < a.size();k++){
    score += a[i+k];
     ans =  max(ans,score- rec(a,i+k+1,dp));
   }
    return dp[i]= ans;

    }

    string stoneGameIII(vector<int>& stoneValue) {
        vector<int>dp(stoneValue.size(),INT_MIN);
         int x = rec(stoneValue,0,dp);
          if(x>0) return "Alice";
          else if(!x) return "Tie";
           return "Bob";
    }
};