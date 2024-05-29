    #include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void cevap_anahtari_uret(char cevap_anahtari[ ], int S)
{
    srand(time(NULL));
    int randsayi[S];

    for(int i=0; i<S; i++)
    {
        randsayi[i]=rand()%5; // 0-4 arasi sayý atandi
        //rand sayiya göre cevap ahatari oluþturuldu
        if(randsayi[i]==0)
            cevap_anahtari[i]='A';

        else if(randsayi[i]==1)
            cevap_anahtari[i]='B';

        else if(randsayi[i]==2)
            cevap_anahtari[i]='C';

        else if(randsayi[i]==3)
            cevap_anahtari[i]='D';

        else if(randsayi[i]==4)
            cevap_anahtari[i]='E';
    }

}

void cevap_anahtari_yazdir(char cevap_anahtari[ ], int S)
{
    printf("Cevap anahtari\n\n");

    for(int i=0; i<S; i++)
        printf("%d:%c | ",i+1,cevap_anahtari[i]);
        //cevap anahtari yazdirildi

}

void sinavi_uygula(char ogrenci_cevaplari[ ][100], char cevap_anahtari[ ], int N, int S, double B, double D)
{

    srand(time(NULL));
    double bos_ihtimal,dogru_ihtimal;
    int i,j;
    B=B*100;    //bos ihtimalinin yüzedlik deðeri bulundu
    D=D*100;    //dogru ihtimalinin yüzedlik deðeri bulundu

    char dizi[5]= {'A','B','C','D','E'};


    for(i=0; i<N; i++)
    {
        for(j=0; j<S; j++)
        {
            bos_ihtimal=rand()%100; // 0-99 arasi sayi atandý
            dogru_ihtimal=rand()%100;

            if(bos_ihtimal<B)    //bos ihtimalden kucuk ise 'x' olarak dolduruldu
                ogrenci_cevaplari[i][j]='X';

            else if(bos_ihtimal>=B)   //bos deðil ise
            {
                if(dogru_ihtimal<D)  //dogru ise cevap ahatarindaki cevap atandi
                {

                    ogrenci_cevaplari[i][j]=cevap_anahtari[j];
                }

                else if(dogru_ihtimal>=D)
                {
                    do
                    {
                        ogrenci_cevaplari[i][j]=dizi[rand()%5];   //yanlýs ise rand cevap atanýp dogru olmadigi kontrol edildi
                    }
                    while(ogrenci_cevaplari[i][j]==cevap_anahtari[j]);
                }
            }
        }
    }

}


void ogrenci_cevabini_yazdir(char ogrenci_cevaplari[ ][100], int ogrenci_ID, int S)
{

    for(int i=0; i<S; i++)
        printf("%d:%c | ",i+1,ogrenci_cevaplari[ogrenci_ID][i]);  //ogreenci cevaplari yazdirildi

}


void ogrencileri_puanla(char ogrenci_cevaplari[ ][100], char cevap_anahtari[ ], double HBN[ ],int N, int S)
{
    double soru_puani=(100/S);  //her sorunun hac puan oldugu bulundu

    for(int i=0; i<N; i++)
    {
        double sayac=0;  //dogru cevaplar sayacta tutuldu dogru cevap sayisiyla carpildi (line 115)
        double ogrenci_puan=0;
        for(int j=0; j<S; j++)
        {
            if(ogrenci_cevaplari[i][j]=='X')
            {

            }
            else if(ogrenci_cevaplari[i][j]==cevap_anahtari[j])
                sayac++;
            else if(ogrenci_cevaplari[i][j]!=cevap_anahtari[j]) //yanlýs ise soru puanýnýn ceyregi puan dusuldu
                ogrenci_puan-=(soru_puani/4);
        }
        ogrenci_puan+=(sayac*soru_puani);

        if(ogrenci_puan<0)
            ogrenci_puan=0;

        HBN[i]=ogrenci_puan;

    }
}


double sinif_ortalamasi_hesapla(double HBN[ ], int N)
{
    double tutamac=0;

    for(int j=0; j<N; j++)
        tutamac+=HBN[j];        //sinif puanlarý toplandý kisi sayisina bolundu (line 134 )

    return (tutamac/N);

}


double standart_sapma_hesapla(double ortalama, double HBN[ ], int N)
{
    double standart=0;
    for(int i=0; i<N; i++)
    {
        standart+=pow(HBN[i]-ortalama,2); //strandart sapma hesaplanip return edildi
    }

    return sqrt(standart/N);

}

void T_skoru_hesapla(double ortalama, double HBN[ ], int N, double std, double T_skoru[ ])
{
    for(int i=0; i<N; i++)
    {
        T_skoru[i]=60+(10*((HBN[i]-ortalama)/std)); //T skoru hesaplanýp dizeye atandi
    }

}




int main()
{
    int N,S;
    float B,D;




    printf("Ogrenci sayisini giriniz (max 100) :");
    scanf("%d",&N);

    printf("soru sayisini giriniz (max 100) :");
    scanf("%d",&S);

    printf("Bos birakma ihtimalini giriniz (0.0-1.0) :");
    scanf("%f",&B);

    printf("Dogru cevap verme ihtimalini giriniz (0.0-1.0) :");
    scanf("%f",&D);


    printf("\n");


    char cevap_anahtari[S];

    char ogrenci_cevaplari[S][100];

    double HBN[S];

    int harf_puan; //harf notu yazdýrýlken kullanildi

    cevap_anahtari_uret(cevap_anahtari,S); //cevap ahatari uretmek icin fonks. kullanildi

    cevap_anahtari_yazdir(cevap_anahtari,S);  //cevap anahtari yazdirmak icin fonks. kullanildi

    printf("\n\n");

    sinavi_uygula(ogrenci_cevaplari,cevap_anahtari,N,S,B,D);  //sýnavý uygulamak icin fonks. kullanildi

    for(int ogrenci_ID=0; ogrenci_ID<=N-1; ogrenci_ID++)
    {
        printf("%d ogrencinin cevaplari :\n",ogrenci_ID+1);

        ogrenci_cevabini_yazdir(ogrenci_cevaplari,ogrenci_ID,S);        //ogrenci cevaplari yazdirildi

        printf("\n");
    }

    ogrencileri_puanla(ogrenci_cevaplari,cevap_anahtari,HBN,N,S);   //ogrenci puanlari hesaplandi

    double ortalama=sinif_ortalamasi_hesapla(HBN,N);

    printf("sinif ortalama : %lf \n\n",ortalama);

    double std=standart_sapma_hesapla(ortalama,HBN,N);  //standart sapma bulundu


    printf("sinifin sitandart sapmasi %lf\n\n",std);

    double T_skoru[N];

    T_skoru_hesapla(ortalama,HBN,N,std,T_skoru);  // t skoru bulundu

    if(ortalama<=100 && ortalama>80)
    {
        printf("Sinif duzeyi : Ustun Basari\n\n");
        harf_puan=0;                                //harf notu degerlerinde sýnýf duzeyi arasýnda 2 artarak ilerledigi için degisken atandý
    }

    else if(ortalama<=80 && ortalama>70)
    {
        printf("Sinif duzeyi : Mukemmel");
        harf_puan=2;
    }

    else if(ortalama<=70 && ortalama>62.5)
    {
        printf("Sinif duzeyi : Cok Iyi");
        harf_puan=4;
    }

    else if(ortalama<=62.5 && ortalama>57.5)
    {
        printf("Sinif duzeyi : Iyi");
        harf_puan=6;

    }

    else if(ortalama<=57.5 && ortalama>52.5)
    {
        printf("Sinif duzeyi : Ortanin Ustu");
        harf_puan=8;

    }

    else if(ortalama<=52.5 && ortalama>47.5)
    {
        printf("Sinif duzeyi : Orta");
        harf_puan=10;

    }

    else if(ortalama<=47.5 && ortalama>42.5)
    {
        printf("Sinif duzeyi : Zayif");
        harf_puan=12;
    }

    else if(ortalama<=42.5 )
    {
        printf("Sinif duzeyi : Kotu");
        harf_puan=14;
    }

    printf("\n");

    for(int i=0; i<N; i++)
    {
        if(T_skoru[i]>=67+harf_puan)     //sinif duzeyine gore harf notu degerlendirme derecesi degisiyor
            printf("%d. ogrencinin HBN: %lf T skoru : %lf harf notu : AA",i+1,HBN[i],T_skoru[i]);

        else if(T_skoru[i]<67+harf_puan && T_skoru[i]>=62+harf_puan)
            printf("%d. ogrencinin HBN: %lf T skoru : %lf harf notu : BA",i+1,HBN[i],T_skoru[i]);

        else if(T_skoru[i]<62+harf_puan && T_skoru[i]>=57+harf_puan)
            printf("%d. ogrencinin HBN: %lf T skoru : %lf harf notu : BB",i+1,HBN[i],T_skoru[i]);

        else if(T_skoru[i]<57+harf_puan && T_skoru[i]>=52+harf_puan)
            printf("%d. ogrencinin HBN: %lf T skoru : %lf harf notu : CB",i+1,HBN[i],T_skoru[i]);

        else if(T_skoru[i]<52+harf_puan && T_skoru[i]>=47+harf_puan)
            printf("%d. ogrencinin HBN: %lf T skoru : %lf harf notu : CC",i+1,HBN[i],T_skoru[i]);

        else if(T_skoru[i]<47+harf_puan && T_skoru[i]>=42+harf_puan)
            printf("%d. ogrencinin HBN: %lf T skoru : %lf harf notu : DC",i+1,HBN[i],T_skoru[i]);

        else if(T_skoru[i]<42+harf_puan && T_skoru[i]>=37+harf_puan)
            printf("%d. ogrencinin HBN: %lf T skoru : %lf harf notu : DD",i+1,HBN[i],T_skoru[i]);

        else if(T_skoru[i]<37+harf_puan && T_skoru[i]>=32+harf_puan)
            printf("%d. ogrencinin HBN: %lf T skoru : %lf harf notu : FD",i+1,HBN[i],T_skoru[i]);

        else if(T_skoru[i]<32+harf_puan)
            printf("%d. ogrencinin HBN: %lf T skoru : %lf harf notu : FF",i+1,HBN[i],T_skoru[i]);

        printf("\n");
    }

}
