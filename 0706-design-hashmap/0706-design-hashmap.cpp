class MyHashMap {
public:
vector<pair<int,int>>vp;
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        
         for(auto&i:vp){
            if(i.first ==key){
               
                i.second = value;
                 return;
            }
         }
          vp.push_back({key,value});
    }
    
    int get(int key) {
            
       
         for(auto&i:vp){
            if(i.first ==key){
                return i.second;
            }
         }
          return -1;
    }
    
    void remove(int key) {
               for(int i=0;i<vp.size();i++){
                if(vp[i].first== key){
                     vp.erase(vp.begin()+i);
                      return;
                }
               }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */