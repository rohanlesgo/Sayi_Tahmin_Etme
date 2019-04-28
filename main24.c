#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h> // Her kosturdugumda karsimiza farkli sayi çikartiyor bu yuzden bu kutuphaneyi ekledik.
int girilensayiduzgunmu(int sayi){  // girilen sayi basamaklarina ayrildi ve kontrol edildi ayni sayi var mi diye.
int birlerbasamagi,onlarbasamagi,yuzlerbasamagi,binlerbasamagi;
int hata=0;

birlerbasamagi = (sayi % 10);
onlarbasamagi = ((sayi % 100) - birlerbasamagi)/10;
yuzlerbasamagi = ((sayi % 1000) - (sayi % 100))/100;
binlerbasamagi = (sayi - (sayi % 1000))/1000;

if ((binlerbasamagi == yuzlerbasamagi) || (binlerbasamagi == onlarbasamagi) || (binlerbasamagi == birlerbasamagi) ){
   // printf("Tekrardan sayi donsun cunku sayi birbirinden farkli degil\n");
    return hata;
    }
if ((yuzlerbasamagi == onlarbasamagi) ||  (yuzlerbasamagi == birlerbasamagi) ){
   // printf("Tekrardan sayi donsun cunku sayi birbirinden farkli degil\n");
    return hata;
    }
if (onlarbasamagi == birlerbasamagi) {
  //  printf("Tekrardan sayi donsun cunku onlar ve birler basamagi birbirinden farkli degil\n");
    return hata;
    }
    hata=1;// egerki hiç bir if'e girmezse hatayı 1 olarak dondursun yani sıkıntı yok devam edebilir kod.
    return hata;
}

int pcsayiduzgunmu(int sayi){  // pc'nin tutgu sayi basamaklarina ayrildi ve kontrol edildi ayni sayi var mi diye.
int birlerbasamagi,onlarbasamagi,yuzlerbasamagi,binlerbasamagi;
int hata=0;

birlerbasamagi = (sayi % 10);
onlarbasamagi = ((sayi % 100) - birlerbasamagi)/10;
yuzlerbasamagi = ((sayi % 1000) - (sayi % 100))/100;
binlerbasamagi = (sayi - (sayi % 1000))/1000;

if ((binlerbasamagi == yuzlerbasamagi) || (binlerbasamagi == onlarbasamagi) || (binlerbasamagi == birlerbasamagi) ){
   // printf("Tekrardan sayi donsun cunku sayi birbirinden farkli degil\n");
    return hata;
    }
if ((yuzlerbasamagi == onlarbasamagi) ||  (yuzlerbasamagi == birlerbasamagi) ){
   // printf("Tekrardan sayi donsun cunku sayi birbirinden farkli degil\n");
    return hata;
    }
if (onlarbasamagi == birlerbasamagi) {
   // printf("Tekrardan sayi donsun cunku onlar ve birler basamagi birbirinden farkli degil\n");
    return hata;
    }
hata=1;// egerki hiç bir if'e girmezse hatayı 1 olarak dondursun yani sıkıntı yok devam edebilir kod.
    return hata;
}

int sayachesaplama(int pcsayi, int girilensayi){ //1. oyun icin sayac hesapliyor.
    int sayacarti=0;
    int sayaceksi=0;
    int sayachicbisy=0;
    int binlerbasamagi1,yuzlerbasamagi1,onlarbasamagi1,birlerbasamagi1;  // burada tekrardan bilgisayarin olusturdugu sayiyi basamaklara ayirdik.

      birlerbasamagi1 = (pcsayi % 10);
      onlarbasamagi1 = ((pcsayi % 100) - birlerbasamagi1)/10;
      yuzlerbasamagi1 = ((pcsayi % 1000) - (pcsayi % 100))/100;
      binlerbasamagi1 = (pcsayi - (pcsayi % 1000))/1000;

    int binlerbasamagi2,yuzlerbasamagi2,onlarbasamagi2,birlerbasamagi2;// burada tekrardan kullanicinin olusturdugu sayiyi basamaklara ayirdik.

      birlerbasamagi2 = (girilensayi % 10);
      onlarbasamagi2 = ((girilensayi % 100) - birlerbasamagi2)/10;
      yuzlerbasamagi2 = ((girilensayi % 1000) - (girilensayi % 100))/100;
      binlerbasamagi2 = (girilensayi - (girilensayi % 1000))/1000;




      int boyut1[4] = {birlerbasamagi1,onlarbasamagi1,yuzlerbasamagi1,binlerbasamagi1}; // pc'nin sayiyi boyut1 dizisine atadim cunku ileride karsilastircam boyut2 ile.
      int boyut2[4] = {birlerbasamagi2,onlarbasamagi2,yuzlerbasamagi2,binlerbasamagi2};// kullanicinin'nin sayiyi boyut2 dizisine atadim cunku ileride karsilastircam boyut1 ile.

        for(int i = 0 ; i < 4 ; i++){
        for(int k = 0 ; k < 4 ; k++){
            if(i == k){// burada ayni basamak degerine sahip rakamlari kontrol ettim.
                if(boyut1[i] == boyut2[k]){
                sayacarti +=1;
                }
            }
            if(i != k){
            if(boyut1[i] == boyut2[k]){ // burada ayni sayi var ise o rakamlari kontrol ettim. Burada soyle birsey var eger basamak degeri ve rakam ayni(sayacarti) ise sayaceksiyi sayacartidan cikarttim.
                sayaceksi -=1;
            }
            }
        }
      }

      printf("sayaceksi:%d\n",sayaceksi);
      printf("sayacarti:%d\n",sayacarti);
      return sayacarti;

}

int sayitahminetbirincibasamak(int pcsayi, int sayac1){

      int binlerbasamagi,yuzlerbasamagi,onlarbasamagi,birlerbasamagi;  // burada tekrardan bilgisayarin olusturdugu sayiyi basamaklara ayirdik.
      int basamak1=0;//1. basamak ifadesi

      binlerbasamagi = pcsayi / 1000;
      yuzlerbasamagi = (pcsayi-(binlerbasamagi*1000))/100;
      onlarbasamagi = (pcsayi-((binlerbasamagi*1000)+(yuzlerbasamagi*100)))/10;
      birlerbasamagi = (pcsayi-((binlerbasamagi*1000)+(yuzlerbasamagi*100)+(onlarbasamagi*10)));


      int tahmin2[] = {birlerbasamagi,onlarbasamagi,yuzlerbasamagi,binlerbasamagi}; // Pc'nin tuttugu rakamlari diziye atadım.
      int sayilistesi[] = {0,1,2,3,4,5,6,7,8,9,birlerbasamagi}; // birlerbasamagini ekledim cunku belkide enbastaki sayi dogruydu.

      int i = sayac1;
      printf("i1 : %d\n",i);
      if (i > 10){
        i = 0;
      }

      while( i < 10){

            tahmin2[0] = sayilistesi[i]; // birler basamagina sayilistesindeki i degerlerini atadim.
            int yenisayi = tahmin2[0]+(tahmin2[1]*10)+(tahmin2[2]*100)+(tahmin2[3]*1000); // yeni sayiyi basamakli sekilde yazdirdim.
            int a ;

            kntrl1: // bu kontrol sayi degistirdigimze degistirilen sayi diger basamaklarla ayni mi degil mi diye kontrol ediyor.

            binlerbasamagi = yenisayi / 1000;
            yuzlerbasamagi = (yenisayi-(binlerbasamagi*1000))/100;
            onlarbasamagi = (yenisayi-((binlerbasamagi*1000)+(yuzlerbasamagi*100)))/10;
            birlerbasamagi = (yenisayi-((binlerbasamagi*1000)+(yuzlerbasamagi*100)+(onlarbasamagi*10)));

            if ((birlerbasamagi == onlarbasamagi) || (birlerbasamagi == yuzlerbasamagi) || (birlerbasamagi == binlerbasamagi) || (yuzlerbasamagi == binlerbasamagi) || (onlarbasamagi == yuzlerbasamagi) || (onlarbasamagi == binlerbasamagi)){
            if (birlerbasamagi == onlarbasamagi){
                    basamak1++ ;
                    printf("basmak1 : %d\n",basamak1);
                    a = sayitahminetikincibasamak(yenisayi,basamak1);
                    yenisayi = a;
            goto kntrl1;

            }
            if (birlerbasamagi == yuzlerbasamagi){
                    basamak1++ ;
                    printf("basmak1 : %d\n",basamak1);
                    a = sayitahminetucuncubasamak(yenisayi,basamak1);
                    yenisayi = a;
            goto kntrl1;

            }
            if(birlerbasamagi == binlerbasamagi){
                    basamak1++ ;
                    printf("basmak1 : %d\n",basamak1);
                    a = sayitahminetdortuncubasamak(yenisayi,basamak1);
                    yenisayi = a;
            goto kntrl1;

            }

            if (yuzlerbasamagi == binlerbasamagi){
                    basamak1++ ;
                    printf("basmak1 : %d\n",basamak1);
                    a = sayitahminetucuncubasamak(yenisayi,basamak1);
                    yenisayi = a;
            goto kntrl1;

            }

              if (onlarbasamagi == yuzlerbasamagi){
                    basamak1++ ;
                    printf("basmak1 : %d\n",basamak1);
                    a = sayitahminetucuncubasamak(yenisayi,basamak1);
                    yenisayi = a;
            goto kntrl1;

            }

             if (onlarbasamagi == binlerbasamagi){
                    basamak1++ ;
                    printf("basmak1 : %d\n",basamak1);
                    a = sayitahminetdortuncubasamak(yenisayi,basamak1);
                    yenisayi = a;
            goto kntrl1;

            }
            }


            return yenisayi;



      }

}

int sayitahminetikincibasamak(int pcsayi,int sayac2){

      int binlerbasamagi,yuzlerbasamagi,onlarbasamagi,birlerbasamagi;  // burada tekrardan bilgisayarin olusturdugu sayiyi basamaklara ayirdik.
      int basamak2=1;//2. basamak ifadesi

      binlerbasamagi = pcsayi / 1000;
      yuzlerbasamagi = (pcsayi-(binlerbasamagi*1000))/100;
      onlarbasamagi = (pcsayi-((binlerbasamagi*1000)+(yuzlerbasamagi*100)))/10;
      birlerbasamagi = (pcsayi-((binlerbasamagi*1000)+(yuzlerbasamagi*100)+(onlarbasamagi*10)));


      int tahmin2[] = {birlerbasamagi,onlarbasamagi,yuzlerbasamagi,binlerbasamagi};// Pc'nin tuttugu rakamlari diziye atadım.
      int sayilistesi[] = {0,1,2,3,4,5,6,7,8,9,onlarbasamagi};// onlarbasamagi ekledim cunku belkide enbastaki sayi dogruydu.

      int i = sayac2; //  i sayaci eger 10'u gecerse 0 esitleyelimki kullanıcı yanlıs ipucu girer ise bir daha sansi olsun dogruyu girebilmek icin.
      printf("i2: %d\n",i);
      if (i > 10){
        i = 0;

      }


      while( i < 10){

            tahmin2[1] = sayilistesi[i];// onlar basamagina sayilistesindeki i degerlerini atadim.
            int yenisayi = tahmin2[0]+(tahmin2[1]*10)+(tahmin2[2]*100)+(tahmin2[3]*1000); // yeni sayiyi basamakli sekilde yazdirdim.
            int a ;

            kntrl2:
            binlerbasamagi = yenisayi / 1000;
            yuzlerbasamagi = (yenisayi-(binlerbasamagi*1000))/100;
            onlarbasamagi = (yenisayi-((binlerbasamagi*1000)+(yuzlerbasamagi*100)))/10;
            birlerbasamagi = (yenisayi-((binlerbasamagi*1000)+(yuzlerbasamagi*100)+(onlarbasamagi*10)));

            if ((onlarbasamagi == yuzlerbasamagi) || ( onlarbasamagi == binlerbasamagi ) ||  (onlarbasamagi == birlerbasamagi) || (yuzlerbasamagi == binlerbasamagi) || (binlerbasamagi == birlerbasamagi) || (yuzlerbasamagi == binlerbasamagi)){

            if (onlarbasamagi == birlerbasamagi){ // eğerki olusturdugumuz yeni sayidaki birler ve onlar basamagi ayni ise listedeki i+1 'i al ve yerine koy.
            tahmin2[1] = sayilistesi[i+1];
            yenisayi = tahmin2[0]+(tahmin2[1]*10)+(tahmin2[2]*100)+(tahmin2[3]*1000); // yeni sayiyi basamakli sekilde yazdirdim.
            goto kntrl2;
            }

            if (onlarbasamagi == yuzlerbasamagi){
                    basamak2++ ;
                    printf("basamak2:%d\n",basamak2);
                    a = sayitahminetucuncubasamak(yenisayi,basamak2);
                    yenisayi = a;
            goto kntrl2;

            }

            if(onlarbasamagi == binlerbasamagi){
                    basamak2 ++;
                    printf("basamak2:%d\n",basamak2);
                    a = sayitahminetdortuncubasamak(yenisayi,basamak2);
                    yenisayi = a;
            goto kntrl2;

            }

            if(yuzlerbasamagi == binlerbasamagi){
                    basamak2++ ;
                    printf("basamak2:%d\n",basamak2);
                    a = sayitahminetdortuncubasamak(yenisayi,basamak2);
                    yenisayi = a;
            goto kntrl2;

            }

             if(binlerbasamagi == birlerbasamagi){
                    basamak2++ ;
                    printf("basamak2:%d\n",basamak2);
                    a = sayitahminetdortuncubasamak(yenisayi,basamak2);
                    yenisayi = a;
            goto kntrl2;

            }
             if(yuzlerbasamagi == birlerbasamagi){
                    basamak2++ ;
                    printf("basamak2:%d\n",basamak2);
                    a = sayitahminetucuncubasamak(yenisayi,basamak2);
                    yenisayi = a;
            goto kntrl2;

            }
            }

            return yenisayi;


      }


}

int sayitahminetucuncubasamak(int pcsayi,int sayac3){
      int binlerbasamagi,yuzlerbasamagi,onlarbasamagi,birlerbasamagi;  // burada tekrardan bilgisayarin olusturdugu sayiyi basamaklara ayirdik.
      int basamak3=0;//1. basamak ifadesi

      binlerbasamagi = pcsayi / 1000;
      yuzlerbasamagi = (pcsayi-(binlerbasamagi*1000))/100;
      onlarbasamagi = (pcsayi-((binlerbasamagi*1000)+(yuzlerbasamagi*100)))/10;
      birlerbasamagi = (pcsayi-((binlerbasamagi*1000)+(yuzlerbasamagi*100)+(onlarbasamagi*10)));


      int tahmin2[] = {birlerbasamagi,onlarbasamagi,yuzlerbasamagi,binlerbasamagi};


      int sayilistesi[] = {0,1,2,3,4,5,6,7,8,9,yuzlerbasamagi};
      int i = sayac3;
      printf("i3:%d\n",i);

       if (i > 10){
        i = 0;
      }

      while( i < 11){

            tahmin2[2] = sayilistesi[i];//yuzlerbasamagina i listesindeki sayiyi atadim.
            int yenisayi = tahmin2[0]+(tahmin2[1]*10)+(tahmin2[2]*100)+(tahmin2[3]*1000); // yeni sayiyi basamakli sekilde yazdirdim.
            int a ;

            kntrl3:

            binlerbasamagi = yenisayi / 1000;
            yuzlerbasamagi = (yenisayi-(binlerbasamagi*1000))/100;
            onlarbasamagi = (yenisayi-((binlerbasamagi*1000)+(yuzlerbasamagi*100)))/10;
            birlerbasamagi = (yenisayi-((binlerbasamagi*1000)+(yuzlerbasamagi*100)+(onlarbasamagi*10)));


            if ((yuzlerbasamagi == binlerbasamagi) ){
            basamak3++ ;
            printf("basamak3:%d\n",basamak3);
            a = sayitahminetdortuncubasamak(yenisayi,basamak3);
            yenisayi = a;
            goto kntrl3;
            }

            if ((yuzlerbasamagi == birlerbasamagi) || (yuzlerbasamagi == onlarbasamagi)){ // eğerki olusturdugumuz yeni sayidaki birler ve onlar basamagi ayni ise listedeki i+1 'i al ve yerine koy.
            tahmin2[2] = sayilistesi[i+1];
            yenisayi = tahmin2[0]+(tahmin2[1]*10)+(tahmin2[2]*100)+(tahmin2[3]*1000); // yeni sayiyi basamakli sekilde yazdirdim.
            goto kntrl3;
            }

            return yenisayi;


      }

}

int sayitahminetdortuncubasamak(int pcsayi,int sayac4){
int binlerbasamagi,yuzlerbasamagi,onlarbasamagi,birlerbasamagi;  // burada tekrardan bilgisayarin olusturdugu sayiyi basamaklara ayirdik.
      int basamak4=0;//1. basamak ifadesi
      binlerbasamagi = pcsayi / 1000;
      yuzlerbasamagi = (pcsayi-(binlerbasamagi*1000))/100;
      onlarbasamagi = (pcsayi-((binlerbasamagi*1000)+(yuzlerbasamagi*100)))/10;
      birlerbasamagi = (pcsayi-((binlerbasamagi*1000)+(yuzlerbasamagi*100)+(onlarbasamagi*10)));


      int tahmin2[] = {birlerbasamagi,onlarbasamagi,yuzlerbasamagi,binlerbasamagi};


      int sayilistesi[] = {1,2,3,4,5,6,7,8,9,binlerbasamagi};
      int i = sayac4;

       if (i > 10){
        i = 0;
      }

      while( i < 11){

            tahmin2[3] = sayilistesi[i];
            int yenisayi = tahmin2[0]+(tahmin2[1]*10)+(tahmin2[2]*100)+(tahmin2[3]*1000); // yeni sayiyi basamakli sekilde yazdirdim.




            return yenisayi;


      }


}



int main()
{

      setlocale(LC_ALL,"Turkish");
      srand(time(NULL));// bilgisayarın her seferinde farkı sayı üretmesi için yazılan bir kod.
      int secim;// oyun bilgisi veya hangi oyunu secmek icin
      char secim1;
      int a=0;// ana monuye donmek icin yazildi.
      ana:
      printf("Hangi oyunu oynamak istersiniz:\n1-Kullanici Tahmin Etsin Sayiyi\n2-Bilgisayar Tahmin Etsin Tuttugun Sayiyi\n3-Kullanma Kilavuzu\n4-Derleme Kilavuzu\n");
      scanf("%d",&secim);
      if((secim < 1) || (secim > 4)){
        goto ana;
      }
      if(secim == 1){ //1. oyun
      int girilensayi,pcsayi;
      int adimsayisi1=1;// kacıncı adımda kullanıcı sayıyı dogru bıldı.

      here1:
      pcsayi=rand()%9000+999;
      int kontrol1 = pcsayiduzgunmu(pcsayi);// pc'nin tuttugu sayi basamaklarına ayrıldı ve basamaklar birbirinden farkli mi degil mi bakildi eger degilse bulana kadar dondu.
      if(kontrol1 == 0){// fonksiyondan gelen deger eger 0 ise yani bilgisayarin tuttugu sayida aynı rakan var ise if'in icine giriyor.
        goto here1;
      }


      here2:
      printf("Lutfen 4 basamakli ve rakamlari birbirinden farkli sayi giriniz:");
      scanf("%d",&girilensayi);
      if(girilensayi <= 999 || girilensayi >= 10000){ // girilen sayinin 4 basamakli olmasini sagladik degilse girene kadar doner.
        goto here2;
      }
      int kontrol2 = girilensayiduzgunmu(girilensayi);// girilen sayi basamaklarına ayrıldı ve basamaklar birbirinden farkli mi degil mi bakildi.
      if (kontrol2 == 0){   // fonksiyondan gelen deger eger 0 ise yani kullanicinin girdigi sayida aynı rakan var ise if'in icine giriyor.
        goto here2;
      }

      printf("Girilen sayi:%d\n",girilensayi);
     // printf("Pc'nin tuttugu sayi:%d\n",pcsayi);

      int surec = sayachesaplama(pcsayi,girilensayi); // burada sayacartiyi kontrol ettim. Sayacarti 4'e eşit olana kadar döner.
      if( surec != 4){
        adimsayisi1 +=1;
        goto here2;
      }
       else if (surec == 4){
        printf("Oyunu %d. adim da kazandiniz Tebrikler.",adimsayisi1);
        printf("Ana menuye donmek icin 9'a basiniz.\n");
      scanf("%d",&a);
      if(a == 9){
         goto ana;
        }
       }
      }
      if(secim == 2){
      int adimsayisi2=1;
      int pcsayi,sayaceksi,sayacarti,toplam3,toplam4,yenisayi1;
      int sayac=0; // Birinci basamak kontrolu icin
      int sayac1=0; // İkinci basamak kontrolu icin
      int sayac2=0; // Ucuncu basamak kontrolu icin
      int sayac3=0; // Dortuncu basamak kontrolu icin

      here3:
      pcsayi=rand()%9000+999;
      int kontrol3 = pcsayiduzgunmu(pcsayi);// pc'nin tuttugu sayi basamaklarına ayrıldı ve basamaklar birbirinden farkli mi degil mi bakildi eger degilse bulana kadar dondu.
      if(kontrol3 == 0){// fonksiyondan gelen deger eger 0 ise yani bilgisayarin tuttugu sayida aynı rakan var ise if'in icine giriyor.
        goto here3;
      }

      ///////////////////////////////////////////1.BASAMAK KONTROL////////////////////////////////////////////////


      printf("Rakamlari birbirinden farkli 4 basamakli sayi PC'nin tuttugu sayi:%d\n",pcsayi);
      don1:
      printf("Lutfen uygun sayaceksiyi giriniz:\n");
      scanf("%d",&sayaceksi);
      if (sayaceksi < -4 || sayaceksi > 0){ // sayaceksi kontrolu
      goto don1;
      }
      don11:
      printf("Lutfen uygun sayacartiyi giriniz:\n");
      scanf("%d",&sayacarti);
      if(sayacarti != 4){
        adimsayisi2++;
      }
      if(sayacarti < 0 || sayacarti > 4 ){ //sayacarti kontrol
      goto don11;
      }
      toplam3 = sayacarti;


      here4:
      yenisayi1 = sayitahminetbirincibasamak(pcsayi,sayac); // yeni sayimizi kontrol ettik
      pcsayi = yenisayi1;

      printf("Yeni sayiniz bu mu:%d\n",yenisayi1);
      don2:
      printf("Lutfen uygun sayaceksiyi giriniz:\n");
      scanf("%d",&sayaceksi);
      if (sayaceksi < -4 || sayaceksi > 0){ // sayaceksi kontrolu
      goto don2;
      }
      don22:
      printf("Lutfen uygun sayacartiyi giriniz:\n");
      scanf("%d",&sayacarti);
      if(sayacarti != 4){
        adimsayisi2++;
      }
      if(sayacarti < 0 || sayacarti > 4 ){//sayacarti kontrol
      goto don22;
      }
      toplam4 = sayacarti;


      while ( ((toplam3 == toplam4) || (toplam4 < toplam3)) ) {  //1. basamakdaki değerleri degistirerek aklımdaki rakamı buldurtmaya calisiyorum bilgisayara.
      sayac +=1;
       if ( sayac == 10){
       sayac = 0;
      }
      goto here4;
      }

      if( toplam4 == 4){
      printf("%d. adim sayisinda bilgisayar sayiyi buldu:%d\n",adimsayisi2,pcsayi);
      printf("Ana menuye donmek icin 9'a basiniz.\n");
      scanf("%d",&a);
      if(a == 9){
         goto ana;
        }
      }


      ///////////////////////////////////////////2.BASAMAK KONTROL////////////////////////////////////////////////


      printf("Tuttugunuz sayi bu mu:%d\n",pcsayi);
      don3:
      printf("Lutfen uygun sayaceksiyi giriniz:\n");
      scanf("%d",&sayaceksi);
      if (sayaceksi < -4 || sayaceksi > 0){ // sayaceksi kontrolu
      goto don3;
      }
      don33:
      printf("Lutfen uygun sayacartiyi giriniz:\n");
      scanf("%d",&sayacarti);
      if(sayacarti != 4){
        adimsayisi2++;
      }
      if(sayacarti < 0 || sayacarti > 4 ){//sayacarti kontrol
      goto don33;
      }
      toplam3 = sayacarti;

      here5:
      yenisayi1 = sayitahminetikincibasamak(pcsayi,sayac1); // 2'ler basamagi dogru olan sayimiz.Kontrol simdi 2. basamakta
      pcsayi = yenisayi1;

      printf("Yeni sayiniz bu mu:%d\n",yenisayi1);
      don4:
      printf("Lutfen uygun sayaceksiyi giriniz:\n");
      scanf("%d",&sayaceksi);
      if (sayaceksi < -4 || sayaceksi > 0){ // sayaceksi kontrolu
      goto don4;
      }
      don44:
      printf("Lutfen uygun sayacartiyi giriniz:\n");
      scanf("%d",&sayacarti);
      if(sayacarti != 4){
        adimsayisi2++;
      }
      if(sayacarti < 0 || sayacarti > 4 ){//sayacarti kontrol
      goto don44;
      }
      toplam4 = sayacarti;

      while ( ((toplam3 == toplam4) || (toplam4 < toplam3)) ){  //2. basamakdaki değerleri degistirerek aklımdaki rakamı buldurtmaya calisiyorum bilgisayara.
      sayac1 +=1;
      if ( sayac1 == 10){
       sayac1 = 0;
      }
      goto here5;
      }

      if( toplam4 == 4){
      printf("%d. adim sayisinda bilgisayar sayiyi buldu:%d\n",adimsayisi2,pcsayi);
      printf("Ana menuye donmek icin 9'a basiniz.\n");
      scanf("%d",&a);
      if(a == 9){
         goto ana;
        }
      }

      ///////////////////////////////////////////3.BASAMAK KONTROL////////////////////////////////////////////////


      printf("Tuttugunuz sayi bu mu:%d\n",pcsayi);
      don5:
      printf("Lutfen uygun sayaceksiyi giriniz:\n");
      scanf("%d",&sayaceksi);
      if (sayaceksi < -4 || sayaceksi > 0){ // sayaceksi kontrolu
      goto don5;
      }

      don55:
      printf("Lutfen uygun sayacartiyi giriniz:\n");
      scanf("%d",&sayacarti);
      if(sayacarti != 4){
        adimsayisi2++;
      }
      if(sayacarti < 0 || sayacarti > 4 ){//sayacarti kontrol
      goto don55;
      }
      toplam3 = sayacarti;

      here6:
      yenisayi1 = sayitahminetucuncubasamak(pcsayi,sayac2); // 3'ler basamagi dogru olan sayimiz.Kontrol simdi 2. basamakta
      pcsayi = yenisayi1;

      printf("Yeni sayiniz bu mu:%d\n",yenisayi1);
      don6:
      printf("Lutfen uygun sayaceksiyi giriniz:\n");
      scanf("%d",&sayaceksi);
      if (sayaceksi < -4 || sayaceksi > 0){ // sayaceksi kontrolu
      goto don6;
      }

      don66:
      printf("Lutfen uygun sayacartiyi giriniz:\n");
      scanf("%d",&sayacarti);
      if(sayacarti != 4){
        adimsayisi2++;
      }
      if(sayacarti < 0 || sayacarti > 4 ){//sayacarti kontrol
      goto don66;
      }
      toplam4 = sayacarti;

      while ( ((toplam3 == toplam4) || (toplam4 < toplam3)) ){  //3. basamakdaki değerleri degistirerek aklımdaki rakamı buldurtmaya calisiyorum bilgisayara.
      sayac2 +=1;
      if ( sayac2 == 10){
       sayac2 = 0;
      }
      goto here6;
      }

         if( toplam4 == 4){
      printf("%d. adim sayisinda bilgisayar sayiyi buldu:%d\n",adimsayisi2,pcsayi);
      printf("Ana menuye donmek icin 9'a basiniz.\n");
      scanf("%d",&a);
      if(a == 9){
         goto ana;
        }
      }

      ///////////////////////////////////////////4.BASAMAK KONTROL////////////////////////////////////////////////

      printf("Tuttugunuz sayi bu mu:%d\n",pcsayi);
      don7:
      printf("Lutfen uygun sayaceksiyi giriniz:\n");
      scanf("%d",&sayaceksi);
      if (sayaceksi < -4 || sayaceksi > 0){ // sayaceksi kontrolu
      goto don7;
      }
      don77:
      printf("Lutfen sayacartiyi giriniz:\n");
      scanf("%d",&sayacarti);
      if(sayacarti != 4){
        adimsayisi2++;
      }
      if(sayacarti < 0 || sayacarti > 4 ){//sayacarti kontrol
      goto don77;
      }
      toplam3 = sayacarti;

      here7:
      yenisayi1 = sayitahminetdortuncubasamak(pcsayi,sayac3); // 4'ler basamagi dogru olan sayimiz.Kontrol simdi 2. basamakta
      pcsayi = yenisayi1;

      printf("Yeni sayiniz bu mu:%d\n",yenisayi1);
      don8:
      printf("Lutfen uygun sayaceksiyi giriniz:\n");
      scanf("%d",&sayaceksi);
      if (sayaceksi < -4 || sayaceksi > 0){ // sayaceksi kontrolu
      goto don8;
      }
      don88:
      printf("Lutfen uygun sayacartiyi giriniz:\n");
      scanf("%d",&sayacarti);
      if(sayacarti != 4){
        adimsayisi2++;
      }
      if(sayacarti < 0 || sayacarti > 4 ){//sayacarti kontrol
      goto don88;
      }
      toplam4 = sayacarti;

      while ( ((toplam3 == toplam4) || (toplam4 < toplam3)) ){  //4. basamakdaki değerleri degistirerek aklımdaki rakamı buldurtmaya calisiyorum bilgisayara.
      sayac3 +=1;
      if ( sayac3 == 10){
       sayac3 = 0;
      }
      goto here7;
      }

      if( toplam4 == 4){
      printf("%d. adim sayisinda bilgisayar sayiyi buldu:%d\n",adimsayisi2,pcsayi);
      printf("Ana menuye donmek icin 9'a basiniz.\n");
      scanf("%d",&a);
      if(a == 9){
         goto ana;
        }
      }




      if(secim == 3){
        printf("Oyunumuzda iki farkli oyun bulunmaktadir. Bunlardan biri olan \"Kullanici Tahmin Etsin\" oyunu ve bir digeri ise\n");
        printf("\"Bilgisayar Tahmin Etsin Tuttugun Sayiyi\" adli 2 farki oyunumuz var.\n");
        printf("Ilk oyunumuzda bilgisayar 4 basamakli rakamlari birbirinden farkli bir sayi tutar hafizasinda ve kullanici ilk\n");
        printf("turda 4 basamakli rakamlari birbirinden farkli rastgele bir sayi girer keyboar'da ve bilgisayarin verdigi\n");
        printf("ipuclari ile birlikte kullanici 4 basamakli sayiyi bilene kadar tahminde bulunur.\n");
        printf("Mesela, bilgisayar 1482 sayisini hafizasinda tuttu ve kullanici 5192 sayisini girdi. Bu durumda bilgisayar\n");
        printf("bize +1 ve -1 degerlerini verecektir. Burada +1 degeri birler basamagi yani 2 rakaminin basamak degeri ve rakam\n");
        printf("esitliginden dolayi bilgisayar +1 degerini dondurur. -1 degeri ise 1 rakaminin her iki sayidada bulunmasi fakat\n");
        printf("basamak degeri esit olmadigindan dolayi bilgisayarin bize verdigi bir diger ipucudur.\n");
        printf("Ikinci oyunumuzda kullanicinin aklinda tuttugu 4 basamakli rakamlari birbirinden farkli sayiyi bilgisayar\n");
        printf("bilgisayar bulmaya calisir. Kullanicinin verdigi ipuclari ile bilgisayar kullanicinin tuttugu sayiyi bulmaya calisir.\n");

        printf("Ana menuye donmek icin 9'a basiniz.\n");
        scanf("%d",&a);
        if(a == 9){
            goto ana;
        }
      }
      if(secim == 4){
        printf("Ilk oyunumda ilk once kullanicinin ve bilgisayarin 4 basamakli rakamlari birbirinden farkli sayilar uretmesini sagladim.\n");
        printf("Daha sonrasinda bilgisayarin tuttugu ve kullanicinin girdigi sayilari basamaklarina ayirarak, basamak basamak sayi kontrolu\n");
        printf("ve basamak yerini kontrol ettim. Bunu kontrol ederek ipuclarini kullaniciya bildirdim ve kullanici bu ipuclarini degerlendirerek\n");
        printf("yeni bir sayi girmesini sagladim taki bilgisayirin tuttugu sayiyi bulana kadar.\n");
        printf("Ikinci oyunumda ise bilgisayarin olusturdugu 4 basamakli rakamlari birbirinden farkli olan sayiyi hafizada tuttum. Kullanicinin\n");
        printf("ipuclarini girmesini saglayarak bilgisayarin yeniden sayi uretmesini sagladim taki bilgisayar kullanicinin tuttugu sayiyi dogru bilene\n");
        printf("kadar.\n");

        printf("Ana menuye donmek icin 9'a basiniz.\n");
        scanf("%d",&a);
        if(a == 9){
            goto ana;
        }
      }


return 0;
}
}




