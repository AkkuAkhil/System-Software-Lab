#include<stdlib.h>
#include<string.h>
#include<stdio.h>
int i=0;
struct{
	char dname[10],fname[10][10];
	int fc;
}dir;

void create(){
	puts("Enter the filename");
	scanf("%s",dir.fname[dir.fc]);
	dir.fc++;
	printf("\n%d is the value of filecounter\n\n",dir.fc);
}

void delete(){
	int y;
	y=(search())-1;
	if(y!=-1){
		printf("\nFound at Position %d\n",y);
		printf("\nDeleted %s\n",dir.fname[y]);
		strcpy(dir.fname[y],dir.fname[dir.fc-1]);
		--dir.fc;
	}
	else{
		printf("\nNot Found\n");
	}
	
}


int search(){
	int x=0,i=0;
	char tmp[20];
	puts("Enter the filename to search");
	scanf("%s",&tmp);
	printf("%s\n%s",dir.fname[0],tmp);
	for(i=0;i<dir.fc;i++){
		if(strcmp(tmp,dir.fname[i])==0){
			x=i+1;
		}
	}
	if(x!=0){
		return x;
	}
	else{
		return -1;
	}
}

void display(){
	puts("\n\tFiles in the directory :");
	for(i=0;i<dir.fc;i++){
		printf("\t%s\n",dir.fname[i]);
	}
}

void main(){
	system("clear");
	int ch,z;
	puts("Enter directory name: ");
	scanf("%s",dir.dname);
	dir.fc=0;
	while(1){
		puts("Enter Your Choice\n1:CREATE\n2:DELETE\n3:SEARCH\n4:DISPLAY\n5:EXIT\n");
		scanf("%d",&ch);
		switch(ch){
			case 1:create();break;
			case 2:delete();break;
			case 3:z=(search());
				if(z!=-1){
					printf("\nFound at Position %d\n",z);break;
				}else{
					printf("\nNot Found\n");break;}
			case 4:display();break;
			default:exit(0);break;
		}
	}
}
