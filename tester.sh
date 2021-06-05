#! /bin/bash #shebang
rm case_tested;



for ((i = 0; i < $1 ; i++))
do
	echo ""
	echo "$i test"
	ARG=$(./random_numbers 500 1 10000)
	echo $ARG >> case_tested
	#echo $ARG
	echo "result"
	./push_swap $ARG | wc -l
	./push_swap $ARG | ./checker_Mac $ARG
done



















#| ./checker $ARG
# echo $ARG > b

# ./checker $ARG
# ./push_swap $ARG

#ARG="17 9 93 80 99 2 5 51 84 4 57 48 14 29 55 35 74 21 94 60 68 63 1 92 23 82 12 67 69 98 52 19 83 97 78 39 75 100 25 24 8 7 41 11 86 44 36 72 18 73 16 64 47 90 65 87 77 59 61 45 30 53 54 66 76 28 37 95 70 91 27 6 50 43 81 3 46 13 31 89 88 96 38 62 33 10 15 79 20 42 40 85 26 34 71 49 32 22 58 56";
#ARG="33 4 5 9 6 2 1 99 40 210 92 100 120"
