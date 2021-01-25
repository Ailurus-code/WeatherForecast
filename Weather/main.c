#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define maxn 1000
#define StringSize 30
#define debug fprintf(output, "OK\n");
#define SIZE 100

FILE *input, *output, *ThisDay;

//Функция, проверяющая совпадает ли данная дата с текущей.
int CheckDate(int day, int month, int year)
{
    struct tm *time_struct; //Структура из библиотеки time.h
    char *date;
    const time_t timer = time(NULL);
    time_struct = localtime(&timer);
    char temp[SIZE] = {0};
    int length = strftime(temp, SIZE, "%d.%m.%Y", time_struct);
    date = (char *) malloc(sizeof(temp));
    strcpy(date, temp);
    char DateInInput[SIZE] = {0};
    sprintf(DateInInput, "%d%d.%d%d.%d", day / 10, day % 10 - 1, month / 10, month % 10, year);
    if (!(strcmp(DateInInput, date))) return 1;
    else return 0;
}

//Достает рандомное предложение из файла словаря
char *RandomPhrase(FILE *Dictionary)
{
    int n, idx;
    char Phrase[SIZE];
    fscanf(Dictionary, "%d", &n);
    idx = rand() % n;
    for (int i = 0; i < idx; i++)
    {
        fgets(Phrase, SIZE, Dictionary);
    }
    Phrase[strlen(Phrase) - 1] = '\0';
    return Phrase;
}

//Выводит первое предложение с датой (если нужно).
char *DateInText(int day, int month, int year)
{
    char Date[SIZE];
    if (CheckDate(day, month, year)) strcpy(Date, RandomPhrase(ThisDay));
    else
    {
        char Sentence[4][StringSize] = {"В ночь", "Ночью"};
        if (month == 12 || month <= 2)
        {
            strcpy(Sentence[2], "Зимней ночью");
            strcpy(Sentence[3], "Холодной зимней ночью");
        }
        else if (month >= 3 && month <= 5)
        {
            strcpy(Sentence[2], "Весенней ночью");
            strcpy(Sentence[3], "В начале суток");
        }
        else if (month >= 6 && month <= 8)
        {
            strcpy(Sentence[2], "Летней ночью");
            strcpy(Sentence[3], "Тёплой летней ночью");
        }
        else
        {
            strcpy(Sentence[2], "Осенней ночью");
            strcpy(Sentence[3], "В начале суток");
        }
        strcpy(Date, Sentence[rand() % 4]);
        if (day / 10 != 0)
        {
            if (day / 10 == 1)
            {
                if (day % 10 == 1) strcat(Date, " одиннадцатого");
                else if (day % 10 == 2) strcat(Date, " двенадцатого");
                else if (day % 10 == 3) strcat(Date, " тринадцатого");
                else if (day % 10 == 4) strcat(Date, " четырнадцатого");
                else if (day % 10 == 5) strcat(Date, " пятнадцатого");
                else if (day % 10 == 6) strcat(Date, " шестнадцатого");
                else if (day % 10 == 7) strcat(Date, " семнадцатого");
                else if (day % 10 == 8) strcat(Date, " восемнадцатого");
                else if (day % 10 == 9) strcat(Date, " девятнадцатого");
                else strcat(Date, " десятого");
            }
            else if (day / 10 == 2)
            {
                if (day % 10 == 0) strcat(Date, " двадцатого");
                else
                {
                    strcat(Date, " двадцать");
                    if (day % 10 == 1) strcat(Date, " первого");
                    else if (day % 10 == 2) strcat(Date, " второго");
                    else if (day % 10 == 3) strcat(Date, " третьего");
                    else if (day % 10 == 4) strcat(Date, " четвертого");
                    else if (day % 10 == 5) strcat(Date, " пятого");
                    else if (day % 10 == 6) strcat(Date, " шестого");
                    else if (day % 10 == 7) strcat(Date, " седьмого");
                    else if (day % 10 == 8) strcat(Date, " восьмого");
                    else strcat(Date, " девятого");
                }
            }
            else if (day == 30) strcat(Date, " тридцатого");
            else strcat(Date, " тридцать первого");
        }
        else
        {
            if (day == 1) strcat(Date, " первого");
            else if (day == 2) strcat(Date, " второго");
            else if (day == 3) strcat(Date, " третьего");
            else if (day == 4) strcat(Date, " четвертого");
            else if (day == 5) strcat(Date, " пятого");
            else if (day == 6) strcat(Date, " шестого");
            else if (day == 7) strcat(Date, " седьмого");
            else if (day == 8) strcat(Date, " восьмого");
            else strcat(Date, " девятого");
        }
        char months[12][8] = {"января", "февраля", "марта", "апреля", "мая", "июня",
                              "июля", "августа", "сентября", "октября", "ноября", "декабря"};
        strcat(Date, " "); strcat(Date, months[month-1]);
    }
    return Date;
}

char *MakeFirstSentence(int day, int month, int year)
{
    //ДОДЕЛАТЬ
    char OutputText[SIZE];
    strcpy(OutputText, DateInText(day, month, year));
    return OutputText;
}

//Удаление пробелов после запятых во входных данных
//Запятые могут встречаться в графах "Направление" и "Явления"
//Удаление пробелов необходимо чтобы  правильно считать все нужные элементы в одну строку
char *DeleteSpaceAfterComa(char *FullString)
{
    for (int i = 0; i < strlen(FullString); i++)
    {
        if (FullString[i] == ',')
        {
            for (int j = i + 2; FullString[j - 1] = FullString[j]; j++);    //Сдвиг строки на один элемент влево
        }
    }
    return FullString;
}

//------------------------------------- Генерация прогноза -------------------------------------------------//
void PrintForecast(int day, int month, int year, int night_lowest_temp, int night_highest_temp, int day_lowest_temp,
                   int day_highest_temp, int lowest_feels_like, int highest_feels_like, int pressure,
                   char Preciptation[],
                   char WindSpeed[], char WindDirection[], char WindGusts[], char Phenomenon[])
{
    char answer[SIZE];

    fputs(answer, output);
}

//-----------------------------------------------------------------------------------------------------------//
int main()
{
    srand(time(0));
    input = fopen("tests.txt", "r");        //Файл, в который записываются тесты из генератора
    output = fopen("result.txt", "w");
    ThisDay = fopen("ThisNight", "r");
    char s[maxn];
    int flag = 0;
    while (fgets(s, maxn, input) != 0)
    {
        // Первая строка входного файла пропускается
        if (!flag)
        {
            flag = 1;
            continue;
        }
        else
        {
            *s = DeleteSpaceAfterComa(s);
            //-------------Считывание входных данных------------------//
            int Day, Month, Year, NightLowestTemp,
                    NightHighestTemp, DayLowestTemp, DayHighestTemp,
                    LowestFeelsLike, HighestFeelsLike, Pressure;

            char Preciptation[StringSize] = {0}, WindSpeed[StringSize] = {0},
                    WindDirection[StringSize] = {0}, WindGusts[StringSize] = {0},
                    Phenomenon[StringSize] = {0};

            sscanf(s, "%d.%d.%d%d..%d%d..%d%d..%d%s%s%s%s%d%s", &Day, &Month, &Year, &NightLowestTemp,
                   &NightHighestTemp, &DayLowestTemp, &DayHighestTemp, &LowestFeelsLike, &HighestFeelsLike,
                   Preciptation, WindSpeed, WindDirection, WindGusts, &Pressure, Phenomenon);
            //---------------------------------------------------------//
//            PrintForecast(Day, Month, Year, NightLowestTemp, NightHighestTemp, DayLowestTemp, DayHighestTemp,
//                    LowestFeelsLike, HighestFeelsLike, Pressure, Preciptation, WindSpeed, WindDirection,
//                    WindGusts, Phenomenon);
//            char ans[SIZE] = {0};
//            sprintf(ans, "%s", DateInText(Day, Month, Year));
//            fprintf(output, "%s\n", ans);
        }
    }
    fclose(input);
    fclose(output);
    return 0;
}
