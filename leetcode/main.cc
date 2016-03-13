#include <stdio.h>

int** threeSum(int* nums, int numsSize, int* returnSize);

int main(int argc, char const *argv[]){
	int ansLen = 0, i, nums[] = {-1,0,1,2,-1,-4};
	int **ans = threeSum(nums,6,&ansLen);
	for(i=0; i<ansLen; ++i){
		printf("%d %d %d\n", ans[i][0],ans[i][1],ans[i][2]);
	}
	return 0;
}