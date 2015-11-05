#include <cstdio>
#include <algorithm>
#define MAX_PAIR 1111
#define abs(a) ((a)>0?(a):(-a))
#define max(a,b) ((a)>(b)?(a):(b))

typedef struct outmappix{
	int pos, code;
} pix;

int width, totlen;
int pixmap[MAX_PAIR][2];
pix outmap[MAX_PAIR*8];

int  getval(int pos);
int  getcod(int pos);
void swap(pix* a, pix* b);
int  cmp(const void* a, const void * b);

int main(int argc, char const *argv[])
{
	while(scanf("%d", &width) != EOF && width != 0){
		int pixval, pixlen;
		int inpairnum = totlen = 0;
		while(scanf("%d%d", &pixval, &pixlen) && (pixlen || pixval)) {
			pixmap[inpairnum][0] = pixval;
			pixmap[inpairnum][1] = pixlen;
			totlen += pixlen;
			inpairnum ++;
		}
		int outpairnum = 0, curpos = 0;
		for (int p = 0; p <= inpairnum; ++p){
			int row = curpos/width;
			int col = curpos%width;
			for (int i = row-1; i <= row+1; ++i){
				for (int j = col-1; j <= col+1; ++j){
					int tmppos = i*width+j;
					if(i<0 || j<0 || j>=width || tmppos >= totlen){
						continue;
					}
					outmap[outpairnum].pos  = tmppos;
					outmap[outpairnum].code = getcod(tmppos);
					outpairnum ++;
				}
			}
			curpos += pixmap[p][1];
		}
		qsort(outmap, outpairnum, sizeof(pix), cmp);
		printf("%d\n", width);
		pix tmp = outmap[0];
		for (int i = 0; i < outpairnum; ++i){
			if(tmp.code == outmap[i].code){
				continue;
			}
			printf("%d %d\n", tmp.code, outmap[i].pos-tmp.pos);
			tmp = outmap[i];
		}
		printf("%d %d\n", tmp.code, totlen-tmp.pos);
		printf("0 0\n");
	}
	printf("0");
	return 0;
}

int getval(int pos)
{
	int p = 0;
	for(int i = 0; i <= pos; i += pixmap[p++][1]);
	return pixmap[p-1][0];
}

int getcod(int curpos)
{
	int ans = 0;
	int val = getval(curpos);
	int row = curpos / width;
	int col = curpos % width;
	for (int i = row-1; i <= row+1; ++i){
		for(int j = col-1; j <= col+1; ++j){
			int tmppos = i*width+j;
			if(i<0 || j<0 || j>=width || tmppos >= totlen){
				continue;
			}
			int tmpval = getval(tmppos)-val;
			tmpval = abs(tmpval);
			ans = max(ans, tmpval);
		}
	}
	return ans;
}

int cmp(const void* a, const void* b)
{
	pix* x = (pix*)a;
	pix* y = (pix*)b;
	return x->pos - y->pos;
}