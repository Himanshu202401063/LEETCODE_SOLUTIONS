class Solution {
public:

  int v(int i,vector<pair<int,pair<int,int>>>&vp){
      int l =i+1;
      int r =  vp.size()-1;
   
      while(l<=r){
         int mid = l + (r-l)/2;

         if(vp[mid].first >= vp[i].second.first){
           
            r=mid-1;
         }
         else l=mid+1;
      }
       return l;
  }
int rec(int i, vector<pair<int,pair<int,int>>>&vp,vector<int>&dp){
    if(i==vp.size()) return 0;
  if(dp[i]!=-1) return dp[i];
       int nottake = rec(i+1,vp,dp);

        int hv =  v(i,vp);
         int take = vp[i].second.second +    rec(hv,vp,dp);
          return dp[i]= max(take,nottake);
}
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = endTime.size();
        vector<pair<int,pair<int,int>>>vp(n);
 int d =0;
        for(int i=0;i<n;i++){
             vp[i]={startTime[i],{endTime[i],profit[i]}};
              d= max(d,endTime[i]);
        }
       
         sort(vp.begin(),vp.end());
           vector<int>dp(n+1,-1);
              return rec(0,vp,dp);
    }
};