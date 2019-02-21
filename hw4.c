
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>


int i=2;

	
int func(int n) 
{
	int value = 0,cp,status=0,flag;	
	if (n == 0)
	{ 
		return 0;
	}
    	int pid = fork(); 
    	if (pid == -1) {
        	exit(0);
    	}
	
    	if (pid==0) { 
		
		srand48(pid);
		value=rand()% 50000;
	        printf("myid: %d pid :%d ppid: %d value: %d\n",i++, getpid(), getppid(),value );
        	n = n-1;
       	 	func(n);
		if(value % 2==0){

			exit(1);
		}
		else{
		
			exit(0);
		}
		
	    }
	    else {
		cp=wait(&status);	  
		printf("myid= %d recieves #odd= %d #even = %d\n",i--,0,0);
	    } 

 	   return WEXITSTATUS(status);   
  
}

int main(int *argc,char * argv[]){

	int n=0,value,flag=0;
	int even=0,odd=0;
	if(argc !=2) {
        	fprintf(stderr,"Usage %s <nprocs>\n ", argv[0]);
        	exit(1);
    	}

	n = atoi(argv[1]); 
	srand48(getpid());
	value=rand()% 50000;
	printf("myid: 1 pid :%d ppid: %d value: %d\n", getpid(), getppid(),value );
	n-=1;
	
	flag=func(n);
	if(flag==1){

        		even+=1;
			
		}
		else{
			odd+=1;
			
		}
	printf("\nodd= %d even= %d\n",odd,even);
	
	
	return 0;
}


