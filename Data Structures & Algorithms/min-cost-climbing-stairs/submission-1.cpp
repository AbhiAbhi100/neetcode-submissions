class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int prev2=0;//for 0
        int prev1=0;//for 1
        int currentCost;

        for(int i=2;i<=cost.size();i++){
            currentCost=min(prev1+cost[i-1],prev2+cost[i-2]);//i-2 me 0 ki and i-1 me 1 ki
            prev2=prev1;//now i-1 new  i-2 hai
            prev1=currentCost;//new i-1 is current cost hai
        }
        return prev1;
    }
};
