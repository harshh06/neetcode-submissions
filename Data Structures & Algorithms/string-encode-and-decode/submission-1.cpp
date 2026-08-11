class Solution {
public:

    string encode(vector<string>& strs) {
        string s="";
        for(string str: strs) {
            int sz=str.size();
            s += to_string(sz);
            s += "#";
            s += str;
        }
        cout << s << "\n";
        return s;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        for(int i=0; i< s.size(); ) {
            int sz=0;
            while(s[i]>='0' && s[i]<='9') {
                sz *= 10;
                sz += s[i]-'0';
                i++;
            }
            if(s[i] =='#') {
                i++;
                string tmp="";
                int cnt=0;
                while(i < s.size() && cnt < sz) {
                    tmp.push_back(s[i]);
                    cnt++;
                    i++;
                }
                ans.push_back(tmp);
            }
        }
        return ans;
    }
};
