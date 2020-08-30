#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define MAX_LINE 100
int main(void) {
	//변수 선언
	int line_count, count;
	char line[MAX_LINE], **line_list;
	FILE *read, *write;
	//파일 입력 선언
	read = fopen("Frozen_snowman.txt", "r");
	assert(read != NULL);//오류 확인
	line_count = 0;
	//파일 읽기
	while (fgets(line, MAX_LINE, read) != NULL) {
		line_count++;
	}
	rewind(read);
	//배열 공간 동적 할당
	line_list = (char**)malloc(line_count * sizeof(char *));
	count = 0;
	while (fgets(line, MAX_LINE, read) != NULL) {
		//파일 읽기
		line_list[count] = (char *)malloc(MAX_LINE * sizeof(char));
		strcpy(line_list[count++], line);
	}
	fclose(read);//파일 닫기
	//파일 출력 선언
	write = fopen("Frozen_snowman_reversed.txt", "w");
	assert(write != NULL);//오류 확인
	//파일 역순으로 출력하기
	for(line_count -= 1;line_count >= 0; line_count--){
		//파일 쓰기
		fputs((const char *) line_list[line_count],write);
	}
	fclose(write);//파일 닫기
	return 0;
}