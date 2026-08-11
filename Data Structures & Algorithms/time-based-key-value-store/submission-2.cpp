class TimeMap {
public:
    TimeMap() {
        
    }
    unordered_map<string, vector<pair<int, string>>> mp;

    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});    
    }
    
    string get(string key, int timestamp) {
        vector<pair<int, string>> v = mp[key];
        int l=0, r=v.size();
        while(l<r) {
            int mid=l + (r-l) / 2;
            if(v[mid].first > timestamp) {
                r=mid;
            }
            else l = mid + 1;
        }
        return l>0 ? v[l-1].second: "";
    }
};
