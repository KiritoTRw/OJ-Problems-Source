#include <stdio.h>
#include <string.h>
int knight[8][8];
int x[]={1,1,2,2,-1,-1,-2,-2};
int y[]={2,-2,1,-1,2,-2,1,-1};
void dfs(int si,int sj,int moves)
{
    if(si < 0 || sj < 0 || si >= 8 || sj >= 8 || moves >= knight[si][sj])
        return;
    knight[si][sj] = moves;
    int i;
    for(i = 0; i < 8; i++)
        dfs(si + x[i],sj + y[i],moves + 1);
}
int main()
{
    char a[10],b[10];
    while(scanf("%s%s",a,b) != EOF)
    {
        memset(knight,10,sizeof(knight));
        dfs(a[0] - 'a',a[1] - '1',0);
        printf("To get from %s to %s takes %d knight moves.\n",a,b,knight[b[0] - 'a'][b[1] - '1']);
    }
    return 0;
}
