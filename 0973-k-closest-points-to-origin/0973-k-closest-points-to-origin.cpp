class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        for(auto&i:points){
            int d = i[0]*i[0]  + i[1]*i[1];
            pq.push({d,{i[0],i[1]}});
        }
        vector<vector<int>>ans;
        while(k--){
           ans.push_back({pq.top().second.first,pq.top().second.second});
           pq.pop();
        }
         return ans;
    }
};