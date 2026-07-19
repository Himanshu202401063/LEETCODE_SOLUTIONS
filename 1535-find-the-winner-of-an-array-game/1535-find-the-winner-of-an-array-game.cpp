class Solution {
public:

void solve(vector<int>&arr){

}
    int getWinner(vector<int>& arr, int k) {
  int prv =arr[0];
  int d=0;
  int ans = arr[0];
  for(int i=1;i<arr.size();i++){
    if(ans > arr[i]){
        d++;
    }
    else {
        d=1;
        ans =arr[i];
    }
    if(d==k) return ans;
  }
     
          return ans;
    }
};