class Solution {
public:
    bool canTransform(vector<int>& source, vector<int>& target) {
        long long s1=0,s2=0;
        for(auto&i:source)s1+=i;
        for(auto&i:target)s2+=i;
         return s1==s2;
    }
};