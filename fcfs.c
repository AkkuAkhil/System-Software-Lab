#include<stdio.h>
#include<stdlib.h>
void main() {
	system("clear");
	int n,i,wt=0,tat=0;
	float awt=0,atat=0;
	puts("\nEnter the no of processes");
	scanf("%d",&n);
	int p[n],b[n],a[n];
	for(i=0;i<n;i++){
		printf("Enter %d process     : ",i+1);
		scanf("%d",&p[i]);
		}puts("");
	for(i=0;i<n;i++){
		printf("Enter %d processs AT : ",i+1);
		scanf("%d",&a[i]);
		}puts("");
	for(i=0;i<n;i++){
		printf("Enter %d processs BT : ",i+1);
		scanf("%d",&b[i]);
		}puts("");
	printf("PROCESS INFORMATIONS\n");
	printf("\n-------------------------------------\n");
	printf("\nPID\tA.T\tB.T\tT.A.T\tW.T");
	printf("\n-------------------------------------\n");
	tat=a[0];
	wt=a[0];
	for(i=0;i<n;i++){
		tat=tat+b[i];	
		printf("\n%d\t%d\t%d\t%d\t%d\t",p[i],a[i],b[i],tat,wt);
		awt+=wt;
		atat+=tat;
		wt=tat-a[i+1];
		}
	awt=awt/n;
	atat=atat/n;
	printf("\n\nAVG Waiting Time is : %f",awt);
	printf("\nAVG TurnAroundTime is : %f",atat);
	puts("\n");
}
