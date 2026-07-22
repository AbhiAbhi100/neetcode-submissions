class Solution {
public:
/**
"Main backtracking use kar raha hoon. curr current parenthesis string ko represent karta hai. openCount aur closeCount track karte hain ki kitne opening aur closing brackets use ho chuke hain. Agar openCount < n hai to '(' add kar sakte hain. Agar closeCount < openCount hai to ')' add kar sakte hain, taaki string kabhi invalid na bane. Jab curr ki length 2*n ho jati hai, to ek valid combination mil jata hai aur use result me store kar deta hoon. Har recursive call ke baad pop_back() karke previous state restore karta hoon aur next possibility explore karta hoon."
*/
    vector<string> res;


    vector<string> generateParenthesis(int n) {
        string curr = "";
        backtrack(curr,0,0,n);
        return res;
    }

    void backtrack(string& curr,int openCount,int closeCount,int n){
        if(curr.size()==2*n){
            res.push_back(curr);
            return;
        }

        if(openCount<n){
            curr.push_back('(');
            backtrack(curr,openCount+1,closeCount,n);
            curr.pop_back();
        }
        if(closeCount<openCount){
            curr.push_back(')');
            backtrack(curr,openCount,closeCount+1,n);
            curr.pop_back();
        }
    }
};