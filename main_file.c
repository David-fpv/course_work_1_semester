#include <stdio.h>

char test[20]; /////////////////////////////////////////////////////////////////////////////////удалить
int number_of_accounts = 0;     // для хранения кол-ва аккаунтов
int number_of_participants = 0; // для хранения кол-ва участников
FILE *accounts_file;            // ссылка на файл с аккаунтами
FILE *participants_file;        // ссылка на файл с участниками конкурса

static struct account // структура для пользователей программой
    {
        char login[20];    
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
        char tool[20];        // инструмент
        int place;            // место
    };
static struct participant participant_information[20]; // делается глобальной для облегчения работы функций

int loading_accounts(void);

int loading_participants(void);

int main(void) {
    
    char login[50];
    char password[50];

    if (!(accounts_file = fopen("accounts.txt", "r+t"))) { // открытие файла в режиме чтения и записи
        printf("Не удальлось открыть файл с аккаунтами.\n");
        return 1;
    } else {
        printf("Файл с аккаунтами открыт успешно. \n");
        loading_accounts();
    }

    for (int i = 0; i < number_of_accounts; i++) {
        printf("%s\n", account_information[i].login);
        printf("%s\n", account_information[i].password);
    }

    if (!(participants_file = fopen("participants.txt", "r+t"))) { // открытие файла в режиме чтения и записи
        printf("Не удалось открыть файл c участниками конкурса.\n");
        return 1;
    } else {
        printf("Файл с участниками конкурса открыт успешно. \n");
        loading_participants();
    }
    
    for (int i = 0; i < number_of_participants; i++) {
        printf("%s\n", participant_information[i].name);
        printf("%s\n\n", participant_information[i].tool);
    }

    return 0;
}

int loading_accounts(void) {
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

int loading_participants(void) {
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