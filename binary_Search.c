#include <stdio.h>

int binarySearch(const int b[], int searchKey, int low, int high);

int main(void) {
	int array[] = {13, 14, 37, 38, 50, 99, 100, 101, 102, 103};

    printf("%d\n", binarySearch(array, 100, 0, 9));

	return 0;
}

int binarySearch(const int b[], int searchKey, int low, int high){
    int middle;
 
    while (low <= high)
    {
        middle = (low + high) / 2;

        if (searchKey == b[middle])
        {            
            return middle;
        }
        
        if (searchKey < b[middle])
        {
            high = middle - 1;        
        }
        else 
        {
            low = middle + 1;
        }
    }
    
    return -1;
}