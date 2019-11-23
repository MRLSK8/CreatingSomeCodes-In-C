#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(void){
    char Data[10];

    // Variavel do tipo "time_t" que guarda datas.
    time_t now;
    // Time() retorna a data atual, no formato do tipo "time_t".
    // Por isso passa o endereço da variavel "now" que é do tipo "time_t"
    time(&now);

    // ctime() retorna uma string no formato que a gente entende (Www Mmm dd hh:mm:ss yyyy)
    /*
        Www: Day of week.
        Mmm: Month name.
        dd : Day of month.
        hh : Hour digit.
        mm : Minute digit.
        ss : Second digit.
        yyyy : Year digit.
    */
    ctime(&now);

    // localtime recebe o parametro de uma variavel do tipo time_t, 
    // e retorna uma struct com atributos (tm_hour, tm_min, tm, tm_sec, tm_mday, tm_mon, tm_year)
    struct tm *localDate = localtime(&now);

    // Mostra a data já, mas com os valores saparados em variveis do tipo "int"
    //printf("\n\n Data: %d/%d/%d\n", localDate->tm_mday, localDate->tm_mon, localDate->tm_year);

    // Copia o data já formatada para a várivel "Data"
    sprintf(Data, "%d/%d/%d", localDate->tm_mday, localDate->tm_mon, localDate->tm_year);

    // Mostra a data já na variavel "Data"
    // printf("\n Data: %s\n\n", Data);

    return 0;
}