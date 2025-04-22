#include <stdio.h>
#include <stdlib.h>

void sort(int* numbers, int size) 
{
    int i = 0;
    int j = 0;
    int temp = 0;
    while( i < size - 1) 
    {
        j = i + 1;
        while(j < size) 
        {
            if (numbers[i] > numbers[j]) 
            {
                temp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = temp;
            }
            j++;
        }
        i++;
    }
}

void findSubsets(int target, int* numbers, int start, int size, int* subset, int subsetSize) 
{
    int i = 0;
    if (target == 0) 
    {
        while(i < subsetSize)
        {
            printf("%d ", subset[i]);
            i++;
        }
        printf("\n");
        return;
    }
    
    i = start;
    while (i < size) 
    {
        if (numbers[i] > target) 
            i++;
        else 
        {
            if (i > start && numbers[i] == numbers[i-1])
                i++; 
            else 
            {
                subset[subsetSize] = numbers[i];
                findSubsets(target - numbers[i], numbers, i + 1, size, subset, subsetSize + 1);
                i++;
            }
        }
    }
}

int main(int argc, char* argv[]) 
{
    int i = 0;
    if (argc < 3) 
        return 1;
    int target = atoi(argv[1]);
    int size = argc - 2;
    int* numbers = (int*)malloc(size * sizeof(int));
    
    while(i < size) 
    {
        numbers[i] = atoi(argv[i + 2]);
        i++;
    }   
    int* subset = (int*)malloc(size * sizeof(int));
    sort(numbers, size);
    findSubsets(target, numbers, 0, size, subset, 0);
    free(numbers);
    free(subset);
    return 0;
}