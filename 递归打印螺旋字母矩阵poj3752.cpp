#include<cstdio> 
char s[300][300];
void f(int x,int y,int start,int m,int n)
{
	int i,j;
	if(m<=0||n<=0)return;
	if(m==1)
	{
		for(i=x;i<x+n;i++)
		{
			s[y][i]='A'+start;
			start=(start+1)%26;
		}
		return;
	}
	if(n==1)
	{
		for(j=y;j<y+m;j++)
		{
			s[j][x]='A'+start;
			start=(start+1)%26;
		}
		return;
	}
	for(i=x;i<x+n-1;i++)
	{
		s[y][i]='A'+start;
		start=(start+1)%26;
	}
	for(j=y;j<y+m-1;j++)
	{
		s[j][x+n-1]='A'+start;
		start=(start+1)%26;
	}
	for(i=x+n-1;i>x;i--)
	{
		s[y+m-1][i]='A'+start;
		start=(start+1)%26;
	}
	for(j=y+m-1;j>y;j--)
	{
		s[j][x]='A'+start;
		start=(start+1)%26;
	}
	f(x+1,y+1,start,m-2,n-2);
}
int main()
{
	int m,n;
	scanf("%d%d",&m,&n);
	f(0,0,0,m,n);
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("   %c",s[i][j]);//一定要数题目中的空格个数！！！ 
		}
		printf("\n");
	}
	return 0;
} 
