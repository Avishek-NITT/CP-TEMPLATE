#!/bin/bash
# ls *.cpp *.txt | entr -s './run.sh'

# Set resource limits
ulimit -t 10 -v 1000000

# Maximum execution time in seconds
MAX_TIME=5

# Maximum number of lines to capture
MAX_LINES=500

# Compile the test.cpp file
# g++ -fsanitize=address -fsanitize=undefined -o test test.cpp
g++ -o test test.cpp

# Check if compilation was successful
if [ $? -eq 0 ]; then
    # Run the compiled executable with input from input.txt, limit execution time to MAX_TIME seconds, 
    # limit output to MAX_LINES lines, and redirect output to output.txt
    timeout $MAX_TIME ./test < input.txt | head -n $MAX_LINES > output.txt
    if [ $? -eq 124 ]; then
        echo "Execution timed out. Possible infinite loop detected. Output limited to $MAX_LINES lines."
    else
        echo "Test run successfully. Output saved to output.txt."
    fi
else
    echo "Compilation failed."
fi
