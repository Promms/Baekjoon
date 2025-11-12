#include <cstdio>
#include <chrono>
#include <cmath>
#include <algorithm>


/////////////////////////////////////////////////////////////////////////
//////////////// YOUR PLAYGROUND FROM HERE ////////////////
////////////////////////////////////////////////////////////////////////

int Median_of_three(int a, const int index_a, int b, const int index_b, int c, const int index_c){
    if ((a < b) ^ (a < c)) return index_a;
    else if ((b < a) ^ (b < c)) return index_b;
    else return index_c;
}

inline void Swap(int* front, int* back){
	int tmp = *front;
	*front = *back;
	*back = tmp;
}

int Partition(int* numbers, int left, int right){
    int mid_point = (left+right)/2;
	int point = Median_of_three(numbers[left], left, numbers[mid_point], mid_point, numbers[right], right);
    int pivot = numbers[point];
	int i = left - 1; // pivot보다 작은 수가 없다고 생각하고 시작
	
	// pivot을 배열의 마지막 위치로 보냄
	Swap(&numbers[point], &numbers[right]);

	for(int k = left; k < right; k++){
		if(numbers[k] < pivot){
			i++; // pivot보다 작은 수 +1
			Swap(&numbers[i], &numbers[k]); // pivot보다 작은 수를 한 쪽으로 모음
		}
	}
	Swap(&numbers[i+1], &numbers[right]); // pivot보다 작은 수들을 numbers[i]까지 모았으니 그 다음 위치에 pivot을 둠
	return i + 1; // pivot의 위치를 리턴
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

void My_Quick_Sort(int* numbers, int left, int right){
    if(left >= right) return;
	int size = right - left + 1;
	if(size <= 16){
		My_Insertion_Sort(numbers, left, right);
        return;
	}
    int point_pivot = Partition(numbers, left, right);
    My_Quick_Sort(numbers,left,point_pivot- 1); // 피봇보다 작은 부분을 정렬
    My_Quick_Sort(numbers,point_pivot+1,right); // 피봇보다 큰 부분을 정렬
}

int Partition_by_bit(int* numbers, int left, int right, int bit_pos){
    int mask = 1 << bit_pos;
    int zero_pos = left;
    int one_pos = right;

    while(zero_pos <= one_pos){
        while(zero_pos <= one_pos && (numbers[zero_pos] & mask) == 0) zero_pos++;
        while(zero_pos <= one_pos && (numbers[one_pos] & mask) != 0) one_pos--;
        if(zero_pos < one_pos){
            Swap(&numbers[zero_pos++], &numbers[one_pos--]);
        }
    }
    return zero_pos; // 비트가 1인 부분이 시작하는 위치
}

void My_MSD_Partition_Sort(int* numbers, int left, int right, int bit_pos){
    if(left >= right)   return;

    int cut_of_bit = 24;
    int cut_of_size = 512;

    if(bit_pos < cut_of_bit || (right - left + 1) < cut_of_size){
        My_Quick_Sort(numbers, left, right);
        return;
    }

    int mid = Partition_by_bit(numbers, left, right, bit_pos);

    My_MSD_Partition_Sort(numbers, left, mid - 1, bit_pos - 1);
    My_MSD_Partition_Sort(numbers, mid, right, bit_pos - 1);
}

void Hybrid_MSD_Quick_Sort(int* numbers, int n){
    if(n <= 1) return;
    for(int i = 0; i < n; i++){
        // signed integer의 MSB는 음수에서 1, 양수에서 0이기 때문에
        // MSB를 뒤집어서 음수가 양수보다 앞에 올 수 있게 했다.
        numbers[i] ^= 0x80000000;
    }
    My_MSD_Partition_Sort(numbers, 0, n-1, 31);

    for(int i = 0; i < n; i++){
        // 앞서 MSB를 뒤집었기 때문에 다시 원래의 MSB로 돌려놓았다.
        numbers[i] ^= 0x80000000;
    }
}

void MyVeryFastSort(int n, int *d){
	Hybrid_MSD_Quick_Sort(d, n);
	//std::sort(d, d + n); 속도 비교를 위해 남겨둠
}

/////////////////////////////////////////////////////////////////////////
//////////////// YOUR PLAYGROUND ENDS HERE ////////////////
////////////////////////////////////////////////////////////////////////

// Utilized to check the correctness
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