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

    printf("==== ����Ų��� 31 ���� ====\n");
    printf("���� 3������ �Է� �����մϴ�.\n");

    printf("���� ���� �����ұ��? (0: ��ǻ�� / 1: �÷��̾�) >> ");
    int order;
    scanf("%d", &order);

    printf("\n================================================\n\n");

    if (order) {
        result = player_start(&mynum, &comnum, &score);
    } else {
        result = computer_start(&mynum, &comnum, &score);
    }

    if (result) {
        printf("�÷��̾� �й�\n");
    } else {
        printf("�÷��̾� �¸�\n");
    }

    return 0;
}

int player_start(int * mynum, int * comnum, int *score)
{
    while (*score < 31){
        srand(time(NULL));
        int n;
        n = (rand()%3)+1;

        printf("%d���� � ������ų���? 1 ~ 3 �߿��� �Է��ϼ���: ", *score);
        scanf("%d", &*mynum);

        if (*mynum > 3 || *mynum < 1) {
            printf("�ٽ� �Է��ϼ���.\n");
            continue;
        }
        *score += *mynum;
        printf("%d���� ����Ǿ����ϴ�.\n\n", *score);
        if (*score >= 31)
            return 1;

        printf("��ǻ�ʹ� %d���� �������׽��ϴ�.\n", n);
        *score += n;
        printf("%d���� ����Ǿ����ϴ�.\n\n", *score);
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

        printf("��ǻ�ʹ� %d���� �������׽��ϴ�.\n", n);
        *score += n;
        printf("%d���� ����Ǿ����ϴ�.\n\n", *score);
        if (*score >= 31)
            return 0;

    MYTURN:
        printf("%d���� � ������ų���? 1 ~ 3 �߿��� �Է��ϼ���: ", *score);
        scanf("%d", &*mynum);

        if (*mynum > 3 || *mynum < 1) {
            printf("�ٽ� �Է��ϼ���.\n");
            goto MYTURN;
        }

        *score += *mynum;
        printf("%d���� ����Ǿ����ϴ�.\n\n", *score);
        if (*score >= 31)
            return 1;
    }

}
