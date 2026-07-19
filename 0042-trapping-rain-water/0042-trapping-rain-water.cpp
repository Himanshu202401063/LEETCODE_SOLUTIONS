class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = n - 1;

        int mx = 0;
        int mn = 0;
        int ans =0;
        while (left <= right) {
          

            if (height[left] <= height[right]) {

                if (height[left] <= mx) {
                    ans += (mx - height[left]);
                }
                else {
                    mx  = height[left];
                }

                left++;
            }
            else {
                 if(height[right] <=mn){
                     ans += (mn -height[right]);
                 }
                 else mn =height[right];
                 right--;
            }
        }
         return ans;
    }
};