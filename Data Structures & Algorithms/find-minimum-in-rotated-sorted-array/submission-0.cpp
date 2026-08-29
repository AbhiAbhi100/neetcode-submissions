class Solution {
public:
   int findMin(vector<int>& a) {
    int lo = 0, hi = a.size() - 1;
    while (lo < hi) {                 // <  hai, <= nahi
        int mid = lo + (hi - lo) / 2;
        if (a[mid] > a[hi]) {
            lo = mid + 1;             // pivot daayen mein
        } else {
            hi = mid;                 // ⚠️ mid - 1 NAHI
        }
    }
    return a[lo];                     // lo == hi
}

};
