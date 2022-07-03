#!/bin/bash
success=0
total=0
rate=0
for i in $(seq 1 1 100)
do
	echo Trial: $i
	g++ -o prog prison.cpp;
	output=$(./prog) ; 
	echo Result: $output
	if [[ $output -eq 1 ]]
	then
		((success++))
		((total++))
		rate=$(echo "scale=5;$success/$total" | bc)
	else
		((total++))
		rate=$(echo "scale=5;$success/$total" | bc)
	fi
	echo Success Rate: $rate
done


