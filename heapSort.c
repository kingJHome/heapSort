#include "heapSort.h"

void exchangeData(int *arr,int i,int j){
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void HeapAdjust(HeapList *hpl,int s,int mode){
	int hlen = hpl->length - 1;

	if( mode ){
		if( 2*s <= hlen ){
			if( 2*s+1<= hlen ){
				if( GT(hpl->array[2*s],hpl->array[2*s+1]) && GT(hpl->array[2*s],hpl->array[s]) ){
					exchangeData(hpl->array,s,2*s);
				}else if( GT(hpl->array[2*s+1],hpl->array[2*s]) && GT(hpl->array[2*s+1],hpl->array[s]) ){
					exchangeData(hpl->array,s,2*s+1);
				}
			}else{
				if( GT(hpl->array[2*s],hpl->array[s]) ){
					exchangeData(hpl->array,s,2*s);
				}
			}
		}
	}else{
		if( 2*s <= hlen ){
			if( 2*s+1<= hlen ){
				if( LT(hpl->array[2*s],hpl->array[2*s+1]) && LT(hpl->array[2*s],hpl->array[s]) ){
					exchangeData(hpl->array,s,2*s);
				}else if( LT(hpl->array[2*s+1],hpl->array[2*s]) && LT(hpl->array[2*s+1],hpl->array[s]) ){
					exchangeData(hpl->array,s,2*s+1);
				}
			}else{
				if( LT(hpl->array[2*s],hpl->array[s]) ){
					exchangeData(hpl->array,s,2*s);
				}
			}
		}
	}
}

void HeapSort(HeapList *hpl,int *mode){
	int mid = (hpl->length-1) / 2;

	for(int j = 0; j < mid; ++j){
		for(int i = mid; i > j; --i){
			HeapAdjust(hpl, i, *mode);
		}
	}
}
