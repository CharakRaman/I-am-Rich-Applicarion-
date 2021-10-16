//Dp ROD CUTTING PROBLEM
//naive approach
#include<stdio.h>/*
int maxprofit(int *a,int n)
{
	if(n==0)//when length is 0 profit is 0
		return 0;
	int i,mon=0;
	for(i=1;i<n;i++){
		mon=a[i]+maxprofit(a,n-i);// net price for a[i]disvision as 1 division is already done + price for (n-i) as i... 
								  //....lenght has been divided already
		if(mon>a[n])//is after division profit greater than total lenght sale profit? ....
			return mon;//.... yes
		else 
			return a[n];//.... no
	}
}*/
int max(int a,int b) {
	return(a>b?a:b); }
	
int maxprofit(int * a,int n)
{
	int cost[n];
	int i,j;
	cost[0]=0;
	for(i=1;i<=n;i++)
	{
		int t=-1;
		for(j=1;j<=i;j++)
			t=max(t,a[j]+cost[i-j]);
		cost[i]=t;
	}
	return cost[n];
}


//modified function we are asked to return the cuts too along with the maximum (optimised) profit....
typedef struct cutting{
	int cost[100];
	int cut[100];
}cutter;//we need structure as we need to return two parameters from our function.

cutter modifiedmaxprofit(int * a,int n)
{
	int i,j;
	cutter c;
	c.cost[0]=0;//as for 0 cut profit is zero
	c.cut[0]=0;//for 0 cut cut lenght is zero
	for(i=1;i<=n;i++)
	{
		int t=-1;
		for(j=1;j<=i;j++)
			if(t<a[j]+c.cost[i-j])//if current t that is t from pervios iteration is less than current cut profit + remaining lenght old profit.
			{
				t=a[j]+c.cost[i-j];
				c.cut[i]=j;	
			}
		c.cost[i]=t;
	}
	return c;
}

int main()
{
 	int a[]={0,1,5,8,9,10,17};
 	int n=4;
	 int profit=maxprofit(a,n);
	 printf("%d",profit);	//the max (optimised) profit we can earn 
	 //if we need the specific cuts too then...
	 printf("\nTHE MODIFIED CUT ROD\n");
	 cutter c=modifiedmaxprofit(a,n);
	 printf("FOR LENGTH: %d\n PROFIT IS: %d\nCUTS ARE:\n",n,c.cost[4]);
	 while(n>0)
	 {
	 	printf("%d\n",c.cut[n]);
	 	n=n-c.cut[n];
	 }
	 return 0;
}





