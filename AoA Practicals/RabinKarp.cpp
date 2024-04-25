#include <bits/stdc++.h>
using namespace std;
int main()
{
    string txt;
    string pat;
    cin >> txt >> pat;
    int q = 13;
    int len = pat.length();
    int h = stoi(pat) % q;
    string n = "";
    int i = 0;
    while (i < len - 1)
    {
        n += txt[i];
        i++;
    }

    while (i < txt.length())
    {
        n += txt[i];
        if (stoi(n) % q == h)
        {
            int k;
            for (k = 0; k < len; k++)
            {
                if (pat[k] != txt[i - len + k + 1])
                {
                    cout << "spurious hit at : " << i - len + 2 << endl;
                    break;
                }
            }
            if (k == len)
                cout << "pattern found at : " << i - len + 2 << endl;
        }
        n.erase(n.begin());
        i++;
    }

    return 0;
}
