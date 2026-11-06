#include <bits/stdc++.h>
using namespace std;

class Expression_Conversion
{
private:
    stack<char> st;
    string s = "A^B^C+D"; 
    string pre_output_string = ""; //+^A^BCD
    string pos_output_string = "";

public:
    void display()
    {
        cout << pre_output_string << "\n";
        cout<<pos_output_string<<"\n";
    }

    bool isRightAsccociative(char ch)
    {
        if (ch == '^')
        {
            return true;
        }
        return false;
    }

    int isoperator(char k)
    {
        switch (k)
        {
        case '^':
            return 3;

        case '*':
        case '/':
            return 2;

        case '+':
        case '-':
            return 1;

        default:
            return -1;
        }
    }

    void Infix_to_Prefix()
    {
        reverse(s.begin(), s.end());
        int i = 0;
        int n = int(s.size());

        while (i < n)
        {
            if (isalpha(s[i]))
            {
                pre_output_string += s[i];
            }
            else if (s[i] == ')')
            {
                st.push(s[i]);
            }
            else if (s[i] == '(')
            {
                while (!st.empty() && st.top() != ')')
                {
                    pre_output_string += st.top();
                    st.pop();
                }

                if (!st.empty())
                {
                    st.pop();
                }
            }
            else
            {
                if (!st.empty() &&
                    isoperator(s[i]) == isoperator(st.top()) &&
                    isRightAsccociative(s[i]))
                {
                    pre_output_string += st.top();
                    st.pop();
                }
                else if (st.empty() ||
                         isoperator(s[i]) >= isoperator(st.top()))
                {
                    st.push(s[i]);
                }
                else
                {
                    while (!st.empty() &&
                           isoperator(s[i]) < isoperator(st.top()))
                    {
                        pre_output_string += st.top();
                        st.pop();
                    }

                    st.push(s[i]); //push low precedance element
                }
            }

            i += 1;
        }

        while (!st.empty())
        {
            pre_output_string += st.top();
            st.pop();
        }

        reverse(pre_output_string.begin(), pre_output_string.end());
    }

    void Infix_to_Postfix()
    {
        int i = 0;
        int n = int(s.size());

        while (i < n)
        {
            if (isalpha(s[i]))
            {
                pos_output_string += s[i];
            }
            else if (s[i] == '(')
            {
                st.push(s[i]);
            }
            else if (s[i] == ')')
            {
                while (!st.empty() && st.top() != '(')
                {
                    pos_output_string += st.top();
                    st.pop();
                }

                // Remove the 'Opening Bracket' from stack but make sure that
                // stack is not empty!
                if (!st.empty())
                {
                    st.pop();
                }
            }
            else if (isoperator(s[i]))
            {
                while (!st.empty() &&
                       st.top() != '(' &&
                       (isoperator(s[i]) < isoperator(st.top()) ||
                        (isoperator(s[i]) == isoperator(st.top()) &&
                         !isRightAsccociative(s[i]))))
                {
                    pos_output_string += st.top();
                    st.pop();
                }

                st.push(s[i]);
            }

            i += 1;
        }

        // While Stack is not empty;
        while (!st.empty())
        {
            pos_output_string += st.top();
            st.pop();
        }
    }
};

int main()
{
    Expression_Conversion exp;
    exp.Infix_to_Postfix();
    exp.Infix_to_Prefix();
    exp.display();
    return 0;
}
