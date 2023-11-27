// Making binary search algorithm which is log(n)

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define ARRAY_LENGTH 7
#define RAND_SEED 17


void init_random(uint8_t * array, const uint32_t length)
{
	srand(RAND_SEED);
	
	for(uint32_t i = 0 ; i < length ; ++i)
	{
		array[i] = rand();
	}
}

void bubble_sort(uint8_t * array, const uint32_t length)
{
	bool sorted = true;
	do{
		sorted = true;
		for(uint32_t i = 0 ; i < length - 1 ; ++i)
		{
			/* swap if larger */ 
			if(array[i] > array[i + 1])
			{
				uint8_t tmp = array[i + 1];
				array[i + 1] = array[i];
				array[i] = tmp;
				sorted = false;
			}
			
		}
	}while(!sorted);
}

int32_t binary_search(const uint8_t * array, const uint32_t length, uint8_t val)
{
	uint8_t low = 0;
	uint8_t high = length;
	
	do
	{	
		uint8_t index = floor((low + high)/2);
		if(val == array[index])
		{
			return index;
		}
		/* check if val is less than then value under the index*/
		else if(val < array[index])
		{
			high = index;
		}
		else
		{
			low = index + 1;
		}
	
	}while(low < high);
	return -1;  
}

void print_array(const uint8_t * array, const uint32_t length)
{
	for(uint32_t i = 0; i < length ; ++i)
	{
		printf("%u\n",array[i]);
	}
}

int main(){
	uint8_t array[ARRAY_LENGTH] = {0};
	
	print_array(array, ARRAY_LENGTH);
	init_random(array, ARRAY_LENGTH);
	print_array(array, ARRAY_LENGTH);
	bubble_sort(array, ARRAY_LENGTH);
	printf("---------- SORTED ----------\n");
	print_array(array, ARRAY_LENGTH);
	
	uint32_t val_to_find = array[3];
	
	int32_t val_index = binary_search(array, ARRAY_LENGTH, val_to_find);
	if(val_index < 0){
		printf("failed to find value\n");
	}
	else{
		printf("found values is %i, value we were searching is %i", array[val_index], val_to_find);
	}
	
	return 1;
};

 
