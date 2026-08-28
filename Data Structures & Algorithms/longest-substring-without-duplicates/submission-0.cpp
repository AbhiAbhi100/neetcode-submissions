class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        

        //stores all the unique characters present in the current window
        unordered_set<char>st;

        //left pointer of the sliding window

        int left = 0 ;

        //stores the maximum length of a valid substring
        int maxLen = 0;

        for(int right = 0;right<s.size();right++){

            //if the current char already existsin the window shrink the window from the left until it becomes the unique
            while(st.count(s[right])){
                //remove the leftmost char from the set
                st.erase(s[left]);

                left++;
            }

            st.insert(s[right]);

            //update the max length found so far
            maxLen = max(maxLen,right-left+1);
        }
        return maxLen;
    }
};
