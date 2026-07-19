class Solution {
public:


 string ans;
bool ok (char ch,string &s){
     for(auto&i:s){
        if(i==ch) return 0;
     }
      return 1;
}
 void rec(string &s,int sz,int i,string temp,char prv){
    if(sz==0){
         if(ans.empty() || temp<ans){
            ans =temp;

         }
          return;
    }
    if(i==s.size() ) return;
      
           
        
        rec(s,sz,i+1,temp,prv);
          if(prv =='#' ||  ok(s[i],temp)){
             rec(s,sz-1,i+1,temp+s[i],s[i]);
          }
    }
 
    string smallestSubsequence(string s) {
         
//   set<char>st;
//   for(auto&i:s)st.insert(i);
//   int size = st.size();
//            rec(s,size,0,"",'#');

//             return ans;

 string ans="";
 unordered_map<char,int>mp;
   unordered_map<char,bool>use;
 for(int i=0;i<s.size();i++){
      mp[s[i]]=i;
 }

       for(int i=0;i<s.size();i++){


        if(use[s[i]]) continue;
        while( !ans.empty() && ans.back() > s[i] && mp[ans.back()] > i){

 use[ans.back()]=0;
            ans.pop_back();
           

        }

 ans.push_back(s[i]);
             use [s[i]]=1;

       }

        return ans;
      
    }
};