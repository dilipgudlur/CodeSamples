/*12.1 O Malloc: Write an aligned malloc and free function that supports allocating memory 
such that the memory address returned is divisible by a specific power of two. 
EXAMPLE align_malloc (1000, 128) will return a memory address that is a multiple 
of 128 and that points to memory of size 1000 bytes. aligned_free() will free memory 
allocated by align_malloc.*/

/*Approach: There are two parts to returning the correct address which is divisible by the alignment
offset. 
a. Allocating sufficient chunck memory so that correct address can be found
b. Finding that address which is divisible by alignment offset.


*/

void* aligned_malloc(size_t required_bytes, size_t alignment) {
	int offset = alignment - 1 + sizeof(void*); //offset is the max that needs to be added to get to the next 
							//address which is a multiple of alignment. Additionally
							//allocate extra space for a void pointer so that we can
							//save address of pointer p so that it can be used to free
							//that memory
	void* p =  (void*) malloc(required_bytes + offset); //so this becomes the minimum memory chunk that is to be allocated
	if(p == NULL)
		return;
	void* q = (void*) (((size_t)(p) + offset) & ~(alignment - 1)); //we know that within p + offset, there will be a multiple
	//of alignment. Once you have that, clear out the trailing bits that increase the address more than the alignment mulitple
	((void**)q)[-1] = p; //save address of p at -1 th index of q. Reason for saving the address is that
				//when q is returned to user, there is no idea of where is the start of the bigger chunk of
				//memory(p) so that it can be freed. So we have to save the address of p somewhere so that it can
				//be referenced later. Here we have saved at the start of q and can start it using -1 th index. 
				//Reason q is dereferenced as (void**) is because we have to save p at -1 th index of q, p is a
				//void*, so we have to look at q like an array that holds void*'s. So to hold void* pointers, we
				//pointer to a pointer hence void**
	return q;
}

void aligned_free(void *q) { 
	void* p = ((void**)q)[-1];//access address of p from -1 th index of q and free it
	free(p);
}


/*Example: lets say alignment is 16 and required_bytes is 40. Lets say current address 35. 
We know a multiple of 16 occurs in the next 16 bytes. Maximum that needs to be added to 35 
to get to the next 16 bytes is 15 (alignment -1). So allocate 40+15 = 55 bytes. Now we have 
a chunk of 55 bytes allocated but instead of malloc returning 35 as the start of the 55 byte 
chunk, we need to return  the address that is a multiple of 16. So let that address lie 
somewhere between 35 and 35+15(50). 50 is represented as 110010. Also note that 48 is the 
correct address to be returned which is 110000. So to generate 48 from 50 we have to clear 
out any bits set after the 5th bit that is the first 4 bits from lsb, so basically "bitwise and" 
with 1111...10000. Determining how bit bits to clear out depends on the alignment. If the alignment 
is 8 (then clear out first 3 bits), if 16 then clear out first 4, if 32 then clear out first 5 bits. 
Doing ~(alignment-1)will generate that mask.
*/
