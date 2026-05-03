class Solution {
public:

    int solve(int i,int M,vector<int>& piles){
        int n = piles.size();
        if(i>=n) return 0;

        //calculating the sum of the remaining piles from i to n-1
        int remainingSum=0;

        for(int k=i;k<n;k++){
            remainingSum+=piles[k];
        }

        int best = 0;

        //trying all the options:: take X from piles(1 to 2M)
        for(int X=1;X<=2*M && i+X<=n;X++){
            int opponentBest = solve(i+X,max(M,X),piles);
            int myGain = remainingSum - opponentBest;
            best = max(best,myGain);
        }

        return best;

    }


    int stoneGameII(vector<int>& piles) {
        return solve(0,1,piles);
    }
};