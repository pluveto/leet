#!/bin/bash

if [ ! -n "$1" ] ;then
    echo -e "\033[31mMissing source file name!\033[0m"
    exit 1
fi

# echo -e "\033[33m"`date`"\033[0m"


outputBinaryFileName=`basename $1 .cpp`'.out'

g++ $1 -o $outputBinaryFileName -std=c++11 -I ~/leet/inc

if [ $? -ne 0 ];then
    echo -e "\033[31mCompilation error!\033[0m"
    exit 1
fi

ts=$(date +%s%N) ; ./$outputBinaryFileName ; tt=$((($(date +%s%N) - $ts)/1000000))

echo -e "\033[33m■\033[0m"


echo -e "\033[32m ┌──End of program──"  

echo " │ Finished in $tt ms."

echo -e "\033[0m"