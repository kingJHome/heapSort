#include "heapSort.h"

void exchangeData(int *arr,int i,int j){
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void HeapAdjust(int *arr,int s,int len,int mode){
	int rc = arr[s];

	for(int j = 2*s; j < len; j *= 2){
		if( j < len && LT(arr[j],arr[j+1]) ){
			++j;
		}

		if( mode==1&&!LT(arr[s],arr[j]) || mode==0&&!GT(arr[s],arr[j]) ){
			break;
		}
		exchangeData(arr, s, j);
		s = j;
	}
}

void HeapSort(HeapList *hpl,int *mode){
	int mid = (hpl->length-1) / 2;

	for(int i = mid; i > 0; --i){
		HeapAdjust(hpl->array, i, hpl->length, *mode);//构建大顶堆或小顶堆
	}
	
	for(int i = hpl->length-1; i > 1; --i){
		exchangeData(hpl->array, 1, i);
		HeapAdjust(hpl->array, 1, i-1, *mode);
	}
}
