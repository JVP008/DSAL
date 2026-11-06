#include <iostream>
#include <stack>
using namespace std;

class Infix_to_Postfix
{
private:
    stack<char> st;
    string result = "";
    int check_precedence(char ch)
    {
        if (ch == '^')
            return 3;
        else if (ch == '/' || ch == '*')
            return 2;
        else if (ch == '+' || ch == '-')
            return 1;
        else
            return -1;
    }

public:
    string convert(string s)
    {
        int i = 0;
        while (i != s.size())
        {
            if (isalpha(s[i]))
            {
                result += s[i];
            }
            else if (s[i] == '(')
            {
                st.push(s[i]);
            }
            else if (s[i] == ')')
            {
                while (!st.empty() && st.top() != '(')
                {
                    result += st.top();
                    st.pop();
                }
                if (!st.empty())
                    st.pop(); // pop the '('
            }
            else if (!st.empty() && (check_precedence(s[i]) > check_precedence(st.top())))
            {
                st.push(s[i]);
            }
            else if (!st.empty() && (check_precedence(s[i]) <= check_precedence(st.top())))
            {
                while (!st.empty() &&
                       check_precedence(s[i]) <= check_precedence(st.top()) )
                {
                    result += st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
        else
        {
            st.push(s[i]);
        }
        i += 1;
    }
    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }
    cout << result;
    return result;
}
};
int main()
{
    string s;
    s = "(A+B)*(C*D-E)*F/G";
    Infix_to_Postfix ip;
    ip.convert(s);
    return 0;
}
