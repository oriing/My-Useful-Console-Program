이 헤더파일에는 10가지 정렬 함수와 그 함수를 보조하는 코드들이 포함되어 있다. 헤더파일을 추가하면 자동으로 stdio.h(표준입출력), stdlib(표준라이브러리), math(수학), memory(메모리) 헤더파일이 추가된다. sortsys 형의 bool(int, int) 함수 포인터 자료형이 제공된다. swaping의 swap 함수(define 형태)가 제공된다. temp는 swap의 대상이 될 수 없다.
ascending, decending은 각각 오름차순, 내림차순을 의미한다.

이하 함수 설명에서는 특별한 언급이 없으면 시작점, 도착점, 정렬대상, 정렬기준을 인자로 받는 것으로 간주하면 된다.

void bubbleSort(int s, int e, int a[], sortsys sos)
버블정렬은 앞에서부터 뒤로 순차적으로 인접 원소끼리 비교 후 바꿔주는 작업을 반복하는 정렬 방법이다. 시간복잡도는 O(n²)이다.

void selectionSort(int s, int e, int a[], sortsys sos)
선택정렬은 가장 작은, 혹은 큰 원소를 선택 후 앞으로 가져오는 과정을 반복하는 정렬 방법이다. 인간이 무의식적으로 사용한다. 시간복잡도는 O(n²)이다.

void insertionSort(int s, int e, int a[], sortsys sos)
삽입정렬은 원소 하나를 선택한 뒤 적당한 위치까지 앞으로 가져오는 과정을 반복하는 정렬 방법이다. 인간이 무의식적으로 사용한다. 시간복잡도는 O(n²)이다.

void quickSort(int l, int r, int d[], sortsys sos)
퀵정렬은 원소 중 하나를 기준(피벗)으로 정한 뒤, 비교를 통해 분할을 반복하는 정렬 방법으로, 분할정복의 대표적인 예시이다. 시간복잡도는 O(n log n)이다.

void heapSort(int k, int d[], sortsys sos)
힙정렬은 힙이라는 자료 구조의 특징을 이용하는 방법이다. 1부터 자료가 존재하는 배열만 사용 가능하다. 1~k까지의 자료를 정렬한다. k, 정렬대상, 정렬방법을 인자로 받는다. 시간복잡도는 O(n log n)이다. void heapify(int k, int d[], sortsys sos)는 힙을 만드는 함수, void shiftdown(int k, int m, int d[], sortsys sos)는 해당 위치에서 힙을 만족하도록 하는 함수이다.

void mergeSort(int l, int r, int d[], sortsys sos)
병합정렬은 전체를 부분으로 나눈 뒤, 합치는 과정을 통해 정렬하는 방법이다. 시간복잡도는 O(n log n)이다. void merge(int l, int m, const int r, int d[], sortsys sos) 함수는 나눈 자료를 합치는 역할을 한다.

void timSort(int l, int r, int d[], sortsys sos)
팀정렬은 일정 크기까지는 병합정렬을, 일정 크기 이하는 선택정렬을 하는 방법으로, 정렬된 것에 가까운 자료에 유리하다. 사실상 현실적인 데이터에 가장 빠른 정렬방법이다. 하이브리드 정렬에 속한다.

void countingSort(int l, int r, int d[], const int minNum, const int maxNum)
카운팅정렬은 해당 숫자가 존재하는 개수를 세는 정렬 방법으로, 중복되는 수가 많고 수의 범위가 크지 않을 때 유리하다. 정렬은 항상 내림차순이다. 시작과 끝, 정렬 대상, 가장 작은 수, 가장 큰 수를 입력받는다. 시간복잡도는 O(n+k)이다.

void bogoSort(int s, int e, int d[], sortsys sos)
보고정렬은 무작위의 순서로 값을 바꾼 다음, 정렬되었는지를 확인하는 것을 반복하는 정렬 방법이다. 기본적으로 적은 값이던 큰 값이던 비효율적이다. 이 방식은 주로 유전알고리즘에서 사용된다. 이 헤더파일은 1000개 이상의 자료를 정렬하는 것을 금지하였다.(물리적 사유로 제한되어 있다.) 시간복잡도는 O(n×n!), 최대 O(∞)이다.

void radixSort(const int start, const int end, int a[], const int base)
기수정렬은 데이터의 비교 없이 나머지 연산을 통한 수학적 성질을 이용하는 방법이다. 자릿수가 적은 정수형 자료 정렬에 유용하다. 오름차순만 가능하다. 시작위치, 끝위치, 정렬대상, 진법 순으로 입력받는다.


※ 이 헤더파일은 다음 링크에서 MIT License로 무료로 다운로드 받을 수 있습니다.
https://github.com/sat0317/CNSH-Project/tree/master/sort%20algorithm