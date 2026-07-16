class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        long long n = nums.size();
    int mx = nums[0];
        vector<long long >pref(n);
        pref[0] = nums[0];
        for(long long  i=1;i<n;i++){
             mx = max(mx,nums[i]); 
             pref[i] = gcd(nums[i],mx);
        }
        sort(pref.begin(),pref.end());
        long long  ans =0;
     for(long long  i=0;i<n/2;i++){
        long long  x = gcd(pref[i],pref[n-i-1]);
        ans+= x;
     }
          return ans;
    }
};