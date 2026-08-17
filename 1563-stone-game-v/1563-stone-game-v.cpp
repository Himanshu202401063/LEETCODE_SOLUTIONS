class Solution {
public:


int rec(vector<int>&pref,int i, int j,vector<vector<int>>&dp){
    if(i==j) return  dp[i][j]=0;
    if(i> j) return  INT_MIN;
    if(dp[i][j]!=-1) return dp[i][j];
    int ans =0;

    for(int l =i;l<=j;l++){
     int  leftsum = pref[l] - (i > 0 ? pref[i-1] : 0);

      int rightsum = pref[j] - pref[l];
        if(leftsum > rightsum){
            ans = max(ans, rightsum + rec(pref,l+1,j,dp));
        }
        else if(leftsum < rightsum) ans = max(ans,leftsum+rec(pref,i,l,dp));
        else ans = max(ans, max(leftsum+rec(pref,i,l,dp),rightsum + rec(pref,l+1,j,dp)));

    }
     return  dp[i][j]=ans;

}
    int stoneGameV(vector<int>& stoneValue) {
          int n = stoneValue.size();
          vector<int>pref(n,0);
        pref[0] = stoneValue[0];
        for(int i=1;i<n;i++) pref[i] = pref[i-1]+ stoneValue[i];
        vector<vector<int>>dp(n,vector<int>(n,-1));
         return rec(pref,0,n-1,dp);

    }
};