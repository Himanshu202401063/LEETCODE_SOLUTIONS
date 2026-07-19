class Solution {
public:


int rec(int n,int k){
    if(n==1) return 0;
    int i = rec(n-1,k);
     int idx = (i+k)%n;
      return idx;
}
    int findTheWinner(int n, int k) {
           int x = rec(n,k);
           return x+1;

    }
};