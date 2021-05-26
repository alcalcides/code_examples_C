#include <stdio.h>
#include "../lib/printVector.h"
#include "../lib/swap.h"


int partition(int *nums, int fromIndex, int untilIndex){
    int pivot = nums[untilIndex];
    int minorPartitionIndexLimit = fromIndex -1;
    for (int j = fromIndex; j < untilIndex; j++)
    {
        if(nums[j] <= pivot){
            minorPartitionIndexLimit++;
            printf("trocando %d por %d\n", nums[minorPartitionIndexLimit], nums[j]);
            swap(&nums[minorPartitionIndexLimit], &nums[j]);
        }
    }
    printf("trocando %d por %d (fixando o pivo)\n", nums[minorPartitionIndexLimit + 1], nums[untilIndex]);
    swap(&nums[minorPartitionIndexLimit+1], &nums[untilIndex]);
    return minorPartitionIndexLimit + 1;

}

void quicksort(int *nums, int fromIndex, int untilIndex){
    printf("sorting\n");
    printVector(&nums[fromIndex], untilIndex - fromIndex + 1);
    if(fromIndex < untilIndex){
        int indexPivo = partition(nums, fromIndex, untilIndex);
        printf("pivo: [%d] => %d\n", indexPivo, nums[indexPivo]);
        printf("sort at left FROM index [%d] TO index [%d]\n", fromIndex, indexPivo - 1);
        quicksort(nums, fromIndex, indexPivo - 1);
        printf("sort at right FROM index [%d] TO index [%d]\n", indexPivo + 1, untilIndex);
        quicksort(nums, indexPivo + 1, untilIndex);
    }
}

int main(void){
    int nums[] = {5, 60, 8, 90, 40, 53, 87, 16};
    int size = sizeof(nums) / sizeof(nums[0]);
    printVector(nums, size);

    quicksort(nums, 0, size - 1);
    
    printVector(nums, size);

}