class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        // unordered_map<int,int>mp;
        // mp[0]=1;
        // int ans =0;
        // for(auto&i:nums){
        //     int d = k-i;
        //     if(mp.find(d)!=mp.end()) {
        //         ans++;
        //         mp[d]--;
        //         mp[i]--;
               
        //     }
        //     mp[i]++;
        // }
        //  return ans;
        sort(nums.begin(),nums.end());
        int i=0;
        int j = nums.size()-1;
        int ans =0;
        while(i<j){
            int sum = nums[i]+ nums[j];
            if(sum==k){
                ans++;
                i++;
                j--;
            }
            else if(sum > k) j--;
            else i++;

        }
         return ans;
    }
};