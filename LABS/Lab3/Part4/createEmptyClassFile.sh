a=$1
b='.cc'
c=$a$b
d='.hh'
e=$a$d
touch $e
touch $c
rm $e
rm $c
touch $e
touch $c

echo "//Francisco Munoz" >> $e
echo "//fmuno003@ucr.edu" >> $e
echo "//861174271" >> $e

echo "#include \"./$e\"" >> $e
echo "$1::$1()" >> $e
echo "{}" >> $e
echo "$1::~$1()" >> $e
echo "{}" >> $e

echo "//Francisco Munoz" >> $e
echo "//fmuno003@ucr.edu" >> $e
echo "//861174271" >> $e

echo "#ifndef $1_hh" >> $c
echo "#define $1_hh" >> $c
echo "class $1" >> $c
echo "{" >> $c
echo "public:" >> $c
echo "$1();" >> $c
echo "~$1();" >> $c
echo "private:" >> $c
echo "};" >> $c
echo "#endif" >> $c