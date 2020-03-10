#include <stdio.h>
#include <string.h>

void hex_binary(char* hex, char * res, int dolzina);
void bin_hex(char* bin);

int main(int argc, char** argv) {
    char obmocje1[] = "0xxxxxxx"; /// za prvo obmocje sablona
    char obmocje2[] = "110xxxxx10xxxxxx"; /// sablona za obmocje2
    char obmocje3[] = "1110xxxx10xxxxxx10xxxxxx"; /// sablona za obmocje3

    char* niz; /// koda, ki jo dobimo z argumenti
    niz = argv[1];
    char resitev[16]; /// resitev ko pretvorimo argument v bin
    if(strlen(niz) <= 2){
        // preverimo ce smo dobili dovolj dolgo kodo (U+)
        printf("Error\n");
        return 0;
    }
    char* unicode = niz + 2; /// se resimo prvih dveh znakov
    int dolzina_unicode = strlen(unicode); /// kako dolga koda ostane
    
    // pretvorimo v bin
    hex_binary(unicode,resitev, dolzina_unicode); /// klicemo funkcijo
    
    /// koliko prostora bomo rabli (koliko x)
    int potrebnih_mest;
    int prva_enica=0;
    for(int i=0; i<strlen(resitev); i++){
        if(resitev[i] == '1' && prva_enica == 0){
            potrebnih_mest = strlen(resitev) - i;
            prva_enica = 1;
        }
    }

    /// Ugotovimo katero obmocje je (stejemo koliko x rabimo prosotra)
    if(potrebnih_mest < 8){
        /// OBMOCJE 1
        int temp = strlen(resitev)-1; /// dolzina resitve
        for (int i = strlen(obmocje1)-1; i >= 0; i--)
        {
            if(obmocje1[i] != '0'){
                /// ce v sabloni za obmocje1 se nismo na mestu kjer je 0 (prvi znak)
                if(temp>=0){
                    /// ce se imamo znake v resitvi
                    obmocje1[i] = resitev[temp];
                    temp -= 1;
                }
                else{
                    /// ce jih nimamo dovolj da pisemo preostale 0
                    obmocje1[i]='0';
                }
            }
        }
        printf("UTF-8 binarno: %s\n", obmocje1);
        bin_hex(obmocje1);
    }
    else if(potrebnih_mest < 12){
        /// OBMOCJE 2
        int temp = strlen(resitev)-1;
        for (int i = strlen(obmocje2)-1; i >= 0; i--)
        {
            if(obmocje2[i] != '1' && obmocje2[i] != '0'){
                /// da nismo na rezerviranih mestih v sabloni
                if(temp>=0){
                    obmocje2[i] = resitev[temp];
                    temp -= 1;
                }
                else{
                    obmocje2[i]='0';
                }
            }
        }
        printf("UTF-8 binarno: %s\n", obmocje2);
        bin_hex(obmocje2);
    }
    else{
        /// OBMOCJE 3
        int temp = strlen(resitev)-1;
        for (int i = strlen(obmocje3)-1; i >= 0 ; i--)
        {
            if(obmocje3[i] != '1' && obmocje3[i] != '0'){
                if(temp>=0){
                    obmocje3[i] = resitev[temp];
                    temp -= 1;
                }
                else{
                    obmocje3[i]='0';
                }
            }
        }
       printf("UTF-8 binarno: %s\n", obmocje3); 
       bin_hex(obmocje3);
    }

	return 0;
}

void hex_binary(char* hex, char * res, int dolzina){

    char binary[16][5] = {"0000", "0001", "0010", "0011", "0100", "0101","0110", "0111", "1000", "1001", "1010", "1011", "1100", "1101", "1110","1111"}; /// bin moznosti hex zapisa
    char znaki [] = "0123456789abcdef"; /// hex znaki
    res[0] = '\0';
    int p = 0;
    int value =0;
        while (hex[p])
        // skozi naso hex kodo
        {
            const char *v = strchr(znaki, tolower(hex[p])); // poisce prvo ujemanje znaka hex[p] v znaki
            if(v[0]>96){
                value=v[0]-87;
            }
            else{
                value=v[0]-48;
            }
            if (v){
                strcat(res, binary[value]); /// zdruzi niza
            }
            p++;
        }
}

void bin_hex(char* bin){
    printf("UTF-8 hex: ");
    for (int i = 0; i < strlen(bin); i+=4)
    {
        if(bin[i] == '0' && bin[i+1] =='0' && bin[i+2] == '0' && bin[i+3] == '0'){printf("0");}
        else if(bin[i] == '0' && bin[i+1] =='0' && bin[i+2] == '0' && bin[i+3] == '1'){printf("1");}
        else if(bin[i] == '0' && bin[i+1] =='0' && bin[i+2] == '1' && bin[i+3] == '0'){printf("2");}
        else if(bin[i] == '0' && bin[i+1] =='0' && bin[i+2] == '1' && bin[i+3] == '1'){printf("3");}
        else if(bin[i] == '0' && bin[i+1] =='1' && bin[i+2] == '0' && bin[i+3] == '0'){printf("4");}
        else if(bin[i] == '0' && bin[i+1] =='1' && bin[i+2] == '0' && bin[i+3] == '1'){printf("5");}
        else if(bin[i] == '0' && bin[i+1] =='1' && bin[i+2] == '1' && bin[i+3] == '0'){printf("6");}
        else if(bin[i] == '0' && bin[i+1] =='1' && bin[i+2] == '1' && bin[i+3] == '1'){printf("7");}
        else if(bin[i] == '1' && bin[i+1] =='0' && bin[i+2] == '0' && bin[i+3] == '0'){printf("8");}
        else if(bin[i] == '1' && bin[i+1] =='0' && bin[i+2] == '0' && bin[i+3] == '1'){printf("9");}
        else if(bin[i] == '1' && bin[i+1] =='0' && bin[i+2] == '1' && bin[i+3] == '0'){printf("A");}
        else if(bin[i] == '1' && bin[i+1] =='0' && bin[i+2] == '1' && bin[i+3] == '1'){printf("B");}
        else if(bin[i] == '1' && bin[i+1] =='1' && bin[i+2] == '0' && bin[i+3] == '0'){printf("C");}
        else if(bin[i] == '1' && bin[i+1] =='1' && bin[i+2] == '0' && bin[i+3] == '1'){printf("D");}
        else if(bin[i] == '1' && bin[i+1] =='1' && bin[i+2] == '1' && bin[i+3] == '0'){printf("E");}
        else{printf("F");}
    }
    printf("\n");
}