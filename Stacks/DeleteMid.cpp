#include <bits/stdc++.h>
using namespace std;

void DelMil(stack<int> &s, int count, int size)
{
    // base case
    if (count == size / 2)
    {
        s.pop();
        return;
    }

    int num = s.top();
    s.pop();

    DelMil(s, count + 1, size);
    s.push(num);
}

int main()
{
    stack<int> st;
    st.push(5);
    st.push(6);
    st.push(7);
    st.push(8);
    st.push(9);
    st.push(15);

    int size = st.size();
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    DelMil(st, 0, size);
    cout << "After Removal: " << endl;
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}