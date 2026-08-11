class Solution {
public:
    int missingInteger(vector<int>& nums) {
       int n = nums.size();
       set<int>s;
      for(auto&i:nums)s.insert(i);
      int cur=nums[0];
     
       for(int i=1;i<n;i++){
            if(nums[i]== nums[i-1]+1) {

              cur+= nums[i];
            
              

            }
       else break;
       }
      while(s.count(cur))cur++;
      return cur;
    }
};