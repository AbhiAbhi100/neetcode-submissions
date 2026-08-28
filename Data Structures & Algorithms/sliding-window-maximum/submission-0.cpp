class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        deque<int>dq;

        vector<int>ans;

        for(int i=0;i<nums.size();i++){

            //remove smaller elemenets from the back
            while(!dq.empty() && nums[dq.back()]<=nums[i]){
                dq.pop_back();
            }

            //add the current index
            dq.push_back(i);

            //remove the indicies that are out of the current window
            if(!dq.empty() && dq.front()<=i-k){
                dq.pop_front();
            }

            //window is complete , store the maximum
            if(i>=k-1){
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};
