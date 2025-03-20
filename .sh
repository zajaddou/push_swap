#!/bin/bash

# Number of tests
TESTS=10000

# Number range
MIN=0
MAX=100

# Number of arguments
NUM=4

STOP=0

generate_random_numbers() {
    nums=()
    while [ "${#nums[@]}" -lt "$NUM" ]; do
        rand=$((RANDOM % (MAX - MIN + 1) + MIN))
        if [[ ! " ${nums[@]} " =~ " $rand " ]]; then
            nums+=("$rand")
        fi
    done
    # Reshuffle if the numbers are already sorted
    while [ "$(echo "${nums[@]}" | tr ' ' '\n' | sort -n | tr '\n' ' ')" == "$(echo "${nums[@]}" | tr ' ' '\n' | tr '\n' ' ')" ]; do
        nums=($(echo "${nums[@]}" | tr ' ' '\n' | sort -R | tr '\n' ' '))
    done
    echo "${nums[@]}"
}

for ((i=0; i<TESTS; i++)); do
    if [ "$STOP" -eq 1 ]; then
        clear
    fi

    INPUT=$(generate_random_numbers)
    
    OUTPUT=$(./push_swap $INPUT)
    
    # Extract only the stack A numbers:
    FINAL_A=$(echo "$OUTPUT" | awk '/> A </ {flag=1; next} /^</ {flag=0} flag {print $3}' | tr '\n' ' ' | tr -s ' ' | sed 's/ *$//')
    
    EXPECTED=$(echo "$INPUT" | tr ' ' '\n' | sort -n | tr '\n' ' ' | sed 's/ *$//')
    
    if [ -z "$FINAL_A" ]; then
        FINAL_A="$EXPECTED"
    fi

    if [ "$FINAL_A" == "$EXPECTED" ]; then
        echo " ✅ "
    else
        clear
        echo " ❌ "
        STOP=1
    fi
    echo " -> : $INPUT"
    echo " <- : $FINAL_A"
    echo ""
    
    if [ "$STOP" -eq 1 ]; then
        break
    fi
done
