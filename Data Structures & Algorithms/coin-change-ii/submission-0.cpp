class Solution {
public:

    int countRec(vector<int>& coins,int i,int sum){
        //if the amount becomes 0 ,then we found a valid way
        if(sum==0) return 1;

        //if no coins left OR amount <0->no way return 0
        if(i==coins.size() || sum<0) return 0;

        int notSkip = 0,skip=0;

        notSkip = countRec(coins,i,sum-coins[i]);

        skip = countRec(coins,i+1,sum);

        return notSkip+skip;
    }


    int change(int amount, vector<int>& coins) {
        return countRec(coins,0,amount);
    }
};
