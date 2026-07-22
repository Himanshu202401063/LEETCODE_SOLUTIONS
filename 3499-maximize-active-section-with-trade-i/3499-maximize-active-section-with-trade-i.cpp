class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        vector<pair<char,int>>vp;
         string t = "1"+s+"1";
       
         for(auto&i:t){
          
              if(vp.empty() || vp.back().first!=i) vp.push_back({i,1});
              else vp.back().second++;
               
         }
         int total=0;
         for(auto&i:s)if(i=='1')total++;
         int ans =total;
         for(int i=1;i<vp.size()-1;i++){
               if(vp[i].first=='0') continue;
               if(vp[i-1].first=='0' && vp[i+1].first=='0'){
                 ans = max(ans,total+vp[i-1].second+vp[i+1].second);
               }
         }
        
        
         
          return ans;


        
    }
};