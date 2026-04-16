class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        

        unordered_set<int>table(nums.begin(),nums.end());

        int maxcount = 0;

        for(int num:table){
            if(table.find(num-1)==table.end()){
                //it means not present inside the table
                int curr = num,count = 1;

                while(table.find(curr+1)!=table.end()){
                    curr++;
                    count++;
                }
                maxcount = max(maxcount,count);
            }
        }
        return maxcount;
    }
};
