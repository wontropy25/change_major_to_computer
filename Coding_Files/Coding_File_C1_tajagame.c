#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void question(char (*wordlists)[20], int n, int i, int *score, int *wordscore);

int main(void)
{
    int i, score, wordscore, count;
    float runtime;
    char s;

    srand(time(NULL));

    printf("타자연습을 시작합니다.\n");
	printf("시작하려면 s키를 눌러주세요: ");
	scanf("%c", &s);
	fgetc(stdin);
	printf("\n");

    if (s == 's')
    {
        printf("연습할 문제 개수: ");
        scanf("%d", &count);
        fgetc(stdin);
        printf("\n");

        char wordlists[][20] = {"hello", "world", "konkuk", "corona", "campus",
                              "file", "edit", "view", "search", "project",
                              "build", "debug", "fortran", "tools", "plugins",
                              "settings", "help", "global", "local", "variable",
                              "integer", "float", "double", "character", "pointer",
                              "coding", "java", "html", "css", "python",
                              "include", "score", "time", "void", "null",
                              "srand", "printf", "scanf", "else", "while",
                              "for", "switch", "gets", "puts", "define",
                              "continue", "break", "sizeof", "signed", "unsigned"};

        int n = sizeof(wordlists)/sizeof(*wordlists);
        score = 0;
        wordscore = 0;

        clock_t start_time = clock();

        for (int i=0; i<count; i++)
        {
            question(wordlists, n, i, &score, &wordscore);
        }

        float runtime = (float)(clock() - start_time)/(CLOCKS_PER_SEC);

        printf("======= [타자 연습 결과] =======\n\n");
        printf("      맞은 단어수: %d개/%d개\n", wordscore, count);
        printf("      정확도: %.1f%%\n", (double)(wordscore*100/count));
        printf("      총 걸린 시간: %.2f초\n", runtime);
        printf("      타자수: %.1f타\n\n", score*60/runtime);
        printf("================================\n");

    } else {
        printf("프로그램을 종료합니다.\n");
    }

    return 0;

}

void question(char (*wordlists) [20], int n, int i, int *score, int *wordscore)
{
    int num = (rand() % n);
    char *word_i = wordlists[num];
    char answer[20] = {};

    printf("[%d번 문제]\n", i+1);
    printf("단어: %s\n", word_i);
    printf("입력: ");
    gets(answer);

    int flag = 1;

    for (int j = 0;  j < strlen(word_i); j++){
        if (word_i[j] != answer[j]){
            flag = 0;
        } else {
            *score += 1;
        }
    }

    if (flag) {
        printf("정답입니다.\n\n");
        *wordscore += 1;
    } else {
        printf("오답입니다.\n\n");
    }
}
