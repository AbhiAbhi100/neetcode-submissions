class Solution {
public:
    int calPoints(vector<string>& operations) {
        
        stack<int>st;
        //yahi hamara stack hai ,score store karega

        for(string &op:operations){

            if(op=="C"){
                //last score ko pop karna hai
                st.pop();
            }
            else if(op == "D"){
                //last score ka double ko push karnege humlog
               
                st.push(2*st.top());
            }
            else if(op == "+"){
                //last 2 scores ka sum push karna hai
                int last1 = st.top();st.pop();
                int last2 = st.top();

                st.push(last1);
                st.push(last1+last2);
            }
            else{
                //yaha ab ye number hi hoga mtlb koi operation nahi hai seedhe andar jaega ye
                int x = stoi(op);
                st.push(x);
            }
        }

        //ab stack me jitne scores hai sabka sum nikal kar ke return kar dena hai hame
        int sum = 0;
        while(!st.empty()){
            sum+=st.top();
            st.pop();
        }

        return sum;
    }
};