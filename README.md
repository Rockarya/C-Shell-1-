1) How to execute my code:-
		To compile and execute the code enter in the terminal:	 ./makefile    (In makefile i have written the terminal command "gcc main.c && ./a.out")

2) Features:-
		->Implemeted history command.
		->Implemented a shell that supports a semi-colon separated list of commands.
		->Supported '&' operator which lets a program run in the background after printing the process id of the newly created process.
		
3) Error handling:-
		Used perror and printf statements for handling errors wherever i feel necessary.For the commands executed by execvp we don't know about it's success so no
		error handling for those commands. 

4) Shell loop in main.c file:-
		Tokenizing the inputted string of prompt and running each command step by step.Each of the commands are implemented as per the specificaition given in Assignment pdf.

5) cd functionality:-
		Implemented cd along with the flags ".","..","tilda" using chdir system call.

6) pwd functionality:-
		Implemented it using getcwd system call.

7) echo functionality:-
		Just tokenized command by space and tab and then outputted all the tokens by keeping a space in between.

8) ls functionality:-
		Implemented ls, ls -l, ls ., ls .., ls tilda, ls -a, ls -al/la and ls <Directoryname>.
		Also their valid combinations.

9) history functionality:-
		Stroring 20 commands in a 2D string and replacing them sequentially with the new ones.Throwing error for invalid commands

10) For system commands except the above specified:-
		I have used execvp system call to implement them.

11) Foreground and Background process:-
		Used forking for this purpose and if process is foreground then we will wait until it finishes it's execution and prints it's output to the terminal
		and if it's background then we won't wait for it and continue further to take user commands.

12) pinfo:-
		got pid using getpid() system call. 
		Opened /proc/pid/status file to get info about Process Status,Virtual memory,pid(already known).
		For getting executable path of file i have used readlink system call.(In this, filename will be /proc/pid/exe).The value returned will be the name of the executable path.  

13) Finished Background Process:-
		When background process gets over then i have wrote a printf statement in code to get acknowledgement about accomplishment of background process.
		A flag was raised to identify whether process is going to be foreground or background(by checking '&' character in the command line)

14) Read Command :-
		Used strtok to tokenize the command.
		In the case of tokenizing command from semi-colon i have used ";" as delimiter whereas in the case where we have to tokenize from spaces and tabs i have used " \t" as delimiter.(By using this delimiter it tokenizes string from both spaces and tabs in one go)

15) Inlcuded a header.h file which contains all the required headers.













  
