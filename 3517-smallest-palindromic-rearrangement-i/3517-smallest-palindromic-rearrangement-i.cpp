class Solution {
public:
    string smallestPalindrome(string s) {
          int n = s.size();
        map<char,int>mp;
        string ans ="";
        string mid ="";
          for(auto&i:s)mp[i]++;
        for(auto&i:mp){
         char ch = i.first;
         int frq = i.second;
               ans += string(frq/2,ch);
               if(frq%2) mid =ch;
        }
         string you = ans;
         reverse(you.begin(),you.end());
       
         return ans +mid+you;

    }
};