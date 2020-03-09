# !/bin/bash

RED='\033[1;31m'
GREEN='\033[1;32m'
NC='\033[0m'

clear

if [ $# -eq "0" ]
then
	echo "Please fill in how many maps of each type you want to test"
	echo "flow-one: "
	read ONES
	echo "flow-ten: "
	read TENS
	echo "flow-thousand: "
	read THOUSANDS
	echo "big: "
	read BIGS
	echo "superposition: "
	read SUPERS
elif [ $1 == "one" ]
then
	ONES=$2
elif [ $1 == "ten" ]
then
	TENS=$2
elif [ $1 == "thousand" ]
then
	THOUSANDS=$2
elif [ $1 == "big" ]
then
	BIGS=$2
elif [ $1 == "super" ]
then
	SUPERS=$2
elif [ $1 == "all" ]
then
	if [ -z "$2" ]
	then
		ONES=10
		TENS=10
		THOUSANDS=10
		BIGS=10
		SUPERS=10
	else
		ONES=$2
		TENS=$2
		THOUSANDS=$2
		BIGS=$2
		SUPERS=$2
	fi
fi

if [ $ONES > 1 ]
then
	if [ -z ${OUR_RESULT+1} ]
	then
		echo "flow-one maps"
	else
		echo ""
		echo "flow-one maps"
	fi
elif [[ $ONES == 1 ]]
then
	if [ -z ${OUR_RESULT+1} ]
	then
		echo "flow-one map"
	else
		echo ""
		echo "flow-one map"
	fi
fi
while [[ $ONES > 0 ]]
do
	./generator --flow-one > test_0000001 && OUR_RESULT=$(.././lem-in < test_0000001 | ./verifier)
	TARGET=$(cat test_0000001 | tail -f -n 1 | tr -dc '0-9')
	sum=$((TARGET-OUR_RESULT))
	if (($sum > 0))
	then
		echo "Our result is ${GREEN}$sum${NC} faster than the target"
	elif (($sum < 0))
	then
		sum=$(($sum*-1))
		echo "Our result is ${RED}$sum${NC} slower than the target"
	elif (($sum == 0))
	then
		echo "Our result is the same as the target"
	fi
	ONES=$(($ONES - 1))
done

if [ $TENS > 1 ]
then
	if [ -z ${OUR_RESULT+1} ]
	then
		echo "flow-ten maps"
	else
		echo ""
		echo "flow-ten maps"
	fi
elif [[ $TENS == 1 ]]
then
	if [ -z ${OUR_RESULT+1} ]
	then
		echo "flow-ten map"
	else
		echo ""
		echo "flow-ten map"
	fi
fi
while [[ $TENS > 0 ]]
do
	./generator --flow-ten > test_0000001 && OUR_RESULT=$(.././lem-in < test_0000001 | ./verifier)
	TARGET=$(cat test_0000001 | tail -f -n 1 | tr -dc '0-9')
	sum=$((TARGET-OUR_RESULT))
	if (($sum > 0))
	then
		echo "Our result is ${GREEN}$sum${NC} faster than the target"
	elif (($sum < 0))
	then
		sum=$(($sum*-1))
		echo "Our result is ${RED}$sum${NC} slower than the target"
	elif (($sum == 0))
	then
		echo "Our result is the same as the target"
	fi
	TENS=$(($TENS - 1))
done

if [ $THOUSANDS > 1 ]
then
	if [ -z ${OUR_RESULT+1} ]
	then
		echo "flow-thousand maps"
	else
		echo ""
		echo "flow-thousand maps"
	fi
elif [[ $THOUSANDS == 1 ]]
then
	if [ -z ${OUR_RESULT+1} ]
	then
		echo "flow-thousand map"
	else
		echo ""
		echo "flow-thousand map"
	fi
fi
while [[ $THOUSANDS > 0 ]]
do
	./generator --flow-thousand > test_0000001 && OUR_RESULT=$(.././lem-in < test_0000001 | ./verifier)
	TARGET=$(cat test_0000001 | tail -f -n 1 | tr -dc '0-9')
	sum=$((TARGET-OUR_RESULT))
	if (($sum > 0))
	then
		echo "Our result is ${GREEN}$sum${NC} faster than the target"
	elif (($sum < 0))
	then
		sum=$(($sum*-1))
		echo "Our result is ${RED}$sum${NC} slower than the target"
	elif (($sum == 0))
	then
		echo "Our result is the same as the target"
	fi
	THOUSANDS=$((THOUSANDS - 1))
done

if [ $BIGS > 1 ]
then
	if [ -z ${OUR_RESULT+1} ]
	then
		echo "big maps"
	else
		echo ""
		echo "big maps"
	fi
elif [[ $BIGS == 1 ]]
then
	if [ -z ${OUR_RESULT+1} ]
	then
		echo "big map"
	else
		echo ""
		echo "big map"
	fi
fi
while [[ $BIGS > 0 ]]
do
	./generator --big > test_0000001 && OUR_RESULT=$(.././lem-in < test_0000001 | ./verifier)
	TARGET=$(cat test_0000001 | tail -f -n 1 | tr -dc '0-9')
	sum=$((TARGET-OUR_RESULT))
	if (($sum > 0))
	then
		echo "Our result is ${GREEN}$sum${NC} faster than the target"
	elif (($sum < 0))
	then
		sum=$(($sum*-1))
		echo "Our result is ${RED}$sum${NC} slower than the target"
	elif (($sum == 0))
	then
		echo "Our result is the same as the target"
	fi
	BIGS=$(($BIGS - 1))
done

if [ $SUPERS > 1 ]
then
	if [ -z ${OUR_RESULT+1} ]
	then
		echo "superposition maps"
	else
		echo ""
		echo "superposition maps"
	fi
elif [[ $SUPERS == 1 ]]
then
	if [ -z ${OUR_RESULT+1} ]
	then
		echo "superposition map"
	else
		echo ""
		echo "superposition map"
	fi
fi
while [[ $SUPERS > 0 ]]
do
	./generator --big-superposition > test_0000001 && OUR_RESULT=$(.././lem-in < test_0000001 | ./verifier)
	TARGET=$(cat test_0000001 | tail -f -n 1 | tr -dc '0-9')
	sum=$((TARGET-OUR_RESULT))
	if (($sum > 0))
	then
		echo "Our result is ${GREEN}$sum${NC} faster than the target"
	elif (($sum < 0))
	then
		sum=$(($sum*-1))
		echo "Our result is ${RED}$sum${NC} slower than the target"
	elif (($sum == 0))
	then
		echo "Our result is the same as the target"
	fi
	SUPERS=$(($SUPERS - 1))
done
