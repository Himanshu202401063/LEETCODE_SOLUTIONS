class Solution {
public:
    long long countCommas(long long n) {
         long long stlen =0;
         long long hg =n;
         long long ans =0;
         while(hg){
            stlen++;
            hg = hg/10;

         }
       vector<long long>p(stlen+1);
       long long k =1;
       for(long long i=0;i<stlen+1;i++){
        p[i]=k*10;
       }
         for( long long i = stlen;i>=4;i--){
             long long comas= (i+2)/3  -1;
             long long rem = n- pow(10,i-1)+ 1;
             long long d = rem*comas;
             n=pow(10,i-1)-1;
             ans +=d;

         }
          return ans;
    }
};