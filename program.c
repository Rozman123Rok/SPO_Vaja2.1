#include <stdio.h>
#include <string.h>


int main(int argc, char** argv) {
    char* niz; /// nasa unicode koda
    niz = argv[1];
    char hex_koda[8]; /// shranimo hex kodo
    int obmocje_uni = 0; /// Katerega tipa je kodiranje
    printf("Koda: %s \n", niz);
    printf("Dolzina kode: %d\n", strlen(niz));
    if(strlen(niz) <= 2){
        printf("Error\n");
        return 0;
    }
    char* unicode = niz + 2; /// se resimo prvih dveh znakov
    printf("Unicode: %s \n", unicode);
    printf("Dolzina unicode: %d\n", strlen(unicode));
	return 0;
}