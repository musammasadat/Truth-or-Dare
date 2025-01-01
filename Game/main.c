#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void dogrulukSorusu() {
    const char *sorular[] = {
        "Hayatta en b�y�k korkun nedir?",
        "Hi� kimseye s�ylemedigin bir sirrini paylasir misin?",
        "Bug�ne kadar yaptigin en cesur sey nedir?",
        "En utandigin an neydi?"
    };

    int soruIndex = rand() % 4;
    printf("\nDogruluk sorusu: %s\n", sorular[soruIndex]);
}

void cesaretGorevi() {
    const char *gorevler[] = {
        "Simdi y�ksek sesle bir sarki s�yle.",
        "Bir arkadasini ara ve ona komik bir sey s�yle.",
        "Hemen ayaga kalk ve 30 saniye dans et.",
        "Bir hayali karakterin sesini taklit et."
    };

    int gorevIndex = rand() % 4;
    printf("\nCesaret g�revi: %s\n", gorevler[gorevIndex]);
}

void yorumYap() {
    const char *yorumlar[] = {
        "Vay, ger�ekten etkileyici!",
        "Harika bir cevap, hayran kaldim!",
        "Tebrikler, �ok cesurca!",
        "Bu ger�ekten g�zelmis, bravo!",
        "Seninle gurur duydum!"
    };

    int yorumIndex = rand() % 5;
    printf("\nYorum: %s\n", yorumlar[yorumIndex]);
}

int main() {
    srand(time(NULL)); // Rastgele sayi �retimi i�in zaman tabanli tohumlama

    char secim;
    char cevap[256];

    printf("=== Dogruluk ve Cesaret Oyunu ===\n");
    printf("Oyun basliyor!\n");

    while (1) {
        printf("\nDogruluk (D) veya Cesaret (C) se�in (�ikmak i�in Q): ");
        scanf(" %c", &secim);

        if (secim == 'D' || secim == 'd') {
            dogrulukSorusu();
            printf("\nCevabinizi yazin: ");
            getchar(); // �nceki satirdan gelen yeni satir karakterini temizlemek i�in
            fgets(cevap, sizeof(cevap), stdin);
            yorumYap();
        } else if (secim == 'C' || secim == 'c') {
            cesaretGorevi();
            printf("\nG�revi yerine getirdikten sonra bir seyler yazin: ");
            getchar(); // �nceki satirdan gelen yeni satir karakterini temizlemek i�in
            fgets(cevap, sizeof(cevap), stdin);
            yorumYap();
        } else if (secim == 'Q' || secim == 'q') {
            printf("Oyundan �iktiniz. G�le g�le!\n");
            break;
        } else {
            printf("Ge�ersiz se�im! L�tfen tekrar deneyin.\n");
        }
    }

    return 0;
}

