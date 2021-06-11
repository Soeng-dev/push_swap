#! /bin/bash #shebang
rm case_tested;
rm overflow;

echo total number of case : $2 >> overflow
echo criterion of overflow : $3 >> overflow


for ((i = 1; i <= $2 ; i++))
do
	#set case
	echo ""
	echo "$i test"
	ARG=$(./random_numbers $1 1 10000)

	#test case log
	echo "$i test" >> case_tested
	echo $ARG >> case_tested

	#get result
	echo "result"
	NUM=$(./push_swap $ARG | wc -l)
	echo $NUM
	

	#overflow log
	if [ $NUM -gt $3 ]; then
		echo "  "  >> overflow
		echo "$i test" >> overflow
		echo $ARG >> overflow
		echo result : $NUM >> overflow
	fi


	./push_swap $ARG | ./checker_Mac $ARG
done

