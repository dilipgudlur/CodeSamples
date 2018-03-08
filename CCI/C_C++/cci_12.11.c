/*12.11 20 Alloc: Write a function in C called my2DA1loc which allocates a two-dimensional array. 
Minimize the number of calls to malloc and make sure that the memory is accessible by the notation arr [ i] [ j].
*/
//Approach1: Naive method using (rows * cols) number of malloc calls 
int** 2DAlloc(int rows, int cols) {
	int** rowPtr = (int**) malloc(rows * sizeof(int*)); //allocate memory for row of int* pointers, each int* will point to its
								//own row of ints
	if(rowPtr == NULL)
		return NULL;
	int i;
	for(i = 0;i < rows;i++) {
		rowPtr[i] = (int)malloc(cols * sizeof(int)); //for each rowPtr allocate a chunk of memory for each column
		if(rowPtr[i] == NULL)
			return NULL;
	}
	return rowPtr;
}

void 2DFree(int** rowPtr, int rows) { //dont need the cols
	int i;
	for(i = 0;i < rows;i++) {
		free(rowPtr[i]); //frees each of the individual rows but doesnt free the memory holding the row ptr
	}
	free(rowPtr); //frees the memory allocated to hold the row pointers
}

//Approach2: Optimize the number of malloc calls. This method makes just one call to free
int **2DAlloc(int rows, int cols) {
	int header = rows * sizeof(int*); //space for rows number of int* pointers
	int data = rows * cols * sizeof(int); //space for rows*cols number of int data
	int** rowPtr = (int**) malloc(header + data); //allocates space for header and data in one go

	int i;

	//Note that each item in header points to start of the row of int data. For example, given rows = 5. cols = 6,
	//rowPtr[0] to rowPtr[5] are the pointers corresponding to header section, since there are 5 rows, there are
	//correpsonding 5 header pointers.
	//rowPtr[0] points to rowPtr[5], rowPtr[5] to rowPtr[10] are the integer data for first row of 6 cols
	//rowPtr[1] points to rowPtr[11], rowPtr[11] to rowPtr[16] are the integer data for second row of 6 cols
	//so on..

	//where does the actual memory for the int data start, lets call it buf
	int* buf = (int*)(rowPtr + rows);//moving rowPtr ahead by rows, this is where buf should point to so we can start filling data
	for(i = 0;i < rows;i++) {
		rowPtr[i] = buf + i * cols;
	}
	return rowPtr;
}

//Deallocating rowPtr can be done in one go using single call to free
