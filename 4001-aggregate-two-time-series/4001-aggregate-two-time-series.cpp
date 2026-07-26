class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1,
                                            vector<vector<int>>& series2) {

        int n = series1.size();
        int m = series2.size();

        int i = 0, j = 0;
       

        vector<vector<int>> ans;

        while (i < n &&  j < m) {
            int a = series1[i][0];
            int b = series2[j][0];
            int val = series1[i][1]+ series2[j][1];

            if(a > b){
                ans.push_back({b,val});
                j++;
            }
            else if (a<b) {
                
                ans.push_back({a,val});
                i++;
            }
            else {
               
                ans.push_back({a, val});
                i++;
                j++;
            }
        }
        while(i<n) ans.push_back({series1[i++]});
        while(j<m) ans.push_back({series2[j++]});

        return ans;
    }
};