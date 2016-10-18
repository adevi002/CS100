Script started on Wed 08 Jun 2016 07:53:10 PM PDT
]0;fmuno003@fmuno003-Satellite-P55W-C: ~/rshell[01;32mfmuno003@fmuno003-Satellite-P55W-C[00m:[01;34m~/rshell[00m$ bin/rshell
[1;32mfmuno003@fmuno003-Satellite-P55W-C:[1;34m/home/fmuno003/rshell[0m$ ls
bin  LICENSE  Makefile	pipe.sh  README.md  src  tests
[1;32mfmuno003@fmuno003-Satellite-P55W-C:[1;34m/home/fmuno003/rshell[0m$ ls | wc
      7       7      49
[1;32mfmuno003@fmuno003-Satellite-P55W-C:[1;34m/home/fmuno003/rshell[0m$ ps | wc
      6      24     169
[1;32mfmuno003@fmuno003-Satellite-P55W-C:[1;34m/home/fmuno003/rshell[0m$ cat < Makefile | tr A-Z a-z | wc > output.txt
[1;32mfmuno003@fmuno003-Satellite-P55W-C:[1;34m/home/fmuno003/rshell[0m$ cat output.txt
     12      27     183
[1;32mfmuno003@fmuno003-Satellite-P55W-C:[1;34m/home/fmuno003/rshell[0m$ echo this is a test | ec  wc
      1       4      15
[1;32mfmuno003@fmuno003-Satellite-P55W-C:[1;34m/home/fmuno003/rshell[0m$ ps aux | wc -l
237
[1;32mfmuno003@fmuno003-Satellite-P55W-C:[1;34m/home/fmuno003/rshell[0m$ ls | sort -r
tests
src
README.md
pipe.sh
output.txt
Makefile
LICENSE
bin
[1;32mfmuno003@fmuno003-Satellite-P55W-C:[1;34m/home/fmuno003/rshell[0m$ ls -a | sort
.
..
bin
.git
LICENSE
Makefile
output.txt
pipe.sh
README.md
src
tests
[1;32mfmuno003@fmuno003-Satellite-P55W-C:[1;34m/home/fmuno003/rshell[0m$ ls -a
.  ..  bin  .git  LICENSE  Makefile  output.txt  pipe.sh  README.md  src  tests
[1;32mfmuno003@fmuno003-Satellite-P55W-C:[1;34m/home/fmuno003/rshell[0m$ exit
]0;fmuno003@fmuno003-Satellite-P55W-C: ~/rshell[01;32mfmuno003@fmuno003-Satellite-P55W-C[00m:[01;34m~/rshell[00m$ exit
exit

Script done on Wed 08 Jun 2016 07:55:04 PM PDT
