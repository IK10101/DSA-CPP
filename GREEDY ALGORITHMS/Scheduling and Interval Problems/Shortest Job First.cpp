//Problem Statement
/*A software engineer is tasked with using the shortest job first (SJF) policy to calculate the average waiting time for each process. The shortest job first also known as shortest job next (SJN) scheduling policy selects the waiting process with the least execution time to run next.

You are given an array of integers bt of size n representing the burst times (execution times) of n processes.

Your task is to calculate the average waiting time for all processes when scheduled using the SJF policy. The waiting time of a process is the total time a process has to wait before its execution starts, which is the sum of burst times of all previously executed processes.

Return the floor of the average waiting time, i.e., the largest whole number less than or equal to the actual average.*/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
   public:
    long long solve(vector<int>& bt) {
        sort(bt.begin(), bt.end());
        long long waitingtime = 0;
        long long totalwaitingtime = 0;
        for (int i = 0; i < bt.size(); i++) {
            totalwaitingtime += waitingtime;
            waitingtime += bt[i];
        }
        return totalwaitingtime / bt.size();
    }
};

//Time Complexity: O(nlogn) due to sorting the burst times.
//Space Complexity: O(1) as we are using only a constant amount of extra space.