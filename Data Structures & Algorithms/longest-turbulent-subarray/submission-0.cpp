class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        
        int n = arr.size();
        int maxLen = 1;
        int currLen = 1;
       
       

        for(int i = 1;i<n ;i++){
        bool a = arr[i-1]>arr[i] && (i==1 || arr[i-2]<arr[i-1]);
        bool b = arr[i-1]<arr[i] && (i==1 ||arr[i-2]>arr[i-1]);
            if(a || b){
                currLen++;
            }
            else if (arr[i]==arr[i-1]){
                currLen = 1;
            }
            else {
                currLen = 2;
            }
            maxLen = max(maxLen,currLen);
        }
        return maxLen;

    }
};