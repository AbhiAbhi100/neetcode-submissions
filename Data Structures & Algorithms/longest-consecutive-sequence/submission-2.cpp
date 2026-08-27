class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>set(nums.begin(),nums.end());
        int best = 0;
        for(int x:set){
            if(set.count(x-1)) continue;

            int len = 1;
            while(set.count(x+len))len++;
            best = max(best,len);
        }
        return best;
    }
};
