//max flow from a to b for each
void floyd()
{
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				w[i][j]=max(w[i][j],min(w[i][k],w[k][j]));
}
