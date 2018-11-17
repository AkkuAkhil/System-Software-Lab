#include<stdio.h>
#include<stdlib.h>

void main(){
	system("clear");
	int n,m,i,j,c1=0,c2=0,k=0;
	puts("Enter the number of processes");
	scanf("%d",&n);
	puts("Enter the number of resources");
	scanf("%d",&m);
	int avail[m],finish[m],total[m],inst[m];
	int max[n][m],need[n][m],allot[n][m];
	//initialize process finished as false
	for(i=0;i<n;i++){
		finish[i]=0;
	}
	//recieve max
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			printf("Enter %d's maximum resource: ",i);
			scanf("%d",&max[i][j]);
		}
	}
	
	
	puts("");//recieve alloted
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			printf("Enter %d's allotted resource: ",i);
			scanf("%d",&allot[i][j]);
		}
	}puts("");//recieve cpu total instance resources
	for(i=0;i<m;i++){
		printf("Enter %d's total instance resource: ",i);
		scanf("%d",&total[i]);
	}puts("");//calculating need
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			need[i][j]=max[i][j]-allot[i][j];
		}
	}//calculate the available
	for(i=0;i<n;i++){
		inst[i]=0;
	}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			inst[i]=inst[i]+allot[j][i];
		}
	}
	for(i=0;i<m;i++){
		avail[i]=total[i]-inst[i];
	}
	
	

	
	
	
	//the safe sequence checking
	while(c1!=n){
		c2=c1;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(need[i][j]<=avail[j]){
					k++;
				}
			}
			if(k==n && finish[i]==0){
				printf("P[%d]",i);
				finish[i]=1;
				for(j=0;j<n;j++){
					avail[j]+=allot[i][j];
				}
				c1++;
			}k=0;
		}
		if(c1==c2){
			printf("\nDEADLOCK\n");
			break;
		}
	}
	
	//printing maximum
	printf("\nMAX\t\t\tALLOTED\t\t\tNEED\n");
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			printf("%d \t",max[i][j]);
		}
		for(j=0;j<m;j++){
			printf("%d \t",allot[i][j]);
		}
		for(j=0;j<m;j++){
			printf("%d \t",need[i][j]);
		}
		puts("");
	}//printing available
	puts("\navailable resources");
	for(i=0;i<n;i++){
		printf("%d \t",avail[i]);
	}
	
puts("");}
