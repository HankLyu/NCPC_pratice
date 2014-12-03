//find min

int binary_search(int beg,int end){
	int mid;
	do{
		mid=(bed+end)/2;
		if(canbe(mid))	end=mid;
		else	beg=mid+1;
	}while(beg<end);
	return end;
}

//find max
int binary_search(int beg,int end){
	int mid;
	do{
		mid=(beg+end+1)/2;
		if(canbe(mid)) beg=mid;
		else end=mid-1;
	}while(beg<end);
	return end;
}
