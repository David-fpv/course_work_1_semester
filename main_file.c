#include <stdio.h>
#define NUMBER_OF_USERS 3



int main(void) {
    char login[50];
    char password[50];

     struct account
     {
        char login[20];
        char password[20];
        int role; // 1 - администратор,  0 - обычный пользователь 
     } user[NUMBER_OF_USERS];

     /*user[0].login = "Mindowg";
     user[0].password = "1195-1263";
     user[0].role = 0;*/

    
     user[2].login[0] = 'T';
     user[2].password = "password";
     user[2].role = 1;

    FILE *f;

    if (!(f = fopen("competitors_1.txt", "r+t"))) { // открытие файла в режиме чтения и записи
        printf("Невозможно открыть файл \n");
    } else {
        printf("Файл открыт или создан");
    }

    while(1) { // основное тело программы
        printf("Введите пожалуйста логин \n");
        gets(login);
        for (int i = 0; i < NUMBER_OF_USERS; i++) {
            if (user[i].login == login) {
                printf("Введите пожалуйста пароль \n");
                gets(password);
            }
        }
    }

    return 0;
}