class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        //number push
        //operator last two pop and perform the operation
        //second top = a

        int <stack>st;
        for(token:tokens){
            if(token != '+','-','*','/'){
                st.push_back(token);
            }
            else{
                int b = st.top(),st.pop();
                int a = st.top(),st.pop();
                int c = a token b;
                st.push_back(c);
            }
        }
        return st.top();
    }
};
