#include<stdlib.h>
#include<string.h>
#include<stdio.h>
int i=0,dc=0;
struct{
	char dname[10],fname[10][10];
	int fc;
}dir[10];

void create(){
	int j=sub();
	puts("Enter the filename");
	scanf("%s",dir[j].fname[dir[j].fc]);
	dir[j].fc++;
	printf("\n%d is the value of filecounter\n\n",dir[j].fc);
}

void created(){
	int j=sub();
	puts("Enter the directory name");
	scanf("%s",dir[j].dname);
	++dc;
}

void deleted(){
	int j=sub();
	--dc;
}

void delete(){
	int y;
	int j=sub();
	y=(search())-1;
	if(y!=-1){
		printf("\nFound at Position %d\n",y);
		printf("\nDeleted %s\n",dir[j].fname[y]);
		strcpy(dir[j].fname[y],dir[j].fname[dir[j].fc-1]);
		--dir[j].fc;
	}
	else{
		printf("\nNot Found\n");
	}
	
}


int search(){
	int j=sub();
	int x=0,i=0;
	char tmp[20];
	puts("Enter the filename to search");
	scanf("%s",&tmp);
	printf("%s\n%s",dir[j].fname[0],tmp);
	for(i=0;i<dir[j].fc;i++){
		if(strcmp(tmp,dir[j].fname[i])==0){
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
	int j;
	for(j=1;j<=dc;j++){
		printf("\n\tFiles in the %d directory :",j);
		for(i=0;i<dir[j].fc;i++){
			printf("\t%s\n",dir[j].fname[i]);
		}
	}
}

int sub(){
	puts("\n\tENter File directory No:");
	int j;
	scanf("%d",&j);
	return j;
}

void main(){
	system("clear");
	int ch,z;
	while(1){
		puts("\nEnter Your Choice\n1:CREATE D\n2:DELETE D\n3:CREATE\n4:DELETE\n5:SEARCH\n6:DISPLAY\n7:EXIT\n");
		scanf("%d",&ch);
		switch(ch){
			case 1:created();break;
			case 2:deleted();break;
			case 3:create();break;
			case 4:delete();break;
			case 5:z=(search());
				if(z!=-1){
					printf("\nFound at Position %d\n",z);break;
				}else{
					printf("\nNot Found\n");break;}
			case 6:display();break;
			default:exit(0);break;
		}
	}
}
