class Solution {
public:
    int smallestNumber(int n, int t) {
    int i =n;
    int ans =-1;
    while(true){
        int k = n;
        int c =1;
        while(k){
            c*=(k%10);
            k=k/10;
        }
        if(c%t==0){
             ans = n;
             break;
        }
        n++;
    }
     return ans;
    }
};