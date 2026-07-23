class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<pair<string,string>>vp;
        for(auto&i:strs){
             string y =i;
              sort(y.begin(),y.end());
               vp.push_back({y,i});
        }
        sort(vp.begin(),vp.end());
        vector<vector<string>>ans;
       int i=0;
       while(i<vp.size()){
        int j=i;
        vector<string>temp;
        while(j<vp.size() && vp[j].first==vp[i].first){
            temp.push_back(vp[j++].second);
        }
        i=j;
        ans.push_back(temp);
       }
           return ans;
    }
};