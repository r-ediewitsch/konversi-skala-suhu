//Nama: Muhammad Riyan Satrio Wibowo
//NPM: 2306229323

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

enum{
    CELCIUS, 
    REAMUR, 
    KELVIN, 
    FAHRENHEIT
};

struct data{
    float skala;
    float beku;
};

const struct data Suhu[] = {{5, 0}, {4, 0}, {5, 273.15}, {9, 32}};

void printASCII();
void printMenu();
void printConvert();
void printHelp();
void inputMenu(int *menu);
int modeCheck(char mode);
const char *getScale(int mode);
char getChar(int mode);
void inputPilihan(char prev, char *mode, char *pos);
float convertSuhu(float suhu, int awal, int akhir, const struct data *Suhu);

int main() {
    float suhuAwal, suhuAkhir;
    char awal, akhir, mode[10];
    int menu;

    printASCII();
    system("pause");
    
    do{
        inputMenu(&menu);
        switch(menu){
            case 1:
                inputPilihan(awal, &awal, strcpy(mode, "awal"));
                inputPilihan(awal, &akhir, strcpy(mode, "akhir"));
                
                printf("Masukkan suhu awal: ");
                scanf("%f", &suhuAwal);

                suhuAkhir = convertSuhu(suhuAwal, modeCheck(awal), modeCheck(akhir), Suhu);

                printf("\nHasil konversi %.2f%c%c ke skala %s adalah: %.2f%c%c\n\n", 
                suhuAwal, getChar(modeCheck(awal)), toupper(awal), getScale(modeCheck(akhir)), 
                suhuAkhir, getChar(modeCheck(akhir)), toupper(akhir));
                
                system("pause");
                break;
            case 2:
                printHelp();
                system("pause");
                break;
            case 3:
                system("pause");
                break;
            default:
                break;
        }
    } while(menu != 3);
    
    return 0;
}

void printASCII(){
    printf("    __ ______  _   ___    ____________  _____ ____\n");
    printf("   / //_/ __ \\/ | / / |  / / ____/ __ \\/ ___//  _/\n");
    printf("  / ,< / / / /  |/ /| | / / __/ / /_/ /\\__ \\ / /  \n");
    printf(" / /| / /_/ / /|  / | |/ / /___/ _, _/___/ // /   \n");
    printf("/_/_|_\\____/_/_|_/__|___/_____/_/_|_|/____/___/   \n");
    printf("  / ___//   |/_  __/ / / /   |  / | / /           \n");
    printf("  \\__ \\/ /| | / / / / / / /| | /  |/ /            \n");
    printf(" ___/ / ___ |/ / / /_/ / ___ |/ /|  /             \n");
    printf("/____/_/ _|_/_/__\\____/_/__|_/_/ |_/              \n");
    printf("  / ___// / / / / / / / / /                       \n");
    printf("  \\__ \\/ / / / /_/ / / / /                        \n");
    printf(" ___/ / /_/ / __  / /_/ /                         \n");
    printf("/____/\\____/_/ /_/\\____/                          \n\n");
}

void printMenu(){
    printf("===============================\n");
    printf("|         Menu  Utama         |\n");
    printf("===============================\n");
    printf("| 1. Konversi Suhu            |\n");
    printf("| 2. Bantuan                  |\n");
    printf("| 3. Exit                     |\n");
    printf("===============================\n");
}

void printConvert(){
	printf("===============================\n");
    printf("|    Skala Pengukuran Suhu    |\n");
    printf("===============================\n");
    printf("| C. Celcius                  |\n");
    printf("| R. Reamur                   |\n");
    printf("| K. Kelvin                   |\n");
    printf("| F. Fahrenheit               |\n");
    printf("===============================\n");
}

void printHelp(){
    system("cls");
    printASCII();

    printf("-- Program untuk Melakukan Konversi Suhu sesuai Skala Awal dan Akhir yang Diinput --\n\n");
    printf("Program ini memiliki 3 menu utama, antara lain:\n");
    printf("1. Konversi Suhu: Berfungsi untuk melakukan konversi suhu.\n");
    printf("   Input skala awal dan akhir bersifat case insensitive, sehingga besar kecilnya huruf tidak berpengaruh.\n");
    printf("2. Bantuan: Berfungsi untuk menampilkan menu ini.\n");
    printf("3. Exit: Berfungsi untuk keluar dari program.\n\n");
    printf("Untuk melakukan konversi suhu, digunakan rumus sebagai berikut:\n");
    printf("=============================================================================================\n");
    printf("|                                                     Skala Akhir                           |\n");
    printf("| Suhu Akhir = (Suhu Awal - Titik Beku Skala Awal) x ------------- + Titik Beku Skala Akhir |\n");
    printf("|                                                      Skala Awal                           |\n");
    printf("=============================================================================================\n\n");
}

void inputMenu(int *menu){
    system("cls");
    printMenu();

    printf("\nMasukkan pilihan: ");
    scanf("%d", menu);

    if(*menu < 1 || *menu > 3){
        printf("Input salah, mohon input sesuai di pilihan!\n\n");
        system("pause");
        inputMenu(menu);
    }
}

int modeCheck(char mode){
    switch(toupper(mode)){
        case 'C':
            return CELCIUS;
        case 'R':
            return REAMUR;
        case 'K':
            return KELVIN;
        case 'F':
            return FAHRENHEIT;
        default:
            return -1;
    }
}

const char *getScale(int mode){
    switch(mode){
        case CELCIUS:
            return "Celcius";
        case REAMUR:
            return "Reamur";
        case KELVIN:
            return "Kelvin";
        case FAHRENHEIT:
            return "Fahrenheit";
        default:
            break;
    }
}

char getChar(int mode){
    switch(mode){
        case CELCIUS:
        case REAMUR:
        case FAHRENHEIT:
            return 248;
        case KELVIN:
            return 32;
        default:
            break;
    }
}

void inputPilihan(char prev, char *mode, char *pos){
    system("cls");
    printConvert();

    if(strcmp(pos, "akhir") == 0)
        printf("\nMasukkan skala suhu awal: %c", prev);

    printf("\nMasukkan skala suhu %s: ", pos);
    scanf(" %c", mode);

    if(modeCheck(*mode) == -1){
        printf("Input salah, mohon masukkan skala sesuai di pilihan!\n\n");
        system("pause");
        inputPilihan(prev, mode, pos);
    }
}

float convertSuhu(float suhu, int awal, int akhir, const struct data *Temp){
    suhu -= Temp[awal].beku;
    suhu *= (Temp[akhir].skala/Temp[awal].skala);
    suhu += Temp[akhir].beku;

    return suhu;
}