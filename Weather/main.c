#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <locale.h>
#include <windows.h>
#include <wchar.h>

#define StringSize 100
#define SIZE 1000
#define WindLess 1
#define MediumWind 2
#define StrongWind 3

FILE *input, *output, *this_night, *this_day, *night, *day, *in_case_of_rain, *in_case_of_snow, *in_case_of_fog,
        *in_case_of_ice, *in_case_of_hail, *no_prec, *strong_wind, *medium_wind, *windless;

//Функция, сравнивающая текущую дату с данной
int CheckDate(int Day, int Month, int Year)
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
    sprintf(DateInInput, "%d%d.%d%d.%d", (Day - 1) / 10, (Day - 1) % 10, Month / 10, Month % 10, Year);
    if (!(strcmp(DateInInput, date))) return 1;             //Добавить случай текущего дня и рассмотреть конец месяца
    else return 0;
}

//Функции вывода предложений/слов из словаря
char *RandomDayPhrase(char *Phrase)
{
    int n, idx;
    day = fopen("TempDifferenceDay.txt", "r");
    char temp[SIZE] = {0};
    fgets(temp, SIZE, day);
    sscanf(temp, "%d", &n);
    idx = rand() % n + 1;
    for (int i = 0; i < idx; i++)
    {
        fgets(temp, SIZE, day);
    }
    if (temp[strlen(temp) - 1] == '\n') temp[strlen(temp) - 1] = '\0';
    fclose(day);
    strcpy(Phrase, temp);
    return Phrase;
}

char *RandomNightPhrase(char *Phrase)
{
    int n, idx;
    night = fopen("TempDifferenceNight.txt", "r");
    char temp[SIZE] = {0};
    fgets(temp, SIZE, night);
    sscanf(temp, "%d", &n);
    idx = rand() % n + 1;
    for (int i = 0; i < idx; i++)
    {
        fgets(temp, SIZE, night);
    }
    if (temp[strlen(temp) - 1] == '\n') temp[strlen(temp) - 1] = '\0';
    fclose(night);
    strcpy(Phrase, temp);
    return Phrase;
}

void RandomThisDayPhrase(int DayLow, int DayHigh)
{
    int n, idx;
    this_day = fopen("ThisDay.txt", "r");
    char temp[SIZE] = {0};
    fgets(temp, SIZE, this_day);
    sscanf(temp, "%d", &n);
    idx = rand() % n + 1;
    for (int i = 0; i < idx; i++)
    {
        fgets(temp, SIZE, this_day);
    }
    if (temp[strlen(temp) - 1] == '\n') temp[strlen(temp) - 1] = '\0';
    fclose(this_day);
    int cnt = 0;
    fprintf(output, " ");
    for (int i = 0; i < strlen(temp); i++)
    {
        if (temp[i] == '#')
        {
            if (cnt == 0)
            {
                fprintf(output, "%d", DayLow);
                cnt++;
            }
            else if (cnt == 1)
            {
                fprintf(output, "%d", DayHigh);
                cnt++;
            }
        }
        else
        {
            fprintf(output, "%c", temp[i]);
        }
    }
    if (cnt == 1)
    {
        fprintf(output, "..%d", DayHigh);
    }
}

char *RandomThisNightPhrase(char *Phrase)
{
    this_night = fopen("ThisNight.txt", "r");
    int n, idx;
    char temp[SIZE] = {0};
    fgets(temp, SIZE, this_night);
    sscanf(temp, "%d", &n);
    idx = rand() % n + 1;
    for (int i = 0; i < idx; i++)
    {
        fgets(temp, SIZE, this_night);
    }
    if (temp[strlen(temp) - 1] == '\n') temp[strlen(temp) - 1] = '\0';
    fclose(this_night);
    strcpy(Phrase, temp);
    return Phrase;
}

char *RandomRainPhrase(char *Phrase)
{
    int n, idx;
    in_case_of_rain = fopen("InCaseOfRain.txt", "r");
    char temp[SIZE] = {0};
    fgets(temp, SIZE, in_case_of_rain);
    sscanf(temp, "%d", &n);
    idx = rand() % n + 1;
    for (int i = 0; i < idx; i++)
    {
        fgets(temp, SIZE, in_case_of_rain);
    }
    if (temp[strlen(temp) - 1] == '\n') temp[strlen(temp) - 1] = '\0';
    fclose(in_case_of_rain);
    strcpy(Phrase, temp);
    return Phrase;
}

char *RandomSnowPhrase(char *Phrase)
{
    int n, idx;
    in_case_of_snow = fopen("InCaseOfSnow.txt", "r");
    char temp[SIZE] = {0};
    fgets(temp, SIZE, in_case_of_snow);
    sscanf(temp, "%d", &n);
    idx = rand() % n + 1;
    for (int i = 0; i < idx; i++)
    {
        fgets(temp, SIZE, in_case_of_snow);
    }
    if (temp[strlen(temp) - 1] == '\n') temp[strlen(temp) - 1] = '\0';
    fclose(in_case_of_snow);
    strcpy(Phrase, temp);
    return Phrase;
}

char *RandomHailPhrase(char *Phrase)
{
    int n, idx;
    in_case_of_hail = fopen("InCaseOfHail.txt", "r");
    char temp[SIZE] = {0};
    fgets(temp, SIZE, in_case_of_hail);
    sscanf(temp, "%d", &n);
    idx = rand() % n + 1;
    for (int i = 0; i < idx; i++)
    {
        fgets(temp, SIZE, in_case_of_hail);
    }
    if (temp[strlen(temp) - 1] == '\n') temp[strlen(temp) - 1] = '\0';
    fclose(in_case_of_hail);
    strcpy(Phrase, temp);
    return Phrase;
}

void RandomNoPrecPhrase()
{
    int n, idx;
    no_prec = fopen("NoPrecipitation.txt", "r");
    char temp[SIZE] = {0};
    fgets(temp, SIZE, no_prec);
    sscanf(temp, "%d", &n);
    idx = rand() % n + 1;
    for (int i = 0; i < idx; i++)
    {
        fgets(temp, SIZE, no_prec);
    }
    if (temp[strlen(temp) - 1] == '\n') temp[strlen(temp) - 1] = '\0';
    fclose(no_prec);
    fprintf(output, "%s", temp);
}

char *RandomWindPhrase(int key, char *Phrase)
{
    int n, idx;
    char temp[SIZE] = {0};
    if (key == WindLess)
    {
        windless = fopen("SentenceForWindlessWeather.txt", "r");
        fgets(temp, SIZE, windless);
        sscanf(temp, "%d", &n);
        idx = rand() % n + 1;
        for (int i = 0; i < idx; i++)
        {
            fgets(temp, SIZE, windless);
        }
        if (temp[strlen(temp) - 1] == '\n') temp[strlen(temp) - 1] = '\0';
        fclose(windless);
        strcpy(Phrase, temp);
    }
    else if (key == MediumWind)
    {
        medium_wind = fopen("SentenceForMediumWind.txt", "r");
        fgets(temp, SIZE, medium_wind);
        sscanf(temp, "%d", &n);
        idx = rand() % n + 1;
        for (int i = 0; i < idx; i++)
        {
            fgets(temp, SIZE, medium_wind);
        }
        if (temp[strlen(temp) - 1] == '\n') temp[strlen(temp) - 1] = '\0';
        fclose(medium_wind);
        strcpy(Phrase, temp);
    }
    else
    {
        strong_wind = fopen("SentenceForWindyWeather.txt", "r");
        fgets(temp, SIZE, strong_wind);
        sscanf(temp, "%d", &n);
        idx = rand() % n + 1;
        for (int i = 0; i < idx; i++)
        {
            fgets(temp, SIZE, strong_wind);
        }
        if (temp[strlen(temp) - 1] == '\n') temp[strlen(temp) - 1] = '\0';
        fclose(strong_wind);
        strcpy(Phrase, temp);
    }
    return Phrase;
}

void RandomPhenomenonPhrase(int key)
{
    if (key == 1)
    {
        int n, idx;
        char temp[SIZE] = {0};
        in_case_of_ice = fopen("InCaseOfIce.txt", "r");
        fgets(temp, SIZE, in_case_of_ice);
        sscanf(temp, "%d", &n);
        idx = rand() % n + 1;
        for (int i = 0; i < idx; i++)
        {
            fgets(temp, SIZE, in_case_of_ice);
        }
        if (temp[strlen(temp) - 1] == '\n') temp[strlen(temp) - 1] = '\0';
        fclose(in_case_of_ice);
        fprintf(output, "%s", temp);
    }
    else if (key == 2)
    {
        int n, idx;
        char temp[SIZE] = {0};
        in_case_of_fog = fopen("InCaseOfFog.txt", "r");
        fgets(temp, SIZE, in_case_of_fog);
        sscanf(temp, "%d", &n);
        idx = rand() % n + 1;
        for (int i = 0; i < idx; i++)
        {
            fgets(temp, SIZE, in_case_of_fog);
        }
        if (temp[strlen(temp) - 1] == '\n') temp[strlen(temp) - 1] = '\0';
        fclose(in_case_of_fog);
        fprintf(output, "%s", temp);
    }
}
//--------------------------------------------//

char *DateInText(int Day, int Month, int Year, char *Date)
{
    char *months[12] = {"января", "февраля", "марта", "апреля", "мая", "июня", "июля", "августа", "сентября", "октября",
                        "ноября", "декабря"};
    if (Day / 10 == 0)
    {
        if (Day == 1) strcpy(Date, "первого ");
        else if (Day == 2) strcpy(Date, "второго ");
        else if (Day == 3) strcpy(Date, "третьего ");
        else if (Day == 4) strcpy(Date, "четвертого ");
        else if (Day == 5) strcpy(Date, "пятого ");
        else if (Day == 6) strcpy(Date, "шестого ");
        else if (Day == 7) strcpy(Date, "седьмого ");
        else if (Day == 8) strcpy(Date, "восьмого ");
        else if (Day == 9) strcpy(Date, "девятого ");
    }
    else if (Day / 10 == 1)
    {
        if (Day % 10 == 0) strcpy(Date, "десятого ");
        else if (Day % 10 == 1) strcpy(Date, "одиннадцатого ");
        else if (Day % 10 == 2) strcpy(Date, "двенадцатого ");
        else if (Day % 10 == 3) strcpy(Date, "тринадцатого ");
        else if (Day % 10 == 4) strcpy(Date, "четырнадцатого ");
        else if (Day % 10 == 5) strcpy(Date, "пятнадцатого ");
        else if (Day % 10 == 1) strcpy(Date, "шестнадцатого ");
        else if (Day % 10 == 1) strcpy(Date, "семнадцатого ");
        else if (Day % 10 == 1) strcpy(Date, "восемнадцатого ");
        else if (Day % 10 == 1) strcpy(Date, "девятнадцатого ");
    }
    else if (Day / 10 == 2)
    {
        if (Day % 10 == 0) strcpy(Date, "двадцатого");
        else
        {
            strcpy(Date, "двадцать");
            if (Day == 1) strcpy(Date, "первого ");
            else if (Day == 2) strcpy(Date, "второго ");
            else if (Day == 3) strcpy(Date, "третьего ");
            else if (Day == 4) strcpy(Date, "четвертого ");
            else if (Day == 5) strcpy(Date, "пятого ");
            else if (Day == 6) strcpy(Date, "шестого ");
            else if (Day == 7) strcpy(Date, "седьмого ");
            else if (Day == 8) strcpy(Date, "восьмого ");
            else if (Day == 9) strcpy(Date, "девятого ");
        }
    }
    else
    {
        if (Day == 30) strcpy(Date, "тридцатого ");
        else strcpy(Date, "тридцать первого ");
    }
    strcat(Date, months[Month - 1]);
    return Date;
}

void PrintTemperature(int Day, int Month, int Year, int NightLow, int NightHigh, int DayLow, int DayHigh,
                      int LowestFeelsLike, int HighestFeelsLike)
{
    fprintf(output, "\t");
    if (CheckDate(Day, Month, Year))
    {
        char Sentence[SIZE] = {0};
        strcpy(Sentence, RandomThisNightPhrase(Sentence));
        int cnt = 0;
        for (int i = 0; i < strlen(Sentence); i++)
        {
            if (Sentence[i] == '#')
            {
                cnt++;
                if (cnt == 1) fprintf(output, "%d", NightLow);
                else if (cnt == 2) fprintf(output, "%d", NightHigh);
            }
            else fprintf(output, "%c", Sentence[i]);
        }
        RandomThisDayPhrase(DayLow, DayHigh);
    }
    else
    {
        char Sentence[SIZE] = {0};
        strcpy(Sentence, RandomNightPhrase(Sentence));
        int cnt = 0;
        for (int i = 0; i < strlen(Sentence); i++)
        {
            if (Sentence[i] == '#')
            {
                cnt++;
                if (cnt == 1)
                {
                    char Date[SIZE] = {0};
                    strcpy(Date, DateInText(Day, Month, Year, Date));
                    if (i == 0)
                    {
                        Date[0] += 32;
                    }
                    for (int j = 0; j < strlen(Date); j++)
                    {
                        fprintf(output, "%c", Date[j]);
                    }
                }
                else if (cnt == 2) fprintf(output, "%d", NightLow);
                else if (cnt == 3) fprintf(output, "%d", NightHigh);
            }
            else fprintf(output, "%c", Sentence[i]);
        }
        char NewSentence[SIZE] = {0};
        strcpy(NewSentence, RandomDayPhrase(NewSentence));
        cnt = 0;
        fprintf(output, " ");
        for (int i = 0; i < strlen(NewSentence); i++)
        {
            if (NewSentence[i] == '#')
            {
                cnt++;
                if (cnt == 1) fprintf(output, "%d", DayLow);
                else if (cnt == 2) fprintf(output, "%d", DayHigh);
            }
            else fprintf(output, "%c", NewSentence[i]);
        }
        if (cnt == 1) fprintf(output, "..%d", DayHigh);
    }
    fprintf(output, " (ощущается как %d..%d). ", LowestFeelsLike, HighestFeelsLike);
}

void PrintPrecipitation(char *Precipitation)
{
    if (strstr("снег", Precipitation))
    {
        char Sentence[SIZE] = {0};
        strcpy(Sentence, RandomSnowPhrase(Sentence));
        for (int i = 0; i < strlen(Sentence); i++)
        {
            if (Sentence[i] == '#') fprintf(output, "%s", Precipitation);
            else fprintf(output, "%c", Sentence[i]);
        }
    }
    else if (strstr("дождь", Precipitation))
    {
        char Sentence[SIZE] = {0};
        strcpy(Sentence, RandomRainPhrase(Sentence));
        for (int i = 0; i < strlen(Sentence); i++)
        {
            if (Sentence[i] == '#') fprintf(output, "%s", Precipitation);
            else fprintf(output, "%c", Sentence[i]);
        }
    }
    else if (strstr("град", Precipitation))
    {
        char Sentence[SIZE] = {0};
        strcpy(Sentence, RandomHailPhrase(Sentence));
        for (int i = 0; i < strlen(Sentence); i++)
        {
            if (Sentence[i] == '#') fprintf(output, "%s", Precipitation);
            else fprintf(output, "%c", Sentence[i]);
        }
    }
    else RandomNoPrecPhrase();
}

void PrintPhenomenon(char *Phenomenon)
{
    int Key;
    if (strlen(Phenomenon) > 5) Key = 1;
    else Key = 2;
    fprintf(output, " ");
    RandomPhenomenonPhrase(Key);
}

void PrintPressure(int Pressure)
{
    char Phrase[3][StringSize] = {"Атмосферное давление", "Атмосферное давление в этот день",
                                  "Давление в атмосфере в этот день"};
    fprintf(output, " %s %d мм ртутного столба.", Phrase[rand() % 3], Pressure);
}

void PrintWind(char *WindSpeed, char *WindDirection, char *WindGusts)
{
    fprintf(output, " ");
    char Phrase[SIZE] = {0};
    if (strlen(WindSpeed) <= 3 && WindSpeed[strlen(WindSpeed) - 1] < '6')
        strcpy(Phrase, RandomWindPhrase(WindLess, Phrase));
    else if ((strlen(WindSpeed) <= 3 && WindSpeed[strlen(WindSpeed) - 1] >= '6') || strlen(WindSpeed) == 4)
        strcpy(Phrase, RandomWindPhrase(MediumWind, Phrase));
    else strcpy(Phrase, RandomWindPhrase(StrongWind, Phrase));
    int cnt = 0;
    for (int i = 0; i < strlen(Phrase); i++)
    {
        if (Phrase[i] == '#')
        {
            cnt++;
            if (cnt == 1) fprintf(output, "%s", WindSpeed);
            else if (cnt == 2) fprintf(output, "%s", WindGusts);
            else
            {
                for (int j = 0; j < strlen(WindDirection); j++)
                {
                    if (WindDirection[j] == 'Ю' &&
                        (j == strlen(WindDirection) - 1 || WindDirection[j + 1] == ','))
                        fprintf(output, "южное");
                    else if (WindDirection[j] == 'Ю' && j != strlen(WindDirection) - 1 &&
                             WindDirection[j + 1] == '-')
                        fprintf(output, "юго");
                    else if (WindDirection[j] == 'С' &&
                             (j == strlen(WindDirection) - 1 || WindDirection[j + 1] == ','))
                        fprintf(output, "северное");
                    else if (WindDirection[j] == 'С' && j != strlen(WindDirection) - 1 &&
                             WindDirection[j + 1] == '-')
                        fprintf(output, "северо");
                    else if (WindDirection[j] == 'В') fprintf(output, "восточное");
                    else if (WindDirection[j] == 'З') fprintf(output, "западное");
                    else if (WindDirection[j] == ',') fprintf(output, ", ");
                    else fprintf(output, "%c", WindDirection[j]);
                }
            }
        }
        else fprintf(output, "%c", Phrase[i]);
    }
}

char *DeleteSpaceAfterComa(char *FullString)
{
    for (int i = 0; i < strlen(FullString); i++)
    {
        if (FullString[i] == ',')
        {
            for (int j = i + 2; j < strlen(FullString); j++)
            {
                FullString[j - 1] = FullString[j];              //Сдвиг строки на один элемент влево
            }
        }
    }
    return FullString;
}

int main()
{
    setlocale(LC_CTYPE, "Rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(0));
    FILE *ThisNight;
    input = fopen("tests.txt", "r");
    output = fopen("result.txt", "w");
    char String[SIZE] = {0};
    fgets(String, SIZE, input);
    while (fgets(String, SIZE, input) != 0)
    {
        strcpy(String, DeleteSpaceAfterComa(String));
        int Day, Month, Year, NightLowestTemp, NightHighestTemp, DayLowestTemp, DayHighestTemp, LowestFeelsLike,
                HighestFeelsLike, Pressure;
        char Precipitation[StringSize] = {0}, WindSpeed[StringSize] = {0}, WindDirection[StringSize] = {0},
                WindGusts[StringSize] = {0}, Phenomenon[StringSize] = {0};
        sscanf(String, "%d.%d.%d %d..%d %d..%d %d..%d %s%s%s%s%d%s", &Day, &Month, &Year, &NightLowestTemp,
               &NightHighestTemp, &DayLowestTemp, &DayHighestTemp, &LowestFeelsLike, &HighestFeelsLike,
               Precipitation, WindSpeed, WindDirection, WindGusts, &Pressure, Phenomenon);
        PrintTemperature(Day, Month, Year, NightLowestTemp, NightHighestTemp, DayLowestTemp, DayHighestTemp,
                         LowestFeelsLike, HighestFeelsLike);
        PrintPrecipitation(Precipitation);
        PrintPhenomenon(Phenomenon);
        PrintWind(WindSpeed, WindDirection, WindGusts);
        PrintPressure(Pressure);
        fprintf(output, "\n");
    }
    fclose(input);
    fclose(output);
    return 0;
}
