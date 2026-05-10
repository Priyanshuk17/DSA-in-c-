#include<bits/stdc++.h>
using namespace std;

class Stack {
    queue<int> q;
public: 
    void push(int x) {
        q.push(x);
        int n = q.size();

        //rotate the queue
        for(int i = 1; i < n; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    // pop Operation
    void pop() {
        if(q.empty()) {
            cout << "Stack is empty\n";
            return;
        }
        q.pop();
    }
    int top() {
        if(q.empty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return q.front();
    }
    // check empty
    bool empty() {
        return q.empty();
    }
};

int main() {
    Stack st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top element: " << st.top() << endl;

    st.pop();
    cout << "Top after pop: " << st.top() << endl;

    st.pop();
    st.pop();

    if(st.empty())
        cout << "Stack is empty" << endl;
    else
        cout << "Stack is not empty" << endl;


    return 0;
}