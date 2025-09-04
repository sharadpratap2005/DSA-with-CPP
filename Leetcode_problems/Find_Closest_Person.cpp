class Solution {
public:
    int findClosest(int x, int y, int z) {
        int p1 = abs(z - x); // distance from z of x
        int p2 = abs(z - y); // distance from z of y

        if (p1 > p2) // if p2<p1 return 2
            return 2;
        else if (p1 < p2) // if p1< p2 return 1
            return 1;
        // if p1==p2 return 0
        return 0;
    }
};
