#include <stdlib.h>
/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int** threeSum(int* nums, int numsSize, int* returnSize) {
	void sort(int* head, int* tail);
	sort(nums, nums+numsSize);
	*returnSize = 0;
    int**ansA = (int**)malloc(sizeof(int)*numsSize);
    ansA[0] = (int*)malloc(sizeof(int)*3);
    int i,j,k,tmp=0;
    for(i=0; i<numsSize; ++i){
    	tmp += nums[i];
    	for(j=i+1; j<numsSize && nums[j]+tmp<=0; ++j){
    		tmp += nums[j];
    		for(k=j+1; k<numsSize && nums[k]+tmp<=0; ++k){
    			tmp += nums[k];
    			if(tmp==0){
    				ansA[*returnSize][0]=nums[i];
    				ansA[*returnSize][1]=nums[j];
    				ansA[*returnSize][2]=nums[k];
    				ansA[++(*returnSize)]=(int*)malloc(sizeof(int)*3);
    			}
    			tmp -= nums[k];
    		}
    		tmp -= nums[j];
    	}
    	tmp -= nums[i];
    }
    return ansA;
}

void swap(int *a, int *b) { int k=*a; *a=*b; *b=k; }

void sort(int *head,int *tail){
    int *left=head, *right=tail-1;
    int midvalue=*(head+(tail-head)/2);
    while(left<right){
        for(;left<tail-1 && *left<=midvalue;++left);
        for(;right>head && *right>=midvalue;--right);
        left<=right?swap(left++,right--):0;
    }
    left<tail-1?sort(left, tail):0;
    right>head?sort(head,right+1):0;
}