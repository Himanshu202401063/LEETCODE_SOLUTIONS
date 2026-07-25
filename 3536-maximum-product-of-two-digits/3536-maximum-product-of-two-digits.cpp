class Solution {
public:
    int maxProduct(int n) {
    int a=-1;
    int b=-1;
    while(n){
        int k = n%10;
      if(k>=a){
        b=a;
        a=k;
      }
      else if(k>b){
        b=k;
      }

        
         n=n/10;

    }
     return a*b;
        
    }
};