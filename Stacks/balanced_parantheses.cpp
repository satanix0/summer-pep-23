#include <bits/stdc++.h>
using namespace std;

bool isValid(string input)
{
    stack<char> st;
    int n = input.size();
    bool ans = true;

    for (int i = 0; i < n; i++)
    {
        // check if i is an opening bracket
        if (input[i] == '(' || input[i] == '{' || input[i] == '[')
        {
            st.push(input[i]);
        }
        else if (input[i] == ')')
        {
            if (!st.empty() && st.top() == '(')
            {
                st.pop();
            }
            else
            {
                ans = false;
                break;
            }
        }
        else if (input[i] == '}')
        {
            if (!st.empty() && st.top() == '{')
            {
                st.pop();
            }
            else
            {
                ans = false;
                break;
            }
        }
        else if (input[i] == ']')
        {
            if (!st.empty() && st.top() == '[')
            {
                st.pop();
            }
            else
            {
                ans = false;
                break;
            }
        }
    }
    if (!st.empty())
    {
        return false;
    }
    return ans;
}

int main()
{

    return 0;
}