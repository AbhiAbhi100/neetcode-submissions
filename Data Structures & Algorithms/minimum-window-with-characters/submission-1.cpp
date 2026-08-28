class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>need,window;

        for(char c:t){
            need[c]++;
        }

        int left = 0,right = 0;
        int valid = 0;

        int start = 0;
        int minLen = INT_MAX;

        while(right<s.size()){
         
            char c = s[right];
            right++;

            //if current  char is needed
            if(need.count(c)){
                //add to the current window
                window[c]++;

                //if the required freq is achieved
                if(window[c]==need[c]){
                    valid++;
                }

            }

            //if al the all the req chars are preset
            while(valid == need.size()){

                //update the min window
                if(right-left<minLen){
                    minLen = right-left;
                    start = left;

                }

                //remove the left character
                char d = s[left];
                left++;

                //if removed char is imp
                if(need.count(d)){
                    //if removing it breaks the req
                    if(window[d]==need[d]){
                        valid--;
                    }

                    window[d]--;
                }
            }
        }

        if(minLen==INT_MAX){
            return "";
        }
        return s.substr(start,minLen);
    }
};
