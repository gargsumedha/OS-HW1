#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define bs 1000  
int main(int argc, char *argv[]){

	FILE *fp;
	int n = 0, i = 0,index = 0;
	char s[bs], oldword[100], nw[100], *pos,temp[bs];
	if(strcmp(argv[1],"-1") == 0)
	{
		

}

if(strcmp(argv[1],"-1") == 0)
        {


}

	else{
	if(argc !=3) {
		fprintf(stderr,"Usage %s [-i] <file-name> <pattern>\n ", argv[0]);
		exit(1);
	}

	fp = fopen(argv[2] , "r");

	if(fp == NULL){
		fprintf(stderr,"error opening data file\n");
		exit(1);		
	}
	printf("enter the patter to be matched");
	n = strlen(argv[3]);
	for(i=0;i < n;i++)
		nw[i] = '*';
	while(fgets(s,bs,fp) != NULL){
			 
		while((pos = strstr(s,argv[3])) != NULL) {
			strcpy(temp,s );
			index = pos - s;
			s[index]='\0';
			strcat(s,nw);
			strcat(s,temp+index+n);
		}
		printf("%s",s);	
	}
}
	fclose(fp);
	return 0;

	
}

