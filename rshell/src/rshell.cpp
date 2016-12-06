#include <iostream> // cout and cin
#include <string> 
#include <vector> // vector containers
#include <stack>
#include <algorithm>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <boost/algorithm/string/trim.hpp> // trim function to remove whitespaces on out ends of string
#include <boost/algorithm/string.hpp> // split function to split a string with delimiters

using namespace std; 
using namespace boost;
void splitTwo(string &IO, vector<string> &IOVector, int index) // function to split string into left and right side from the symbol
{
	string tempString;
	tempString = IO.substr(0, index - 1);
	IOVector.push_back(tempString);
}
bool redirection(string left, string right, int flag) // function set by flags depending on type of input or output
{
    mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
    vector<char*> commandStrings;
    vector<string> tempVector;
    trim(left);
    trim(right);
    split(tempVector, left, is_any_of(" "));
    for(unsigned int i = 0; i < tempVector.size(); ++i)
        commandStrings.push_back(const_cast<char*>(tempVector.at(i).c_str()));
    int childStatus = 0;
    pid_t pid = fork();
    if(pid < 0)
    {
        perror("Fork Failed");
        exit(1);
    }
    else if(flag == 1 && pid == 0) // input redirection
    {
        commandStrings.push_back(const_cast<char*>(right.c_str())); // right side of < command
        if(open(right.c_str(), O_RDONLY) < 0) // open file to read only
        {
            perror("Error opening file");
            exit(1);
        }
        if(close(0) == -1) // close stdin
            perror("Error closing file");
        if(dup(open(right.c_str(), O_RDONLY)) < 0) // set file to input
            perror("Error with dup");
        char **command = &commandStrings[0];
        if(execvp(command[0], command) < 0) // execute command
        {
            perror("execvp");
            exit(1);
        }
    }
    else if(flag == 2 && pid == 0) // output redirection with truncation action
    {
        int fd = open(right.c_str(), O_WRONLY|O_CREAT|O_TRUNC, mode); // output redirection and just truncate file
        if(fd < 0)
        {
            perror("Error Opening file: Truncate");
            exit(1);
        }
        if(close(1) < 0)
        {
            perror("Closing File Error");
            exit(1);
        }
        if(dup2(fd, 1) < 0)
        {
            perror("Dup2 Error");
            exit(1);
        }
        if(close(fd) < 0)
        {
            perror("Closing file error");
            exit(1);
        }
        char **command = &commandStrings[0];
        if(execvp(command[0], command) < 0) // execute command and write to file
        {
            perror("execvp");
            exit(1);
        }
    }
    else if(flag == 3 && pid == 0) // output redirection with appending action
    {
        if(open(right.c_str(), O_WRONLY|O_CREAT|O_APPEND, mode) < 0) // output redirection and just append to file
        {
            perror("Error Opening file: Truncate");
            exit(1);
        }
        if(close(1) == -1)
        {
            perror("Closing File Error");
            exit(1);
        }
        if(dup2(open(right.c_str(), O_WRONLY|O_CREAT|O_APPEND, mode), 1) < 0)
        {
            perror("Dup2 Error");
            exit(1);
        }
        char **command = &commandStrings[0];
        if(execvp(command[0], command) < 0) // execute command and append to file
        {
            perror("execvp");
            exit(1);
        }
    }
    else if(pid > 0)
    {
        wait(&childStatus);
        if(wait(&childStatus) != -1) // if waiting for child does not success an error is thrown out
            perror("wait error");
        if(WIFEXITED(childStatus))
        {
            if(WEXITSTATUS(childStatus) != 0) //program ffailed but exited normally
                return false;
            else // program succeeded
                return true; 
        }
        else
        {
            perror("abnormal child exit"); // the child program exited incorrectly, throws out an error
            return false;
        }        
    }
    return true;
}
bool pipeCommand(string left, string right) // pipe command
{
    vector<char*> commandStrings;
    vector<string> tempVector, tempVector2;
    trim(left);
    trim(right);
    split(tempVector, left, is_any_of(" "));
    split(tempVector2, right, is_any_of(" "));
    for(unsigned int i = 0; i < tempVector.size(); ++i)
        commandStrings.push_back(const_cast<char*>(tempVector.at(i).c_str()));
    int fd[2];
    if(pipe(fd) < 0)
    {
        perror("Error with first pipe");
        exit(1);
    }
    pid_t pid = fork();
    if(pid < 0)
    {
        perror("First fork failed");
        exit(1);
    }
    else if(pid == 0)
    {
        if(close(fd[0]) < 0)
        {
            perror("First Close Error");
            exit(1);
        }
        if(dup2(fd[1], 1) < 0)
        {
            perror("Dup2 Error");
            exit(1);
        }
        char **command = &commandStrings[0];
        if(execvp(command[0], command) < 0)
        {
            perror("execvp");
            exit(1);
        }
    }
    if(close(fd[1]) < 0)
    {
        perror("Second Close Error");
        exit(1);
    }
    int in = dup(0);
    if(in < 0)
    {
        perror("2nd Dup Error");
        exit(1);
    }
    if(dup2(fd[0], 0) < 0)
    {
        perror("3rd Dup error");
        exit(1);
    }
    pid_t pid2 = fork();
    if(pid2 < 0)
    {
        perror("Second Fork Failed");
        exit(1);
    }
    else if(pid2 == 0)
    {
        commandStrings.clear();
        for(unsigned int i = 0; i < tempVector2.size(); ++i)
            commandStrings.push_back(const_cast<char*>(tempVector2.at(i).c_str()));
        char **command = &commandStrings[0];
        if(execvp(const_cast<char*>(command[0]), command) < 0)
        {
            perror("Execvp");
            exit(1);
        }
    }
    if(dup2(in, 0) < 0)
    {
        perror("Dup2 Error");
        exit(1);
    }
    if(close(in) < 0)
    {
        perror("original close error");
        exit(1);
    }
    return true;
}
bool balancedParentheses(string commandInput)
{
    stack<char> parenthesesStack;
    for(unsigned int i = 0; i < commandInput.size(); ++i)
    {
        if(commandInput.at(i) == '(' || commandInput.at(i) == '[')
            parenthesesStack.push(commandInput.at(i))
        else if(commandInput.at(i) == ')' || commandInput.at(i) == ']')
        {
            if(!parenthesesStack.empty())
                parenthesesStack.pop();
            else
            {
                perror("Unbalanced parentheses or brackets");
                return false;
            }
        }
    }
    if(!parenthesesStack.empty())
    {
        perror("Unbalanced parentheses or brackets");
        return false;
    }
    return true;
}
class User
{
    public:
        string evaluate()
        {
            string input; // variable to hold user input
            char hostName[256], directory[1024]; //set asside 256 characters and 1024 characters
            getcwd(directory, sizeof directory); // get the current directory of where user is
            gethostname(hostName, sizeof hostName); // get the hose name of the user machine
            cout << "\033[1;32m" <<  getenv("USER") << "@" << hostName << ":\033[1;34m" << directory << "\033[0m$ "; // output user name and host name and current directory with the appropriate colors
            getline(cin, input); // get input from the user
            return input; // return input that was retrieved from the user
        }
};
class Test
{
    private:
        int flag;
    public:
        bool isFound;
        Test(vector<string> commandVector)
        {
            const char* flag_1 = "-f"; // flag for regular file
            const char* flag_2 = "-d"; // flag for directoy
            const char* flag_3 = "-e"; // flg for if file exists
            bool flag_f = strcmp(flag_1, commandVector.at(0).c_str());
            bool flag_d = strcmp(flag_2, commandVector.at(0).c_str());
            bool flag_e = strcmp(flag_3, commandVector.at(0).c_str());
            if(flag_f && flag_d && flag_e)
                flag = 1;
            else
                commandVector.erase(commandVector.begin());
            struct stat buffer;
            vector<const char*> comVector;
            comVector.push_back(commandVector.at(0).c_str());
            if(stat(const_cast<char*>(comVector[0]), &buffer) < 0)
            {
                perror("Stat");
                isFound = false;
            }
            else
            {
                if(flag)
                    isFound = true;
                else if(flag_f) // check if file is a regular file
                    (S_ISREG(buffer.st_mode)) ? isFound = true : isFound = false;
                else if(flag_d) // check if file is a directory
                    (S_ISDIR(buffer.st_mode)) ? isFound = true : isFound = false;
                else
                {
                    perror("Incorrect input for test");
                    exit(0);
                }
            }
        }
};
class Base
{
    public:
        Base() {};
        virtual bool evaluate() = 0;
};
class InOut : public Base
{
    private:
        string IO;
        vector<string> IOVector;
    public:
        InOut(string c) : IO(c) {};
        bool evaluate()
        {
            string temp, left, right;
            int index, flag;
            bool inputOutput = false;
			while(IO.size() != 0) // parses command into vector and makes checking left and right side of command easier
			{
                if(IO.find("<") != string::npos) 
                	index = IO.find("<");
            	else if(IO.find(">>") != string::npos)
            	{	
					index = IO.find(">>");
					flag = 1;
            	}
				else if(IO.find('>') != string::npos)
					index = IO.find('>');
            	else if(IO.find("|") != string::npos)
                	index = IO.find("|");
            	else
            	    index = -1;
            	trim(IO);
				splitTwo(IO, IOVector, index);
				if(index != -1)
				{
				    temp = IO.at(index);
				    if(flag == 1)
				    {
	                    temp = temp + ">";
	                    index++;
				    }
				    IOVector.push_back(temp);
				    IO.erase(IO.begin(), IO.begin() + index + 1);
				}
				else
				    IO.erase(IO.begin(), IO.end());
				flag = 0;
			}
			while(IOVector.size() != 0)
			{
			    left = IOVector.at(0);
			    IOVector.erase(IOVector.begin());
			    right = IOVector.at(1);
			    if(IOVector.at(0) == ">")
			        flag = 2;
			    else if(IOVector.at(0) == "<")
			        flag = 1;
			    else if(IOVector.at(0) == "|")
			        flag = 4;
			    else if(IOVector.at(0) == ">>") 
			        flag = 3;
			    if(flag < 4)
			        inputOutput = redirection(left, right, flag);
			    else
			        inputOutput = pipeCommand(left, right);
			    IOVector.erase(IOVector.begin());
			    IOVector.erase(IOVector.begin());
			}
            return inputOutput;
        }
};
class Connector : public Base
{
    protected:
        bool previous;
        Base* current;
        int selector;
    public:
        Connector() : Base () {};
        ~Connector();
};
class Command : public Base // DEBUG TEST
{
    private:
        vector<string> commandVector;
    public:
        Command(vector<string> input) : commandVector(input) {}
        ~Command();
        bool evaluate()
        {
            if(commandVector.at(0) == "exit") // if first command is exit then exit program WORKS FINE
                exit(0);
            else if(commandVector.at(0) == "test") // test command for testing files and directories DEBUG
            {   
                commandVector.erase(commandVector.begin());
                if(commandVector.empty() || (commandVector.size() == 1 && ((commandVector.at(0) == "-e") || (commandVector.at(0) == "-f") || (commandVector.at(0) == "-d"))))
                {
                    perror("No File Passed");
                    exit(0);
                }
                Test* test = new Test(commandVector);
                cout << "(" << boolalpha << test->isFound << ")" << endl;
                return test->isFound;
            }
            else if(commandVector.at(0) == "cd") // change directory WORKS FINE
            {
                commandVector.erase(commandVector.begin());
                if(commandVector.size() == 0 || commandVector.at(0) == "~" || commandVector.at(0) == "/")
                {
                    if(chdir(getenv("HOME")) < 0)
                    {
                        perror("Directory Error: Home");
                        return false;
                    }
                }
                else if(chdir(commandVector.at(0).c_str()) < 0) // if cd was unsuccessful throw an error
                {
                    perror("Directory Error");
                    return false;
                }
                return true;
            }
            else // execute other regualr commands with execvp WORKS PERFECTLY
            {
                vector<char*> commandArray;
                for(size_t i = 0; i < commandVector.size(); ++i)
                {
                    if(commandVector.at(i) == "") {}
                    else
                        commandArray.push_back(const_cast<char*>(commandVector.at(i).c_str()));
                }
                int childStatus = 0;
                pid_t pid = fork();
                if(pid < 0)
                {
                    perror("forking child process failed");
                    exit(0);
                }
                else if(pid == 0)
                {
                    commandArray.push_back('\0');
                    char **command = &commandArray[0];
                    if(execvp(const_cast<char*>(command[0]), command) < 0)
                    {
                        perror("Error executive");
                        exit(127);
                    }
                    exit(0);
                }
                else if(pid > 0) // wait for completion of the child execution
                {
                    wait(&childStatus); //wait until child finishes
                    if(wait(&childStatus) != -1) // if waiting for child does not success an error is thrown out
                        perror("wait error");
                    if(WIFEXITED(childStatus))
                    {
                        if(WEXITSTATUS(childStatus) != 0) //program ffailed but exited normally
                            return false;
                        else // program succeeded
                            return true; 
                    }
                    else
                    {
                        perror("abnormal child exit"); // the child program exited incorrectly, throws out an error
                        return false;
                    }
                }
                return false;
            }
        }
};
class Symbols : public Connector
{
    public:
        Symbols(bool before, Base* present, int flag){previous = before; current = present; selector = flag;}
        ~Symbols();
        bool evaluate()
        {
            if(selector == 1) // ampersand connector flag
            {
                if(previous) // if previous command executed execute the next command or return false
                    return current->evaluate();
                return false;
            }
            else if(selector == 2) // or connector flag
            {
                if(!previous) //if previous command did not execute, execute next command
                    return current->evaluate();
                return false; // else return false;
            }
            else if(selector == 3) // semi colon connect flag
                return current->evaluate(); // execute command all the time
            return false;
        }
};
class CommandEntered : public Base
{
    private:
        string input;
        vector<string> commandHolder;
    public:
        CommandEntered(string command, vector<string> v) : input(command), commandHolder(v) {}
        bool evaluate()
        {
            const char* command = input.c_str();
            int flag = 3;
            bool previous;
            vector<string> commandArray, tempVector;
            trim(input);
            tempVector.push_back("\0");
            if(input.find("#") != string::npos) // if user inputted a #, everything afterwards is considered command
                input = input.substr(0, input.find("#")); // remove everything from # to end of string
            if(input.find("(") != string::npos) // check for parentheses and precedence
            {
                if(!balancedParentheses(input)) // check for balanced parentheses
                    return false; // else return false and error
                while(tempVector.size() != 0) // begin extraction of groups of commands inside parentheses
                {
                    if(input.find("(") != string::npos)
                        split(tempVector, input, is_any_of("() "));
                    for(unsigned int i = 0; i < tempVector.size(); ++i)
                    {
                        if(tempVector.at(i) != "")
                            commandHolder.push_back(tempVector.at(i));
                    }
                    tempVector.clear();
                }
            }
            else if((input.find('|') != input.find("||")) || (input.find("<") != string::npos) || (input.find(">") != string::npos) || (input.find(">>") != string::npos)) // check for IO arrows for redirection
            {
                InOut* reDirection = new InOut(input);
                system(command);
                return true;
                return reDirection->evaluate();
            }
            else if(input.find("[") != string::npos)
            {
                if(!balancedParentheses(input))
                    return false;
                input.replace(input.find('['), input.find('[') + 1, "test ");
                input.replace(input.find(']'), input.find(']') - 1, "");
                split(commandHolder, input, is_any_of(" "));
                commandHolder.push_back(input);
            }
            else
            {
                input.erase(remove(input.begin(), input.end(), '\"'), input.end());
                split(commandHolder, input, is_any_of(" "), token_compress_off);
            }
			commandHolder.push_back("\0");
            while(commandHolder.size() != 0)
            {
                unsigned int j = 0;
                for(; j < commandHolder.size() - 1; ++j)
                {
                    if(commandHolder.at(j) == "&&")
                    {
                        flag = 1;
                        ++j;
                        break;
                    }
                    else if(commandHolder.at(j) == ";")
                    {
                        flag = 3;
                        ++j;
                        break;
                    }
                    else if(commandHolder.at(j) == "||")
                    {
                        flag = 2;
                        ++j;
                        break;
                 	}
                    commandArray.push_back(commandHolder.at(j));
                }
                Symbols* currentCommand = new Symbols(previous, new Command(commandArray), flag);
                previous = currentCommand->evaluate();
                commandArray.clear();
                commandHolder.erase(commandHolder.begin(), commandHolder.begin() + j + 1);
            }
            commandHolder.clear();
            commandArray.clear();
            return true;
        }
};
int main()
{
    User* user = new User();
    string commandInput = "";
    vector<string> commandVector;
    while(1)
    {
        commandInput = user->evaluate();
        trim(commandInput);
        if(commandInput == "" || commandInput == "\t" || commandInput.at(0) == '#') {}
        else
        {
            CommandEntered* terminal = new CommandEntered(commandInput, commandVector);
            terminal->evaluate();
        }
        commandInput.clear();
    }
    return 0;
}
