/* 
 *  Name: Sumedha Garg
 *  Login:
 *  Purpose:
 *  **** Add anything else relevant here ****
 *  Bug report: No bugs, and all the features have been implemented
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define bs 1000  
int main(int argc, char *argv[]){

	FILE *fp;
	int n = 0, i = 0,index = 0;
	char s[bs], oldword[100], nw[100], *pos,temp[bs];

	// case insensitive if loop 
	if(strcmp(argv[1],"-i") == 0 )
	{
		if(argc !=4) {
                fprintf(stderr,"Usage %s [-i] <file-name> <pattern>\n ", argv[0]);
               	exit(1);
        	}

	        fp = fopen(argv[2] , "r");
		
        	if(fp == NULL){
       	        	fprintf(stderr,"error opening data file\n");
        	        exit(1);
	        }

	        n = strlen(argv[3]); //length of pattern
      	
		  	for(i=0;i < n;i++)
               		nw[i] = '*'; //creating new word
	        
			while(fgets(s,bs,fp) != NULL){  //reading from the file 
		
				while((pos = strcasestr(s,argv[3])) != NULL) { 
					//replacing the oldword to newword
					strcpy(temp,s );
                    index = pos - s;
                    s[index]='\0';
                    strcat(s,nw);
                	strcat(s,temp+index+n);
               	}
                printf("%s",s); //reflecting the changes to the standard output

		}
	}
	// checking for the right command in case insensitive invocation
	else if(strcmp(argv[1],"-i") != 0 && argc == 4) {
		fprintf(stderr,"Usage %s [-i] <file-name> <pattern>\n ", argv[0]);
        exit(1);
	}
	// case sensitive pattern matching
	else if(argc == 3) {

		fp = fopen(argv[1] , "r");
	
		if(fp == NULL){
			fprintf(stderr,"error opening data file\n");
			exit(1);		
		}

		n= strlen(argv[2]); //length of pattern 
		
		for(i=0;i < n;i++)
			nw[i] = '*';
		
		while(fgets(s,bs,fp) != NULL){ //reading from the file
			 
			while((pos = strstr(s,argv[2])) != NULL) {
		
				//replacing the oldword to newword
				strcpy(temp,s );
				index = pos - s;
				s[index]='\0';
				strcat(s,nw);
				strcat(s,temp+index+n);
			}
			printf("%s",s);	//reflecting the changes to the standard output
		}
	}

	// checking for correct case sensitive invocation
	else{

		fprintf(stderr,"Usage %s [-i] <file-name> <pattern>\n ", argv[0]);
        exit(1);

	}

	fclose(fp);
	return 0;
	
}
