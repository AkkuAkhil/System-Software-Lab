#include<stdio.h>
#include<stdlib.h>
void main() {
	system("clear");
	int n,i,tq=2,t=0,flag=1;
	float awt=0,atat=0,twt=0,ttat=0;
	puts("\nEnter the no of processes");
	scanf("%d",&n);
	int p[n],b[n],rem[n],wt[n],tat[n];

//INPUT SECTION
	for(i=0;i<n;i++){
		printf("Enter %d process     : ",i+1);
		scanf("%d",&p[i]);
		}puts("");
	for(i=0;i<n;i++){
		printf("Enter %d processs BT : ",i+1);
		scanf("%d",&b[i]);
		}puts("");
//SLICING SECTION
	for(i=0;i<n;i++){
		rem[i]=b[i];
		}
	while(1){
		flag=1;
		for(i=0;i<n;i++){
			if(rem[i]>0){
				flag=0;
				if(rem[i]>tq){
					t+=tq;
					rem[i]-=tq;
					}
				else{
					t+=rem[i];
					wt[i]=t-b[i];
					rem[i]=0;
					}
				}
			}
			if(flag==1){break;}
		}puts("reached");
	for(i=0;i<n;i++){
		tat[i]=b[i]+wt[i];
		}
	
	for(i=0;i<n;i++){
		twt+=wt[i];
		ttat+=tat[i];
		}
	
	awt=twt/n;
	atat=ttat/n;
	printf("\n\nAVG Waiting Time is : %f",awt);
	printf("\nAVG TurnAroundTime is : %f",atat);
	puts("\n");
}
