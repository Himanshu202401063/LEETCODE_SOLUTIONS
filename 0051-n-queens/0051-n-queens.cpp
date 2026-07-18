class Solution {
public:


bool valid(int i,int j,vector<string>&s){

    // up 
    for(int row =i-1;row>=0;row--){
        if(s[row][j]=='Q') return 0;

    }
    // left dia 
    for(int row =i-1,col=j-1;row>=0 && col>=0;row--,col--){
        if(s[row][col]=='Q') return 0;
    }
    for(int row = i-1,col=j+1;row >=0 && col<s.size();row--,col++){
        if(s[row][col]=='Q') return 0;
    }


     return 1;
}
vector<vector<string>>ans;
void rec( vector<string>&s,int row){

    if(row >= s.size()) {
         ans.push_back(s);
         return;
    }

     for(int i=0;i<s.size();i++){
        if(valid(row,i,s)){
            s[row][i] ='Q';
             rec(s,row+1);
             s[row][i] ='.';
        }
     }
}
    vector<vector<string>> solveNQueens(int n) {


          vector<string>s(n,string(n,'.'));
            rec(s,0);
   return  ans;
        
    }
};