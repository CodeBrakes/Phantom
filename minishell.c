
// ########################## START OF LIBRARIES SECTION ########################

#include	<stdio.h>
#include	<stdlib.h>
#include	<sys/types.h>
#include	<sys/wait.h>
#include	<string.h>
#include <libgen.h>
#include	<unistd.h>
#include 	<termios.h>
#include	"minishell.h"
// ########################## END OF LIBRARIES SECTION ########################


// ########################## START OF STRUCTS SECTION ########################

ssize_t	my_getpass (char *[], size_t *, FILE *);

int main_shell_1();

int main_shell_2();

int main_shell_3();

void printPrompt(char *);		

void readCommand(char *);	 

int parseCommand(char *, struct command_t *);

char *lookupPath(char **, char **);

int parsePath(char **, char *);


// ########################## END OF STRUCTS SECTION ########################


// ########################## START OF PROGRAM SECTION ########################

int main(){

	main_shell_1();
	
	return 0;
}

int main_shell_1() {

	while(TRUE){

    	char var[10], var2[10];
    	int a, flag=0;
    	size_t n;

		if(flag != TRUE){
				
			char usernm[14], *pass=malloc(6), c;
	
			printf("\n\n\n########################### AUTHORIZED ACCESS #############################\n");
    		printf("\n\nType username for privileged user:\t");
    		scanf("%s", usernm);
    		getchar();
  			
  		if( strcmp(usernm, username1) == 0 ){
    			
    		printf("\n\nType privileged user password:\t");
    		a=my_getpass(&pass, &n, stdin);
    		pass[a-1]='\0';
   					
    		if( strcmp(pass, password2) == 0 ){
    			flag=1;
    			printf("\n\nValidation is completed...\n\n");
    			sleep(2);
    			break;
    		}
    	}
	
    		free(pass);
		}

		printf("\n\nWrong user configure username or password\nTry again...\n");
		sleep(2);
	}



    char commandLine[LINE_LEN], *pathv[MAX_PATHS];
    
    int numPaths, len, chPID, stat; 
    
    int i, j;


    pid_t thisChPID;
    
    struct command_t command;


    for(i=0; i<MAX_ARGS; i++){
        command.argv[i] = (char *) malloc(MAX_ARG_LEN);
    }

    parsePath(pathv, "Shell_1");

    while(TRUE) {
       
        // Prompt shell_3-(config mode) #
        printPrompt("shell_1-(user mode) >");

        // Synarthsh pou diavazei ti exei grapsei o xrhsths. 
        // Diavazei thn entolh kai thn apothikevei sto commandLine
        readCommand(commandLine);
        
        // An o xrhsths gapsei exit h quit tote
        if( (strcmp(commandLine, "exit") == 0) || (strcmp(commandLine, "quit") == 0) ){

            break;	//termatise to shell
        } 
        else if(strcmp(commandLine, "priv_user") == 0){
        	main_shell_2();
        	
        }
        else{


	        // Epeksergazetai thn entolh pou edwse o xrhsths. Diavazei to commandLine kai to apothikevei sthn domh command
	        parseCommand(commandLine, &command);

	        // 
	        command.name  = lookupPath(command.argv, pathv);

	        if(command.name == NULL) {
	            fprintf(stderr, "Command %s not found\n", command.argv[0]);
	            continue;
	        }

	        if((chPID = fork()) == 0) {

	            #ifdef DEBUG
	                for(i=1; i<command.argc; i++)
		                printf("argv[%d] = %s\n", i,  command.argv[i]);
	            #endif

	            execv(command.name, command.argv);
	        }

	        thisChPID = wait(&stat);
    	}
	}
}

int main_shell_2() {

	while(TRUE){

    	char var[10], var2[10];
    	int a, flag=0;
    	size_t n;

		if(flag != TRUE){
				
			char usernm[14], *pass=malloc(6), c;
	
			printf("\n\n\n########################### AUTHORIZED ACCESS #############################\n");
    		printf("\n\nType username for privileged user:\t");
    		scanf("%s", usernm);
    		getchar();
  			
  		if( strcmp(usernm, username2) == 0 ){
    			
    		printf("\n\nType privileged user password:\t");
    		a=my_getpass(&pass, &n, stdin);
    		pass[a-1]='\0';
   					
    		if( strcmp(pass, password2) == 0 ){
    			flag=1;
    			printf("\n\nValidation is completed...\n\n");
    			sleep(2);
    			break;
    		}
    	}
	
    		free(pass);
		}

		printf("\n\nWrong user configure username or password\nTry again...\n");
		sleep(2);
	}



    char commandLine[LINE_LEN], *pathv[MAX_PATHS];
    
    int numPaths, len, chPID, stat; 
    
    int i, j;


    pid_t thisChPID;
    
    struct command_t command;


    for(i=0; i<MAX_ARGS; i++){
        command.argv[i] = (char *) malloc(MAX_ARG_LEN);
    }


    parsePath(pathv, "Shell_2");

    while(TRUE) {
       
        // Prompt shell_3-(config mode) #
        printPrompt("shell_2-(privileged mode) #");

        // Synarthsh pou diavazei ti exei grapsei o xrhsths. 
        // Diavazei thn entolh kai thn apothikevei sto commandLine
        readCommand(commandLine);
        
        // An o xrhsths gapsei exit h quit tote
        if( (strcmp(commandLine, "exit") == 0) || (strcmp(commandLine, "quit") == 0) ){
        	break;
        }

        else if(strcmp(commandLine, "config") == 0){
        	main_shell_3();
        	
        }
        else{

	        // Epeksergazetai thn entolh pou edwse o xrhsths. Diavazei to commandLine kai to apothikevei sthn domh command
	        parseCommand(commandLine, &command);

	        // 
	        command.name  = lookupPath(command.argv, pathv);

	        if(command.name == NULL) 
	        {
	            fprintf(stderr, "Command %s not found\n", command.argv[0]);
	            continue;
	        }

	        if((chPID = fork()) == 0) {

	            #ifdef DEBUG
	                for(i=1; i<command.argc; i++)
		                printf("argv[%d] = %s\n", i,  command.argv[i]);
	            #endif

	            execv(command.name, command.argv);
	        }

	        thisChPID = wait(&stat);
	    }
	}
}

int main_shell_3() {

	while(TRUE){

    	char var[10], var2[10];
    	int a, flag=0;
    	size_t n;

		if(flag != TRUE){
				
			char usernm[14], *pass=malloc(6), c;
	
			printf("\n\n\n########################### AUTHORIZED ACCESS #############################\n");
    		printf("\n\nType username for privileged user:\t");
    		scanf("%s", usernm);
    		getchar();
  			
  		if( strcmp(usernm, username3) == 0 ){
    			
    		printf("\n\nType privileged user password:\t");
    		a=my_getpass(&pass, &n, stdin);
    		pass[a-1]='\0';
   					
    		if( strcmp(pass, password3) == 0 ){
    			flag=1;
    			printf("\n\nValidation is completed...\n\n");
    			sleep(2);
    			break;
    		}
    	}
	
    		free(pass);
		}

		printf("\n\nWrong user configure username or password\nTry again...\n");
		sleep(2);
	}



    char commandLine[LINE_LEN], *pathv[MAX_PATHS];
    
    int numPaths, len, chPID, stat; 
    
    int i, j;


    pid_t thisChPID;
    
    struct command_t command;


    for(i=0; i<MAX_ARGS; i++){
        command.argv[i] = (char *) malloc(MAX_ARG_LEN);
    }


    parsePath(pathv, "Shell_3");

    while(TRUE) {
       
        // Prompt shell_3-(config mode) #
        printPrompt("shell_3-(config mode) #");

        // Synarthsh pou diavazei ti exei grapsei o xrhsths. 
        // Diavazei thn entolh kai thn apothikevei sto commandLine
        readCommand(commandLine);
        
        // An o xrhsths gapsei exit h quit tote
        if( (strcmp(commandLine, "exit") == 0) || (strcmp(commandLine, "quit") == 0) ){

            break;
        }

        // Epeksergazetai thn entolh pou edwse o xrhsths. Diavazei to commandLine kai to apothikevei sthn domh command
        parseCommand(commandLine, &command);

        // 
        command.name  = lookupPath(command.argv, pathv);

        if(command.name == NULL) 
        {
            fprintf(stderr, "Command %s not found\n", command.argv[0]);
            continue;
        }

        if((chPID = fork()) == 0) {

            #ifdef DEBUG
                for(i=1; i<command.argc; i++)
	                printf("argv[%d] = %s\n", i,  command.argv[i]);
            #endif

            execv(command.name, command.argv);
        }

        thisChPID = wait(&stat);
    }
}

// ########################## END OF PROGRAM SECTION ########################


ssize_t	my_getpass (char *lineptr[], size_t *n, FILE *stream){

	struct termios old, new;
	int nread;

 	 if (tcgetattr (fileno (stream), &old) != 0)
    	return -1;
 	
 	new = old;
	new.c_lflag &= ~ECHO;
	
	if (tcsetattr (fileno (stream), TCSAFLUSH, &new) != 0)
    return -1;

  	nread = getline (lineptr, n, stream);
  	(void) tcsetattr (fileno (stream), TCSAFLUSH, &old);

  	return nread;
}

// ########################## START OF FUNCTIONS SECTION ########################


void printPrompt(char *a) {

	char *promptString=a;

    printf("\n");
    printf("%s ", promptString);
}

void readCommand(char *buffer) {
 
    fgets(buffer, LINE_LEN, stdin);

    buffer[strlen(buffer)-1] = '\0';

    printf("\n");
}

int parseCommand(char *cLine, struct command_t *cmd) {
    
    int argc, i, j;
    char **clPtr;

    clPtr = &cLine; // To cLine einai mia metavlith pou p
    argc = 0;

    while((cmd->argv[argc++] = strsep(clPtr, WHITESPACE)) != NULL) ;

    cmd->argv[argc--] = '\0';	
    cmd->argc = argc;
    if (cmd->argc > 0){
    	cmd->argv[0] = basename(cmd->argv[0]);
    }
    return  1;	
}

char *lookupPath(char **argv, char **dir) {

    int i;
    char *result, pName[MAX_PATH_LEN];

    if(*argv[0] == '/') {
        
        result = (char *) malloc(strlen(argv[0])+1);
        strcpy(result, argv[0]);
        return result;
    
    }

    for(i = 0; i < MAX_PATHS; i++) {

        if(dir[i] == NULL) break;
        strcpy(pName, dir[i]);
        strcat(pName, "/");
        strcat(pName, argv[0]);

        if(access(pName, X_OK | F_OK) != -1) {

            result = (char *) malloc(strlen(pName)+1);
            strcpy(result, pName);
            return result;		

        }
    
    }
    
    fprintf(stderr, "%s: command not found\n", argv[0]);
    return NULL;
}

int parsePath(char *dirs[], char *shell) {

    int i;
    char pathEnvVar[30];
    register char *thePath, *oldp;

    for(i=0; i<MAX_ARGS; i++)
	
    dirs[i] = NULL;
	
	sprintf(pathEnvVar, "./shell_commands/%s", shell);
	
    thePath = (char *) malloc(strlen(pathEnvVar) + 1);
    strcpy(thePath, pathEnvVar);

    i = 0;
    oldp = thePath;

    for(;; thePath++) {
	   
       if( (*thePath == ':') || (*thePath == '\0') ) {
            
            dirs[i] = oldp;
            i++;

            if(*thePath == '\0'){
                break;
            } 
                
            *thePath = '\0';
            oldp = thePath + 1;
        }

    }

}


// ########################## END OF FUNCTIONS SECTION ########################