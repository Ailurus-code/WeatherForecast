#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define maxn 1000
#define StringSize 20
#define debug fprintf(output, "OK\n");
#define SIZE 100

FILE *input, *output;

//char *GetRandomSentence()
//{
//    return;
//}

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
    sprintf(DateInInput, "%d%d.%d%d.%d", day / 10, day % 10, month / 10, month % 10, year);
//    fprintf(output, "%s\n", date);
    if (!(strcmp(DateInInput, date))) return 1;
    else return 0;
}

char *DateInText(int day, int month, int year)
{
    char *Date;
    if (CheckDate(day, month, year))
    {
        Date = (char*) malloc(sizeof("Сегодня"));
        strcpy(Date, "Сегодня");
    }
    else
    {
        Date = (char*) malloc(sizeof("Доделать"));
        strcpy(Date, "ДОДЕЛАТЬ");
    }
//    debug
//    fprintf(output, "%s\n", Date);  //Вот тут работает
    return Date;                   //А вот тут уже нет! (АААААА помогите)
}

char *MakeText(int day, int month, int year)
{
    char OutputText[SIZE] = {0};
    strcpy(OutputText, DateInText(day, month, year));
    return OutputText;
}

char *DeleteSpaceAfterComa(char *FullString)
{
    for (int i = 0; i < strlen(FullString); i++)
    {
        if (FullString[i] == ',')
        {
            for (int j = i + 2; FullString[j - 1] = FullString[j]; j++);
        }
    }
    return FullString;
}

void PrintForecast(int day, int month, int year, int night_lowest_temp, int night_highest_temp, int day_lowest_temp,
                   int day_highest_temp, int lowest_feels_like, int highest_feels_like, int pressure, char Preciptation[],
                   char WindSpeed[], char WindDirection[], char WindGusts[], char Phenomenon[])
{
    char answer[SIZE];

    fputs(answer, output);
}

int main()
{
    srand(time(0));
    input = fopen("tests.txt", "r");
    output = fopen("result.txt", "w");
    char s[maxn];
    int flag = 0;
    while (fgets(s, maxn, input) != 0)
    {
        if (!flag)
        {
            flag = 1;
            continue;
        }
        else
        {
            *s = DeleteSpaceAfterComa(s);

            int Day, Month, Year, NightLowestTemp,
                    NightHighestTemp, DayLowestTemp, DayHighestTemp,
                    LowestFeelsLike, HighestFeelsLike, Pressure;

            char Preciptation[StringSize] = {0}, WindSpeed[StringSize] = {0},
                    WindDirection[StringSize] = {0}, WindGusts[StringSize] = {0},
                    Phenomenon[StringSize] = {0};

            sscanf(s, "%d.%d.%d%d..%d%d..%d%d..%d%s%s%s%s%d%s", &Day, &Month, &Year, &NightLowestTemp,
                   &NightHighestTemp, &DayLowestTemp, &DayHighestTemp, &LowestFeelsLike, &HighestFeelsLike,
                   Preciptation, WindSpeed, WindDirection, WindGusts, &Pressure, Phenomenon);

//            PrintForecast(Day, Month, Year, NightLowestTemp, NightHighestTemp, DayLowestTemp, DayHighestTemp,
//                    LowestFeelsLike, HighestFeelsLike, Pressure, Preciptation, WindSpeed, WindDirection,
//                    WindGusts, Phenomenon);
            char ans[SIZE] = {0};
            sprintf(ans, "%s", DateInText(Day, Month, Year));
            fprintf(output, "%s\n", ans);
        }
    }
    fclose(input); fclose(output);
    return 0;
}