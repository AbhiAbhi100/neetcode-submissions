class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size(),best = 0;
        stack<int>st;
        for(int i=0;i<=n;i++){
            int curr = (i==n)?0:h[i];

            while(!st.empty() && h[st.top()]>=curr){//curr hai nextsmall
                int ht = h[st.top()]; st.pop();

                int left = st.empty()?-1:st.top();//ye hai prevsmaller

                int width = i-left-1;

                best = max(best,ht*width);


            }
            st.push(i);
        }
        return best;
    }
};