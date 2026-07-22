class Solution {
public:
/**
Main current index se har possible substring try karta hoon. Agar substring palindrome hai to use current partition me add karta hoon aur remaining string ke liye recursion call karta hoon. Jab recursion return karta hai to us substring ko remove kar deta hoon taaki next substring try kar sakun. Jab start string ke end tak pahunch jata hai, iska matlab ek valid partition mil gaya hai, jise result me store kar deta hoon."
0*/

    vector<vector<string>>res;
    vector<string>part;

    vector<vector<string>> partition(string s) {
        backtrack(0,s);
        return res;
    }

    void backtrack(int start,string& s){
        if(start == s.size()){
            res.push_back(part);
            return;
        }

        for(int end = start;end <s.size();end++){
            if(isPallindrome(s,start,end)){
                part.push_back(s.substr(start,end-start+1));
                backtrack(end+1,s);
                part.pop_back();
            }
        }
    }

    bool isPallindrome(string& s,int l,int r){
        while(l<r){
            if(s[l]!=s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};