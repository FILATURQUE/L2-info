#include <stdlib.h>
#include <stdio.h>
#define prl { printf("\n"); }
    
    
// Type énuméré

typedef enum {
    Janvier = 1, Fevrier, Mars, Avril, Mai, Juin, Juillet, Aout, Septembre, Octobre, Novembre, Decembre,
    Jan = 1, Fev, Mar, Avi, May, Jui, Jul, Aou, Sep, Oct, Nov, Dec

} month_t;

void print_month(month_t m){
    switch (m)
    {
    case Janvier |Jan:
        printf("Janvier ou JANVIER ENCULER DE TA MAMAN \n");
        break;

    case Fev | Fevrier:
        printf("FEEEEVRIER ou Fev ENCULER DE TA MAMAN \n");
        break;

    case Mar | Mars:
        printf("Mars \n");
        break;

    case Avi | Avril:
        printf("Avril \n");
        break;

    case Mai | May:
        printf("Mai \n");
        break;

    case Jui | Juin:
        printf("Juin \n");
        break;

    case Juillet | Jul:
        printf("Juillet \n");
        break;

    case Aou | Aout:
        printf("Aout \n");
        break;

    case Sep | Septembre:
        printf("Septembre \n");
        break;


    case Oct | Octobre:
        printf("Octobre \n");
        break;

    case Nov | Novembre:
        printf("NOVEMBRE OU JACKIE EST TROP NUL A VALO CA RIME LOL (NON) \n");
        break;

    case Dec | Decembre:
        printf("Decembre\n");
    break;

    default:
        printf("T'ES NUL BOUFFON C'EST PAS UN MOI ENCULE \n");
        break;
    }
}

 


/// la définition du type date_t est à mettre ici

typedef struct {
    unsigned char day;
    month_t month;
    short year;
} date_t;

date_t date(unsigned char d, month_t m, short y) {
    date_t date = {d, m, y};
    return date;
}

void print_date(date_t d){
        printf("%02hhu/%02d/%hd \n",d.day,d.month,d.year); 
}

// Type union

/// la définition du type timestamp_t est à mettre ici
typedef union{
    
    long sec;
    date_t date;

} timestamp_t;


timestamp_t ts_sec(long s){
    timestamp_t ts;
    ts.sec = s;
    return ts;
}

timestamp_t ts_date(date_t d){
    timestamp_t td; 
    td.date = d;
    return td;
     
}



int main()
{
    printf("%lu \n",sizeof(date_t));
    print_date(date(1,Nov,3456));

    printf("%lu \n",sizeof(timestamp_t));

    int i;
    for(i = 0; i < 8*(sizeof(long)); i++) {
    printf("%hhu", ts_sec(1L << i).date.day); prl;
    print_month(ts_sec(1L << i).date.month); prl;
    printf("%hd", ts_sec(1L << i).date.year); prl;
  }


    /* 
    month_t m = Janvier;
    printf("taille %d \n", sizeof(m));

    month_t m1 = Fevrier;
    month_t m2 = Fev;
 
    if (m1 != m2) {
        fprintf(stderr, "Failure!!\n");
        exit(EXIT_FAILURE);
    }
    */

/* 
    print_month(Nov);
    print_month(Mai);
    print_month(Jan); */
}