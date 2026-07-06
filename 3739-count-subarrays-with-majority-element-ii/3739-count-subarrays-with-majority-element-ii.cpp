class Solution {
public:
    long long countMajoritySubarrays(vector<int>& v, int tar) {
        int n = v.size();
        map<int,int>m;
        long long ps = 0;
        m[0] = 1;
        long long ans = 0;
        long long valid = 0;
        for(int i=0;i<n;i++){
            if(v[i]==tar){
                valid += m[ps];
                ps++;
            }
            else{
                ps--;
                valid -= m[ps];
            }
            m[ps] += 1;
            ans += valid;
        }
        return ans;
    }
};