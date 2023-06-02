#include <stdio.h>
#include <stdlib.h>

#define MAX_CONTACTS 100

struct Contact {
    char lastName[50];
    char firstName[50];
    char middleName[50];
    long long phoneNumber;
};

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    char* inputFileName = argv[1];
    char* outputFileName = argv[2];

    // Открываем входной файл для чтения
    FILE* inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    // Открываем выходной файл для записи
    FILE* outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        fclose(inputFile); // Закрываем входной файл перед выходом
        return 1;
    }

    // Читаем контакты из файла и записываем их в выходной файл
    struct Contact contact;
    while (fscanf(inputFile, "%s %s %s %lld",
                  contact.lastName,
                  contact.firstName,
                  contact.middleName,
                  &contact.phoneNumber) == 4) {
        fprintf(outputFile, "%s %s %s %lld\n",
                contact.lastName,
                contact.firstName,
                contact.middleName,
                contact.phoneNumber);
    }

    // Закрываем файлы
    fclose(inputFile);
    fclose(outputFile);

    printf("Contacts copied from %s to %s.\n", inputFileName, outputFileName);

    return 0;
}

