#include <bits/stdc++.h>
using namespace std;

// BruteForce-->we will store the pass ratio in a array for each class and check which one have the highest delta difference . THe one which have the highest diifernence we will put the extra student there and keep doing it until the extra student is zero. But it will will lead to TLE as it is checking again and again the maximum delta differnece for every class.

class Solution
{
public:
    double maxAverageRatio(vector<vector<int>> &classes, int extraStudents)
    {
        int n = classes.size();
        // Declare the array for storing the pass ratio
        vector<double> PR(n);
        for (int i = 0; i < n; i++)
        {
            // storing pass ratio
            double ratio = (double)classes[i][0] / classes[i][1];
            PR[i] = ratio;
        }
        // checking which class will have the maximum change if the extra
        // student is placed and then place there after that update the pass
        // ratio array to further placement.

        while (extraStudents != 0)
        {
            vector<double> newPR(n);
            for (int i = 0; i < n; i++)
            {
                // storing new pass ratio for every class
                double newRatio =
                    (double)(classes[i][0] + 1) / (classes[i][1] + 1);
                newPR[i] = newRatio;
            }
            // finding the index at which the class pass ratio will have the
            // maximum difference if so then put extra students there
            double max_difference = 0.0;
            int classIndex = 0;

            for (int i = 0; i < n; i++)
            {
                double difference = newPR[i] - PR[i];
                if (difference > max_difference)
                {
                    max_difference = difference;
                    classIndex = i;
                }
            }
            PR[classIndex] = newPR[classIndex];
            classes[classIndex][0]++;
            classes[classIndex][1]++;
            extraStudents--;
        }
        double result = 0.0;
        for (int i = 0; i < n; i++)
        {
            result += PR[i];
        }
        return result / n;
    }
};

// Optimal Solution --> This time we will use the priority_que to store the maximum delta class with its index also and update that class students only and again perform the task.
class Solution
{
public:
#define p pair<double, int>
    //(delta,index)
    double maxAverageRatio(vector<vector<int>> &classes, int extraStudents)
    {
        int n = classes.size();
        priority_queue<p> PQ;
        for (int i = 0; i < n; i++)
        {
            double PR = (double)classes[i][0] / classes[i][1];
            double newPR = (double)(classes[i][0] + 1) / (classes[i][1] + 1);
            // find the delta if this class is updated with extra student
            double delta = newPR - PR;
            // push the delta with index at which this delta occurs into the
            // priority queue
            PQ.push({delta, i});
        }
        while (extraStudents--)
        {
            auto it = PQ.top();      // Top element having the maximum delta
            double delta = it.first; // delta
            int index = it.second;   // index at which the class having this delta
            // remove it
            PQ.pop();

            classes[index][0]++; // Increase the pass students in class having
                                 // max delta
            classes[index]
                   [1]++; // Increase the total students also in that class

            // now we will update the pass ratio to further add the extra
            // student.
            double current_PR = (double)classes[index][0] / classes[index][1];
            double update_PR =
                (double)(classes[index][0] + 1) / (classes[index][1] + 1);

            delta = update_PR - current_PR;
            PQ.push({delta, index});
        }
        double total = 0.0;
        for (int i = 0; i < n; i++)
        {
            total += (double)classes[i][0] / classes[i][1];
        }

        return total / n;
    }
};