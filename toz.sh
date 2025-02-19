#!/bin/bash

# Define the numbers
ARG="1 2 3 4 5"

# Generate all 120 permutations of 1 2 3 4 5 and store them in an array
permute() {
    local arr=("$@")
    local first
    local rest
    local perms
    local result

    if [ ${#arr[@]} -eq 1 ]; then
        echo "${arr[0]}"
        return
    fi

    for i in "${!arr[@]}"; do
        first="${arr[i]}"
        rest=("${arr[@]:0:i}" "${arr[@]:((i+1))}")
        perms=$(permute "${rest[@]}")
        while IFS= read -r perm; do
            result="$first $perm"
            echo "$result"
        done <<< "$perms"
    done
}

# Create the list of all permutations
permute $ARG | while read perm; do
    echo "Testing permutation: $perm"
    ./push_swap $perm | wc -l
done
