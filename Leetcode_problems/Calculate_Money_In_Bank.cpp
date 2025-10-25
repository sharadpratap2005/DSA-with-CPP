class Solution {
public:
    int totalMoney(int n) {
        if (n < 7) {
            return (n * (n + 1)) / 2;
        }
        int money = 0;
        int sn = n / 7;
        int sm = n % 7;

        if (sm == 0) {
            return (sn * (56 + (sn - 1) * 7)) / 2;
        } else {
            money += (sn * (56 + (sn - 1) * 7)) / 2;
            int remain = (sm * ((2 * (sn + 1)) + (sm - 1))) / 2;
            money += remain;
        }
        return money;
    }
};
