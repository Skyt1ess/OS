#!/bin/bash
printf "0\n" > data.txt

while true 
do
	if `ln data.txt data.txt.lock`;  then
		data=$(tail -n 1 data.txt.lock)
		((data++))
		printf "$((data))\n" >> data.txt.lock
		rm data.txt.lock
	fi
done