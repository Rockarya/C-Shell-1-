int cd_command(char ** str,char * Parentdirectory)
{
	char *curdirectory=NULL;
	curdirectory=(char *)malloc(1000*sizeof(char));
	curdirectory=getcwd(curdirectory,1000*sizeof(char));

	if(str[1]==NULL || strcmp(str[1],"~")==0)
	{
		return chdir(Parentdirectory);
	}
	else
	{
		if(strcmp(Parentdirectory,curdirectory)==0 && strcmp(str[1],"..")==0)
		{
			printf("%s\n",curdirectory);
		}
		else
		{
			return chdir(str[1]);
		}
	}
}
