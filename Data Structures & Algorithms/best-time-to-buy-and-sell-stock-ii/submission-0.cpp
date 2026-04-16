class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
               //buy and selll stocks 2 me hame chup chap se increasing slope walo ko add kar dena hai apne profit me ye ek greedy approch hai
        int profit = 0;

        //traverse from day 1
        for(int i=1;i<prices.size();i++){
            //if price increases ,take the profit
            if(prices[i]>prices[i-1]){
                profit+=prices[i]-prices[i-1];
            }
        }

        return profit;
    }
};