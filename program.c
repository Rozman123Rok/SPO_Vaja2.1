#include <stdio.h>
#include <string.h>

void hex_binary(char* hex, char * res, int dolzina);

int main(int argc, char** argv) {
    char obmocje1[] = "0xxxxxxx";
    char obmocje2[] = "110xxxxx10xxxxxx";
    char obmocje3[] = "1110xxxx10xxxxxx10xxxxxx";

    char* niz; /// nasa unicode koda
    niz = argv[1];
    char resitev[16]; /// shranimo hex kodo
    int obmocje_uni = 0; /// Katerega tipa je kodiranje
    printf("Koda: %s \n", niz);
    printf("Dolzina kode: %d\n", strlen(niz));
    if(strlen(niz) <= 2){
        printf("Error\n");
        return 0;
    }
    char* unicode = niz + 2; /// se resimo prvih dveh znakov
    //printf("Unicode: %s \n", unicode);
    //printf("Dolzina unicode: %d\n", strlen(unicode));
    int dolzina_unicode = strlen(unicode);
    // pretvorimo v bin
    hex_binary(unicode,resitev, dolzina_unicode);
    printf("resitev: %s\n", resitev);
    /// koliko prostora bomo rabli (koliko x)
    int potrebnih_mest;
    int prva_enica=0;
    printf("Dolzina resitve: %d\n", strlen(resitev));
    for(int i=0; i<strlen(resitev); i++){
        printf("%c ", resitev[i]);
        if(resitev[i] == '1' && prva_enica == 0){
            potrebnih_mest = strlen(resitev) - i;
            prva_enica = 1;
        }
    }

    printf("potrebnih: %d\n", potrebnih_mest);

    ///
    if(potrebnih_mest < 8){
        printf("Prvo obmocje\n");
        printf("Dim obmocje: %d, ob: %s\n", strlen(obmocje1), obmocje1);
    }
    else if(potrebnih_mest < 12){
        printf("Obmocje 2\n");
        printf("Dim obmocje: %d, ob: %s\n", strlen(obmocje2), obmocje2);
    }
    else{
        printf("Obmocje 3\n");
        printf("Dim obmocje: %d, ob: %s\n", strlen(obmocje3), obmocje3);
        int temp = strlen(resitev)-1;
        for (int i = strlen(obmocje3)-1; i >= 0 ; i--)
        {
            if(obmocje3[i] != '1' && obmocje3[i] != '0'){
                printf("%c , %c", obmocje3[i], resitev[temp]);
                obmocje3[i] = resitev[temp];
                printf("%c ", obmocje3[i]);
                printf("%s\n", obmocje3);
                temp -= 1;
            }
        }
       printf("Izpis: %s\n", obmocje3); 
    }


/**
 * Od X'00 do X'7F	0xxx xxxx
 * Od X'80 do X'7FF	110x xxxx 10xx xxxx
 * Od X'800 do X'FFFF	1110 xxxx 10xx xxxx 10xx xxxx
**/





	return 0;
}

void hex_binary(char* hex, char * res, int dolzina){
    char binary[16][5] = {"0000", "0001", "0010", "0011", "0100", "0101","0110", "0111", "1000", "1001", "1010", "1011", "1100", "1101", "1110","1111"};
    char digits [] = "0123456789abcdef";
    //printf("Unicode: %s\n", hex);
    char input[] = "6"; // input value
    //printf("%d\n", dolzina);
    res[0] = '\0';
    int p = 0;
    int value =0;
        while (hex[p])
        {
            const char *v = strchr(digits, tolower(hex[p]));
            if(v[0]>96){
                value=v[0]-87;
            }
            else{
                value=v[0]-48;
            }
            if (v){
                strcat(res, binary[value]);
            }
            p++;
        }
        ///printf("Res:%s\n", res);
}