#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED  

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <memory.h>
#define swaping(a, b) int temp=a;a=b;b=temp


typedef bool (*sortsys)(int, int);

bool ascending(int a, int b){
	return a<=b;
}

bool desending(int a, int b){
	return a>=b;
}

void bubbleSort(int s, int e, int a[], sortsys sos){
	for(int i=s;i<e;i++){
		for(int j=s+1;j<e-i+1+s;j++){
			if(!sos(a[j-1], a[j])){
				swaping(a[j-1], a[j]);
			}
		}
	}
}

void selectionSort(int s, int e, int a[], sortsys sos){
	int min;
	for(int i=s;i<e;i++){
		min=i;
		for(int j=i+1;j<=e;j++){
			if(sos(a[j], a[min])){
				min=j;
			}
		}
		swaping(a[i], a[min]);
	}
}

void insertionSort(int s, int e, int a[], sortsys sos){
	for(int i=s;i<e;i++){
		for(int j=i+1;j>0&&!sos(a[j-1], a[j]);j--){
			swaping(a[j], a[j-1]);
		}
	} 
}

void quickSort(int l, int r, int d[], sortsys sos){
	int pivot=d[l];
	int p=l+1;
	int q=r;
	if(l>=r) return;
	
	while(1){
		while(sos(d[p], pivot)&&p<r) p++;
		while(!sos(d[q], pivot) && q>l) q--;
		
		if(p<q){
			swaping(d[p], d[q]);
		} else {
			swaping(d[l], d[q]); break;
		}
	}
	
	quickSort(l, q-1, d, sos);
	quickSort(q+1, r, d, sos);
}

void shiftdown(int k, int m, int d[], sortsys sos){
	if(k>m/2) return;
	int i=2*k;
	if(!sos(d[i+1], d[i]) && i<m) i++;
	if(sos(d[k], d[i])){
		swaping(d[k], d[i]);
		shiftdown(i, m, d, sos);
	}
}
void heapify(int k, int d[], sortsys sos){
	for(int i=k/2;i>=1;i--){
		shiftdown(i, k, d, sos);
	}
}
void heapSort(int k, int d[], sortsys sos){
	heapify(k, d, sos);
	for(int i=k;i>=1;i--){
		swaping(d[1], d[i]);
		shiftdown(1, i-1, d, sos);
	}
}

void merge(int l, int m, const int r, int d[], sortsys sos){
	int temp[r+1];
	int i=l, j=m+1;
	for(int k=l;k<=r;k++){
		if(i<=m && (sos(d[i], d[j]) || j>r))
			temp[k]=d[i++];
		else temp[k]=d[j++];
	}
	for(int k=l;k<=r;k++){
		d[k]=temp[k];
	}
}
void mergeSort(int l, int r, int d[], sortsys sos){
	if(l>=r) return;
	int m=(l+r)/2;
	mergeSort(l, m, d, sos);
	mergeSort(m+1, r, d, sos);
	merge(l, m, r, d, sos);
}

void timSort(int l, int r, int d[], sortsys sos){
	if(r-l<=32){
		selectionSort(l, r, d, sos);
		return;
	}
	int m=(l+r)/2;
	timSort(l, m, d, sos);
	timSort(m+1, r, d, sos);
	merge(l, m, r, d, sos);
}

void countingSort(int l, int r, int d[], const int minNum, const int maxNum){
	int temp[maxNum-minNum+1]={};
	for(int i=l;i<=r;i++){
		temp[d[i]-minNum]++;
	}
	
	int k=l;
	for(int i=0;i<=maxNum-minNum;i++){
		for(int j=0;j<temp[i];j++){
			d[k++]=i+minNum;
		}
	}
}

void bogoSort(int s, int e, int d[], sortsys sos){
	int i, j, k, l;
	const int n=e-s+1;
	int deck[1000];
	
	if(n>1000){
		printf("YOU CANNOT USE THIS\n");
		return;
	}
	
	while(1){
		for(i=s+1;i<=e;i++)
			if(sos(d[i], d[i-1])) break;
		if(i>e) break;
		l=n;
		
		for(int im=0;im<n;im++) deck[im]=d[im+s];
		
		for(i=0;i<n;i++){
			j=rand()%l;
			d[i+s]=deck[j];
			
			k=rand()%l;
			deck[j]=deck[k];
			deck[k]=deck[--l];
		}
	}
}

void radixSort(const int start, const int end, int a[], const int base){
    int ex, i, j, max=a[start];
    for(i=start; i<=end; i++)
		if(a[i]>max)
			max=a[i];
    
    for(ex=1; ex<=max; ex*=base){
    	int output[end+1], count[base]={};
    	
    	for(i=start; i<=end; i++)
			count[(a[i]/ex)%base]++;
			
    	for(i=1; i<base; i++)
			count[i] += count[i-1];
    	
    	for(i=end; i>=start; i--){
    		j = (a[i]/ex)%base;
    		output[count[j]-1+start] = a[i];
    		count[j]--;
    	}
    	for(i=start; i<=end; i++)
			a[i] = output[i];
    }
}


#endif
