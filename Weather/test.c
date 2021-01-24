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
int

int main()
{
    srand(time(0));
    out = fopen("tests.txt", "w");
    fprintf(out,
            "Дата\t\tНочью \t\tДнем\t Ощущается \t\tОсадки\t\tСкорость\tНаправление\t\tПорывы \t\tДавление \tЯвления\n");
    int NumberOfTests = rand() % 10;
    int PrevDay = 0, PrevMon = 0, flag = 0;
    while (NumberOfTests--)
    {
        if (!flag)
        {
            //First iteration
        }
            int DateShift = rand() % 3;
            //to do
    }
    printf("OK");
    return 0;
}