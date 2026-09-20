class Solution {
public:
    int reverseDegree(string s) {
        int ans =0;
        for(int i=0;i<s.size();i++){
            int d =  26-(s[i] -'a');
            ans += d*(i+1);
        }
         return ans;
    }
};