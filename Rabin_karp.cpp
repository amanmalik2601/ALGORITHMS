#include "bits/stdc++.h"
using namespace std;
vector<int> rabinKarp(string str,string patt)
{
	 const int p=31;
	 const int mod=1000000007;

        long long ph=patt[0]-'a'+1;
        long long po=p;
        for(int i=1;i<patt.length();++i)
        {
        	ph=(ph + (patt[i]-'a'+1) * po) % mod;
        	po=(po*p) % mod;
        }

        po=p;
        vector<long long>dp(str.length());
        vector<long long>pw(str.length());
        dp[0]=str[0]-'a'+1;
        pw[0]=1;
        
        
        for(int i=1;i<str.length();++i)
        {
        	dp[i]=(dp[i-1] + (str[i]-'a'+1) * po) % mod;
        	pw[i]=po;
        	po=(po*p) % mod;
        }

        

        int i=0;
        int j=patt.length()-1;

        vector<int>occ;

        while(j<str.length())
        {
        	long long val=dp[j];
        	if(i>0)
        	{
        		val=(val-dp[i-1] +mod) % mod;
        	}
        	if(val == (ph * pw[i]) % mod)
        		occ.push_back(i);

        	++i,++j;
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

        vector<int>ans=rabinKarp(str,patt);
        for(int i=0;i<ans.size();i++)
        	cout<<ans[i];

	return 0;       
}