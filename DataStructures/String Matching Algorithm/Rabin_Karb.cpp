/*
    ॐ
        JAI SHREE RAM

        Hare Krishna Hare Krishna Krishna Krishna Hare Hare
        Hare Rama Hare Rama Rama Rama Hare Hare
    
                                                ॐ
*/

//Written by Bhuwanesh Nainwal
#include <bits/stdc++.h>
using namespace std;

int polyHashString(string &s)
{
	int hash = 0LL, p = 31, m = 1e9 + 7, n = s.length(), power = 1;

	for(int i = 0 ; i < n ; i++)
	{
		hash += (power * (s[i] - 'a' + 1));
		power *= p;
		power %= m;
		hash %= m;
	}

	return hash; 
}


void helper(string &pattern, string &s)
{
	int patternHash = polyHashString(pattern);

    int hash = 0, power = 1,  mod = 1e9 + 7, pr = 31;
    
    
    int len = pattern.length();
    int n = s.length();
    for(int i = n - len ; i < n ; i++)
    {
            hash = hash + (s[i] - 'a' + 1) * power;
            hash %= mod;
            if(i != n - 1)
                power *= pr;
            power %= mod;                
            if(i == n - 1)
            {
            	if(hash == patternHash)
            		cout << "Pattern found at the index " << i << '\n'; 
            }
    }
    
    for(int i = n - len - 1 ; i >= 0 ; i--)
    {
            
        hash = hash - (s[i + len] - 'a' + 1) * power;
        hash %= mod;
        hash = hash + mod;
        hash %= mod;
        hash = hash * pr;
        hash %= mod;
        hash = hash + (s[i] - 'a' + 1);
        hash %= mod;

		if(hash == patternHash)
    		cout << "Pattern found at the index " << i << '\n';         
    }
}

void solve()
{
	string s = "abcabcbasdsaabc";
	string pattern = "abc";

	helper(pattern, s);

}

int main()
{

    fast;
    local();
    int T = 1;
    // cin>>T;

    while(T--)
    {
        solve();
    }

    return 0;
}