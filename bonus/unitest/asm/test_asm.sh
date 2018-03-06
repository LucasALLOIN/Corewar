#!/bin/sh
## EPITECH PROJECT, 2018
## test_asm.sh
## File description:
## test for asm in bash
##

[[ $(ls warriors/ | grep tek) != "" ]] && mv warriors/champion_tek_1.s warriors/champion_1.s
value_nicollet=$($PWD/asm_tek warriors/champion_1.s)
mv warriors/champion_1.s warriors/champion_tek_1.s
value_tek=$($PWD/asm warriors/champion_tek_1.s)

if [[ $value_nicollet == "" && $value_tek == "" ]] 
then
	the_diff=$(diff champion_1.cor champion_tek_1.cor);
	if [[ $the_diff != "" ]]
	then
		if [[ $1 == "-h" ]]
		then
		echo "$(diff "$(hexdump champion_1.cor)" "$(hexdump champion_tek_1.cor)")"
		else
		echo "$the_diff"
		fi
	fi
fi
rm *.cor
