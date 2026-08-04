class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
         sort(nums.begin(),nums.end());
         vector<int>ans;
         int l = nums[0];
         int r = nums[nums.size()-1];
         int k=0;
         for(int i=l;i<=r;i++){
            if(nums[k]==i) {
                k++;
                
            }
            else {
                ans.push_back(i);
               
            }

         }
          return ans;
    }
};