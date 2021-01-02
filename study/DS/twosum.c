#include<stdio.h>
#include<stdlib.h>
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int* result = malloc(sizeof(returnSize)), i,j;

    for(i=0; i<numsSize;i++)
    {
        int diff = target - nums[i];
        for(int j=0;j<numsSize;j++)
        {
            if(nums[j] == diff)
            {
                result[0] = i;
                result[1] = j;

                return result;
            }
        }
    }

}

int main()
{
    int nums[4] = {2,7,11,15}, target = 9;
    int* result = twoSum(nums,4,target,16);

    printf("result is %d %d",result[0],result[1]);
    
}