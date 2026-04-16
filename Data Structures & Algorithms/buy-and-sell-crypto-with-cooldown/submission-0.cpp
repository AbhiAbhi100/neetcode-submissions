class Solution {
public:

    int solve(int i,int canBuy,vector<int>& prices){

        //base case
        if(i>=prices.size()) return 0;

        int profit = 0;

        if(canBuy){
            //option 1 : buy today
            int take = -prices[i]+solve(i+1,0,prices);

            //option 2: skip today
            int skip = solve(i+1,1,prices);

            profit = max(take,skip);
        }
        else{
            //sell today =>cooldown jump to i+2
            int take = prices[i]+solve(i+2,1,prices);

            //option 2: skip today
            int skip = solve(i+1,0,prices);

            profit = max(take,skip);
        }

        return profit;
    }

    int maxProfit(vector<int>& prices) {
        return solve(0,1,prices);
    }
};
