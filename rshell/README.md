# RSHELL CS100
A simple shell program created for CS100: Software Construction at University of California, Riverside.

-------------------------------------------------
##Introduction 
-------------------------------------------------

This program is a basic shell implemented that functions as a terminal. It will take commands from the user and implement the commands for the user. The program first prints a command prompt and then the user is allowed to type in their command at any time. The program will read the command on one line and then execute it.
All of the code is written in C++. 

------------------------------------------------
##Functionality
-----------------------------------------------
The program is able to handle any kind of commands. For example some of the commans include:

     ls -a

     echo hello world 

     pwd

     cal

     date

cd <directory>

Some complex commands that the program can hold are examples of input/output redirection and piping.
For example:

     ls -l | grep Makefile
     
     sort < Makefile > output.txt

-----------------------
##Bugs/ Limitations
-----------------------
Inside the program, there is a limitation with the parentheses. The code will only work by the following (echo this && echo that && echo this). It will take any code in the parentheses but it will not work if there are two different groups like the following: (echo this && echo that) || (echo this && echo that). The group has to be together for the code for parentheses to work correctly.

When using ls command, it will display the correct files and directories but it will not display their distinct colors.

---------------------
##How to Build
---------------------
```
     $ git clone https://github.com/fmuno003/rshell.git
     $ cd rshell
     $ git checkout hw4
     $ make
     $ bin/rshell
```
