#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int player_start(int * mynum, int * comnum, int *score);
int computer_start(int * mynum, int * comnum, int *score);

int main(void)
{
    int mynum;
    int comnum;
    int score = 0;
    int result;

    printf("==== 베스킨라빈스 31 게임 ====\n");
    printf("숫자 3개까지 입력 가능합니다.\n");

    printf("누가 먼저 시작할까요? (0: 컴퓨터 / 1: 플레이어) >> ");
    int order;
    scanf("%d", &order);

    printf("\n================================================\n\n");

    if (order) {
        result = player_start(&mynum, &comnum, &score);
    } else {
        result = computer_start(&mynum, &comnum, &score);
    }

    if (result) {
        printf("플레이어 패배\n");
    } else {
        printf("플레이어 승리\n");
    }

    return 0;
}

int player_start(int * mynum, int * comnum, int *score)
{
    while (*score < 31){
        srand(time(NULL));
        int n;
        n = (rand()%3)+1;

        printf("%d부터 몇개 증가시킬까요? 1 ~ 3 중에서 입력하세요: ", *score);
        scanf("%d", &*mynum);

        if (*mynum > 3 || *mynum < 1) {
            printf("다시 입력하세요.\n");
            continue;
        }
        *score += *mynum;
        printf("%d까지 진행되었습니다.\n\n", *score);
        if (*score >= 31)
            return 1;

        printf("컴퓨터는 %d개를 증가시켰습니다.\n", n);
        *score += n;
        printf("%d까지 진행되었습니다.\n\n", *score);
        if (*score >= 31)
            return 0;
    }

}

int computer_start(int * mynum, int * comnum, int *score)
{
    while (*score < 31){
        srand(time(NULL));
        int n;
        n = (rand()%3)+1;

        printf("컴퓨터는 %d개를 증가시켰습니다.\n", n);
        *score += n;
        printf("%d까지 진행되었습니다.\n\n", *score);
        if (*score >= 31)
            return 0;

    MYTURN:
        printf("%d부터 몇개 증가시킬까요? 1 ~ 3 중에서 입력하세요: ", *score);
        scanf("%d", &*mynum);

        if (*mynum > 3 || *mynum < 1) {
            printf("다시 입력하세요.\n");
            goto MYTURN;
        }

        *score += *mynum;
        printf("%d까지 진행되었습니다.\n\n", *score);
        if (*score >= 31)
            return 1;
    }

}
