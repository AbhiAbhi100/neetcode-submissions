class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        //step1 : freq count karne ke lie hashmap || key=number,value=kitni baar aaya
        unordered_map<int,int>freq;

        for(int num:nums){
            freq[num]++;
        }

        int n = nums.size();

        //step2:bucket create kar rhe hain .. bucket ka index represent karega freq
        //bucket[index] me store honge woh number jinki freq = index hain

        vector<vector<int>>bucket(n+1);

        //ab freq map ko traverse karenge
        for(auto &pair:freq){

            int number = pair.first;
            int frequency = pair.second;

            bucket[frequency].push_back(number);
        }


        vector<int>result;


        for(int i=n;i>=0;i--){
            for(int num:bucket[i]){
                result.push_back(num);

                //agar k elemets mil gaye toh return kar do
                if(result.size() ==k){
                    return result;
                }
            }
        }














    }
};
