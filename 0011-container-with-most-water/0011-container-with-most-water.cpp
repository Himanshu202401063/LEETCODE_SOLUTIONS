class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i=0;
        int j = n-1;
        int ans = -2e9;
        while(i<=j){
            int wid =  j-i;
            ans = max(ans,min(height[i],height[j])*wid);
            if(height[i] < height[j])i++;
            else j--;
        }
          return ans;
    }
};