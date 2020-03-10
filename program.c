#include <stdio.h>
#include <string.h>

void hex_binary(char* hex, char * res, int dolzina);

int main(int argc, char** argv) {
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