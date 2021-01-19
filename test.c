#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

FILE *out;

char *WinterPrecipitation[2] = {"снег", "нет"},
     *SummerPrecipitation[3] = {"дождь", "нет", "град"},
     *OtherPrecipitation[3] = {"нет", "дождь"};

//char WindCold[24][8] = {"12-14", "13-15", "14-16", "15-17", "16-18", "17-19", "18-20", "19-21", "20-22", "21-23",
//                        "22-24",
//                        "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23",
//                        "24"}, WindWarm[11][8] = {"0", "1", "2", "3", "4", "5", "0-2", "1-3", "2-4", "3-5",
//                                                  "4-6"}, WindMild[][8] = {"6", "7", "8", "9", "10", "11", "5-7", "6-8", ""}
int LengthOfNumber(int num)
{
    int ans = 0;
    if (num == 0) return 1;
    else
    {
        while (num)
        {
            ans++;
            num /= 10;
        }
        return ans;
    }
}

int DateGeneration()
{
    int Ans, RandomDay = rand() % 32, RandomYear = 2021 + rand() % 20;
    if (RandomDay < 10) fprintf(out, "0%d.", RandomDay);
    else fprintf(out, "%d.", RandomDay);
    if (RandomDay == 31)
    {
        int months[7] = {1, 3, 5, 7, 8, 10, 12};
        int RandomMonth = months[rand() % 8];
        if (RandomMonth < 10) fprintf(out, "0%d.", RandomMonth);
        else fprintf(out, "%d.", RandomMonth);
        Ans = RandomMonth;
    }
    else if (RandomDay == 30 ||
             (RandomDay == 29 && (RandomYear % 4 != 0 || RandomYear % 100 != 0 || RandomYear % 400 != 0)))
    {
        int months[11] = {1, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
        int RandomMonth = months[rand() % 12];
        if (RandomMonth < 10) fprintf(out, "0%d.", RandomMonth);
        else fprintf(out, "%d.", RandomMonth);
        Ans = RandomMonth;
    }
    else
    {
        int RandomMonth = rand() % 12 + 1;
        if (RandomMonth < 10) fprintf(out, "0%d.", RandomMonth);
        else fprintf(out, "%d.", RandomMonth);
        Ans = RandomMonth;
    }
    fprintf(out, "%d  ", RandomYear);
    return Ans;
}

int WarmTempGeneration()
{
    int NightLowestTemp = rand() % 30, len = LengthOfNumber(NightLowestTemp);
    int NightHighestTemp = NightLowestTemp + (rand() % 10 + 1);
    len += LengthOfNumber(NightHighestTemp);
    if (NightLowestTemp < 0) len++;
    if (NightHighestTemp < 0) len++;
    fprintf(out, "%d..%d", NightLowestTemp, NightHighestTemp);
    len += 2;
    for (int i = 0; i < 12 - len; i++)
    {
        fprintf(out, " ");
    }
    int DayLowestTemp = NightLowestTemp + rand() % 10, DayHighestTemp = DayLowestTemp + rand() % 8+1;
    len = LengthOfNumber(DayLowestTemp) + LengthOfNumber(DayHighestTemp);
    if (DayLowestTemp < 0) len++;
    if (DayHighestTemp < 0) len++;
    fprintf(out, "%d..%d", DayLowestTemp, DayHighestTemp);
    len += 2;
    int AverageTemp =
            ((NightLowestTemp + NightHighestTemp) / 2 + (DayHighestTemp + DayHighestTemp) / 2) / 2, LowestFeelsLike =
            AverageTemp + rand() % 20 - 10, HighestFeelsLike = LowestFeelsLike + rand() % 15;
    len += LengthOfNumber(LowestFeelsLike) + LengthOfNumber(HighestFeelsLike);
    if (LowestFeelsLike < 0) len++;
    if (HighestFeelsLike < 0) len++;
    len += 2;
    for (int i = 0; i < 18 - len; i++)
    {
        fprintf(out, " ");
    }
    fprintf(out, "%d..%d", LowestFeelsLike, HighestFeelsLike);
    if (AverageTemp > (LowestFeelsLike + HighestFeelsLike) / 2 + 3) return 1;
    else if (AverageTemp < (LowestFeelsLike + HighestFeelsLike) / 2 - 3) return -1;
    else return 0;
}

int ColdTempGeneration()
{
    int NightLowestTemp = rand() % 40 - 45, len = LengthOfNumber(NightLowestTemp);
    int NightHighestTemp = NightLowestTemp + (rand() % 10 + 1);
    len += LengthOfNumber(NightHighestTemp);
    if (NightLowestTemp < 0) len++;
    if (NightHighestTemp < 0) len++;
    fprintf(out, "%d..%d", NightLowestTemp, NightHighestTemp);
    len += 2;
    for (int i = 0; i < 12 - len; i++)
    {
        fprintf(out, " ");
    }
    int DayLowestTemp = NightLowestTemp + rand() % 10, DayHighestTemp = DayLowestTemp + rand() % 8+1;
    len = LengthOfNumber(DayLowestTemp) + LengthOfNumber(DayHighestTemp);
    if (DayLowestTemp < 0) len++;
    if (DayHighestTemp < 0) len++;
    fprintf(out, "%d..%d", DayLowestTemp, DayHighestTemp);
    len += 2;
    int AverageTemp =
            ((NightLowestTemp + NightHighestTemp) / 2 + (DayHighestTemp + DayHighestTemp) / 2) / 2, LowestFeelsLike =
            AverageTemp + rand() % 20 - 10, HighestFeelsLike = LowestFeelsLike + rand() % 15;
    len += LengthOfNumber(LowestFeelsLike) + LengthOfNumber(HighestFeelsLike);
    if (LowestFeelsLike < 0) len++;
    if (HighestFeelsLike < 0) len++;
    len += 2;
    for (int i = 0; i < 18 - len; i++)
    {
        fprintf(out, " ");
    }
    fprintf(out, "%d..%d", LowestFeelsLike, HighestFeelsLike);
    if (AverageTemp > (LowestFeelsLike + HighestFeelsLike) / 2 + 3) return 1;
    else if (AverageTemp < (LowestFeelsLike + HighestFeelsLike) / 2 - 3) return -1;
    else return 0;
}

int MediumTempGeneration()
{
    int NightLowestTemp = rand() % 10 - 5, len = LengthOfNumber(NightLowestTemp);
    int NightHighestTemp = NightLowestTemp + (rand() % 10 + 1);
    len += LengthOfNumber(NightHighestTemp);
    if (NightLowestTemp < 0) len++;
    if (NightHighestTemp < 0) len++;
    fprintf(out, "%d..%d", NightLowestTemp, NightHighestTemp);
    len += 2;
    for (int i = 0; i < 12 - len; i++)
    {
        fprintf(out, " ");
    }
    int DayLowestTemp = NightLowestTemp + rand() % 10, DayHighestTemp = DayLowestTemp + rand() % 8+1;
    len = LengthOfNumber(DayLowestTemp) + LengthOfNumber(DayHighestTemp);
    if (DayLowestTemp < 0) len++;
    if (DayHighestTemp < 0) len++;
    fprintf(out, "%d..%d", DayLowestTemp, DayHighestTemp);
    len += 2;
    int AverageTemp =
            ((NightLowestTemp + NightHighestTemp) / 2 + (DayHighestTemp + DayHighestTemp) / 2) / 2, LowestFeelsLike =
            AverageTemp + rand() % 20 - 10, HighestFeelsLike = LowestFeelsLike + rand() % 8;
    len += LengthOfNumber(LowestFeelsLike) + LengthOfNumber(HighestFeelsLike);
    if (LowestFeelsLike < 0) len++;
    if (HighestFeelsLike < 0) len++;
    len += 2;
    for (int i = 0; i < 18 - len; i++)
    {
        fprintf(out, " ");
    }
    fprintf(out, "%d..%d", LowestFeelsLike, HighestFeelsLike);
    if (AverageTemp > (LowestFeelsLike + HighestFeelsLike) / 2 + 3) return 1;
    else if (AverageTemp < (LowestFeelsLike + HighestFeelsLike) / 2 - 3) return -1;
    else return 0;
}

void WindAndPrecipitationGeneration(int temp, int mon)
{
    int len;
    if (mon == 12 || mon <= 2)
    {
        len = fprintf(out, "%s", WinterPrecipitation[rand() % 2]);
    }
    else if ((mon >= 3 && mon <= 4) || (mon >= 10 && mon <= 11))
    {
        len = fprintf(out, "%s", OtherPrecipitation[rand() % 2]);
    }
    else
    {
        len = fprintf(out, "%s", SummerPrecipitation[rand() % 3]);
    }
    for (int i=0; i<15-len/2; i++) fprintf(out, " ");

}

int main()
{
    srand(time(0));
    out = fopen("tests.txt", "w");
    fprintf(out,
            "Дата\t\tНочью \t\tДнем\t Ощущается \t\tОсадки\t\tСкорость\tНаправление\t\tПорывы \t\tДавление \tЯвления\n");
    int NumberOfTests = rand() % 20;
    while (NumberOfTests--)
    {
        int month = DateGeneration(), temperature;
        if ((month >= 3 && month <= 4) || (month >= 9 && month <= 11)) temperature = MediumTempGeneration();
        else if (month == 12 || month <= 2) temperature = ColdTempGeneration();
        else temperature = WarmTempGeneration();
        fprintf(out, "\t\t ");
        WindAndPrecipitationGeneration(temperature, month);
        fprintf(out, "\n");
    }
    printf("OK");
    return 0;
}