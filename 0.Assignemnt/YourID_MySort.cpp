#include <cstdio>
#include <chrono>
#include <cmath>


/////////////////////////////////////////////////////////////////////////
//////////////// YOUR PLAYGROUND FROM HERE ////////////////
////////////////////////////////////////////////////////////////////////

int Gen_Random_Number(int min, int max){
	auto now_time = std::chrono::system_clock::now();
	auto duration = now_time.time_since_epoch();

	auto nano_sec = std::chrono::duration_cast<std::chrono::nanoseconds>(duration).count();

	int range = max - min + 1;
	
	return min + (unsigned long long) nano_sec % range
}

void Swap(int* front, int* back){
	int tmp = *front;
	*front = *back;
	*back = tmp;
}

void Partition(int* numbers, int left, int right){
	int point = Gen_Random_Number(left, right);
	int pivot = numbers[point];
	int i = left - 1; // pivot보다 작은 수가 없다고 생각하고 시작
	
	// pivot을 배열의 마지막 위치로 보냄
	Swap(&numbers[pivot], &numbers[right]);

	for(int k = left; k < right; k++){
		if(numbers[k] <= pivot){
			i++;
		}
	}
}

void My_Insertion_Sort(int* numbers, int left, int right){

}

void My_Quick_Sort(int* numbers, int left, int right){
	int size = left - right;
	if(left < right && size <= 8){
		My_Insertion_Sort(numbers, left, right);
	}else if(left < right){
		int point_pivot = Partition(numbers, left, right);

	}
}

void MyVeryFastSort(int n, int *d)
{


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