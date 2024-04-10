#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <wchar.h>

#include "types.h"

void get_ClientList(struct Client *Clients,wchar_t *input_string){
    swscanf(input_string, L"%99[^,],%lld,%d.%d.%d,%d.%d.%d,%d,%d",
            &Clients->Full_Name,
            &Clients->phone_number,
            &Clients->reg_date.day,
            &Clients->reg_date.month,
            &Clients->reg_date.year,
            &Clients->use_date.day,
            &Clients->use_date.month,
            &Clients->use_date.year,
            &Clients->peny,
            &Clients->credit);
}

void get_ServiceList(struct Service *Services,char *input_string){
    char *token;
    token = strtok(input_string, ",");
    if (token){
        strcpy(Services->name, token); 
        token = strtok(NULL, ","); 
        if (token){
            strcpy(Services->code, token); 
            token = strtok(NULL, ",");
            if(token){
                strcpy(Services->tariff, token); 
                token = strtok(NULL, ",");
                if(token){
                    strcpy(Services->interval, token); 
                    token = strtok(NULL, ",");
                }
            } 
        }

    }
}

void get_UsageList(struct Usage *Usages, char *input_string){
    sscanf(input_string,"%lld, %d, %d.%d.%d %d:%d:%d, %d",
            &Usages->phone_number, &Usages->service_code,
            &Usages->call_time.day, &Usages->call_time.month, &Usages->call_time.year,
            &Usages->call_time.hour, &Usages->call_time.minute, &Usages->call_time.seconds,
            &Usages->duration);
}


int main() {
    setlocale(LC_ALL, "Russian");
    system("chcp 1251"); 

    struct Client Clients[10];
    struct Service Services[10];
    struct Usage Usages[10];

    FILE *file_ptr = fopen("Clients.txt", "r");
    FILE *file_ptr1 = fopen("Service.txt", "r");
    FILE *file_ptr2 = fopen("Usage.txt", "r");
    FILE *file_ptr3 = fopen("Param.ini", "r");
    FILE *file_ptr4 = fopen("Report.txt", "wt");

    for (int i = 0; i < 10; i++)
    {
        wchar_t input_string[100];
        fgetws(input_string, 100, file_ptr);
        get_ClientList(&Clients[i],&input_string);
    }
    
    for (int i = 0; i < 10; i++)
    {
        char input_string[100];
        fgets(input_string,100,file_ptr1);
        get_ServiceList(&Services[i],&input_string);
    }

    for (int i = 0; i < 10; i++)
    {
        char input_string[100];
        fgets(input_string,100,file_ptr2);
        get_UsageList(&Usages[i],&input_string);
    }
    
    
    struct Foundclient pClient;

    wchar_t input_string[100];
    fgetws(input_string,100,file_ptr3);
    swscanf(input_string,L"%99[^,],%d.%d.%d,%d.%d.%d",&pClient.Name,
    &pClient.start.day,
    &pClient.start.month,
    &pClient.start.year,
    &pClient.end.day,
    &pClient.end.month,
    &pClient.end.year);


    int countlist=0;
    int list_of_usages[10];

    for (int i = 0; i < 10; i++)
    {
        if(!wcscmp(pClient.Name,Clients[i].Full_Name)){
            pClient.phone_number = Clients[i].phone_number;
            break;
        }
    }
    

    for (int i = 0; i < 10; i++)
    {
        int daycount = Usages[i].call_time.day + Usages[i].call_time.month*30 + Usages[i].call_time.year*365;
        int usstcount = pClient.start.day + pClient.start.month*30 + pClient.start.year*365;
        int usedcount = pClient.end.day + pClient.end.month*30 + pClient.end.year*365;
        
        if(pClient.phone_number == Usages[i].phone_number){
            if(daycount>=usstcount && daycount<=usedcount){
                int exist = 0;
                for (size_t j = 0; i < countlist; i++)
                {
                    if(list_of_usages[i]==Usages[i].service_code) exist=1;
                }
                
                if(!exist){
                    list_of_usages[countlist] = Usages[i].service_code;
                    countlist++;
                }
            }
        }   
    }
    
    for (int i = 0; i < countlist; i++)
    {
        fprintf(file_ptr4,"%s\n",Services[list_of_usages[i]-1].name);
    }
    

    fclose(file_ptr);
    fclose(file_ptr1);
    fclose(file_ptr2);
    fclose(file_ptr3);
    fclose(file_ptr4);
}
