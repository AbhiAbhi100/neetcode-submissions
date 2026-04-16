class Solution {
public:

    int countMemoRec(vector<int>& coins,int i,int amount,vector<vector<int>>& memo){

        
        if(amount==0) return 1;

        //out of coins return 0 target becomes negative
        if(i ==(int)coins.size() || amount<0) return 0;

        //if already computed ,return it from the memo
        if(memo[i][amount] != -1) return memo[i][amount];

        //take
        int take = countMemoRec(coins,i,amount-coins[i],memo);

        //do not take
        int skip = countMemoRec(coins,i+1,amount,memo);

        return memo[i][amount]=take+skip;
    }

    int change(int amount, vector<int>& coins) {

        int n = coins.size();

        vector<vector<int>>memo(n,vector<int>(amount+1,-1));

        return countMemoRec(coins,0,amount,memo);


    }
};
