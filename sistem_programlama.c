#include <stdio.h>
#include <stdlib.h>

int asalKontrol(int);

int main(void)
{
    int t1 = 0, t2 = 1, nextTerm = 1, n;

    // Kullanıcıdan üst limit girmesi istenir
    printf("Pozitif bir sayı girin: ");
    scanf("%d", &n);

    // Dizi tanımlanır ve Fibonacci sayılarının hesaplanabilmesi için ilk iki değer (0 ve 1) atanır
    int idizi[20];
    idizi[0] = 0;
    idizi[1] = 1;

    // Dizinin elemanlarına sıra ile değerleri atama
    for (int i = 2; i < 20; i++)
    {
        idizi[i] = idizi[i - 2] + idizi[i - 1];
    }

    // Kullanıcının girdiği üst limite göre Fibonacci değerleri yazdırılır (Sadece kullanıcıdan alınan değerden küçük ise)
    for (int i = 0; i < 20; i++)
    {
        if (idizi[i] <= n)
        {
            printf("dizi[%d]= %d\n", i, idizi[i]);
        }
    }

    // Fibonacci değerleri hesaplanır
    nextTerm = t1 + t2;

    while (nextTerm <= n)
    {
        t1 = t2;
        t2 = nextTerm;
        nextTerm = t1 + t2;
    }

    // Fibonacci sayıları arasından Asal olanlar yazdırılır
    for (int j = 0; j < 20; j++)
    {
        int x = asalKontrol(idizi[j]);
        if (x == 1)
        {
            if (idizi[j] < n)
                printf("Hem Fibonacci Hem Asal sayılar = %d\n", idizi[j]);
        }
    }
}

// Asal kontrol fonksiyonu
int asalKontrol(int sayi)
{
    int kontrol = 0;
    if (sayi < 2)
        return -1;

    for (int k = 2; k <= sayi / 2; k++)
    {
        if (sayi % k == 0)
        {
            kontrol = 1;
            break;
        }
    }

    if (kontrol == 0)
        return 1;
    else
        return -1;
}