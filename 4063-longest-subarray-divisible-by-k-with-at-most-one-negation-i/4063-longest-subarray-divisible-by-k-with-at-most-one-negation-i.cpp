class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
       
       
    
       
        int ans =0;
        for(int i=0;i<n;i++){
            unordered_map<long long,int>mp;
            int sum =0;
            for(int j=i;j<n;j++){
                     sum += nums[j];
                     long long rem = (2*nums[j]%k + k)%k;
                     mp[rem]++;

                     long long h = (sum%k + k)%k;
                   if(h==0 || mp.count(h) ) ans = max(ans,j-i+1);
            }
        }
         return ans;
    }
};