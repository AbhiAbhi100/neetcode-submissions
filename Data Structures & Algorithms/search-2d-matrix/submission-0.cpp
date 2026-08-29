class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        
        int m = mat.size();
        int n = mat[0].size();

        int low = 0;
        int high = m*n-1;

        while(low<=high){
            int mid = low+(high-low)/2;

            int val = mat[mid/n][mid%n];

            //N SE DIVIDE COL SE
            if(val  == target) return true;

            else if (val<target) low = mid+1;
            else high = mid-1;

        }
        return false;
    }
};
