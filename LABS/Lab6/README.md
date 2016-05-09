# LAB 6
In this lab we will build upon the composite class that you created in the composite and strategy lab to build a (very) simple calculator application. This calculator will allow the user to do running total calculations (similar to a simple phone calculator) with the additional function of allowing the user to undo and redo commands that they have input. We will accomplish this by leveraging the command pattern to create a history that we can write to, traverse, and overwrite as necessary, and which will save the state of our calculation every time a new operation is requested.

Since this lab relies on a completed composite pattern, you have been provided with an
implementation of the composite pattern that you were to design. You may also use your own
composite classes if you would prefer.

You have also been provided with a main function in calculator.cppthat will deal with user
input and output, and interface that user I/O with the menu class. This menu has the following
commands:

● Exit the Program
    ○ Typing “exit” as a command will exit the program
  
● Undo a Command
    ○ Typing “undo” will go back to the last command, and can be called until there are no more commands to undo
  
● Redo a Command
    ○ Typing “redo” will go forward to the next command, and can be called until there are no more commands to redo

● Do a Calculation
    ○ Do a running calculation. This calculation must start with a single number (ex: 3), and after a single number has been input should take an operator followed by a number (ex: + 10). Note that a space is required between the operator and the number.
