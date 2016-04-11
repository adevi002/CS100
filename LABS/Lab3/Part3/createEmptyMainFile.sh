touch main.cc
rm main.cc
touch main.cc


echo "/*" >> main.cc
while read line; 
do
	echo $line >> main.cc
	done < Francisco_861174271.txt

	echo  "*/" >> main.cc

echo "int main(int argc, const char** argc)" >> main.cc
echo "{}" >> main.cc
