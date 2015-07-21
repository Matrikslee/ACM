#include <cstdio>
#include <cstring>

int handle(char *s, int *head, int *tail);

int main(int argc, char const *argv[])
{
	char s[100];
	while(scanf("%s", s) && s[0]!='-'){
		int head=-1, tail=-1;
		handle(s, &head, &tail);
		if(head==-1) {
			printf("%s can not be classified after 15 iterations\n", s);
		} else if(head==0&&tail==1){
			printf("%s is self-inventorying\n", s);
		} else if(tail-head==1) {
			printf("%s is self-inventorying after %d steps \n", s, head);
		} else {
			printf("%s enters an inventory loop of length %d\n", s, tail-head);
		} 
	}
	return 0;
}

void getinventory(char *ss, char *s)
{
	int nums[10] = {0};
	for(char *p=s;*p!='\0';nums[*p++-'0']++);
	for(int i=0, p=0; i<10; ++i){
		if(nums[i]!=0){
			while(nums[i]!=0){
				ss[p++]=nums[i]%10+'0';
				nums[i]/=10;
			}
			ss[p++]=i+'0';
			ss[p]='\0';
		}
	}
}

int handle(char *s, int *head, int *tail)
{
	char cs[16][100];
	strcpy(cs[0], s);
	for(int i=0; i<15; ++i){
		getinventory(cs[i+1], cs[i]);
	}
	for(int i=0; i<16; ++i){
		for(int j=i+1; j<16; ++j){
			if(strcmp(cs[i],cs[j])==0){ *head = i; *tail = j; }
			if(*head!=-1) { break; }
		}
		if(*head!=-1) { break; }
	}
	return *head;
}