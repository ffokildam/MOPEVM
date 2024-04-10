#include <wchar.h>

typedef struct
{
    int day, month, year, hour, minute, seconds;
} tDateTime;

struct Client {
    wchar_t Full_Name[100];
    long long int phone_number;
    tDateTime reg_date;
    tDateTime use_date;
    int peny;
    int credit;
};

struct Service {
    char name[100];
    char code[10];
    char tariff[10];
    char interval[10];
};

struct Usage {
    long long int phone_number;
    int service_code;
    int duration;
    tDateTime call_time;
};

struct Foundclient{
        wchar_t Name[100];
        long long int phone_number;
        tDateTime start;
        tDateTime end;
};