class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0, twenty = 0;
        int current_wallet = 0;
        for(int bill:bills)
        {
            if(bill == 5) five++;
            if(bill == 10) 
            {
                if(five >= 1)
                {
                    five--;
                    ten++;
                }
                else return false;
            }
            if(bill == 20) 
            {
                if(ten>=1 && five >=1)
                {
                    twenty++;
                    five--;
                    ten--;
                }
                else if(five>=3)
                {
                    twenty++;
                    five-=3;
                }
                else return false;
            }
        }
        return true;
    }
};