#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "heapSort.h"

void getData(char *ch,HeapList *hl);
void visitHeap(HeapList hl);

int main(int argc,char *argv[]){
	int mode = 1;
	HeapList hl = {NULL,0};
	FILE *fp = fopen("data.txt","r");

	if( fp ){
		char *txtData = NULL;
		size_t getlen = 0;

		if( getline(&txtData, &getlen, fp)!=-1 ){
			getData(txtData,&hl);
			printf("排序前：");
			visitHeap(hl);
			HeapSort(&hl, &mode);
			printf("排序后：");
			visitHeap(hl);
		}
	}

	return 0;
}

void getData(char *ch,HeapList *hl){
	size_t clen = strlen(ch);
	int staticLen = 0;
	char seperator[] = " \n",
		 *delim = NULL;

	for(size_t i = 0; i < clen; ++i){
		if(ch[i]==' ' || ch[i]=='\n'){
			staticLen++;
		}
	}

	hl->array = (int*)malloc((staticLen+1) * sizeof(int));
	if( hl->array ){
		hl->length = staticLen + 1;
		staticLen = 1;
		delim = strtok(ch, seperator);
		if( delim ){
			hl->array[staticLen++] = atoi(delim);
			while( delim = strtok(NULL, seperator) ){
				hl->array[staticLen++] = atoi(delim);
			}
		}
	}
}

void visitHeap(HeapList hl){
	for(int i = 1; i < hl.length; ++i){
		printf("%-4d", hl.array[i]);
	}
	printf("\n");
}
