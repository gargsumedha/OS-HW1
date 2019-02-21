/* 
 *  Name:Sumedha Garg
 *  Login: SP_19_CPS536_13
 *  Purpose: HomeWork 2
 *  **** Add anything else relevant here ****
 *  Bug report:Counter Getting reset as each process makes a different copy of it
 */
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#define range 50000

int i=2;

	
int create(int n) 
{
	int value = 0,cp,status=0,flag,odd=0,even=0;	
	if (n == 0)
	{ 
		return 0;
	}
    	int pid = fork(); 
    	if (pid == -1) { // failure to create child
		fprintf(stderr,"failure to create child\n");
        	exit(0);
    	}
	
    	if (pid==0) { //child process creation
		
		srand(getpid());
		value=rand()% range;
	        fprintf(stderr,"myid: %d pid :%d ppid: %d value: %d\n",i++, getpid(), getppid(),value );
        	n = n-1;
       	 	create(n);
		if(value % 2==0){

			exit(1);
		}
		else{
		
			exit(0);
		}
		
		
	    }
	    else { //Passing the random value of child in parent process
		i--;
		while((cp=wait(&status))>0){	

			if(WIFEXITED(status)) {
				if(WEXITSTATUS(status))
					 even+=1;
				else
					odd+=1;  
				fprintf(stderr,"myid= %d recieves #odd= %d #even = %d\n",i--,odd,even);
			} 
			else
				fprintf(stderr, "Abnormal exit of child. \n");
		}
	}
 	return 0;   
  
}

int main(int argc,char * argv[]){

	int n=0,value;
	int even=0,odd=0;

	if(argc !=2) {
        	fprintf(stderr,"Usage %s <nprocs>\n ", argv[0]);
        	exit(1);
    	}

	n = atoi(argv[1]); 
	srand(getpid());
	value=rand()% range;
	fprintf(stderr,"myid: 1 pid :%d ppid: %d value: %d\n", getpid(), getppid(),value ); // Displaying the main process
	n-=1;
	create(n);
	
	return 0;
}


