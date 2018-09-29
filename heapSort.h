#ifndef _MYHEAP_SORT
#define _MYHEAP_SORT

#define LT(a,b) ((a) < (b))
#define LQ(a,b) ((a) <= (b))
#define GT(a,b) ((a) > (b))
#define GQ(a,b) ((a) >= (b))

typedef struct{
	int *array;
	int length;
}SqList;

typedef SqList HeapList;

//数据交换
//参数说明：
//	arr：待交换数据的数组
//	i，j：两个交换数据的位置
void exchangeData(int *arr,int i,int j);

//堆调整
//参数说明：
//	hpl:待调整列表
//	s:需要调整的位置
//	mode:大堆排序还是小堆排序
void HeapAdjust(int *arr,int s,int len,int mode);

//堆排序
//参数说明：
//	hpl:待排序列
//	mode:0,小堆排序；1,大堆排序
void HeapSort(HeapList *hpl,int *mode);

#endif
