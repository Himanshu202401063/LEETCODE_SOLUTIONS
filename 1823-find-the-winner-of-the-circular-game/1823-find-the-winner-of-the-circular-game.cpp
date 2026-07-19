class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int>a;
        for(int i=1;i<=n;i++)a.push_back(i);
  int i=0;
    while(a.size()>1){
         int idx =(i+k-1)%a.size();
         a.erase(a.begin()+idx);
         i =idx;
    }
     return a[0];
        
    }
};