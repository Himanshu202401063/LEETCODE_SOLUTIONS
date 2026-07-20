class Solution {
public:
    int compress(vector<char>& chars) {
          int n = chars.size();
          int w =0;
          int i=0;
          while(i<n){
            char ch = chars[i];
            int cnt =0;
            while(i<n&&chars[i]==ch){
                i++;
                cnt++;
            }
            chars[w++]=ch;
            if(cnt >1){
                string s = to_string(cnt);
                for(auto&i:s)chars[w++]=i;
            }
          }
           return w;
    }
};