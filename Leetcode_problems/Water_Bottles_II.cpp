class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int count = 0;
        while (numBottles >= numExchange) {
            count += numExchange;
            numBottles -= numExchange;
            numExchange++;
            numBottles += 1;
        }
        return numBottles + count;
    }
};
//simple simulation 
class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int drank = numBottles;
        int empty = numBottles;
        while (empty >= numExchange) {
            empty -= numExchange;
            drank++;
            empty++;
            numExchange++;
        }
        return drank;
    }
};
