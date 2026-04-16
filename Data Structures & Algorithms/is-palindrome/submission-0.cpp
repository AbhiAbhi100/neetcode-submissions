class Solution {
public:
    bool isPalindrome(string s) {
        

        int l=0,r=s.size()-1;

        while(l<r){
            //skip non-alphanumeric characters from the left
            while(l<r && !isalnum(s[l])){
                l++;
            }

            //skip non-alphanumeric characters from right
            while(l<r && !isalnum(s[r])){
                r--;
            }

            //compare characters after converting to the lowercase
            if(tolower(s[l]) != tolower(s[r])){
                return false;
            }

            //Move both pointers toward center
            l++;
            r--;
        }
        return true;
    }
};
