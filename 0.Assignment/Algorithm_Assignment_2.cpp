#include <cstdio>
#include <chrono>
#include <cmath>


/////////////////////////////////////////////////////////////////////////
//////////////// YOUR PLAYGROUND FROM HERE ////////////////
////////////////////////////////////////////////////////////////////////

// XorShift32 난수 생성기
int Gen_Random_Number(int min, int max, unsigned int& seed){
	// seed가 0인 상황을 방지
	seed += 1;
	seed ^= (seed << 13);
	seed ^= (seed >> 17);
	seed ^= (seed << 5);
	int range = max - min + 1;
	return min + (unsigned int)(seed % range);
}

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


void Three_way_partition(int* numbers, int left, int right, int& same_start, int& same_end){
	unsigned int seed = left + right;
	int r_num_1 = Gen_Random_Number(left, right, seed);
	int r_num_2 = Gen_Random_Number(left, right, seed);
	int r_num_3 = Gen_Random_Number(left, right, seed);
	int point = Median_of_three(numbers[r_num_1], r_num_1, numbers[r_num_2], r_num_2, numbers[r_num_3], r_num_3);
    int pivot = numbers[point];
	
	int point_small = left - 1;
	int point_same = left - 1;
	
	// pivot을 배열의 마지막 위치로 보냄
	Swap(&numbers[point], &numbers[right]);

	for(int k = left; k < right; k++){
		if(numbers[k] < pivot){
			point_small++; // pivot보다 작은 수 +1
			point_same++; // pivot과 같은 수 +1
			Swap(&numbers[point_small], &numbers[k]); // pivot보다 작은 수를 한 쪽으로 모음

			if(point_small != point_same){
				Swap(&numbers[point_same], &numbers[k]);
				// 같은 수가 있었는데 pivot보다 작은 수와 swap이 일어나서 같은 수가 k의 위치로 갔으면
				// 그 같은 수를 point_same 위치로 보내야 함
			}
		}else if(numbers[k] == pivot){
			point_same++;
			Swap(&numbers[point_same], &numbers[k]);
		}
	}
	Swap(&numbers[point_same+1], &numbers[right]); // pivot보다 작은 수들을 numbers[i]까지 모았으니 그 다음 위치에 pivot을 둠

	same_start = point_small + 1;
	same_end = point_same + 1;
}

void My_Quick_Sort(int* numbers, int left, int right){
    if(left >= right) return;
	int size = right - left + 1;
	if(size <= 24){
		My_Insertion_Sort(numbers, left, right);
        return;
	}

	int left_point, right_point;
    Three_way_partition(numbers, left, right, left_point, right_point);
    My_Quick_Sort(numbers, left, left_point - 1);
    My_Quick_Sort(numbers, right_point + 1,right);
}

void My_MSD_Radix_Sort_8bit(int* numbers, int* tmp, int left, int right, int shift){
    int size = right - left + 1;

	// 크기가 64보다 작아지면 바로 quick sort로 전환
	if(size < 64){
		My_Quick_Sort(numbers, left, right);
		return;
	}

	if(shift < 0) return; // 8비트씩 나누는데 더 이상 나눌 비트가 없으면 종료

	// 8비트를 기준으로 버킷을 나눌 것이기 때문에 256개의 버킷을 만들고
	// 각 버킷의 count를 0으로 초기화 -> 자기보다 작은 숫자가 몇 번 나왔는지 세는 역할
	const int Num_Buckets = 256;
	int count[Num_Buckets + 1] = {0};

	// 음수는 Sign bit이 1, 양수는 0이기 때문에 첫 버킷을 나누는 단계에서
	// 오름차순을 만들기 위해서는 sigh bit을 반대로 생각해서 계산해야한다.
	// shift가 24가 아닐 때는 a ^ 0 = a 이기 때문에 아무런 영향을 미치지 않는다.
	int Signbit_key = (shift == 24) ? 0x80 : 0x00;

	for(int i = left; i <= right; i++){
		// 1111 1111 와의 and 연산을 통해 numbers[i]의 8비트를 masking함
		// 그 후 sign bit과의 xor을 통해 첫 shift에서 MSB를 반대로 뒤집어준다.
		int byte = ((numbers[i] >> shift) & 0xFF) ^ Signbit_key;
		count[byte + 1]++;
	}

	// 누적합으로 자기보다 작은 숫자가 몇 번 나왔는지 셈
	for(int i = 0; i < Num_Buckets; i++)
		count[i + 1] += count[i];
	
	// 내 시작 위치는 자기보다 작은 숫자가 모두 나온 위치
	int bucket_start[Num_Buckets];
	for(int i = 0; i < Num_Buckets; i++)
		bucket_start[i] = count[i];

	// count에 저장된 bucket의 시작위치를 이용해 올바른 bucket에 숫자를 넣는다
	for(int i = left; i <= right; i++){
		int byte = ((numbers[i] >> shift) & 0xFF) ^ Signbit_key;
		tmp[left + count[byte]++] = numbers[i];
	}

	for(int i = left; i <= right; i++){
        numbers[i] = tmp[i];
    }

	for(int i = 0; i < Num_Buckets; i++){
        int b_start = left + bucket_start[i];
        int b_end = left + count[i] - 1; 
        
        if(b_start < b_end){
            My_MSD_Radix_Sort_8bit(numbers, tmp, b_start, b_end, shift - 8);
        }
    }
}

void MyVeryFastSort(int n, int *d){
	if(n <= 1)		return;

	int* tmp = new int[n];
	My_MSD_Radix_Sort_8bit(d, tmp, 0, n-1, 24);
	delete[] tmp;
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