class Solution {
public:
    int gcdOfOddEvenSums(int n) {
          int even=  (2*n*(2*n+1))/2 - n*n;
           return gcd(even,n*n);
    }
};