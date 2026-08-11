class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m= matrix[0].size();
        int l=0, r=matrix.size()*m - 1;
        while(l<=r) {
            int mid = l + (r-l)/2;
            int val=matrix[mid/m][mid%m];
            if(target == val) return true;
            else if(val < target) l=mid+1;
            else r=mid-1;
        }
        return false;
    }
};
