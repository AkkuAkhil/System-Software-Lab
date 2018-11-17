#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int n=200;

void fcfs(int noq,int st,int qu[noq]){
	int s=0,i;
	printf("%d",st);
	for(i=0;i<noq;i++) {
		s+=abs(st-qu[i]);
		st=qu[i];
		printf(" => %d",st);
	}
	printf("\n\nTotal seek time = %d\n",s);
	float a=s/noq;
	printf("\n\n AVG seek time : %f\n",a);
}

void scan(int noq,int st,int qu[noq]){
	int i,j,s=0,temp=st,c=0;
	printf("%d",st);
	s+=st+(qu[noq-1]-0);
	for(i=0;i<noq;i++) {
		if(st < qu[i]) {
			for(j=i-1; j>= 0;j--) {
				st = qu[j];
				printf(" => %d",st);
				}printf(" => 0");
			c=i;
  			break;
  		}
  	}
	st=temp;
	for(i=0;i<noq;i++) {
		if(st > qu[i]) {
			for(j=c; j<noq;j++) {
				st = qu[j];
				printf(" => %d",st);
				}
			break;
		}
	}
	printf("\n\n Total seek time : %d\n",s);	
	float a=s/noq;
	printf("\n\n AVG seek time : %f\n",a);
}

void cscan(int noq,int st,int qu[noq]){
	int i,j,s=0,temp=st,c=0;
	printf("%d",st);
	s+=(st-0);
	for(i=0;i<noq;i++) {
		if(st < qu[i]) {
			for(j=i-1; j>= 0;j--) {
				st = qu[j];
				printf(" => %d",st);
				}printf(" => 0 => 199");
			for(j=noq-1; j>2;j--) {
				st = qu[j];
				printf(" => %d",st);
				}
			s+=((n-1)-st);
			break;
		}
	}
	printf("\n\n Total seek time : %d\n",s);
	float a=s/noq;
	printf("\n\n AVG seek time : %f\n",a);
}

void main() {
	system("clear");
	int noq,qu[8],i,j,st,ch,t;
	/*noq=8;
	qu[0]=95;qu[1]=180;qu[2]=34;qu[3]=119;qu[4]=11;
	qu[5]=123;qu[6]=62;qu[7]=64;
	st=50;*/
	puts("Enter no of process");scanf("%d",&noq);
	puts("Enter each process");
	for(i=0;i<noq;i++) {
		scanf("%d",&qu[i]);
	}
	puts("Enter the head position");scanf("%d",&st);
	while(1){ 
		puts("\n----------------------------------------");
		puts("1.FCFS\n2.SCAN\n3.C-SCAN\n4:EXIT");
		printf("Enter the operation :");
		scanf("%d",&ch);
		if(ch >= 2) {
			for(i=0;i<noq;i++)
				for(j=i+1;j<noq;j++)
					if(qu[i]>qu[j]) {
						t=qu[i];
						qu[i] = qu[j];
						qu[j] = t;
					}
		}
		switch(ch){
			case 1:puts("FCFS\n");fcfs(noq,st,qu);break;
			case 2:puts("SCAN\n");scan(noq,st,qu);break;
			case 3:puts("C-SCAN\n");cscan(noq,st,qu);break;
			case 4:exit(0);
		}
	}
}

