#include <bits/stdc++.h>
using namespace std;

int main() {
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);

    for(size_t i = 0; i < st.size(); i++) {
        cout << st.top() << endl;
        st.pop();
    }
    cout << st.top() << endl;
    st.pop();
    return 0;
}