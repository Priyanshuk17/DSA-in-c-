class MinStack {
private:
    stack<long long> st;
    long long mini;

public:
    MinStack() {
        mini = LLONG_MAX;
    }

    void push(int val) {
        if (st.empty()) {
            st.push(val);
            mini = val;
        }
        else if (val < mini) {
            // encode value
            st.push(2LL * val - mini);
            mini = val;
        }
        else {
            st.push(val);
        }
    }

    void pop() {
        if (st.empty()) return;

        long long topVal = st.top();
        st.pop();

        if (topVal < mini) {
            // decode previous minimum
            mini = 2 * mini - topVal;
        }
    }

    int top() {
        if (st.empty()) return -1;

        long long topVal = st.top();
        if (topVal < mini)
            return mini;   // encoded value
        return topVal;
    }

    int getMin() {
        return mini;
    }
};
