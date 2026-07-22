class Solution {
public:
/*
Main is problem ko backtracking se solve kar raha hoon. Har digit ke corresponding kuch letters hote hain (jaise 2 → abc, 3 → def). Main ek temporary string curr maintain karta hoon jo current combination ko represent karti hai.

Recursion me i current digit ka index batata hai. Har call me main current digit ke saare possible letters par loop lagata hoon.

Ek letter choose karta hoon aur curr me add karta hoon.
Phir next digit ke liye recursive call karta hoon.
Jab recursion se wapas aata hoon to pop_back() karke us letter ko hata deta hoon, taaki next letter try kar sakun. Isi process ko backtracking kehte hain.

Base case tab aata hai jab curr ki length digits ki length ke equal ho jati hai. Iska matlab har digit ke liye ek letter choose ho chuka hai, to main curr ko answer me store kar deta hoon

pop_back() state ko restore karta hai. Agar main ise na karun, to previous choice curr me hi rahegi aur next combinations galat banenge

*/

    vector<string> res;

    unordered_map<char, string> digitToLetters = {
        {'2',"abc"}, {'3',"def"}, {'4',"ghi"}, {'5',"jkl"},
        {'6',"mno"}, {'7',"pqrs"}, {'8',"tuv"}, {'9',"wxyz"}
    };
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return res;
        string curr = "";
        backtrack(0,digits,curr);
        return res;
    }

    void backtrack(int i,string& digits,string& curr){
        if(curr.size()==digits.size()){
            res.push_back(curr);
            return;
        }
        string letters = digitToLetters[digits[i]];
        for(char c:letters){
            curr.push_back(c);//choose
            backtrack(i+1,digits,curr);//explore
            curr.pop_back();//unchoose
        }
    }
};