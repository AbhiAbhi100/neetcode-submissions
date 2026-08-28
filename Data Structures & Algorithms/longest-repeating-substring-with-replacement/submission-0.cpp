class Solution {
public:
    int characterReplacement(string s, int k) {
        

        unordered_map<char,int>freq;

        int left = 0;

        int maxFreq = 0;

        int ans = 0;

        for(int right = 0;right<s.size();right++){

            //add the current char
            freq[s[right]]++;

            //update the max freq
            maxFreq = max(maxFreq,freq[s[right]]);

            //current window size
            int windowSize = right-left+1;

            //  too many reqplacement needed
            if(windowSize-maxFreq >k){
                freq[s[left]]--;
                left++;
            }

            //updating the ans 
            ans = max(ans,right-left+1);

        }
        return ans;
    }
};
