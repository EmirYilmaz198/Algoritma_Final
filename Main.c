#include <stdio.h>


FILE *dosya;



int main()
{
  int islem, tutar, sifre, sifre_denetleme, psw_chance, psw, secim1;

  float bakiye ;
  

  printf("\t\t\t ----------------------------------Hos Geldiniz--------------------------------");
  printf("\n\n\n\n\n\n\n\n");
  printf("\n\nLUTFEN KART SIFRENIZI TUSLAYIN : ");  
  scanf("%d", &sifre);

  dosya = fopen("sifre.txt", "r");
  fscanf(dosya, "%d", &sifre_denetleme);
  fclose(dosya);

  if (sifre_denetleme == sifre) {
    system("cls");
    while (1) {
      printf("1-Para Cekme  2-Para Yatirma 3-Bakiye Gorme  4:Cikis   5 :Sifre Degistir  ");
      printf("\n\n Isleminizi Seciniz : ");
      scanf("%d", &islem);

      if (islem == 1) {
        system("cls");
        
        dosya = fopen("kalan.txt", "r");
        fscanf(dosya, "%f", &bakiye);
        printf("Bakiyeniz : %.2f", bakiye);
        fclose(dosya);
        
        printf("\n\nCekmek Istediginiz Tutari Giriniz : "); 
        scanf("%d", &tutar);
        
            if (bakiye >= tutar) {
              bakiye = bakiye - tutar;
              system("cls");
              printf("\n\n %d TL Cekildi.\n\n Kalan Bakiyeniz: %.2f", tutar, bakiye);
              dosya = fopen("kalan.txt", "w");
              fprintf(dosya, "%.2f", bakiye);
              fclose(dosya);

            
              printf("\n\nBaska Bir Islem Yapmak Ister Misiniz :   (1)EVET          (2)HAYIR\n");
              scanf("%d", &secim1);
              system("cls");
                    if (secim1 == 1) {
                      continue;
                      
                    }
                    else if (secim1 == 2) {
                      system("cls");
                      printf("Cikis Yapildi");
                      return 0;
                    }

              
            }

            else
              printf("Bakiye yetersiz.");
      }

      else if (islem == 2) {
        system("cls");

        dosya = fopen("kalan.txt", "r");
        fscanf(dosya, "%f", &bakiye);
        printf("Bakiyeniz : %.2f", bakiye);
        fclose(dosya);

        printf("\nYatirmak istediginiz tutari giriniz :");
        scanf("%d", &tutar);

        bakiye = bakiye + tutar;

        dosya = fopen("kalan.txt", "w");
        fprintf(dosya, "%.2f", bakiye);
        fclose(dosya);
        system("cls");

        printf("\n %d TL yatirildi\n\n Bakiyeniz : %.2f", tutar, bakiye);



        printf("\n Baska Bir Islem Yapmak Ister Misiniz :  (1)EVET          (2)HAYIR\n");
        scanf("%d", &secim1);
        system("cls");
              if (secim1 == 1) {
                continue;
              }
              if (secim1 == 2) {
                system("cls");
                printf("Cikis Yapildi");
                return 0;
              }
      }

      else if (islem == 3) {
        system("cls");
        dosya = fopen("kalan.txt", "r");
        fscanf(dosya, "%f", &bakiye);
        printf("Bakiyeniz :  %.2f TL \n",bakiye);
        fclose(dosya);
        


        printf("\n Baska Bir Islem Yapmak Ister Misiniz :  (1)EVET          (2)HAYIR \n");
        scanf("%d", &secim1);
        system("cls");

              if (secim1 == 1) {
                continue;
              }
              else if (secim1 == 2) {
                system("cls"); 
                printf("\nCikis Yapildi");
                return 0;
              }

        
      }

      else if (islem == 4) {
        system("cls");
        printf("Cikis yapilidi ");
        break;
      }

      else if (islem == 5) {
        system("cls");
        int sifre_yeni;

        dosya = fopen("sifre.txt", "r");
        fscanf(dosya, "%d", &psw_chance);
        fclose(dosya);

        printf("Eski Sifrenizi Giriniz : ");
        scanf("%d",&psw);


        if(psw_chance == psw ){

        printf("Eski sifre dogru lutfen yeni sifrenizi girin  : ");  
        scanf("%d", &sifre_yeni);
        dosya = fopen("sifre.txt", "w");
        fprintf(dosya, "%d", sifre_yeni);
        fclose(dosya);
        system("cls");
        printf("Sifreniz basariliyle degistirildi.\n\n");
        }

        else {
          printf("Sifre Hatali \n");
        }

        printf("Baska Bir Islem Yapmak Ister Misiniz : (1)EVET          (2)HAYIR \n");
        scanf("%d", &secim1);

    
        if (secim1 == 1) {
          continue;
        }
        else if (secim1 == 2) {
          system("cls");
          printf("Cikis Yapildi");
          return 0;
        }


      }

      else {
        system("cls");
        printf("\n\n Hatali Islem Yaptiniz Lutfen Terar Denyiniz !! \n\n");
      }


    }

  }
  else
    printf("sifreniz hatalidir");

  return 0;
}