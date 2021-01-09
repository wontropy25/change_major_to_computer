#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int RPS(int *point, int *win, int *draw, int *lose);

int main(void)
{
    printf("====== ���������� ����Ʈ ���� ======\n\n");
    printf("����Ʈ ����: �ִ� 500P���� ����\n�¸�: ������ ����Ʈ ȹ��\n����: ����Ʈ ����\n�й�: ������ ����Ʈ ���\n����Ʈ�� ������ �Ǹ� �ڵ�����\n");
    printf("���� ����Ʈ: 300P\n\n");
    printf("=====================================\n");

    int point = 300;
    char ask;
    int win = 0;
    int draw = 0;
    int lose = 0;

    do {
    printf("\n");
    RPS(&point, &win, &draw, &lose);
    printf("���� ����Ʈ: %dP\n", point);
    if (point < 0) break;
    printf("===========================================================\n");

    printf("������ ��� �����Ͻðڽ��ϱ�? (y�� ������ �����մϴ�.) >> ");
    scanf("%c", &ask);

    } while ((ask == 'y') || (ask == 'Y'));

    printf("\n\n=================================================\n");
    printf("    ������ ����Ǿ����ϴ�. ���� ����Ʈ: %dP    \n\n", point);
    printf("            ���� ����: %d�� %d�� %d��    \n", win, draw, lose);
    printf("=================================================\n");

    return 0;
}

int RPS(int *point, int *win, int *draw, int *lose)
{
    int select;
    srand(time(NULL));
    int n = rand()%3;
    int money;
    char menu[][10] = {"����", "����", "��"};

    do {
        printf("������ �ݾ��� �Է��ϼ��� >> ");
        scanf("%d", &money);
    } while (money <= 0 || money>500 || money>*point);

    printf("(����: 1 / ����: 2 / ��: 3) �߿��� �����ϼ��� >> ");
    scanf("%d", &select);
    fgetc(stdin);

    printf("��ǻ�ʹ� %s�� �½��ϴ�. ", menu[n]);

    int flag = (select - n)%3;

    switch (flag){
    case 0:
        printf("[�й�]\n");
        printf("%dP�� �Ҿ����ϴ�.\n", money);
        *point -= money;
        *lose += 1;
        break;

    case 1:
        printf("[����]\n");
        printf("����Ʈ�� �״�� �����˴ϴ�.\n");
        *draw += 1;
        break;

    default:
        printf("[�¸�]\n");
        printf("%dP�� ������ϴ�.\n", money);
        *point += money;
        *win += 1;
        break;
    }
}

