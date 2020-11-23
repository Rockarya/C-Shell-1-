#include<stdio.h>
#include "header.h"
typedef long long int ll;

int main()
{
	//This is just to get the Parent directory i am in
	char *Parentdirectory=NULL;
	Parentdirectory=(char *)malloc(1000*sizeof(char));
	Parentdirectory=getcwd(Parentdirectory,1000*sizeof(char));

	ll i,j,f,flag,fo,pid;
	char **string=NULL;
	string=(char **)malloc(1000*sizeof(char));
	while(1)
	{
		type_prompt(Parentdirectory);
		char *buffer=NULL;
		size_t bufsize=1005;			//It’s an unsigned integral type which is used to represent the size of objects in bytes
		buffer=(char *)malloc(bufsize*sizeof(char));
		if(buffer==NULL)
		{
			perror("Unable to allocate buffer\n");
			exit(1);
		}
		getline(&buffer,&bufsize,stdin);
		char **s=NULL;
		s=(char **)malloc(100*sizeof(char));
		for(i=0;i<100;i++)
		{
			s[i]=(char *)malloc(100*sizeof(char));
		}
		s=read_command(buffer);
		
		i=0;
		//implementing built-in commands and system calls
		while(s[i]!=NULL)
		{
			string=history(string,s[i]);				//To get the history of commands
			char *token=NULL,**str=NULL;
			str=(char **)malloc(100*sizeof(char));
			token=(char *)malloc(100*sizeof(char));
			token=strtok(s[i]," \t");		//By writing " \t" delimiter it will tokenize with both space bar and tab

			j=0,flag=0;
			while(token!=NULL)
			{
				str[j]=(char *)malloc(100*sizeof(char));
				strcpy(str[j],token);
				j++;
				token=strtok(NULL," \t");
			}
			str[j]=NULL;
			if(strcmp(str[j-1],"&")==0)
			{
				str[j-1]=NULL;			//if flag==1 then last command is & so equate it to NULL so that it won't be considered as parameter
				flag=1;					//to determine process is foreground or background
			}

			f=fork();			//This is just meant to run foreground and background process
			if(f>0)
			{
				if(flag==1)
				{
								//if we are running background process then we do not have to wait for it to get finish
				}
				else
				{
					wait(NULL);		//We have to wait until foreground process completes and returns to us
				}
			}
			else if(f==0)
			{
				pid=getpid();
				if(flag==1)
				{
					printf("%s with pid %lld created succesfully\n",str[0],pid);			//To get acknowledgement that Background process is created
				}

				if(strcmp(str[0],"cd")==0)
				{
					if(cd_command(str,Parentdirectory)<0)
					{
						printf("%s : Command not found\n",str[0]);
					}
				}
				else if(strcmp(str[0],"echo")==0)
				{
					echo_command(str);
				}
				else if(strcmp(str[0],"pwd")==0)			
				{
					pwd_command(Parentdirectory);
				}
				else if(strcmp(str[0],"ls")==0)
				{
					
					if(!ls(str,Parentdirectory))
					{
						printf("%s : Command not found\n",str[0]);
					}
				}
				else if(strcmp(str[0],"pinfo")==0)
				{
					if(!pinfo_command(str))
					{
						printf("File doesn't exists\n");
					}
				}
				else if(strcmp(str[0],"history")==0)
				{
					if(!history_command(string,str))
					{
						printf("Invalid command\n");
					}
				}
				else
				{
					fo=fork();
					if(fo==0)
					{
						execvp_command(str);
					}
					else if(fo>0)
					{
						wait(NULL);
					}
					else
					{
						perror("No child is created\n");
					}
				}
				if(flag==1)
				{
					printf("%s with pid %lld exited normally\n",str[0],pid);		//To get the status of the completion of the background process.
					exit(0);													//It will enter here only when it will get complete
				}
			}
			else
			{
				perror("Child not created\n");
			}
			i++;
		}
	}
	return 0;
}
