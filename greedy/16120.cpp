#include <iostream>
#include <stack>
using namespace std;

int main(void)
{
    string tmp;
    cin >> tmp;
    stack<char> st;

    for (int i = 0 ; i < tmp.size() ; ++i)
    {
        // cout << "now: " << tmp[i] << '\n';
        if (tmp[i] == 'A')
        {
            if (i + 1 < tmp.size() && tmp[i + 1] == 'P')
            {
                if (st.size() > 1)
                {
                    char a = st.top();st.pop();
                    char b = st.top();st.pop();
                    if (a == b && a == 'P')
                    {
                        st.push('P');
                        ++i;
                    }
                    else
                    {
                        st.push('P');
                        st.push('P');
                        st.push('A');
                    }
                }
                else {
                    st.push('A');
                }
            }
            else
                st.push('A');
        }
        else
            st.push('P');
    }
    if (st.size() == 1 && st.top() == 'P')
        cout << "PPAP";
    else
        cout << "NP";
}