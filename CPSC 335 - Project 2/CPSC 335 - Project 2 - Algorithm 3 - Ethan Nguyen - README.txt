Overview:
The program uses a merging technique to combine multiple sorted arrays into a single sorted list. This program uses min-heap with priority queue to extract and merge elements. The first element of each sorted array is inserted into a min-heap which is extracted by the smallest element and then added to a resulting list. This process continues until all of the elements in each array are properly inserted into the heap and then extracted by priority. This will continuously repeat until all the elements are extracted which will result into the resulting array.

How to Execute:
ensure g++ is installed
navigate to the directory the source file is in
ensure the txt files are in the same directory
compile using this command:
g++ -o CPSC335-Proj2-Algo3-EthanNguyen CPSC335-Proj2-Algo3-EthanNguyen.cpp
run the compiled program
./CPSC335-Proj2-Algo3-EthanNguyen