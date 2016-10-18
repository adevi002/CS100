Script started on Wed 08 Jun 2016 07:48:26 PM PDT
]0;fmuno003@fmuno003-Satellite-P55W-C: ~/rshell[01;32mfmuno003@fmuno003-Satellite-P55W-C[00m:[01;34m~/rshell[00m$ bi[K[Kmake
mkdir -p bin
g++ -Wall -Werror -ansi -pedantic src/rshell.cpp -o bin/rshell
]0;fmuno003@fmuno003-Satellite-P55W-C: ~/rshell[01;32mfmuno003@fmuno003-Satellite-P55W-C[00m:[01;34m~/rshell[00m$ bin/rshell
[1;32mfmuno003@fmuno003-Satellite-P55W-C:[1;34m/home/fmuno003/rshell[0m$ clear
[3;J[H[2J[1;32mfmuno003@fmuno003-Satellite-P55W-C:[1;34m/home/fmuno003/rshell[0m$ ls > o O output.txt
[1;32mfmuno003@fmuno003-Satellite-P55W-C:[1;34m/home/fmuno003/rshell[0m$ pwd > output2.txt
[1;32mfmuno003@fmuno003-Satellite-P55W-C:[1;34m/home/fmuno003/rshell[0m$ ls >> output2.txt
[1;32mfmuno003@fmuno003-Satellite-P55W-C:[1;34m/home/fmuno003/rshell[0m$ cat output.txt
bin
LICENSE
Makefile
outputRedirection.sh
output.txt
README.md
src
tests
[1;32mfmuno003@fmuno003-Satellite-P55W-C:[1;34m/home/fmuno003/rshell[0m$ cat output2.txt
/home/fmuno003/rshell
bin
LICENSE
Makefile
output2.txt
outputRedirection.sh
output.txt
README.md
src
tests
[1;32mfmuno003@fmuno003-Satellite-P55W-C:[1;34m/home/fmuno003/rshell[0m$ rm output2.r txt
[1;32mfmuno003@fmuno003-Satellite-P55W-C:[1;34m/home/fmuno003/rshell[0m$ outpu     rm output.txt
[1;32mfmuno003@fmuno003-Satellite-P55W-C:[1;34m/home/fmuno003/rshell[0m$ echo This is great > thisFile.txt
[1;32mfmuno003@fmuno003-Satellite-P55W-C:[1;34m/home/fmuno003/rshell[0m$ cat thisFile.txt
This is great
[1;32mfmuno003@fmuno003-Satellite-P55W-C:[1;34m/home/fmuno003/rshell[0m$ rm thisFile.txt
[1;32mfmuno003@fmuno003-Satellite-P55W-C:[1;34m/home/fmuno003/rshell[0m$ cat < Makefile > output.txt
[1;32mfmuno003@fmuno003-Satellite-P55W-C:[1;34m/home/fmuno003/rshell[0m$ cat O < Out   output.txt
COMPLETE = g++ -Wall -Werror -ansi -pedantic src/rshell.cpp -o bin/rshell
BIN = mkdir -p bin

all:
	$(BIN)
	$(COMPLETE)
rshell:
	$(BIN)
	$(COMPLETE)
clean:
	rm bin/rshell
	rm -rf bin
[1;32mfmuno003@fmuno003-Satellite-P55W-C:[1;34m/home/fmuno003/rshell[0m$ rm output.txt
[1;32mfmuno003@fmuno003-Satellite-P55W-C:[1;34m/home/fmuno003/rshell[0m$ clear
[3;J[H[2J[1;32mfmuno003@fmuno003-Satellite-P55W-C:[1;34m/home/fmuno003/rshell[0m$ exit
]0;fmuno003@fmuno003-Satellite-P55W-C: ~/rshell[01;32mfmuno003@fmuno003-Satellite-P55W-C[00m:[01;34m~/rshell[00m$ exit
exit

Script done on Wed 08 Jun 2016 07:50:19 PM PDT
