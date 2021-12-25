#include "bits/stdc++.h"
using namespace std;
vector<int> kmp(string str,string patt)
{
	string s="";
	s.append(patt);
	s.append("#");
	s.append(str);

	vector<int>lps(s.length(),0);
	int i=1,len=0;

	while(i<s.length())
	{
		if(s[i] == s[len])
		{
			len++;
			lps[i]=len;
			++i;
		}

		else
		{
			if(len > 0)
				len=lps[len-1];
			
			else
			{
				lps[i]=0;
				++i;
			}
		}
	}

	vector<int>occ;

	for(int i=0;i<lps.size();++i)
	{
		if(lps[i] == patt.length())
			occ.push_back(i - patt.length() - lps[i]);
	}

	return occ;
}
int main()
{
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

        string str,patt;
        cin>>str>>patt;

        vector<int>ans=kmp(str,patt);
        for(int i=0;i<ans.size();++i)
        	cout<<ans[i];

	return 0;       
}