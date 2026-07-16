class Solution {
public:
int f(string &s,int i,int j){
        while(i<=j) {
            if(s[i]!=s[j]) return 0;
            i++;
            j--;
        }
         return 1;
}
 vector<vector<string>>ans;
 void rec(string &s,int i,vector<string>&temp){
    if(i==s.size()){
        ans.push_back(temp);
        return;
    }
     
      
           for(int  l =i;l<=s.size();l++){
 if(f(s,i,l)){
            temp.push_back(s.substr(i,l-i+1));
           rec(s,l+1,temp);
               temp.pop_back();

 }

           }
 }

    vector<vector<string>> partition(string s) {
        vector<string>temp;
            rec(s,0,temp);
             return ans;
    }
};