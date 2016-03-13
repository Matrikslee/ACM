/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    *returnSize = numsSize>0?numsSize-k+1:0;
    int* deQ = (int*)malloc(sizeof(int)*numsSize);
    int* ansQ = (int*)malloc(sizeof(int)**returnSize);
    int* head = deQ, *tail=deQ;
    int i; for(i=0; i<k; ++i){
    	for(;head!=tail && nums[*(tail-1)]<nums[i]; --tail);
    	*tail++ = i;
    }
    for(i=0; i<*returnSize; ++i){
    	if(*head<i){
    		++head;
    	}
    	for(;head!=tail && nums[*(tail-1)]<nums[i+k]; --tail);
    	*tail++ = i+k;
    	ansQ[i] = nums[*head];
    }
    free(deQ);
    return ansQ;
}

