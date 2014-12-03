void dijkstra()
{
	memset(visit,false,sizeof(visit));
	for(int i=0;i<n;i++)	d[i]=INF;
	d[0]=0;
	for(int i=0;i<n;i++){
		int mind=INF,mink;
		for(int j=0;j<n;j++)
			if(!visit[j] && mind>d[j]){
				mind=d[j];
				mink=j;
			}
		visit[mink]=1;
		for(int j=0;j<n;j++){
			if(d[j]>max(d[mink],dis(mink,j)))
				d[j]=max(d[mink],dis(mink,j));
		}
	}
}
