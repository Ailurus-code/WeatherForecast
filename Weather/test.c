#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

FILE *out;

int LengthOfNumber(int num)
{
    int ans = 0;
    while (num)
    {
        ans++;
        num /= 10;
    }
    return ans;
}

int DateGeneration()
{
    int Ans, RandomDay = rand()%32, RandomYear = 2021 + rand()%20;
    if (RandomDay<10) fprintf(out, "0%d.", RandomDay);
    else fprintf(out, "%d.", RandomDay);
    if (RandomDay==31)
    {
        int months[7] = {1, 3, 5, 7, 8, 10, 12};
        int RandomMonth = months[rand()%8];
        if (RandomMonth<10) fprintf(out, "0%d.", RandomMonth);
        else fprintf(out, "%d.", RandomMonth);
        Ans = RandomMonth;
    }
    else if (RandomDay==30 || (RandomDay==29 && (RandomYear%4!=0 || RandomYear%100!=0 || RandomYear%400!=0)))
    {
        int months[11] = {1, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
        int RandomMonth = months[rand()%12];
        if (RandomMonth<10) fprintf(out, "0%d.", RandomMonth);
        else fprintf(out, "%d.", RandomMonth);
        Ans = RandomMonth;
    }
    else
    {
        int RandomMonth = rand()%12+1;
        if (RandomMonth<10) fprintf(out, "0%d.", RandomMonth);
        else fprintf(out, "%d.", RandomMonth);
        Ans = RandomMonth;
    }
    fprintf(out, "%d  ", RandomYear);
    return Ans;
}

void WarmTempGeneration()
{
    int NightLowestTemp = rand()%45, len = LengthOfNumber(NightLowestTemp);
    int NightHighestTemp = NightLowestTemp + (rand()%10);
    len+=LengthOfNumber(NightHighestTemp);
    if (NightLowestTemp<0) len++;
    if (NightHighestTemp<0) len++;
    fprintf(out, "%d..%d", NightLowestTemp, NightHighestTemp);
    len+=2;
    for (int i=0; i<12-len; i++)
    {
        fprintf(out, " ");
    }
    int DayLowestTemp = NightLowestTemp + rand()%10, DayHighestTemp = DayLowestTemp + rand()%8;
    len = LengthOfNumber(DayLowestTemp) + LengthOfNumber(DayHighestTemp);
    if (DayLowestTemp<0) len++;
    if (DayHighestTemp<0) len++;
    fprintf(out, "%d..%d", DayLowestTemp, DayHighestTemp);
    len += 2;
    for (int i=0; i<12-len; i++)
    {
        fprintf(out, " ");
    }
}

void ColdTempGeneration()
{
    int NightLowestTemp = rand()%40-45, len = LengthOfNumber(NightLowestTemp);
    int NightHighestTemp = NightLowestTemp + (rand()%10);
    len+=LengthOfNumber(NightHighestTemp);
    if (NightLowestTemp<0) len++;
    if (NightHighestTemp<0) len++;
    fprintf(out, "%d..%d", NightLowestTemp, NightHighestTemp);
    len+=2;
    for (int i=0; i<12-len; i++)
    {
        fprintf(out, " ");
    }
    int DayLowestTemp = NightLowestTemp + rand()%10, DayHighestTemp = DayLowestTemp + rand()%8;
    len = LengthOfNumber(DayLowestTemp) + LengthOfNumber(DayHighestTemp);
    if (DayLowestTemp<0) len++;
    if (DayHighestTemp<0) len++;
    fprintf(out, "%d..%d", DayLowestTemp, DayHighestTemp);
    len += 2;
    for (int i=0; i<12-len; i++)
    {
        fprintf(out, " ");
    }
}

void MediumTempGeneration()
{
    int NightLowestTemp = rand()%10-5, len = LengthOfNumber(NightLowestTemp);
    int NightHighestTemp = NightLowestTemp + (rand()%10);
    len+=LengthOfNumber(NightHighestTemp);
    if (NightLowestTemp<0) len++;
    if (NightHighestTemp<0) len++;
    fprintf(out, "%d..%d", NightLowestTemp, NightHighestTemp);
    len+=2;
    for (int i=0; i<12-len; i++)
    {
        fprintf(out, " ");
    }
    int DayLowestTemp = NightLowestTemp + rand()%10, DayHighestTemp = DayLowestTemp + rand()%8;
    len = LengthOfNumber(DayLowestTemp) + LengthOfNumber(DayHighestTemp);
    if (DayLowestTemp<0) len++;
    if (DayHighestTemp<0) len++;
    fprintf(out, "%d..%d", DayLowestTemp, DayHighestTemp);
    len += 2;
    for (int i=0; i<12-len; i++)
    {
        fprintf(out, " ");
    }
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
        int month = DateGeneration();
        if ((month>=3 && month<=4) || (month>=9 && month<=11)) MediumTempGeneration();
        else  if (month==12 || month<=2) ColdTempGeneration();
        else WarmTempGeneration();
        fprintf(out, "\n");
    }
    return 0;
}