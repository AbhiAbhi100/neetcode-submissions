class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        //if s1 is bigger than s2,impossible

        if(s1.size()>s2.size()){
            return false;
        }

        //freq arrays
        vector<int>need(26,0);
        vector<int>window(26,0);

        for(char c:s1){
            need[c-'a']++;
        }

        int left = 0;

        //expand window
        for(int right=0;right<s2.size();right++){
            //add the current char
            window[s2[right]-'a']++;

            //if window becomes larger than s1 remove the left char
            if(right-left+1>s1.size()){
                window[s2[left]-'a']--;
                left++;
            }

            if(window==need){
                return true;
            }

        }
        return false;
    }
};
