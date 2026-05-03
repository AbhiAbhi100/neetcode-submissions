class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        //map me dal ke count
        map<int,int>frequency;

        for(int element:nums){
            frequency[element]++;
        }

        for(const auto& pair: frequency){
            if(pair.second==2){
                return true;
               
            }
        }
        return false;
    }
};