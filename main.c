#include <stdio.h>
#include <stdlib.h>
typedef struct Dugum {
    int sayi;
    struct Dugum* sonra;
} Dugum;
typedef struct Kuyruk {
    Dugum* ilkDugum;
    Dugum* son;
} Kuyruk;

void ekle(Kuyruk* kuyruk, int sayi) {
    Dugum* dugum = (Dugum*) malloc(sizeof(Dugum));
    dugum->sayi = sayi;
    dugum->sonra = NULL;
    
    if (kuyruk->ilkDugum == NULL) {
        kuyruk->ilkDugum = dugum;
        kuyruk->son = dugum;
    } else {
        kuyruk->son->sonra = dugum;
        kuyruk->son = dugum;
    }
    printf("Girmis oldugunuz %d kuyruga eklendi.\n", sayi);
}

void sil(Kuyruk* kuyruk) {
    if (kuyruk->ilkDugum == NULL) {
        printf("Kuyrukta sayi yok, eleman silinemedi.\n");
        return;
    }
    int silinen = kuyruk->ilkDugum->sayi;
    Dugum* eski_ilkDugum = kuyruk->ilkDugum;
    kuyruk->ilkDugum = kuyruk->ilkDugum->sonra;
    free(eski_ilkDugum);
    printf("%d kuyruktan silindi.\n", silinen);
}

void goruntule(Kuyruk* kuyruk) {
    if (kuyruk->ilkDugum == NULL) {
        printf("Kuyruk bos.\n");
        return;
    }
    printf("Kuyruk elemanlari: ");
    Dugum* dugum = kuyruk->ilkDugum;
    while (dugum != NULL) {
        printf("%d ", dugum->sayi);
        dugum = dugum->sonra;
    }
    printf("\n");
}
int main() {
    Kuyruk kuyruk = { NULL, NULL };
    int secim,sayi;
     
    while (1) {
        printf("1-Eleman ekle\n2-Eleman sil\n3-Kuyruktaki elemanlari goster\n4-Cikis yap\n\n");
        
        printf("Lutfen yukaridaki seceneklerden birini seciniz: ");
        scanf("%d", &secim);
        printf("\n");
        switch (secim) {
            case 1:
                printf("Eklenecek elemani giriniz: ");
                scanf("%d", &sayi);
                printf("\n");
                ekle(&kuyruk, sayi);
                printf("\n****\n\n");
                break;
            case 2:
                sil(&kuyruk);
                printf("\n****\n\n");
                break;
            case 3:
                goruntule(&kuyruk);
                printf("\n****\n\n");
                break;
            case 4:
                return 0;
            default:
                printf("Gecersiz secim,lutfen seceneklerden birini tekrar deneyin.\n");
                printf("\n****\n\n");
        }
    }
    return 0;
}
