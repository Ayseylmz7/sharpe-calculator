#include <stdio.h>

// Ana fonksiyon. Programin calismaya basladigi yer.
int main() {
    // Ondalikli sayilari saklamak icin 'double' degisken tipini kullaniyoruz.
    double yatirim_getirisi, risksiz_faiz, standart_sapma, sharpe_orani;

    // Kullaniciya baslik ve bilgilendirme mesaji gonderiyoruz.
    printf("--- Sharpe Orani Hesaplayici ---\n\n");
    printf("Lutfen oranlari ondalik olarak girin (orn: 15%% icin 0.15).\n\n");

    // ------------------------------------------------
    // 1. Yatirim Getirisi Veri Girisi
    // ------------------------------------------------
    printf("1. Yatirim Getirisini (ornegin 0.15) giriniz: ");
    
    // Kullanicidan girilen degeri 'yatirim_getirisi' degiskenine atiyoruz.
    if (scanf("%lf", &yatirim_getirisi) != 1) {
        printf("Hata: Gecersiz giris.\n");
        return 1; // Hata durumunda programdan cikis yap.
    }

    // ------------------------------------------------
    // 2. Risksiz Faiz Orani Veri Girisi
    // ------------------------------------------------
    printf("2. Risksiz Faiz Oranini (ornegin 0.05) giriniz: ");
    
    // Kullanicidan girilen degeri 'risksiz_faiz' degiskenine atiyoruz.
    if (scanf("%lf", &risksiz_faiz) != 1) {
        printf("Hata: Gecersiz giris.\n");
        return 1;
    }

    // ------------------------------------------------
    // 3. Standart Sapma (Risk) Veri Girisi
    // ------------------------------------------------
    printf("3. Portfoyun Standart Sapmasini (Risk, ornegin 0.12) giriniz: ");
    
    // Kullanicidan girilen degeri 'standart_sapma' degiskenine atiyoruz.
    if (scanf("%lf", &standart_sapma) != 1) {
        printf("Hata: Gecersiz giris.\n");
        return 1;
    }

    // Risk (Standart Sapma) sifir ise bolme islemi yapilamaz. Kontrol ediyoruz.
    if (standart_sapma == 0) {
        printf("\nHata: Standart Sapma sifir olamaz.\n");
        return 1;
    }

    // ------------------------------------------------
    // Sharpe Orani Hesaplama (Ana Formül)
    // ------------------------------------------------
    // Formül: (Yatirim Getirisi - Risksiz Faiz Orani) / Standart Sapma
    sharpe_orani = (yatirim_getirisi - risksiz_faiz) / standart_sapma;

    // ------------------------------------------------
    // Sonucu Ekrana Yazdirma
    // ------------------------------------------------
    printf("\n--- Hesaplama Sonucu ---\n");
    
    // Hesaplanan Sharpe Oranini 4 ondalik basamak hassasiyetinde yazdiriyoruz.
    printf("HESAPLANAN SHARPE ORANI: %.4f\n", sharpe_orani);
    printf("------------------------\n");

    // ------------------------------------------------
    // Sonuc Yorumu
    // ------------------------------------------------
    printf("\n--- Sharpe Orani Yorumu ---\n");
    if (sharpe_orani >= 3.0) {
        printf("MUKEMMEL (3.0 uzeri).\n");
    } else if (sharpe_orani >= 2.0) {
        printf("COK IYI (2.0 - 3.0 arasi).\n");
    } else if (sharpe_orani >= 1.0) {
        printf("IYI (1.0 - 2.0 arasi).\n");
    } else if (sharpe_orani > 0.0) {
        printf("Kabul edilebilir ancak zayif.\n");
    } else {
        printf("Risk almaya degmez (Negatif veya sifir).\n");
    }


    return 0; // Program basariyla sonlandi.
}
