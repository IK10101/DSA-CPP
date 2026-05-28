//Problem Statement
/* Given an 2D array Jobs of size Nx3, where Jobs[i][0] represents JobID , Jobs[i][1] represents Deadline , Jobs[i][2] represents Profit associated with that job. Each Job takes 1 unit of time to complete and only one job can be scheduled at a time.

The profit associated with a job is earned only if it is completed by its deadline. Find the number of jobs and maximum profit.*/


#include <algorithm>
#include <vector>

using namespace std;

class Solution {
   private:
    static bool comparator(vector<int>& a, vector<int>& b) {
        return a[2] > b[2];
    }

   public:
    vector<int> JobScheduling(vector<vector<int>>& Jobs) {
        sort(Jobs.begin(), Jobs.end(), comparator);

        int maxDeadline = 0;

        for (auto& job : Jobs) {
            maxDeadline = max(maxDeadline, job[1]);
        }

        vector<int> slot(maxDeadline + 1, -1);

        int countJobs = 0;
        int maxProfit = 0;

        for (auto& job : Jobs) {
            int id = job[0];
            int deadline = job[1];
            int profit = job[2];

            for (int j = deadline; j > 0; j--) {
                if (slot[j] == -1) {
                    slot[j] = id;

                    countJobs++;
                    maxProfit += profit;

                    break;
                }
            }
        }

        return {countJobs, maxProfit};
    }
};

//Time Complexity: O(N log N) due to sorting the jobs based on profit.
//Space Complexity: O(maxDeadline) for the slot array, where maxDeadline is the maximum deadline among the jobs.