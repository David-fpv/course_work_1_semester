#include <stdio.h>
#include <string.h>

char test[20]; /////////////////////////////////////////////////////////////////////////////////удалить
int number_of_accounts = 0;     // для хранения кол-ва аккаунтов
int number_of_participants = 0; // для хранения кол-ва участников
FILE *accounts_file;            // ссылка на файл с аккаунтами
FILE *participants_file;        // ссылка на файл с участниками конкурса

static struct account // структура для пользователей программой
    {
        char login[30];    
        char password[20]; 
        int role; // 1 - администратор,  0 - обычный пользователь 
    };
    static struct account account_information[10]; // делается глобальной

    static struct participant // структура для участника
    {
        char surname[15];     // фамилия участника
        char name[15];        // имя
        char middle_name[15]; // отчество
        int year_of_birth;    // год рождения
        char tool[15];        // инструмент
        int place;            // место
    };
static struct participant participant_information[20]; // делается глобальной для облегчения работы функций

void loading_accounts(void);     // загрузка аккаунтов

void loading_participants(void); // загрузка участников

int get_log_in(void);           // чтобы войти в систему

int isStringsEquals(char *, char *);

int string_length (char *);

int main(void) {

    if (!(accounts_file = fopen("accounts.txt", "r+t"))) { // открытие файла в режиме чтения и записи
        printf("Не удальлось открыть файл с аккаунтами.\n");
        return 1;
    } else {
        printf("Файл с аккаунтами открыт успешно. \n");
        loading_accounts();
    }

    if (!(participants_file = fopen("participants.txt", "r+t"))) { // открытие файла в режиме чтения и записи
        printf("Не удалось открыть файл c участниками конкурса.\n");
        return 1;
    } else {
        printf("Файл с участниками конкурса открыт успешно. \n");
        loading_participants();
    }

    while (1) {
        get_log_in();
        break;
    } 

    return 0;
}

void loading_accounts(void) {
    int i = 0;
    while (1) {
        fscanf(accounts_file, "%s", account_information[i].login);    // считываем логин
        fscanf(accounts_file, "%s", account_information[i].password); // считываем пароль
        fscanf(accounts_file, "%d", &account_information[i].role);    // считываем тип аккаунта
        i++;                                                          // для массива структур

        if (feof(accounts_file)) {                                    // для прекращения чтения из файла, когда он закончится
            break;
        }
    }
    number_of_accounts = i;                                           // для кол-ва аккаунтов
    fclose(accounts_file);                                            // закрытие файла
}

void loading_participants(void) {
    int i = 0;
    while (1) {
        fscanf(participants_file, "%s", participant_information[i].surname);        // считываем фамилию
        fscanf(participants_file, "%s", participant_information[i].name);           // имя
        fscanf(participants_file, "%s", participant_information[i].middle_name);    // отчество
        fscanf(participants_file, "%d", &participant_information[i].year_of_birth); // дату рождения
        fscanf(participants_file, "%s", participant_information[i].tool);           // инструмент
        fscanf(participants_file, "%d", &participant_information[i].place);         // занятое место в конкурсе
        i++;                                                                        // для массива структур

        if (feof(participants_file)) {                                              // для прекращения чтения из файла, когда он закончится
            break;
        }
    }
    number_of_participants = i;                                                      // для кол-ва участников
    fclose(participants_file);                                                       // закрытие файла
}

/*int get_log_in(void) { // для входа в систему
    int flag_1 = 1; // Общий цикл для входа
    int flag_2 = 1;  // возможно ненужна
    int flag_3 = 1; // для while с password
    char login[50];
    char password[50];
    while(flag_1) {    
        printf("Введите свой логин. \n");
        scanf("%s", login);
        for (int i = 0; i < number_of_accounts; i++) { // чтобы проверить не совпадает ли с каким нибудь логином
            if(isStringsEquals(account_information[i].login, login)) {
                printf("Введите свой пароль. \n");
                scanf("%s", password);
                while (flag_3) {
                    if(isStringsEquals(account_information[i].password, password)) {
                        printf("Вы вошли в систему. \n");
                        flag_1 = 0;
                        flag_3 = 0;
                    } else {
                        printf("Неверный пароль. \n");
                        while(flag_2) {

                        }
                    }
                }
            }
            if(i == number_of_accounts) {
                printf("Неверный логин. \n");
                break;
            }
        }
    }
}*/

int get_log_in(void) { // для входа в систему
    int flag_1 = 1; // Общий цикл для входа
    int flag_2 = 1;  // возможно ненужна
    int flag_3 = 1; // для while с password // такого уже нету
    char login[50];
    char password[50];
    char exit_string[2] = "0"; 
    /*do {
        printf("Введите свой логин или \"0\" для выхода. \n");
        scanf("%s", login);
        printf("%d\n", string_length(login));
        /*if (isStringsEquals(exit_string, login)) { // условие для выхода
            printf("Программа завершена. \n");
            return 2;
        }/*
        for (int i = 0; i < number_of_accounts; i++) { // чтобы проверить не совпадает ли с каким нибудь логином
            if(strcmp(account_information[i].login, login) == 0) {
                printf("Введите свой пароль. \n");
                scanf("%s", password);
                if(strcmp(account_information[i].password, password) == 0) {
                    printf("Вы вошли в систему. \n");
                    flag_1 = 0;
                    return account_information[i].role;
                } else {
                    printf("Неверный пароль. \n");
                    break;
                }
            }
            if(i == number_of_accounts) {
                printf("Неверный логин. \n");
                break;
            }
        }
        break;
    }
    while (flag_1);*/
}

int isStringsEquals(char *arr1, char *arr2) { // для проверки совпадают ли строки, нужно для логина, пароля
    if(sizeof(*arr1) == sizeof(*arr2)) {
            for (int i = 0; i < sizeof(*arr1); i++) {
                if (*(arr1 + i) != *(arr2 + i)) {
                    return 0; // не совпадение
                }
            }
        } else {
            return 0; // не совпадение
        }
}