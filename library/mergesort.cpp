void mergesort(int a[],int low,int high){
	if(high>low){
		mergesort(a,low,(low+high)/2);
		mergesort(a,1+(low+high)/2,high);
		merge(a,low,high);
	}
}
void merge(int a[],int low,int high){
	int b[1000],i,j,k=-1,mid=(low+high)>>1;
	for(i=low,j=mid+1;i<=mid||j<=high;){
		if(i>(low+high)/2) 	b[++k]=a[j++];
		else if(j>high)		b[++k]=a[i++];
		else if(a[i]>a[j]){
			b[++k]=a[j++];
			t=t+1+mid-i;
		}
		else 				b[++k]=a[i++];
	}
	k=0;
	for(i=low;i<=high;i++) a[i]=b[k++];
}
