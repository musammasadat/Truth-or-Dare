#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void dogrulukSorusu() {
    const char *sorular[] = {
        "Hayatta en büyük korkun nedir?",
        "Hiç kimseye söylemedigin bir sirrini paylasir misin?",
        "Bugüne kadar yaptigin en cesur sey nedir?",
        "En utandigin an neydi?"
    };

    int soruIndex = rand() % 4;
    printf("\nDogruluk sorusu: %s\n", sorular[soruIndex]);
}

void cesaretGorevi() {
    const char *gorevler[] = {
        "Simdi yüksek sesle bir sarki söyle.",
        "Bir arkadasini ara ve ona komik bir sey söyle.",
        "Hemen ayaga kalk ve 30 saniye dans et.",
        "Bir hayali karakterin sesini taklit et."
    };

    int gorevIndex = rand() % 4;
    printf("\nCesaret görevi: %s\n", gorevler[gorevIndex]);
}

void yorumYap() {
    const char *yorumlar[] = {
        "Vay, gerçekten etkileyici!",
        "Harika bir cevap, hayran kaldim!",
        "Tebrikler, çok cesurca!",
        "Bu gerçekten güzelmis, bravo!",
        "Seninle gurur duydum!"
    };

    int yorumIndex = rand() % 5;
    printf("\nYorum: %s\n", yorumlar[yorumIndex]);
}

int main() {
    srand(time(NULL)); // Rastgele sayi üretimi için zaman tabanli tohumlama

    char secim;
    char cevap[256];

    printf("=== Dogruluk ve Cesaret Oyunu ===\n");
    printf("Oyun basliyor!\n");

    while (1) {
        printf("\nDogruluk (D) veya Cesaret (C) seçin (Çikmak için Q): ");
        scanf(" %c", &secim);

        if (secim == 'D' || secim == 'd') {
            dogrulukSorusu();
            printf("\nCevabinizi yazin: ");
            getchar(); // Önceki satirdan gelen yeni satir karakterini temizlemek için
            fgets(cevap, sizeof(cevap), stdin);
            yorumYap();
        } else if (secim == 'C' || secim == 'c') {
            cesaretGorevi();
            printf("\nGörevi yerine getirdikten sonra bir seyler yazin: ");
            getchar(); // Önceki satirdan gelen yeni satir karakterini temizlemek için
            fgets(cevap, sizeof(cevap), stdin);
            yorumYap();
        } else if (secim == 'Q' || secim == 'q') {
            printf("Oyundan çiktiniz. Güle güle!\n");
            break;
        } else {
            printf("Geçersiz seçim! Lütfen tekrar deneyin.\n");
        }
    }

    return 0;
}

