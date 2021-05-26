#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../lib/swap.h"
#include "../lib/printVector.h"
#include "../lib/randomize.h"


int partition(int *nums, int fromIndex, int untilIndex)
{
    int pivot = nums[untilIndex];
    int minorPartitionIndexLimit = fromIndex - 1;
    for (int j = fromIndex; j < untilIndex; j++)
    {
        if (nums[j] <= pivot)
        {
            minorPartitionIndexLimit++;
            swap(&nums[minorPartitionIndexLimit], &nums[j]);
        }
    }
    swap(&nums[minorPartitionIndexLimit + 1], &nums[untilIndex]);
    return minorPartitionIndexLimit + 1;
}

int randomizedPartition(int *nums, int fromIndex, int untilIndex)
{
    int randomizedIndex = randomize(fromIndex, untilIndex);
    swap(&nums[untilIndex], &nums[randomizedIndex]);
    return partition(nums, fromIndex, untilIndex);
}

void randomizedQuicksort(int *nums, int fromIndex, int untilIndex)
{
    if (fromIndex < untilIndex)
    {
        int indexPivo = randomizedPartition(nums, fromIndex, untilIndex);
        randomizedQuicksort(nums, fromIndex, indexPivo - 1);
        randomizedQuicksort(nums, indexPivo + 1, untilIndex);
    }
}

int main(void)
{
    int nums[] = {5, 600, 40, 53, 87, 16};
    int size = sizeof(nums) / sizeof(nums[0]);
    
    initializeRandomSeed();

    printVector(nums, size);
    randomizedQuicksort(nums, 0, size - 1);
    printVector(nums, size);
}