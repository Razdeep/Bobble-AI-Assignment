output = executable
input = input.csv
cc = g++

clean:
	rm -f executable

test: all
	./${output} ${input}

all: clean
	g++ *.cpp -o ${output}	