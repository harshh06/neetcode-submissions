class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> st;
        int n = heights.size();
        int maxArea = 0;
        for(int i=0; i<n; i++) {
            int start = i;
            while(!st.empty() && st.top().second > heights[i]) {
                int h = st.top().second;
                int id = st.top().first;
                st.pop();
                int area = h * (i-id);
                maxArea = max(maxArea, area);
                start = id;
            }
            st.push({start, heights[i]});
        }
        while(!st.empty()) {
            int l= st.top().first;
            int h = st.top().second;
            int area = h * (n-l) ;
            maxArea = max(maxArea, area);
            st.pop();
        }
        return maxArea;
    }
};
