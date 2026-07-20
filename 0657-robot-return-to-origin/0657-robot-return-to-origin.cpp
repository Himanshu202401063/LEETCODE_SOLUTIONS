class Solution {
public:
    bool judgeCircle(string moves) {
        int ans =0;
        for(auto&i:moves){
            if(i=='U')ans+=2;
            else if(i=='D')ans-=2;
            else if(i=='R')ans+=100;
            else ans-=100;
        }
         return ans==0;
        
    }
};