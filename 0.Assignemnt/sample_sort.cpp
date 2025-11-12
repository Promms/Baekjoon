#include <cstdio>
#include <chrono>
#include <cmath>
#include <algorithm>

// --- 1. 기본 유틸리티 함수 ---

/////////////////////////////////////////////////////////////////////////
//////////////// YOUR PLAYGROUND FROM HERE ////////////////
////////////////////////////////////////////////////////////////////////

// --- 1. 기본 유틸리티 함수 ---
inline void Swap(int* front, int* back){
	int tmp = *front;
	*front = *back;
	*back = tmp;
}

void My_Insertion_Sort(int* numbers, int left, int right){
	for(int i = left + 1; i <= right; i++){
		int tmp = numbers[i];
		int j = i;
		while(j > left && numbers[j - 1] > tmp){
            numbers[j] = numbers[j - 1];
            j--;
        }
		numbers[j] = tmp;
	}
}

// --- 2. 힙 정렬 (Heapsort) 컴포넌트 ---
// (이전과 동일)
void heapify(int* arr, int n, int i, int left) {
    int largest = i;          
    int l = 2 * i + 1;        
    int r = 2 * i + 2;        

    if (l < n && arr[left + l] > arr[left + largest])
        largest = l;
    if (r < n && arr[left + r] > arr[left + largest])
        largest = r;
    if (largest != i) {
        Swap(&arr[left + i], &arr[left + largest]);
        heapify(arr, n, largest, left);
    }
}
void My_Heap_Sort_Range(int* arr, int left, int right) {
    int n = right - left + 1; 
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, left);
    for (int i = n - 1; i > 0; i--) {
        Swap(&arr[left], &arr[left + i]);
        heapify(arr, i, 0, left);
    }
}

// --- 3. 퀵 정렬 (Quicksort) 컴포넌트 ---

// 피벗 선택 (세 값의 중위값)
int Median_of_three(int a, const int index_a, int b, const int index_b, int c, const int index_c){
    if ((a < b) ^ (a < c)) return index_a;
    else if ((b < a) ^ (b < c)) return index_b;
    else return index_c;
}

// *** 2-WAY 파티션 (원래의 Lomuto 방식) ***
int Partition_2_way(int* numbers, int left, int right){
    // 1. 피벗 선택
    int mid_point = (left+right)/2;
	int point = Median_of_three(numbers[left], left, numbers[mid_point], mid_point, numbers[right], right);
    int pivot = numbers[point];
	
    // 2. 피벗을 맨 뒤로
	Swap(&numbers[point], &numbers[right]);

    // 3. 2-way 파티션
    int i = left - 1; 
	for(int k = left; k < right; k++){
		if(numbers[k] < pivot){
			i++; 
			Swap(&numbers[i], &numbers[k]);
		}
	}
    // 4. 피벗을 제자리로
	Swap(&numbers[i+1], &numbers[right]);
	return i + 1; // 피벗의 위치
}


// --- 4. 인트로정렬 (Introsort) 메인 로직 ---
const int INSERTION_SORT_THRESHOLD = 24;

void My_Intro_Sort_Loop(int* numbers, int left, int right, int depth_limit) {
    int size = right - left + 1;

    // 베이스 케이스 1: 배열이 매우 작으면 삽입 정렬
    if (size <= INSERTION_SORT_THRESHOLD) {
        if (size > 1) { // 1개 이하면 정렬 필요 없음
            My_Insertion_Sort(numbers, left, right);
        }
        return;
    }

    // 베이스 케이스 2: 재귀가 너무 깊어지면 힙 정렬
    if (depth_limit == 0) {
        My_Heap_Sort_Range(numbers, left, right);
        return;
    }

    // 재귀 단계: 2-way 퀵 정렬
    int pivot_point = Partition_2_way(numbers, left, right);

    My_Intro_Sort_Loop(numbers, left, pivot_point - 1, depth_limit - 1);
    My_Intro_Sort_Loop(numbers, pivot_point + 1, right, depth_limit - 1);
}

// --- 5. 최종 호출 함수 ---
void MyVeryFastSort(int n, int *d){
    if (n <= 1) return;
    int depth_limit = 2 * static_cast<int>(log2(n));
    My_Intro_Sort_Loop(d, 0, n - 1, depth_limit);
}

/////////////////////////////////////////////////////////////////////////
//////////////// YOUR PLAYGROUND ENDS HERE ////////////////
////////////////////////////////////////////////////////////////////////

bool Validate(int n, int *d)
{
	for(int i=1;i<n;i++)
	{
		if( d[i-1] > d[i] )
		{
			return false;
		}
	}	
	return true;
}

int main(int argc, char **argv)
{
	if( argc != 3 )
	{
		fprintf( stderr , "USAGE:  EXECUTABLE   INPUT_FILE_NAME   OUTPUT_FILE_NAME\n");
		return 1;
	}

	// Get input from a binary file whose name is provided from the command line
	int n, *d;
	FILE *input = fopen( argv[1] , "rb" );
	int e = fread( &n , sizeof(int) , 1 , input );
	d = new int [ n ];
	e = fread( d , sizeof(int) , n , input );
	fclose(input);

	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();

	// Call your sorting algorithm
	MyVeryFastSort( n , d );

	std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
	std::chrono::milliseconds elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	double res_time = elapsed_time.count();

	bool res_validate = Validate( n , d );

	// Write the results (corretness and time)
	FILE *output = fopen( argv[2] , "w" );
	if( res_validate ) { fprintf( output , "OKAY\n" ); printf("OKAY\n"); }
	else { fprintf( output , "WRONG\n" ); printf("WRONG\n");  }
	fprintf( output , "%d\n" , (int)res_time );
	printf( "%d\n" , (int)res_time );
	fclose(output);

	delete [] d;

	return 1;
}