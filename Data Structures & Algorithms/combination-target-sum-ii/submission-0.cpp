class Solution {
public:
//for loop lagate hai toh not take apne aap ho jata hai -- do new child ban rhe hai
//bahut imp hai


        void solve(int i,vector<int>& candidates,int target, vector<int>temp,vector<vector<int>>& result){
                //base case
                if(target == 0){
                        result.push_back(temp);
                        return;
                }
                if(target<0 || i>=candidates.size()){
                        return;
                }

                 for(int ind=i;i<candidates.size();i++){
                        if(i>ind && candidates[i]==candidates[i-1]){
                                //continue;
                                continue;
                        }
                        temp.push_back(candidates[i]);
                        solve(i+1,candidates,target-candidates[i],temp,result);

                        temp.pop_back();
                       
                 }
 
                
                
        }


    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>result;
        vector<int>temp;


        solve(0,candidates,target,temp,result);
        return result;
    }
};
