class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;

        for(int &bill:bills){
            if(bill==5){
                five++;
            }
            else if(bill == 10){
                //return 5 dollar to customer if you have otherwise return false
                if(five>0){
                    five--;
                    ten++;
                }
                else{
                    return false;
                }
            }
            //ab 20 hai toh 15 wapis karna hai
            else if (five>0 && ten >0){
                five--;
                ten--;
            }
            else  if(five>=3){
                five-=3;
            }
            else{
                return false;
            }

        }
        return true;
    }
};