# Phantom
This secure shell is based on cisco IOS philosophy. There are three layers each layer is connected to each other and execute a set of restricted linux commands. Shell 1 executes simple user commands. Shell 2 executes privileged linux commands. Shell 3 executes admin commands. There is full documentation inside the .zip file about the commands that each secure shell executes.

Instructions

In a linux distribution install gcc compiler to compile the program. 

minishell.c is the main c program 

minishell.h contains usernames and password for each shell you can also change them to whatever you want.

The folder shell_commands contain shortcuts for each linux command. To create command shortcuts in linux
simply enter the command ln -s "path of the command" "name of shortcut" in the coresponding folder.
Let's see an example

	1. 	ls -s /bin/ls ls
	2.	sudo chmod a+wrx ls
	3.	paste shortcut on the coresponding shell folder e.g. Shell_1

Each layer is connected to each other. To get access in shell 2 you have to be logged in shell 1.
While in shell 1 type shell2 and afterwards the password 123. The same proceedure will be followed 
for shell 3. While on shell 2 type the command shell3 and the password 123. To exit in a shell type
the command exit. This command will direct you to the previous shell.
In the Documentation folder you will find a list with all the available commands in each shell. 
