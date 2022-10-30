#include <bits/stdc++.h>

void KMPpreprocess(string &pat, vector<int> &lps)
{
	int i = 1, len = 0;
	lps[0] = 0;

	while(i < pat.length())
	{
		if(pat[i] == pat[len])
		{
			lps[i] = len + 1;
			len++;
			i++;
		}
		else
		{
			if(len != 0)
				len = lps[len - 1];
			else
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}

void KMPsearch(string &str, string &pat)
{
	vector<int> lps(pat.length() + 1, 0);
	KMPpreprocess(pat, lps);
	int i = 0, j = 0;

	while(i < str.length())
	{
			if(str[i] == pat[j])
			{
				i++;
				j++;
			}
			else
			{
				if(j != 0)
					j = lps[j - 1];
				else
					i++;
			}

			if(j == pat.length())
			{
				cout << "Pattern found at " << i - j << nl;
				j = lps[j - 1];
			}
	}
}

void solve()
{
	string str = "abcabcabc";
	string pattern = "abc";
	KMPsearch(str, pattern);

}




int32_t main()
{

    int T = 1;
    // cin>>T;

    while(T--)
    {
        solve();
    }

    return 0;
}