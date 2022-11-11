# Small Linux Grep project

This project was done with C++. Project uses command line arguments, so it should be compiled with g++ or gcc.

## Compiling

To compile the program on linux with g++, you can use the following command:

```properties
g++ grep.cpp -o run
```  

## Usage

This project uses grep manual page as a txt document from which the program finds user input values.

The txt file can be found in the repository. You can see the same content on linux manual page with the following command:

```properties
man grep
```  
Grep manual page allso shows well what this project is aiming to do, so i urge you to rumble through it.

You can use your own txt document as well, if you wish to do so but remember to add it in the sam file location.

## Running the program

You can run the program with the following command on linux:

```properties
./run following man_grep_plain_ASCII.txt
```  
The word "following" can be replaced with your own word.

You can add more parameters to get more information:

```properties
./run -olo following man_grep_plain_ASCII.txt
``` 
Adds line numbers of sentences which contains the word "following" in the file.

At the moment you can use three of the following parameters:

"-olo"
"-ol"
"-oo"

You can use the grep manual page for deeper understaing of the parameters.

## Basic version of the program (can be used with IDE and does not require command line arguments)

You can just run the program with the command: 

```properties
./run
``` 
In the vanilla version, the program starts and asks the user for a string and a search string.
The program next compares the 2 given strings and finds the position of the latter string in the first string, if it exists.

## Needs fixing

- Readme could be a bit more clear
- Comments in the code could be more descriptive
- Some of the Variables in the code could be a bit more descriptive
