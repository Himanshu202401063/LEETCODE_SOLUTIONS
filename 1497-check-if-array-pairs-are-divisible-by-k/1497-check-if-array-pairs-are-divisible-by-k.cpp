class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int>mp;
        int ans =0;
        for(auto&i:arr){
            int rem = (i%k + k)%k;
          if(mp[rem] > 0){
            ans++;
            mp[rem]--;
          }
           
            else  mp[(k-rem)%k]++;
        }
         return ans == (arr.size())/2;
        
    }
};