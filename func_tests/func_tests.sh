#!/bin/bash

touch out.txt

i=1
failed=0
while [ -f "../data/pos_0${i}_in.txt" ]; do
	if [ -f "../data/pos_0${i}_args.txt" ]; then
		bash pos_case.sh "../../func_tests/data/pos_0${i}_in.txt" "../../func_tests/data/pos_0${i}_out.txt" "../../func_tests/data/pos_0${i}_args.txt"
	else
		bash pos_case.sh "../data/pos_0${i}_in.txt" "../data/pos_0${i}_out.txt"
	fi
	if [ "$?" -eq 0 ]; then
		echo -e "Pos_test${i} SUCCCESS"
	else
		echo -e "Pos_test${i} FAILURE"
		failed=$((failed+1))
	fi
	i=$((i+1))
done
