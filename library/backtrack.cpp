void backtrack(int n) // n is the dimension
{	//to print like 1, 12, 123, 2 ,23....
	if (n == 3){	//when it is the solution
		print_solution();
		return;
	}
	solution[n] = true;
	backtrack(n+1);
	solution[n] = false;
	backtrack(n+1);
}
void backtrack(int n)
{	//to print like 123, 132, 213, 231.....
	if(n == len){
		for(int i=0;i<len;i++)
			printf("%c",ans[i]);
		printf("\n");
		return ;
	}
	char last='\0';
	for(int i=0;i<len;i++)
		if(solution[i]==0 && last != ar[i] ){
			solution[i]=1;
			last=ar[i];
			ans[n]=ar[i];
			backtrack(n+1);
			solution[i]=0;
		}
}
