//Удобная, хорошая версия
#include <stdio.h>
#include <stdbool.h>

#define LEFT 0
#define CENTRE 1
#define RIGHT 2

const char * aligs[3] = {"влево", "по центру", "вправо"};
const char * onOff[2] = {"Откл" "Вкл"};

struct font {
    unsigned int fontId : 8;
    unsigned int fontSize : 7;
    unsigned int alig : 2;
    bool bold : 1;
    bool it : 1;
    bool und : 1;
};

void showSettings(const struct font * get);
void showMenu(void);

int main(void)
{
    struct font setting = {0, 0, LEFT, 0, 0, 0};
    int choice;
    int IDMask = 255;
    int fontSizeMask = 127;
    int aligMask = 3;

    printf("Текущие настройки шрифта:\n");
    showSettings(&setting);
    showMenu();
    while(scanf("%d", &choice) == 1)
    {
        switch(choice)
        {
            case 1:
              puts("Выберите ID нового шрифта от 0 до 255:");
              scanf("%d", &choice);
              setting.fontId = choice & IDMask;
              puts("");
              break;
            case 2:
              setting.bold = (setting.bold == 0) ? 1 : 0;
              puts("");
              break;
            case 3:
              puts("Выберите новый размер от 0 до 127:");
              scanf("%d", &choice);
              setting.fontSize = choice & fontSizeMask;
              puts("");
              break;
            case 4:
              setting.it = (setting.it == 0) ? 1 : 0;
              puts("");
              break;
            case 5:
              puts("Выберите вариант выравнивания:\n"
                   "0 - Влево\n"
                   "1 - По центру\n"
                   "2 - Вправо");
              scanf("%d", &choice);
              setting.alig = choice & aligMask;
              puts("");
              break;
            case 6:
              setting.und = (setting.und == 0) ? 1 : 0;
              break;
        }
        showSettings(&setting);
        showMenu();
    }

    return 0;
}

void showSettings(const struct font * get)
{
    printf("ID    Размер    Выравнивание      Ж      К      Ч\n");
    printf("%d       %d", get->fontId, get->fontSize);
    switch(get->alig)
    {
        case LEFT:
          printf("          %s", aligs[0]);
          break;
        case CENTRE:
          printf("          %s", aligs[1]);
          break;
        case RIGHT:
          printf("          %s", aligs[2]);
          break;
    }
    printf("       %s", get->bold == false ? "откл" : "вкл");
    printf("    %s", get->it == false ? "откл" : "вкл");
    printf("  %s\n", get->und == false ? "откл" : "вкл");
}
void showMenu(void)
{
    printf("1)Изменить шрифт      3)Изменит размер      5)Изменить выравнивание\n"
            "2)Полужирный          4)Курсив              6)Подчеркнутый\n"
           "q)Завершить\n");
}