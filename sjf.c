#include<stdio.h>
#include<stdlib.h>
void main() {
	system("clear");
	int n,i,j,wt=0,tat=0,temp;
	float awt=0,atat=0;
	puts("\nEnter the no of processes");
	scanf("%d",&n);
	int p[n],b[n];
//INPUT OPERATION
	for(i=0;i<n;i++){
		printf("Enter %d process     : ",i+1);
		scanf("%d",&p[i]);
		}puts("");
	for(i=0;i<n;i++){
		printf("Enter %d processs BT : ",i+1);
		scanf("%d",&b[i]);
		}puts("");
		
	printf("\nPID\tB.T");
	printf("\n-----------\n");
	for(i=0;i<n;i++){	
		printf("\n%d\t%d",p[i],b[i]);
		}puts("");
	
//SORTING BASED ON BT
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(b[i]<b[j]){
				temp=p[i];
				p[i]=p[j];
				p[j]=temp;
				temp=b[i];
				b[i]=b[j];
				b[j]=temp;
				}
			}
		}
//PRINTING VALUES
	printf("\nPROCESS INFORMATIONS");
	printf("\n-------------------------------------\n");
	printf("PID\tB.T\tT.A.T\tW.T");
	printf("\n-------------------------------------");
	for(i=0;i<n;i++){
		tat=tat+b[i];	
		printf("\n%d\t%d\t%d\t%d\t",p[i],b[i],tat,wt);
		awt+=wt;
		atat+=tat;
		wt=tat;
		}
	awt=awt/n;
	atat=atat/n;
	printf("\n\nAVG Waiting Time is : %f",awt);
	printf("\nAVG TurnAroundTime is : %f",atat);
	puts("\n");
}
