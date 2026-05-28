//Problem Statement

/* Given one meeting room and N meetings represented by two arrays, start and end, where start[i] represents the start time of the ith meeting and end[i] represents the end time of the ith meeting, determine the maximum number of meetings that can be accommodated in the meeting room if only one meeting can be held at a time.*/

#include <algorithm>
#include <vector>
using namespace std;

class Solution {
   public:
    int maxMeetings(vector<int>& start, vector<int>& end) {
        int n = start.size();

        vector<pair<int, int>> meetings;
        for (int i = 0; i < n; i++) {
            meetings.push_back({end[i], start[i]});
        }
        sort(meetings.begin(), meetings.end());

        int count = 1;
        int lastend = meetings[0].first;

        for (int i = 1; i < n; i++) {
            int currstart = meetings[i].second;
            int currend = meetings[i].first;

            if (currstart > lastend) {
                count++;
                lastend = currend;
            }
        }
        return count;
    }
};

//Time Complexity: O(N log N) due to sorting the meetings based on their end times.
//Space Complexity: O(N) for storing the meetings in a vector of pairs.