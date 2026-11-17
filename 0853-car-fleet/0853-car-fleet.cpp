class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = speed.size();
        vector<pair<int, double>> cars;
        for (int i = 0; i < n; i++) {
            double time = (double)(target - position[i]) / speed[i];
            cars.push_back({position[i], time});
        }
        sort(cars.rbegin(), cars.rend());
        stack<double> st;
        for (auto it : cars) {
            double currTime = it.second;
            if (st.empty() || currTime > st.top()) {
                st.push(currTime);
            }
        }
        return st.size();
    }
};