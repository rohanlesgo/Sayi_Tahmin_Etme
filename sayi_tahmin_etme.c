
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h> // Her kosturdugumda karsimiza farkli sayi çikartiyor bu yuzden bu kutuphaneyi ekledik.
int girilensayiduzgunmu(int sayi){  // girilen sayi basamaklarina ayrildi ve kontrol edildi ayni sayi var mi diye.
int birlerbasamagi,onlarbasamagi,yuzlerbasamagi,binlerbasamagi;
int hata=0;

birlerbasamagi = (sayi % 10);  //basamaklara ayrildi
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

birlerbasamagi = (sayi % 10);//basamaklara ayrildi
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

      birlerbasamagi1 = (pcsayi % 10);//basamaklara ayrildi
      onlarbasamagi1 = ((pcsayi % 100) - birlerbasamagi1)/10;
      yuzlerbasamagi1 = ((pcsayi % 1000) - (pcsayi % 100))/100;
      binlerbasamagi1 = (pcsayi - (pcsayi % 1000))/1000;

    int binlerbasamagi2,yuzlerbasamagi2,onlarbasamagi2,birlerbasamagi2;// burada tekrardan kullanicinin olusturdugu sayiyi basamaklara ayirdik.

      birlerbasamagi2 = (girilensayi % 10);//basamaklara ayrildi
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

int * sayitahminetbirincibasamak(int pcsayi, int sayac1){ // fonksiyon output'unda 2 farklı sayi dondurmek istedigim icin bu sekilde pointer olusturdum.

      int binlerbasamagi,yuzlerbasamagi,onlarbasamagi,birlerbasamagi;  // burada tekrardan bilgisayarin olusturdugu sayiyi basamaklara ayirdik.
      static int a1[2]; // main fonksiyonuna degerleri atmak icin static dizi olusturdum.

      binlerbasamagi = pcsayi / 1000;
      yuzlerbasamagi = (pcsayi-(binlerbasamagi*1000))/100;
      onlarbasamagi = (pcsayi-((binlerbasamagi*1000)+(yuzlerbasamagi*100)))/10;
      birlerbasamagi = (pcsayi-((binlerbasamagi*1000)+(yuzlerbasamagi*100)+(onlarbasamagi*10)));



      int a[8];
      int i=sayac1;
     // printf("i:%d\n",i);

      for( i ; i < 11 ; i++){
        if((onlarbasamagi == i) || (yuzlerbasamagi == i) || (binlerbasamagi == i)){

        }
      else {
      a[i] = i;
     // printf("a[%d]:%d\n",i,a[i]);
      pcsayi = a[i]+(onlarbasamagi*10)+(yuzlerbasamagi*100)+(binlerbasamagi*1000); // yeni sayiyi basamakli sekilde yazdirdim.

      a1[0]=pcsayi;
      a1[1]=i;

              return a1;
      }
      }


}

int * sayitahminetikincibasamak(int pcsayi,int sayac2){// fonksiyon output'unda 2 farklı sayi dondurmek istedigim icin bu sekilde pointer olusturdum.

      int binlerbasamagi,yuzlerbasamagi,onlarbasamagi,birlerbasamagi;  // burada tekrardan bilgisayarin olusturdugu sayiyi basamaklara ayirdik.
      static int a1[2]; // main fonksiyonuna degerleri atmak icin dizi olusturdum.

      binlerbasamagi = pcsayi / 1000;
      yuzlerbasamagi = (pcsayi-(binlerbasamagi*1000))/100;
      onlarbasamagi = (pcsayi-((binlerbasamagi*1000)+(yuzlerbasamagi*100)))/10;
      birlerbasamagi = (pcsayi-((binlerbasamagi*1000)+(yuzlerbasamagi*100)+(onlarbasamagi*10)));



      int a[8];
      int i=sayac2;
     // printf("i2:%d\n",i);

      for( i ; i < 11 ; i++){
        if((birlerbasamagi == i) || (yuzlerbasamagi == i) || (binlerbasamagi == i)){

        }
      else {
      a[i] = i;
     // printf("a[%d]:%d\n",i,a[i]);
      pcsayi = birlerbasamagi+(a[i]*10)+(yuzlerbasamagi*100)+(binlerbasamagi*1000); // yeni sayiyi basamakli sekilde yazdirdim.

      a1[0]=pcsayi;
      a1[1]=i;

              return a1;
      }
      }

}

int * sayitahminetucuncubasamak(int pcsayi,int sayac3){// fonksiyon output'unda 2 farklı sayi dondurmek istedigim icin bu sekilde pointer olusturdum.
      int binlerbasamagi,yuzlerbasamagi,onlarbasamagi,birlerbasamagi;  // burada tekrardan bilgisayarin olusturdugu sayiyi basamaklara ayirdik.
      static int a1[2]; // main fonksiyonuna degerleri atmak icin dizi olusturdum.

      binlerbasamagi = pcsayi / 1000;
      yuzlerbasamagi = (pcsayi-(binlerbasamagi*1000))/100;
      onlarbasamagi = (pcsayi-((binlerbasamagi*1000)+(yuzlerbasamagi*100)))/10;
      birlerbasamagi = (pcsayi-((binlerbasamagi*1000)+(yuzlerbasamagi*100)+(onlarbasamagi*10)));


      int a[8];
      int i=sayac3;
    //  printf("i3:%d\n",i);

      for( i ; i < 11 ; i++){
        if((birlerbasamagi == i) || (onlarbasamagi == i) || (binlerbasamagi == i)){

        }
      else {
      a[i] = i;
      //printf("a[%d]:%d\n",i,a[i]);
      pcsayi = birlerbasamagi+(onlarbasamagi*10)+(a[i]*100)+(binlerbasamagi*1000); // yeni sayiyi basamakli sekilde yazdirdim.

      a1[0]=pcsayi;
      a1[1]=i;

              return a1;
      }
      }

}

int * sayitahminetdortuncubasamak(int pcsayi,int sayac4){// fonksiyon output'unda 2 farklı sayi dondurmek istedigim icin bu sekilde pointer olusturdum.
      int binlerbasamagi,yuzlerbasamagi,onlarbasamagi,birlerbasamagi;  // burada tekrardan bilgisayarin olusturdugu sayiyi basamaklara ayirdik.
      static int a1[2]; // main fonksiyonuna degerleri atmak icin dizi olusturdum.

      binlerbasamagi = pcsayi / 1000;
      yuzlerbasamagi = (pcsayi-(binlerbasamagi*1000))/100;
      onlarbasamagi = (pcsayi-((binlerbasamagi*1000)+(yuzlerbasamagi*100)))/10;
      birlerbasamagi = (pcsayi-((binlerbasamagi*1000)+(yuzlerbasamagi*100)+(onlarbasamagi*10)));



      int a[8];
      int i=sayac4;
   //   printf("i4:%d\n",i);

      for( i ; i < 11 ; i++){
        if((birlerbasamagi == i) || (onlarbasamagi == i) || (yuzlerbasamagi == i) || (i == 0)){

        }
      else {
      a[i] = i;
     // printf("a[%d]:%d\n",i,a[i]);
      pcsayi = birlerbasamagi+(onlarbasamagi*10)+(yuzlerbasamagi*100)+(a[i]*1000); // yeni sayiyi basamakli sekilde yazdirdim.

      a1[0]=pcsayi;
      a1[1]=i;

              return a1;
      }
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

      printf("Girilen sayi:%d\n",girilensayi);// printf("Pc'nin tuttugu sayi:%d\n",pcsayi);

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

      if(secim == 2){// 2. oyun
      int adimsayisi2=1;
      int pcsayi,sayaceksi,sayacarti,sayaceksi1,sayacarti1,sayaceksi2,sayacarti2;
      int toplam4,toplam3;
      int *returnyeni; // fonksiyondan 2 deger cekebilmek icin pointer olusturdum.
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


      if(sayacarti != 4){ //adim saiyisi icin olusturuldu.
        adimsayisi2++;
      }

      if(sayacarti < 0 || sayacarti > 4 ){ //sayacarti kontrol
      goto don11;
      }

      sayaceksi1 = sayaceksi;
      sayacarti1 = sayacarti;
      //printf("sayaceksi1:%d\n",sayaceksi1);
     // printf("sayacarti1:%d\n",sayacarti1);
      toplam3= sayacarti1 + abs(sayaceksi1);
    //  printf("toplam3:%d\n",toplam3);

        if( toplam3 == 4){// toplam 3 dedıgımız sey mutlak degerli sayaceksinin ve sayacartilarin toplamidır.
      printf("%d. adim sayisinda bilgisayar sayilari buldu:%d\n",adimsayisi2,pcsayi);
      printf("Ana menuye donmek icin 9'a basiniz.\n");
      scanf("%d",&a);
      if(a == 9){
         goto ana;
        }
      }

      here4:

      returnyeni  = sayitahminetbirincibasamak(pcsayi,sayac);//retunyeni adlı diziye 1. diziye yenisayiyi, 2. diziye sayacı(i degerini) attık.

      for ( int i = 0; i < 2; i++ ) {   // fonksiyondan donen sayilari esitledim.
      if( i == 0){
        pcsayi = *(returnyeni + i);
      }
      else{
         sayac = *(returnyeni + i);
      }
   }

      pcsayi =returnyeni[0];
      sayac = returnyeni[1];

     // printf("pcsayi:%d\n",pcsayi);
     // printf("sayac:%d\n",sayac);

      sayac++;

     // printf("sayac:%d\n",sayac);

      printf("Yeni sayiniz bu mu:%d\n",pcsayi);

      don2:
      printf("Lutfen uygun sayaceksiyi giriniz:\n");
      scanf("%d",&sayaceksi);

      if (sayaceksi < -4 || sayaceksi > 0){ // sayaceksi kontrolu
      goto don2;
      }

      don22:
      printf("Lutfen uygun sayacartiyi giriniz:\n\n");
      scanf("%d",&sayacarti);

      if(sayacarti != 4){
        adimsayisi2++;
      }

      if(sayacarti < 0 || sayacarti > 4 ){//sayacarti kontrol
      goto don22;
      }

      sayaceksi2 = sayaceksi;
      sayacarti2 = sayacarti;
    //  printf("sayaceksi2:%d\n",sayaceksi2);
   //   printf("sayacarti2:%d\n",sayacarti2);
      toplam4= sayacarti2 + abs(sayaceksi2);
  //    printf("toplam4:%d\n",toplam4);


      while ( ((sayaceksi1 == sayaceksi2) && ( sayacarti1 == sayacarti2)) || ((sayaceksi1 == sayaceksi2) && ( sayacarti1 > sayacarti2)) || ((sayaceksi1 < sayaceksi2) && (sayacarti1 == sayacarti2) )) { // burada kontrolu sagladık eger gerekli sartlar saglanmazsa sayının degısımını saglıyoruz sureklı.
             sayaceksi1 = sayaceksi2;
             sayacarti1 = sayacarti2;
           //  printf("sayaceksi1:%d\n",sayaceksi1);
         //    printf("sayacarti1:%d\n",sayacarti1);
       if ( sayac == 10){
       sayac = 0;
      }
      goto here4;
      }

      if( toplam4 == 4){// toplam 4 dedıgımız sey mutlak degerli sayaceksinin ve sayacartilarin toplamidır.
      printf("%d. adim sayisinda bilgisayar sayilari buldu:%d\n",adimsayisi2,pcsayi);
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

      sayaceksi1 = sayaceksi;
      sayacarti1 = sayacarti;
     // printf("sayaceksi1:%d\n",sayaceksi1);
     // printf("sayacarti1:%d\n",sayacarti1);
      toplam3= sayacarti1 + abs(sayaceksi1);
    //  printf("toplam3:%d\n",toplam3);

       if( toplam3 == 4){// toplam 3 dedıgımız sey mutlak degerli sayaceksinin ve sayacartilarin toplamidır.
      printf("%d. adim sayisinda bilgisayar sayilari buldu:%d\n",adimsayisi2,pcsayi);
      printf("Ana menuye donmek icin 9'a basiniz.\n");
      scanf("%d",&a);
      if(a == 9){
         goto ana;
        }
      }

      here5:

     returnyeni  = sayitahminetikincibasamak(pcsayi,sayac1);//retunyeni adlı diziye 1. diziye yenisayiyi, 2. diziye sayacı(i degerini) attık.

      for ( int i = 0; i < 2; i++ ) {   // fonksiyondan donen sayilari esitledim.
      if( i == 0){
        pcsayi = *(returnyeni + i);
      }
      else{
         sayac1 = *(returnyeni + i);
      }
   }

      pcsayi =returnyeni[0];
      sayac1 = returnyeni[1];

    //  printf("pcsayi:%d\n",pcsayi);
  //    printf("sayac1:%d\n",sayac1);

      sayac1++;

     // printf("sayac1:%d\n",sayac1);

      printf("Yeni sayiniz bu mu:%d\n",pcsayi);

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

      sayaceksi2 = sayaceksi;
      sayacarti2 = sayacarti;
      //printf("sayaceksi2:%d\n",sayaceksi2);
     // printf("sayacarti2:%d\n",sayacarti2);
      toplam4= sayacarti2 + abs(sayaceksi2);
     // printf("toplam4:%d\n",toplam4);

      while ( ((sayaceksi1 == sayaceksi2) && ( sayacarti1 == sayacarti2)) || ((sayaceksi1 == sayaceksi2) && ( sayacarti1 > sayacarti2)) || ((sayaceksi1 < sayaceksi2) && (sayacarti1 == sayacarti2) )) {// burada kontrolu sagladık eger gerekli sartlar saglanmazsa sayının degısımını saglıyoruz sureklı.
             sayaceksi1 = sayaceksi2;
             sayacarti1 = sayacarti2;
          //   printf("sayaceksi11111:%d\n",sayaceksi1);
          //   printf("sayacarti11111:%d\n",sayacarti1);
       if ( sayac1 == 10){
       sayac1 = 0;
      }
      goto here5;
      }

         if( toplam4 == 4){// toplam 4 dedıgımız sey mutlak degerli sayaceksinin ve sayacartilarin toplamidır.
      printf("%d. adim sayisinda bilgisayar sayilari buldu:%d\n",adimsayisi2,pcsayi);
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

      sayaceksi1 = sayaceksi;
      sayacarti1 = sayacarti;
   //   printf("sayaceksi1:%d\n",sayaceksi1);
    //  printf("sayacarti1:%d\n",sayacarti1);
      toplam3= sayacarti1 + abs(sayaceksi1);
    //  printf("toplam3:%d\n",toplam3);

       if( toplam3 == 4){// toplam 3 dedıgımız sey mutlak degerli sayaceksinin ve sayacartilarin toplamidır.
      printf("%d. adim sayisinda bilgisayar sayilari buldu:%d\n",adimsayisi2,pcsayi);
      printf("Ana menuye donmek icin 9'a basiniz.\n");
      scanf("%d",&a);
      if(a == 9){
         goto ana;
        }
      }

      here6:

      returnyeni  = sayitahminetucuncubasamak(pcsayi,sayac2);//retunyeni adlı diziye 1. diziye yenisayiyi, 2. diziye sayacı(i degerini) attık.

      for ( int i = 0; i < 2; i++ ) {   // fonksiyondan donen sayilari esitledim.
      if( i == 0){
        pcsayi = *(returnyeni + i);
      }
      else{
         sayac2 = *(returnyeni + i);
      }
   }

      pcsayi =returnyeni[0];
      sayac2 = returnyeni[1];

   //   printf("pcsayi:%d\n",pcsayi);
    //  printf("sayac2:%d\n",sayac2);

      sayac2++;

   //   printf("sayac2:%d\n",sayac2);

      printf("Yeni sayiniz bu mu:%d\n",pcsayi);

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

      sayaceksi2 = sayaceksi;
      sayacarti2 = sayacarti;
   //   printf("sayaceksi2:%d\n",sayaceksi2);
   //   printf("sayacarti2:%d\n",sayacarti2);
      toplam4= sayacarti2 + abs(sayaceksi2);
  //    printf("toplam4:%d\n",toplam4);

       while ( ((sayaceksi1 == sayaceksi2) && ( sayacarti1 == sayacarti2)) || ((sayaceksi1 == sayaceksi2) && ( sayacarti1 > sayacarti2)) || ((sayaceksi1 < sayaceksi2) && (sayacarti1 == sayacarti2) )) {// burada kontrolu sagladık eger gerekli sartlar saglanmazsa sayının degısımını saglıyoruz sureklı.
             sayaceksi1 = sayaceksi2;
             sayacarti1 = sayacarti2;
         //    printf("sayaceksi11111:%d\n",sayaceksi1);
         //    printf("sayacarti11111:%d\n",sayacarti1);
       if ( sayac2 == 10){
       sayac2 = 0;
      }
      goto here6;
      }

         if( toplam4 == 4){// toplam 4 dedıgımız sey mutlak degerli sayaceksinin ve sayacartilarin toplamidır.
      printf("%d. adim sayisinda bilgisayar sayilari buldu:%d\n",adimsayisi2,pcsayi);
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

      sayaceksi1 = sayaceksi;
      sayacarti1 = sayacarti;
    //  printf("sayaceksi1:%d\n",sayaceksi1);
   //   printf("sayacarti1:%d\n",sayacarti1);
      toplam3= sayacarti1 + abs(sayaceksi1);
  //    printf("toplam3:%d\n",toplam3);

         if( toplam3 == 4){// toplam 3 dedıgımız sey mutlak degerli sayaceksinin ve sayacartilarin toplamidır.
      printf("%d. adim sayisinda bilgisayar sayilari buldu:%d\n",adimsayisi2,pcsayi);
      printf("Ana menuye donmek icin 9'a basiniz.\n");
      scanf("%d",&a);
      if(a == 9){
         goto ana;
        }
      }

      here7:

      returnyeni  = sayitahminetdortuncubasamak(pcsayi,sayac3);//retunyeni adlı diziye 1. diziye yenisayiyi, 2. diziye sayacı(i degerini) attık.

      for ( int i = 0; i < 2; i++ ) {   // fonksiyondan donen sayilari esitledim.
      if( i == 0){
        pcsayi = *(returnyeni + i);
      }
      else{
         sayac3 = *(returnyeni + i);
      }
   }

      pcsayi =returnyeni[0];
      sayac3 = returnyeni[1];

   //   printf("pcsayi:%d\n",pcsayi);
   //   printf("sayac3:%d\n",sayac3);

      sayac3++;

  //    printf("sayac3:%d\n",sayac3);

      printf("Yeni sayiniz bu mu:%d\n",pcsayi);

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

      sayaceksi2 = sayaceksi;
      sayacarti2 = sayacarti;
  //    printf("sayaceksi2:%d\n",sayaceksi2);
  //    printf("sayacarti2:%d\n",sayacarti2);
      toplam4= sayacarti2 + abs(sayaceksi2);
   //   printf("toplam4:%d\n",toplam4);

         while ( ((sayaceksi1 == sayaceksi2) && ( sayacarti1 == sayacarti2)) || ((sayaceksi1 == sayaceksi2) && ( sayacarti1 > sayacarti2)) || ((sayaceksi1 < sayaceksi2) && (sayacarti1 == sayacarti2) )) {// burada kontrolu sagladık eger gerekli sartlar saglanmazsa sayının degısımını saglıyoruz sureklı.
             sayaceksi1 = sayaceksi2;
             sayacarti1 = sayacarti2;
          //   printf("sayaceksi11111:%d\n",sayaceksi1);
          //   printf("sayacarti11111:%d\n",sayacarti1);
       if ( sayac3 == 10){
       sayac3 = 0;
      }
      goto here7;
      }

         if( toplam4 == 4){// toplam 4 dedıgımız sey mutlak degerli sayaceksinin ve sayacartilarin toplamidır.

      printf("%d. adim sayisinda bilgisayar sayilari buldu:%d\n",adimsayisi2,pcsayi);
      printf("Ana menuye donmek icin 9'a basiniz.\n");
      scanf("%d",&a);
      if(a == 9){
         goto ana;
        }
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




