class Solution {
public:

int rec(vector<int>&a,int player,int i,int mx,vector<vector<vector<int>>>&dp){
    int n = a.size();
    if(i>= a.size()) return 0;
    if(dp[player][i][mx]!=-1) return dp[player][i][mx];
    int score = 0;
   int ans =  (player?-1:2e9);
   for(int l = 1;l<= min(2*mx , n-i);l++){

     score+= a[i+l-1];

     if(player==1){
              ans = max(ans,score + rec(a,0,i+l,max(mx,l),dp)); 
    }
    else {
            ans = min(ans,rec(a,1,i+l,max(mx,l),dp)); 
    }
   }
    return  dp[player][i][mx]= ans;
}
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<vector<int>>>dp(2,vector<vector<int>>(n+1,vector<int>(n+1,-1)));


         return rec(piles,1,0,1,dp);  /// player index max value 

        
    }
};