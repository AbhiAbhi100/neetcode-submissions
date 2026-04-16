class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
                unordered_set<int>numSet(nums.begin(),nums.end());
        //o(n) set banayenge hum

        int longest = 0;

        for(int n:numSet){
            //check karo ki ye sequence ka start hai ya nahi
            if(numSet.find(n-1)==numSet.end()){
                //nahi mila n-1 mtlb
                int length = 1;
                int current = n;

                //ab next consecutive numbers ko check karenge
                while(numSet.find(current+1)!=numSet.end()){
                    current++;
                    length++;
                }

                longest = max(longest,length);
            }
        }
        return longest;
    }
};
