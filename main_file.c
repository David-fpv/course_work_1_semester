#include <stdio.h>

int number_of_accounts = 0;     // для хранения кол-ва аккаунтов
int number_of_participants = 0; // для хранения кол-ва участников
FILE *accounts_file;            // ссылка на файл с аккаунтами
FILE *competitors_file;         // ссылка на файл с участниками конкурса

static struct account // структура для пользователей программой
    {
        char login[20];    
        char password[20]; 
        int role; // 1 - администратор,  0 - обычный пользователь 
    };
    static struct account account_information[10]; // делается глобальной

int loading_accounts(void);

int main(void) {
    
    char login[50];
    char password[50];

    static struct participant // структура для участника
    {
        char fio[50];      // ФИО участника
        int year_of_birth; // год рождения
        char tool[20];     // инструмент
        int place;         // место
    };
    static struct participant participant_information[50]; // делается глобальной для облегчения работы функций

    if (!(accounts_file = fopen("accounts.txt", "r+t"))) { // открытие файла в режиме чтения и записи
        printf("Не удальлось открыть файл с аккаунтами.\n");
        return 0;
    } else {
        printf("Файл с аккаунтами открыт успешно. \n");
        //loading_accounts();
    }

    if (!(competitors_file = fopen("competitors.txt", "r+t"))) { // открытие файла в режиме чтения и записи
        printf("Не удалось открыть файл c участниками конкурса.\n");
        return 0;
    } else {
        printf("Файл с участниками конкурса открыт успешно. \n");
    }
    

    return 0;
}

int loading_accounts(void) {
    int i = 0;
    char place_char; // для того чтобы записать место, а потом перевести в int
    while(feof(accounts_file)) {
       fgets(account_information[i].login, 20, accounts_file); 
       fgets(account_information[i].password, 20, accounts_file); 
       fgets(place_char, 1, accounts_file); 
       account_information[i].role = int(place_char);
       i++;
       number_of_accounts++;
    }
}