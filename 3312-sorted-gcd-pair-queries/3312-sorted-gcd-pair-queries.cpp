class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
          int mx = *max_element(nums.begin(),nums.end());
          vector<long long>freq(mx+1,0);
            for(auto&i:nums)freq[i]++;

        vector<long long>cnt(mx+1,0);
        for(int i=1;i<=mx;i++){
              for(int m =i;m<=mx;m+=i){
                 cnt[i] += freq[m];
              }
        }

        vector<long long>ex(mx+1,0);

        for(int i=mx;i>=1;i--){

           ex[i] =( cnt[i]*(cnt[i]-1))/2;

            for(int j=2*i;j<=mx;j+=i){
                ex[i] -= ex[j];
            }
        }
         vector<long long >pref(mx+1,0);
         for(int i=1;i<=mx;i++){
             pref[i] =pref[i-1]+ex[i];
         }
vector<int>ans;
    for(auto&i:queries){
      auto it = lower_bound(pref.begin(),pref.end(),i+1)- pref.begin();
       ans.push_back(it);
    }
              return ans; 
        
    }
};