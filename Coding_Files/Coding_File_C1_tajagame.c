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

    printf("Ÿ�ڿ����� �����մϴ�.\n");
	printf("�����Ϸ��� sŰ�� �����ּ���: ");
	scanf("%c", &s);
	fgetc(stdin);
	printf("\n");

    if (s == 's')
    {
        printf("������ ���� ����: ");
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

        printf("======= [Ÿ�� ���� ���] =======\n\n");
        printf("      ���� �ܾ��: %d��/%d��\n", wordscore, count);
        printf("      ��Ȯ��: %.1f%%\n", (double)(wordscore*100/count));
        printf("      �� �ɸ� �ð�: %.2f��\n", runtime);
        printf("      Ÿ�ڼ�: %.1fŸ\n\n", score*60/runtime);
        printf("================================\n");

    } else {
        printf("���α׷��� �����մϴ�.\n");
    }

    return 0;

}

void question(char (*wordlists) [20], int n, int i, int *score, int *wordscore)
{
    int num = (rand() % n);
    char *word_i = wordlists[num];
    char answer[20] = {};

    printf("[%d�� ����]\n", i+1);
    printf("�ܾ�: %s\n", word_i);
    printf("�Է�: ");
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
        printf("�����Դϴ�.\n\n");
        *wordscore += 1;
    } else {
        printf("�����Դϴ�.\n\n");
    }
}
