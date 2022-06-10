#!/bin/bash
GREEN="\033[38;5;2m"
NORMAL="\033[38;5;255m"
RED="\033[38;5;1m"
BLUE="\033[38;5;4m"
PURPLE="\033[0;35m"
YELLOW="\033[0;33m"

echo -e "${RED}\n---- MY PUSH_SWAP ERROR TEST CASES ---- \n ${NORMAL}"

######### INPUT VALIDATION TEST ##############
echo -e "${PURPLE}---- INPUT VALIDATION ---- ${NORMAL}"

echo -e "${BLUE}some arguments aren’t integers: 1 2 3 one ${NORMAL}"
./push_swap 1 2 3 one

echo -e "${BLUE}some arguments are bigger than an integer: 2 1 3 6 5 2147483648 ${NORMAL}"
./push_swap 2 1 3 6 5 2147483648

echo -e "${BLUE}some arguments has doubles${NORMAL}"
./push_swap 44 79 85 44 65 31 28 3 86 30 25 59 56 60 17 36 10 29 88 46 49
#####################

######### SOME TEST CASES ##############
echo -e "${PURPLE}\n---- SOME TEST CASES ---- ${NORMAL}"

echo -e "${RED}no argument provided './push_swap' \n${NORMAL}"
./push_swap

echo -e "${RED}Already sorted list -0 1 2 3 4 5 6 7 8 9-${NORMAL}"
echo -e "${YELLOW}Instruction amount:${NORMAL}"
ARG="0 1 2 3 4 5 6 7 8 9"; ./push_swap $ARG | wc -l
echo -e "${GREEN}Checker:${NORMAL}"
AARG="0 1 2 3 4 5 6 7 8 9"; ./push_swap $ARG | ./checkers/checker_MAC $ARG

echo -e "${RED}1(list size)${NORMAL}"
echo -e "${YELLOW}Instruction amount:${NORMAL}"
ARG="42"; ./push_swap $ARG | wc -l
echo -e "${GREEN}Checker:${NORMAL}"
AARG="42"; ./push_swap $ARG | ./checkers/checker_MAC $ARG

echo -e "${RED}3(list size)${NORMAL}"
echo -e "${YELLOW}Instruction amount:${NORMAL}"
ARG=`ruby -e "puts (1..3).to_a.shuffle.join(' ')"`; ./push_swap $ARG | wc -l
echo -e "${GREEN}Checker:${NORMAL}"
ARG=`ruby -e "puts (1..3).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checkers/checker_MAC $ARG

echo -e "${RED}5(list size)${NORMAL}"
echo -e "${YELLOW}Instruction amount:${NORMAL}"
ARG=`ruby -e "puts (1..5).to_a.shuffle.join(' ')"`; ./push_swap $ARG | wc -l
echo -e "${GREEN}Checker:${NORMAL}"
ARG=`ruby -e "puts (1..5).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checkers/checker_MAC $ARG

echo -e "${RED}20(list size)${NORMAL}"
echo -e "${YELLOW}Instruction amount:${NORMAL}"
ARG=`ruby -e "puts (1..19).to_a.shuffle.join(' ')"`; ./push_swap $ARG | wc -l
echo -e "${GREEN}Checker:${NORMAL}"
ARG=`ruby -e "puts (1..19).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checkers/checker_MAC $ARG

echo -e "${RED}100(list size)${NORMAL}"
echo -e "${YELLOW}Instruction amount:${NORMAL}"
ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`; ./push_swap $ARG | wc -l
echo -e "${GREEN}Checker:${NORMAL}"
ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checkers/checker_MAC $ARG

echo -e "${RED}500(list size)${NORMAL}"
echo -e "${YELLOW}Instruction amount:${NORMAL}"
ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`; ./push_swap $ARG | wc -l
echo -e "${GREEN}Checker:${NORMAL}"
ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checkers/checker_MAC $ARG
