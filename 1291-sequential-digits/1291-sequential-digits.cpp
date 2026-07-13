class Solution {
public:
 vector<int>ans;
void rec(int i ,int j,int st,int digit){
      if (  digit >=10 && digit>= i && digit <= j){
         ans .push_back(digit);
          
      }
      if( digit > j || st >9 ) return;

    
             
                rec(i,j, st+1, (digit*10 )+ st );
                
    }

    vector<int> sequentialDigits(int low, int high) {
       for(int i=1;i<=9;i++){
          rec(low,high,i,0);
       }
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};