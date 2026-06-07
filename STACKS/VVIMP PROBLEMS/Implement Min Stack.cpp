//Problem Statement

/*Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.*/


//Solution-1 (Using Pair Stack)
#include <iostream>
#include <stack>
using namespace std;

class MinStack {
   private:
    stack<pair<int, int>> st;

   public:
    void push(int x) {
        if (st.empty()) {
            st.push({x, x});
        } else {
            int minVal = min(x, st.top().second);
            st.push({x, minVal});
        }
    }

    void pop() {
        if (!st.empty()) {
            st.pop();
        }
    }

    int top() {
        return st.top().first;
    }

    int getMin() {
        return st.top().second;
    }
};


//Time Complexity: O(1) for all operations
//Space Complexity: O(2N) in the worst case when all elements are in decreasing order


//Solution-2 (Using One Stack)
#include <iostream>
#include <stack>
#include <climits>
using namespace std;

class MinStack {
   private:
    stack<int> st;
    int minVal=INT_MAX;

   public:
    MinStack() {}

    void push(int x) {
        if (x <= minVal) {
            st.push(minVal);
            minVal = x;
        }
        st.push(x);
    }

    void pop() {
        if (st.top() == minVal) {
            st.pop();
            minVal = st.top();
            st.pop();
        } else {
            st.pop();
        }
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return minVal;
    }
};

//Time Complexity: O(1) for all operations
//Space Complexity: O(N) in the worst case when all elements are in decreasing order
