#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> parent;
vector<int> record;
vector<int> dp;
vector<int> path;
void dfs(int cur,int last)
{
    int i;
    if(cur==0)
    {
    	printf("  { ");
        for(i=path.size()-1;i>=0;i--)
        printf("%d ",path[i]);
        printf(" }\n");
        return;
    }
    for(i=0;i<=record[cur];i++)
    {
        int coin=parent[cur][i];
        if(coin>last)
        continue;
        path.push_back(coin);
        dfs(cur-coin,coin);
        path.pop_back();
    }
}
int main()
{
    int n,i=0,m,j;
    printf("How much?:");
    scanf("%d",&n);
    printf("How many?:");
    scanf("%d",&m);
    printf("Which kind?:");
    vector<int> a(m);
    dp.resize(n+1,INT_MAX/2);
    parent.resize(n+1,vector<int>(n+1));
    record.resize(n+1,-1);
    dp[0]=0;
    for(j=0;j<m;j++)
    {
        scanf("%d",&a[i]);
        if(a[i]<=n)
            i++;
    }
    sort(a.begin(),a.begin()+i);
    m=i;
    for(i=0;i<=n;i++)
    {
        if(dp[i]!=INT_MAX/2)
        {
            for(j=0;j<m;j++)
            {
                if(i+a[j]<=n)
                {
                    if(dp[i+a[j]]>dp[i]+1)
                    {
                        dp[i+a[j]]=dp[i]+1;
                        record[i+a[j]]=0;
                        parent[i+a[j]][record[i+a[j]]]=a[j];
                    }
                    else if(dp[i+a[j]]==dp[i]+1)
                    {
                        record[i+a[j]]++;
                        parent[i+a[j]][record[i+a[j]]]=a[j];
                    }
                }
            }
        }
    }
    printf("Minimum number of coins:%d\n",dp[n]);
    printf("Paths:\n");
    dfs(n,INT_MAX/2);
    return 0;
}