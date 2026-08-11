class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int ans=0 ,bottom_h=0;
        for(int i=0; i< height.size(); i++) {
            int area=0;
            while(!st.empty() && height[st.top()]<height[i]) {
                int bottom = height[st.top()];
                st.pop();
                if(st.empty()) break;
                int h = min(height[i], height[st.top()]) - bottom;
                int w = i-st.top()-1;
                area += h*w;
            }
            ans+= area;
            st.push(i);
        }
        return ans;
    }
};
