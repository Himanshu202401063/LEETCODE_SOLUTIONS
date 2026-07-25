class TimeMap {
public:
unordered_map<string,vector<pair<int,string>>>mp;


    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {

           mp[key].push_back({timestamp,value});
    }
    
   string get(string key, int timestamp) {

    auto &v = mp[key];

    auto pos = upper_bound(
        v.begin(), v.end(), timestamp,
        [](int t, const pair<int,string> &p){
            return t < p.first;
        }
    );

    if(pos == v.begin()) return "";

    pos--;

    return pos->second;
}
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */