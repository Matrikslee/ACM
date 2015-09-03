#include <cstdio>
#include <cstring>

int  id[255], ch[255];
int  left[255], right[255];

int  construct(char *preorder, char *inorder, int len);
void postprint(int root);

int main(int argc, char const *argv[])
{
	char preorder[255], inorder[255];
	while(~scanf("%s%s", preorder, inorder)){
		int len=strlen(preorder);
		for(int i=0; i<len; ++i){
			id[preorder[i]] = i;
			ch[i] = preorder[i];
			left[i]=right[i]=0;
		}
		int root = construct(preorder, inorder, len);
		postprint(0); 
		putchar('\n');
	}
	return 0;
}

int construct(char *preorder, char *inorder, int len)
{
	int root = len>0?id[preorder[0]]:0;
	for(int i=0; i<len; ++i){
		if(id[inorder[i]]==root){
			if(i!=0) {
				left[root]  = construct(preorder+1,   inorder,     i);
			}
			if(len-i-1>0) {
				right[root] = construct(preorder+i+1, inorder+i+1, len-i-1);
			}
			break;
		}
	}
	return root;
}

void postprint(int root)
{
	if(left[root]  != 0) {
		postprint(left[root]);
	}
	if(right[root] != 0) {
		postprint(right[root]);
	}
	putchar(ch[root]);
}