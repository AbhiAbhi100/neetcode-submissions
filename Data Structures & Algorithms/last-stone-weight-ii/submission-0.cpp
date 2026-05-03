class Solution {
public:

    int solveRec(int i,int sum1,const vector<int>& stones,int total){
        int n = stones.size();

        if(i==n){
            //all the stones are assigned , return the final differnce
            return abs(total-2*sum1);
        }

        //not-skip : include stones[i] in the subset1
        int notSkip = solveRec(i+1,sum1+stones[i],stones,total);

        //skip : do not include stones[i] in the subset1
        int skip = solveRec(i+1,sum1,stones,total);

        return min(notSkip,skip);
        //this because ek path kuch aur dega aur ek kuch aur toh dono ka minimum lenge hmlog
    }


    int lastStoneWeightII(vector<int>& stones) {
        int total = accumulate(stones.begin(),stones.end(),0);
        return solveRec(0,0,stones,total);
    }
};