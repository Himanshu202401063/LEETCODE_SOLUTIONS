class dsu{

    private:
    vector<int>parent,size;
    public:
    dsu(int n){
        parent.resize(n);
        size.resize(n,1);
        for(int i=0;i<n;i++) parent[i]=i;

    }

    int find(int u){
         if(u==parent[u]) return u;
          return parent[u] = find(parent[u]);
    }

    void uns(int u,int v){
           int a = find(u);
           int b = find(v);
            if(a==b) return;
             if(size[a] > size[b]){
                 size[a]+=size[b];
                 parent[b] =a;
             }
             else {
                parent[a]=b;
                size[b]+=size[a];
             }
    }
};


class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
         int n =0;
         int m =0;
         for(auto&i:stones){
            n = max(n,i[0]);
            m =max(m,i[1]);
         }
        n++;
        m++;
        dsu ds(n+1+m);
        unordered_map<int,int>mp;
        for(auto&i:stones){
             int x = i[0];
             int y =i[1]+n;
               ds.uns(x,y);
               mp[x]=1;
               mp[y]=1;
                
        }
  int cnt =0;

        for(auto&i:mp){
            if(ds.find(i.first)==i.first) cnt++;
        }
         return stones.size()-cnt;
    }
};