class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
    stack<double>s;
    int n = speed.size();
    vector<pair<int,int>>vp;
    for(int i=0;i<n;i++){
        vp.push_back({position[i],speed[i]});
    }
    sort(vp.begin(),vp.end());
    for(int i=n-1;i>=0;i--){

        double x = (double)(target-vp[i].first)/vp[i].second;
        
       if(s.empty() || x > s.top()) s.push(x);
    }
         return s.size();
    }
};