#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int RPS(int *point, int *win, int *draw, int *lose);

int main(void)
{
    printf("====== 가위바위보 포인트 게임 ======\n\n");
    printf("포인트 베팅: 최대 500P까지 가능\n승리: 베팅한 포인트 획득\n동일: 포인트 유지\n패배: 베팅한 포인트 상실\n포인트가 음수가 되면 자동종료\n");
    printf("시작 포인트: 300P\n\n");
    printf("=====================================\n");

    int point = 300;
    char ask;
    int win = 0;
    int draw = 0;
    int lose = 0;

    do {
    printf("\n");
    RPS(&point, &win, &draw, &lose);
    printf("현재 포인트: %dP\n", point);
    if (point < 0) break;
    printf("===========================================================\n");

    printf("게임을 계속 진행하시겠습니까? (y를 누르면 진행합니다.) >> ");
    scanf("%c", &ask);

    } while ((ask == 'y') || (ask == 'Y'));

    printf("\n\n=================================================\n");
    printf("    게임이 종료되었습니다. 최종 포인트: %dP    \n\n", point);
    printf("            게임 전적: %d승 %d무 %d패    \n", win, draw, lose);
    printf("=================================================\n");

    return 0;
}

int RPS(int *point, int *win, int *draw, int *lose)
{
    int select;
    srand(time(NULL));
    int n = rand()%3;
    int money;
    char menu[][10] = {"가위", "바위", "보"};

    do {
        printf("베팅할 금액을 입력하세요 >> ");
        scanf("%d", &money);
    } while (money <= 0 || money>500 || money>*point);

    printf("(가위: 1 / 바위: 2 / 보: 3) 중에서 선택하세요 >> ");
    scanf("%d", &select);
    fgetc(stdin);

    printf("컴퓨터는 %s를 냈습니다. ", menu[n]);

    int flag = (select - n)%3;

    switch (flag){
    case 0:
        printf("[패배]\n");
        printf("%dP를 잃었습니다.\n", money);
        *point -= money;
        *lose += 1;
        break;

    case 1:
        printf("[동일]\n");
        printf("포인트가 그대로 유지됩니다.\n");
        *draw += 1;
        break;

    default:
        printf("[승리]\n");
        printf("%dP를 얻었습니다.\n", money);
        *point += money;
        *win += 1;
        break;
    }
}

