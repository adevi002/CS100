declare array=(5 4 3 2 1)

for((i = 0; i <=4; ++i))
do
	for((j = 0; j <=4; ++j))
		do
			if [ "$j" -ne  4 ]; then
				if [ "${array[$j]}" -gt "${array[$j + 1]}" ]; then
					num1=${array[$j]}
					array[$j]=${array[$j+ 1]}
					array[$j + 1]=$num1;
					fi
				fi
			done
		done

for i in "${array[@]}"
	do
		echo "$i"
	done
