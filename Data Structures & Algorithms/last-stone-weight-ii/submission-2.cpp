class Solution {
public:

    int solveRec(int i,int sum1,vector<int>& stones,int total,vector<vector<int>>& memo){
        int n = stones.size();

        if(i==n){
            return abs(total-2*sum1);
        }

        //if already computed, return the result
        if(memo[i][sum1] != -1) return memo[i][sum1];

        //not skip :: including the stones[i] in the sum 1
        int notSkip = solveRec(i+1,sum1+stones[i],stones,total,memo);

        //skip : do not include in the stones[i] in the sum1
        int skip = solveRec(i+1,sum1,stones,total,memo);

        return memo[i][sum1] = min(notSkip,skip);
    }


    int lastStoneWeightII(vector<int>& stones) {
        int total = accumulate(stones.begin(),stones.end(),0);
        int n = stones.size();


        vector<vector<int>>memo(n,vector<int>(total+1,-1));

        return solveRec(0,0,stones,total,memo);

    }
};