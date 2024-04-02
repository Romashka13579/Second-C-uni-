#include "stdio.h"
#pragma warning(disable:4996)
#include <iostream>
#include <windows.h>
#include <time.h>
#include <conio.h>


int uloha_2_1_1() {
    int result = 0;
    __asm
    {
        MOV eax, 2
        MOV ebx, 3
        ADD eax, ebx
        MOV result, eax
    }
    printf("%d\n", result);
}

int uloha_2_1_2(int cislo) {
    int result = 0;
    __asm
    {
        MOV eax, cislo
        SHL eax, 1
        MOV result, eax
    }
    printf("%d\n", result);
}

int uloha_2_1_3(int cislo) {
    int result = 0;
    __asm
    {
        MOV eax, cislo
        CMP eax, 9
        JG point
        ADD eax, '0'
        JMP END
        point :
        ADD eax, 55
            JMP END
            END :
        MOV result, eax;
    }
    printf("cislo in hexadecimal = %c\n", result);
}

void uloha_2_1_4(unsigned int* a, unsigned int* b, unsigned int* c, unsigned int* d) {
    __asm
    {
        mov eax, 0    // Set up the function code
        cpuid            // Execute CPUID instruction
        mov edi, a       // Move the address of a into edi
        mov[edi], eax   // Store the result of CPUID into a
        mov edi, b       // Move the address of d into edi
        mov[edi], ebx   // Store the result of CPUID into d
        mov edi, c       // Move the address of a into edi
        mov[edi], ecx   // Store the result of CPUID into a
        mov edi, d       // Move the address of d into edi
        mov[edi], edx   // Store the result of CPUID into d
    }
}

int uloha_2_2() {
    char string[] = "architektura_pocitacov_je_super_predmet";
    int strlength = sizeof(string) / sizeof(char);
    for (int i = 0; i < strlength; i++) {
        printf("%c", string[i]);
    }
    char* pointerstr = string;
    printf("\n%p\n", pointerstr);
    pointerstr += 1;
    *pointerstr = *"A";
    for (int i = 0; i < strlength; i++) {
        printf("%c", string[i]);
    }
    pointerstr += 1000000;
//    *pointerstr = *"A";
    //for (int i = 0; i < strlength; i++) {
    //    printf("%c ", string[i]);
    //}


    int pole[] = { 1, 2, 3, 4, 5 };
    int length = sizeof(pole) / sizeof(int);
    printf("\n");
    for (int i = 0; i < length; i++) {
        printf("%d ", pole[i]);
    }
    int* pointer = pole;
    printf("\n%p\n", pointer);
    pointer += 1;
    *pointer = 10;
    for (int i = 0; i < length; i++) {
        printf("%d ", pole[i]);
    }
    return 0;
}

int uloha_2_3_1() {
    FILE* fr;
    FILE* fw;
    fr = fopen("poviedka.html", "r");
    char ch;
    if (!fr) {
        printf("not");
    }
    else {
        while ((ch = fgetc(fr)) != EOF) {
            int char2 = ch;
            if (char2 == 165) char2 = 188;
            else if (char2 == 165) char2 = 188;
            else if (char2 == 169) char2 = 138;
            else if (char2 == 171) char2 = 141;
            else if (char2 == 174) char2 = 142;
            else if (char2 == 181) char2 = 190;
            else if (char2 == 185) char2 = 154;
            else if (char2 == 187) char2 = 157;
            else if (char2 == 190) char2 = 158;
            printf("%c", char2);
        }
    }
    return 0;
}

int uloha_2_5_1_pomocny() {
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int k = 0; k <= 255; k++) {
        SetConsoleTextAttribute(hConsole, k);
        printf("color\n");
    }
    return 0;
}

int uloha_2_5_1() {
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int i = 0; i <= 100; i++) {
        if (i <= 10) {
            SetConsoleTextAttribute(hConsole, 10);
        }
        else if (i <= 22) {
            SetConsoleTextAttribute(hConsole, 4);
        }
        else if (i <= 35) {
            SetConsoleTextAttribute(hConsole, 1);
        }
        else if (i <= 50) {
            SetConsoleTextAttribute(hConsole, 5);
        }
        else if (i <= 100) {
            SetConsoleTextAttribute(hConsole, 3);
        }
        Sleep(100);
        printf("%.3d\n", i);
    }
    return 0;
}

int LinePrinf(char text[], char info[], int length) {
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    int k = 0;

    printf("%c", 179);
    SetConsoleTextAttribute(hConsole, 10);
    printf("%s", text);
    SetConsoleTextAttribute(hConsole, 6);
    printf("%c ", 179);
    for (int j = 0; j < length; j++) {
        if (length - j <= strlen(info)) {
            SetConsoleTextAttribute(hConsole, 10);
            printf("%c", info[k]);
            k++;
        }
        else {
            printf(" ");
        }
    }
    SetConsoleTextAttribute(hConsole, 6);
    printf(" %c", 179);
    return 0;
}

int uloha_2_5_2() {
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    COORD point = { 50, 10 };
    char meno[] = "Roman Rudenko";
    char vyska[] = "180cm";
    char hmotnost[] = "80kg";
    char tel[] = "0968856930";

    int length = strlen(meno);
    length = (length >= strlen(vyska)) ? length : strlen(vyska);
    length = (length >= strlen(hmotnost)) ? length : strlen(hmotnost);
    length = (length >= strlen(tel)) ? length : strlen(tel);

    char header[] = " Zaznam 001 ";
    int k = 0;

    for (int i = 0; i < 10; i++) {
        SetConsoleCursorPosition(hConsole, point);
        if (i % 2 == 1) {
            SetConsoleTextAttribute(hConsole, 6);
            if (i == 9) {
                for (int j = 0; j < length + 16; j++) {
                    if (j == 0) { printf("%c", 192); }
                    else if (j == length + 15) { printf("%c", 217); }
                    else if (j == 12) { printf("%c", 193); }
                    else { printf("%c", 196); }
                }
            }
            else {
                for (int j = 0; j < length + 16; j++) {
                    if (j == 0) { printf("%c", 195); }
                    else if (j == length + 15) { printf("%c", 180); }
                    else if (j == 12 && i == 1) { printf("%c", 194); }
                    else if (j == 12 && i != 1) { printf("%c", 197); }
                    else { printf("%c", 196); }
                }
            }
        }
        else if (i == 0) {
            k = 0;
            for (int j = 0; j < length + 16; j++) {
                if (j < (length + 16 - strlen(header)) / 2 || j >= (length + 16 + strlen(header)) / 2) {
                    SetConsoleTextAttribute(hConsole, 6);
                    if (j == 0) { printf("%c", 218); }
                    else if (j == length + 15) { printf("%c", 191); }
                    else { printf("%c", 196); }
                }
                else {
                    SetConsoleTextAttribute(hConsole, 10);
                    printf("%c", header[k]);
                    k++;
                }
            }
        }
        else if (i == 2) {
            k = 0;
            char text[] = " Meno      ";
            LinePrinf(text, meno, length);
        }
        else if (i == 4) {
            char text[] = " Vyska     ";
            LinePrinf(text, vyska, length);
        }
        else if (i == 6) {
            char text[] = " Hmotnost  ";
            LinePrinf(text, hmotnost, length);
        }
        else if (i == 8) {
            char text[] = " Tel       ";
            LinePrinf(text, tel, length);
        }
        point.Y += 1;
    }
    return 0;
}

void VypisNavodu() {
    printf("%c", 218);
    for (int i = 0; i < 32; i++) {
        printf("%c", 196);
    }
    printf("%c\n", 191);
    printf("%c                                %c\n", 179, 179);
    printf("%c F1 - vypise navod na pouzitie  %c\n", 179, 179);
    printf("%c                                %c\n", 179, 179);
    printf("%c F2 - spusti meranie            %c\n", 179, 179);
    printf("%c                                %c\n", 179, 179);
    printf("%c F10 alebo ESC - skonci program %c\n", 179, 179);
    printf("%c                                %c\n", 179, 179);
    printf("%c", 192);
    for (int i = 0; i < 32; i++) {
        printf("%c", 196);
    }
    printf("%c\n", 217);
}

int uloha_2_6() {
    clock_t Start, Koniec;
    float Trvanie;

    unsigned char ch = 0;
    unsigned char ch2 = 0;
    char letters[] = "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm,./;'[]{}:\"><|/\\1234567890-=!@#$%^&*()_+";
    do
    {
        if (kbhit()) {
            ch = getch();
            if (ch == 0x00) {
                ch2 = getch();
                switch (ch2)
                {
                case 59:
                    VypisNavodu();
                    break;
                case 68:
                    printf("Koniec");
                    break;
                case 60:
                    srand(time(NULL));
                    int random = rand() % strlen(letters);
                    printf("Stlac: %c\n", letters[random]);
                    Start = clock();
                    do
                    {
                        if (kbhit()) {
                            ch = getch();
                        }
                    } while (ch != letters[random]);
                    Koniec = clock();
                    Trvanie = (float)(Koniec - Start) / CLOCKS_PER_SEC;
                    printf("%g sec\n", Trvanie);
                    break;
                }
            }
        }
    } while (ch != 27 && ch2 != 68);
    return 0;
}

int main() {
    //uloha_2.1.1
    //uloha_2_1_1();

    //uloha_2.1.2
    //uloha_2_1_2(12);
     
    //uloha_2.1.3
    //uloha_2_1_3(9);

    //uloha_2.1.4
    //unsigned int eax, ebx, ecx, edx;
    //uloha_2_1_4(&eax, &ebx, &ecx, &edx);

    //printf("CPU Features:\n");
    //printf("EDX: %X\n", eax);
    //printf("EAX: %X\n", ebx);
    //printf("EDX: %X\n", ecx);
    //printf("EAX: %X\n", edx);

    //uloha_2_2
    //uloha_2_2();

    //uloha_2_3_1
    //uloha_2_3_1();

    //uloha_2_5_1
    //uloha_2_5_1();
    //uloha_2_5_1_pomocny();

    //uloha_2_5_2
    //uloha_2_5_2();
     
    //uloha_2_6
    uloha_2_6();
}
