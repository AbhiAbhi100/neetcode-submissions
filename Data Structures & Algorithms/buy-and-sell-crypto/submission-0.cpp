class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();

        int minPrice = prices[0];
        int maxProfit = 0;

        for(int i=1;i<n;i++){
            int profit = prices[i]-minPrice;

            if(prices[i]<minPrice){
                minPrice = prices[i];
            }
            if(profit>maxProfit){
                maxProfit = profit;
            }

        }
        return maxProfit;
    }
};
