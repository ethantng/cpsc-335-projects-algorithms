Overview:
The program will process an input text file that has multiple lines. These lines will consist of concatenated strings and a list of targeted cities. The program will identify the indexes of each target substring's occurrence in the concatenated string and output both the indices and corresponding targeted words.
The program will first read input data from the input text file 'in2a.txt'.
Next, the target list will be parsed and the list of substrings will be extracted.
The program will find the target words in the concatenated string, store and sort them in order.
The output will print in an output txt file called 'out2a.txt' which stores the results of the extracted indices and words.
To ensure the program works, it is necessary to make sure that both text files are available. 

How to Execute:
ensure g++ is installed
navigate to the directory the source file is in
ensure the txt files are in the same directory
compile using this command:
g++ -o CPSC362-Proj2-Algo1-EthanNguyen CPSC362-Proj2-Algo1-EthanNguyen.cpp
run the compiled program
./CPSC362-Proj2-Algo1-EthanNguyen