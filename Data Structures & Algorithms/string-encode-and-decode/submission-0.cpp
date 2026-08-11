class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_str = "";
        for(string &str: strs) {
            int str_len = str.size();
            string tmp = to_string(str_len) + "#" + str;
            encoded_str += tmp;
            // cout << encoded_str << " "; 
        }
        // cout << "\n";
        return encoded_str;
    }

    vector<string> decode(string s) {
        int s_len = s.size();
        int i = 0;
        // cout << s_len << "\n";
        vector<string> strs;
        while(i < s_len) {
            int j = i;
            // cout << "cur: "<< i << "\n";
            string tmp_str_len = "";
            // cout << "\n";
            while(s[j] != '#') {
                // cout << s[j] << "\n";
                tmp_str_len += s[j];
                j++;
            }
            // cout << "len: "<< tmp_str_len << "\n";
            int str_len = stoi(tmp_str_len);
            i = j+1;
            string tmp_str = "";
            int loop_len = j+1+str_len;
            for(; i<loop_len; i++) {
                tmp_str += s[i];
            }
            // cout << tmp_str << "\n";
            strs.push_back(tmp_str);
        }
        return strs;
    }
};
