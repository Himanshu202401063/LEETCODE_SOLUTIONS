class Solution {
public:
    long long sumAndMultiply(int n) {
        long long  sum =0;
        int len =0;
        int k=n;
        while(k){
            len++;
            k=k/10;

        }

        long long p =1;
        long long digit =0;
        while(n){

            int curdigit = n%10;
            
         if(curdigit!=0){    
            sum += curdigit;
   digit= digit + p*curdigit;

   p=p*10;
         }
            n=n/10;

        }
         return sum*digit;
        
    }
};