#include<iostream>
#include<cstdio>
#include<cstring>

#define maxx 100005

using namespace std;

int parent[maxx],kind[maxx];

int find(int x)
{
	int t=parent[x];
	if(t<0)	return x;
	parent[x]=find(t);
	kind[x]=(kind[x]+kind[t])%2;
	return parent[x];
}

int main()
{
	int m,n,test,a,b,roota,rootb;
	char k[5];
	scanf("%d",&test);
	while(test--){
		scanf("%d %d",&n,&m);
		memset(parent,-1,sizeof(parent));
		memset(kind,0,sizeof(kind));
		for(int i=0;i<m;i++){
			scanf("%s %d %d",k,&a,&b);
			roota=find(a),rootb=find(b);
			if(k[0]=='A'){		//ask
				if(roota != rootb)
					printf("Not sure yet.\n");
				else{
					if(kind[a] == kind[b])
						printf("In the same gang.\n");
					else
						printf("In different gangs.\n");
				}
			}//if ask
			else{		//differ
				if(roota != rootb){
					parent[rootb] += parent[roota];
					parent[roota] = rootb;
					kind[roota]=(kind[a] + kind[b] +1)%2;
				}
			}	//if differ
		}
	}//while
	return 0;
}
