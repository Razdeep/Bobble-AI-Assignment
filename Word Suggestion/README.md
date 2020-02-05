# Word Suggestion
## Goal: 
Given a list of words (say dictionary) in a csv file along with its frequency. Take a word as
input and suggest five closest words from the dictionary sorted in order of relevance.
Assume that the user is trying to type a dictionary word which they misspelled, and you have to
suggest the correct word.

### Requirements
 - g++
 - make

## How to compile

 - Using Make
 ```bash
 $ make all
 ```

 - Compiling Manually
 ```bash
 $ g++ Word_suggestion.cpp -o executable
 ```

 - Running <br/>
 Make sure to replace the CAPTALIZED words
 `./executable DICTIONARY_FILE MISPELT_WORD` <br/>
 Example
 ```bash
./executable dictionary.csv hellp
 ```

