class Solution {
public:
    // // Upper bound find karne wala aapka function
    // int findidx(int k, vector<int>& nums) {
    //     return upper_bound(nums.begin(), nums.end(), k) - nums.begin() - 1;
    // }

    
    // void dfs(int node, vector<int>& nums, int maxDiff, vector<int>& vis, int c) {
    //     vis[node] = c; 
        
       
    //     int max_val = maxDiff + nums[node];
    //     int it = findidx(max_val, nums);
        
      
    //     for (int i = node + 1; i <= it; i++) {
    //         if (vis[i] == 0) { 
    //             dfs(i, nums, maxDiff, vis, c);
    //         }
    //     }
    // }

    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> vis(n, 0);
        int c =0; 
        for(int i=1;i<n;i++){
            if(nums[i]-nums[i-1] >maxDiff){
                c++;
            }
            vis[i]=c;
        }
        vector<bool> ans;
        for (auto& q : queries) {
            int ui = q[0];
            int vi = q[1];
            
           
            if (vis[ui] == vis[vi]) {
                ans.push_back(true);
            } else {
                ans.push_back(false);
            }
        }
        
        return ans;
    }
};