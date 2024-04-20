# Takes the problem id as input
# You can add "bash ../../judge.sh" as alias in .bashrc, .bash_profile or .zshrc for easy access
# alias judge="bash ../../judge.sh" or alias judge="zsh ../../judge.sh" 
# Usage: bash ../../judge.sh <problem_id> (e.g. bash ../../judge.sh A)

for i in $(ls -d data/*.dat); do
    # Get the input file
    INPUT=$i

    if [ ${i:5:1} != $1 ]; then
        continue
    fi

    # Get the expected output
    EXPCT=$(echo $i | sed 's/\.dat/\.diff/')

    # Get the output file
    OUT=$(echo $i | sed 's/\.dat/\.out/')

    # Run the program
    g++ -std=c++17 -O2 -Wall -Wextra -Wshadow -fsanitize=undefined -fsanitize=address $1.cpp -o $1
    ./$1 < $i > $OUT
    if [ $? -ne 0 ]; then
        echo "Runtime Error"
        exit 1
    fi

    # Compare the output
    diff $OUT $EXPCT
    if [ $? -ne 0 ]; then
        echo "Wrong Answer"
        exit 1
    fi
    echo "Test case $INPUT passed"

    # Clean up
    rm $OUT
done