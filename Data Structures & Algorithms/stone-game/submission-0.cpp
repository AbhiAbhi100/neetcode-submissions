class Solution {
public:

    int solve(int i,int j,vector<int>& piles){
        //base case
        if(i==j) return piles[i];

        //choice1: take left
        int takeLeft = piles[i]-solve(i+1,j,piles);

        //choice2: take right
        int takeRight = piles[j]-solve(i,j-1,piles);

        return max(takeLeft,takeRight);
    }

    bool stoneGame(vector<int>& piles) {
        //short me ye karenge ki
        //har step par recursion bolega ki
        //left pile uthao ya right pile uthao
        //aur fir opponenent ka best move ke baad net differnce calculate karenge
        int n = piles.size();
        int diff = solve(0,n-1,piles);
        return diff > 0;
    }
};