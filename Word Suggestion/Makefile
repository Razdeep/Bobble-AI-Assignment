output = executable
dictionary = dictionary.csv
word = hellp
cc = g++

clean:
	rm -f executable

test: all
	./${output} ${dictionary} ${word}

all: clean
	g++ *.cpp -o ${output}	