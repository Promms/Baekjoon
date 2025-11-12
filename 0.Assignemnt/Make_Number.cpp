#include <cstdio>
#include <cstdlib>
#include <ctime>

void makeReversedNumbers(FILE* fp, int size, int start) {
    // 먼저 크기를 binary로 작성
    fwrite(&size, sizeof(int), 1, fp);
    
    // 역순으로 숫자 생성하여 binary로 작성
    for(int i = 0; i < size; i++) {
        int num = start - i;
        fwrite(&num, sizeof(int), 1, fp);
    }
}

int main() {
    // 배열 크기 설정
    const int SIZE = 100000000;  // 원하는 배열 크기
    const int START = 100000000; // 시작값
    
    // binary 모드로 파일 열기
    FILE* fp = fopen("reverse_input.bin", "wb");
    if(!fp) {
        printf("파일을 열 수 없습니다.\n");
        return 1;
    }
    
    // 역순으로 숫자 생성 및 파일에 작성
    makeReversedNumbers(fp, SIZE, START);
    
    fclose(fp);
    printf("파일 생성 완료: reverse_input.bin\n");
    printf("생성된 숫자 개수: %d\n", SIZE);
    
    return 0;
}