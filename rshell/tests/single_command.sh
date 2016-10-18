Script started on Mon 16 May 2016 10:41:01 PM PDT
]0;fmuno003@hammer:~/branch/rshell/tests[?1034h[fmuno003@hammer tests]$ bin/rshell
bash: bin/rshell: No such file or directory
]0;fmuno003@hammer:~/branch/rshell/tests[fmuno003@hammer tests]$ cd ..
]0;fmuno003@hammer:~/branch/rshell[fmuno003@hammer rshell]$ bin/rshell
fmuno003@hammer.cs.ucr.edu$: ls -a
.  ..  bin  .git  LICENSE  Makefile  README.md	src  tests
fmuno003@hammer.cs.ucr.edu$: clear
[H[2Jfmuno003@hammer.cs.ucr.edu$: ex  date
Mon May 16 22:41:22 PDT 2016
fmuno003@hammer.cs.ucr.edu$: cal
      May 2016      
Su Mo Tu We Th Fr Sa
 1  2  3  4  5  6  7
 8  9 10 11 12 13 14
15 [7m16[27m 17 18 19 20 21
22 23 24 25 26 27 28
29 30 31

fmuno003@hammer.cs.ucr.edu$: git status
# On branch exec
# Changed but not updated:
#   (use "git add <file>..." to update what will be committed)
#   (use "git checkout -- <file>..." to discard changes in working directory)
#
#	modified:   README.md
#	modified:   tests/comment_command.sh
#	modified:   tests/single_command.sh
#
# Untracked files:
#   (use "git add <file>..." to include in what will be committed)
#
#	bin/
#	tests/typescript
no changes added to commit (use "git add" and/or "git commit -a")
fmuno003@hammer.cs.ucr.edu$: ls
bin  LICENSE  Makefile	README.md  src	tests
fmuno003@hammer.cs.ucr.edu$: clear
[H[2Jfmuno003@hammer.cs.ucr.edu$: ls -a
.  ..  bin  .git  LICENSE  Makefile  README.md	src  tests
fmuno003@hammer.cs.ucr.edu$: lls  s -a1
.
..
bin
.git
LICENSE
Makefile
README.md
src
tests
fmuno003@hammer.cs.ucr.edu$: make
mkdir -p bin
g++ -Wall -Werror -ansi -pedantic src/rshell.cpp -o bin/rshell
fmuno003@hammer.cs.ucr.edu$: w
 22:41:41 up 11 days,  4:39, 15 users,  load average: 2.43, 2.24, 2.17
USER     TTY      FROM              LOGIN@   IDLE   JCPU   PCPU WHAT
hvasi001 pts/0    ip68-96-83-247.o 20:56    1:35m  0.06s  0.06s -bash
mpho001  pts/1    99-53-225-208.li 21:19    3:21   0.18s  0.14s vim Execute.cpp
bli020   pts/2    66-215-226-109.d 22:04    1.00s  0.11s  0.04s vim commented_c
gmart020 pts/3    169.235.216.66   21:47   32:11   0.14s  0.08s vim Makefile
crese002 pts/4    169.235.218.94   21:50   50:44   0.01s  0.01s -bash
bli020   pts/5    75-142-194-182.s 21:27   56:27   0.09s  0.05s vim multi_comma
fmuno003 pts/6    fmuno003-satelli 22:28   12:48   0.01s  0.01s -bash
gmart020 pts/7    169.235.216.66   22:17    0.00s  0.08s  0.08s -bash
abui011  pts/8    138.23.64.122    21:56    3.00s  0.13s  0.00s bin/rshell
dnguy104 pts/9    169.235.216.185  22:32    7:34   0.01s  0.01s -bash
fmuno003 pts/10   r6100.dyn.ucr.ed 22:33    0.00s  0.03s  0.00s script single_c
fmuno003 pts/11   -                22:41    0.00s  0.03s  0.00s bin/rshell
yli066   pts/12   66-215-152-175.d 18:17    1.00s  0.55s  0.55s -bash
jliaw001 pts/14   63.138.45.36     22:38    2:25   0.02s  0.02s -bash
kmena003 pts/23   147.58.148.146.b 19:49    1:21m  0.08s  0.08s -bash
fmuno003@hammer.cs.ucr.edu$: who
hvasi001 pts/0        2016-05-16 20:56 (ip68-96-83-247.oc.oc.cox.net)
mpho001  pts/1        2016-05-16 21:19 (99-53-225-208.lightspeed.irvnca.sbcglobal.net)
bli020   pts/2        2016-05-16 22:04 (66-215-226-109.dhcp.rvsd.ca.charter.com)
gmart020 pts/3        2016-05-16 21:47 (169.235.216.66)
crese002 pts/4        2016-05-16 21:50 (169.235.218.94)
bli020   pts/5        2016-05-16 21:27 (75-142-194-182.static.rvsd.ca.charter.com)
fmuno003 pts/6        2016-05-16 22:28 (fmuno003-satellite-p55w-c.dyn.ucr.edu)
gmart020 pts/7        2016-05-16 22:17 (169.235.216.66)
abui011  pts/8        2016-05-16 21:56 (138.23.64.122)
dnguy104 pts/9        2016-05-16 22:32 (169.235.216.185)
fmuno003 pts/10       2016-05-16 22:33 (r6100.dyn.ucr.edu)
fmuno003 pts/11       2016-05-16 22:41
yli066   pts/12       2016-05-16 18:17 (66-215-152-175.dhcp.rvsd.ca.charter.com)
jliaw001 pts/14       2016-05-16 22:38 (63.138.45.36)
kmena003 pts/23       2016-05-16 19:49 (147.58.148.146.bc.googleusercontent.com)
fmuno003@hammer.cs.ucr.edu$: who am i
fmuno003 pts/11       2016-05-16 22:41
fmuno003@hammer.cs.ucr.edu$: clear
[H[2Jfmuno003@hammer.cs.ucr.edu$: exit
]0;fmuno003@hammer:~/branch/rshell[fmuno003@hammer rshell]$ exit

Script done on Mon 16 May 2016 10:41:47 PM PDT
