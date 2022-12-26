#include <stdio.h>

void bubbleSort(int [], int );

int main(void) {
	
    int array[] = {38, 37, 13, 14, 100, 101, 102, 103, 99, 50};
    bubbleSort(array, sizeof(array) / sizeof(array[0]));

    printf("%d", array[0]);
    for (size_t i = 1; i < 10; i++)
    {
        printf(" %d", array[i]);
    }    

	return 0;
}

void bubbleSort(int a[], int size){
    int pass;
    int i;
    int hold;
    int swap;

    for(pass = 1; pass < size; pass++){
        swap = 0;

        for(i = 0; i < size - pass; i++){
            if(a[i] > a[i + 1]){
                hold = a[i];
                a[i] = a[i + 1];
                a[i + 1] = hold;

                swap = 1; // Houve pelo menos uma troca
            }
        }

        if (swap == 0) // Se não houve nenhuma troca, então os dados já deveram estar na ordem certa
        {
        break;
        } 
    }
}