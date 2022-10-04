#!/bin/bash

first_file=$(grep -o -E "[A-Za-z0-9]+ [0-9]+\n?" "$1" | tr -d "\n")
second_file=$(grep -o -E "[A-Za-z0-9]+ [0-9]+\n?" "$1" | tr -d "\n")

if [ "$first_file" = "$second_file" ]; then
	exit 0
	echo -e "Here"
else
	exit 1
fi
