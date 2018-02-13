/*10.6 Sort Big File: Imagine you have a 20 GB file with one string per line. Explain how you would sort the file.*/

//Approach: entire 20 gb cannot fit in the memory. Let's say you have 4 gb memory. Split input
//into 5 chunks of 4 gb. Read the first chunk into memory, sort it using merge sort and write back into
//temp output file into secondary memory. Similarly do this for other 4 chunks. Once all 5 chunks are
//sorted, then use external sort (minheap) to sort the 5 chunks.
//Ref to https://www.geeksforgeeks.org/merge-k-sorted-arrays/ to merge k sorted arrays
//Ref to https://www.geeksforgeeks.org/external-sorting/ for overall external sorting algo
