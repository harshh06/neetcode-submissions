class Solution {
public:

    bool isSame(vector<int>&a, vector<int>&b) {
        for(int i=0;i<26;i++) if(a[i]!=b[i]) return false;
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        if(s2.size()<s1.size()) return false;
        vector<int> freq(26, 0), freq2(26, 0);
        int k=s1.size();
        for(char ch: s1) freq[ch-'a']++;
        for(int i=0;i<s1.size(); i++) freq2[s2[i]-'a']++;
        if(isSame(freq, freq2)) return true;
        for(int i=k;i<s2.size(); i++) {
            freq2[s2[i-k]-'a']--;
            freq2[s2[i]-'a']++;
            if(isSame(freq, freq2)) return true;
        }
        return false;
    
    }
};
