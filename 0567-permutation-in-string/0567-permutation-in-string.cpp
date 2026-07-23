class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int>mp;
        for(auto&i:s1)mp[i]++;
   unordered_map<char,int>mp1;
        for(int i=0;i<s2.size();i++){
            mp1[s2[i]]++;
            if(i>=s1.size()){
                mp1[s2[i-s1.size()]]--;
                if(mp1[s2[i-s1.size()]]==0) mp1.erase(s2[i-s1.size()]);

            }
            if(mp==mp1) return 1;
        }
       return 0;
    }
};