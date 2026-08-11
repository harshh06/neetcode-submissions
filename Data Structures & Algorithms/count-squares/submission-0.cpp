class CountSquares {
public:
    map<pair<int,int>, int>cnt;
    unordered_map<int, vector<int>> yPoints;
    CountSquares() {
    }
    
    void add(vector<int> point) {
        cnt[{point[0],point[1]}]++;
        if(cnt[{point[0],point[1]}] == 1) 
            yPoints[point[0]].push_back(point[1]);
    }
    
    int count(vector<int> point) {
        int x=point[0], y=point[1];
        int ans=0;
        for(int j: yPoints[x]) {
            if(abs(j-y)>0) {
                int len=abs(y-j);
                int x21=x-len;
                int x22=x+len;
                if(cnt.contains({x21,y}) && cnt.contains({x21,j})) {
                    int curCnt=1*cnt[{x21,y}]*cnt[{x21,j}]*cnt[{x,j}];
                    ans+=curCnt;
                }
                if(cnt.contains({x22,y}) && cnt.contains({x22,j})) {
                    int curCnt=1*cnt[{x22,y}]*cnt[{x22,j}]*cnt[{x,j}];
                    ans+=curCnt;
                }
            }
        }
        return ans;
    }
};
