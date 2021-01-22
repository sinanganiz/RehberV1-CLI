#include <iostream>
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
using namespace std;


struct dugum
{
	char adsoyad[30], adres[90], TC[12], telefon[11];
	struct dugum *next;
};

void gotoxy(short x,short y) ;
void anaMenu();
void Secim(char s);
void loading();
int RehberiYaz(struct dugum *liste);
void Menu1(int satir);
void Menu2(int satir);
void Menu3(int satir);
void Menu4();
void Menu5();
void MenuX();

struct dugum *liste, *fadress;
int main()
{
	
	liste=(struct dugum*)malloc(sizeof(struct dugum));
	fadress=liste;
	liste->next=NULL;
	strcpy(liste->adsoyad,"     ");
	strcpy(liste->adres,"     ");
	strcpy(liste->TC,"     ");
	strcpy(liste->telefon,"     ");
	

	FILE *rehber;
	rehber=fopen("Rehber.txt","r");
	if(rehber!=NULL)
	{
		while(!feof(rehber))
		{

			fscanf(rehber," %[^;] ; %[^;] ; %s ; %s ;\n",&liste->adsoyad, &liste->adres, &liste->TC, &liste->telefon);
	
			liste->next=(struct dugum *)malloc(sizeof(struct dugum));
			liste=liste->next;
			liste->next=NULL;
			strcpy(liste->adsoyad,"     ");
			strcpy(liste->adres,"     ");
			strcpy(liste->TC,"     ");
			strcpy(liste->telefon,"     ");
	
		}	
		fclose(rehber);
	}


	

	anaMenu();
	system("pause");
	return 0;
}

void gotoxy(short x,short y)
{ 
	COORD pos={x,y}; 
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos); 
}


void anaMenu()
{
	system("color 6");
	gotoxy(40,1);
	cout<<"Rehber Version 1.0";
	gotoxy(30,3);
	cout<<"----------------------------------------";
	gotoxy(30,4);
	cout<<"/\t\t  [ 1 ] Ekle"; gotoxy(69,4);cout<<"/";
	gotoxy(30,5);
	cout<<"/\t\t  [ 2 ] Cikar"; gotoxy(69,5);cout<<"/";
	gotoxy(30,6);
	cout<<"/\t\t  [ 3 ] Ara"; gotoxy(69,6);cout<<"/";
	gotoxy(30,7);
	cout<<"/\t\t  [ 4 ] Degistir"; gotoxy(69,7);cout<<"/";
	gotoxy(30,8);
	cout<<"/\t\t  [ 5 ] Yaz"; gotoxy(69,8);cout<<"/";
	gotoxy(30,9);
	cout<<"/\t\t  [ 6 ] Goster"; gotoxy(69,9);cout<<"/";
	gotoxy(30,10);
	cout<<"/\t\t  [ ESC ] Cik"; gotoxy(69,10);cout<<"/";
	gotoxy(30,11);
	cout<<"----------------------------------------";




	char AnaSecim;
	gotoxy(41,12);
	cout<<"Seciminiz : ";
	AnaSecim= getche();
	Secim(AnaSecim);
}

void loading()
{
	int i=0;
	gotoxy(46,14);
		cout<<"Yukleniyor";
		gotoxy(33,15);
		for(i=0;i<11;i++)
		{
			
			cout<<" o ";
			Sleep(300);
		}

		system("CLS");


}
void Secim(char s)
{
	int satir;
	int n=0;
	switch(s)
	{
		
	case '1':
		loading();
		satir=RehberiYaz(liste);
		Menu1(satir);
		break;
	
	case '2':
		
		loading();
		satir=RehberiYaz(liste);
		Menu2(satir);

		break;
	
	case '3':
		
		loading();
		satir=1;
		Menu3(satir);
	
		break;
		
	case '4':
		loading();
		Menu4();
		break;
		
	case '5':
		loading();
		Menu5();
		break;

	case '6':
		loading();
		liste=fadress;
		RehberiYaz(liste);
		liste=fadress;
		cout<<endl<<endl<<"\n\t\tAna menuye donmek icin [ESC] tusuna basiniz.";
		while( getch()!=27)
		{
		}
		system("CLS");
		anaMenu();
		break;
		
	case 27:
		gotoxy(46,14);
			cout<<"CCikis yapiliyor";
		gotoxy(33,15);
		for(n=0;n<11;n++)
		{
			
			cout<<" o ";
			Sleep(300);
		}

		system("CLS");

			MenuX();
		break;



	default:
		system("CLS");
		gotoxy(22,17);
		cout<<"------------------------------------------------------------";
		gotoxy(22,18);
		cout<<"|                                                          |";
		gotoxy(22,19);
		cout<<"| HATA : Gecersiz secim yaptiniz. Lutfen tekrar deneyiniz. |";
		gotoxy(22,20);
		cout<<"|                                                          |";
		gotoxy(22,21);
		cout<<"------------------------------------------------------------";
	
		anaMenu();
		gotoxy(41,12);
		cout<<"Seciminiz : ";
		char ss;
		ss= getchar();
		Secim(ss);
		break;
	}

}



int RehberiYaz(struct dugum *liste)
{
	gotoxy(45,1);
	cout<<"Rehber Listesi";
	gotoxy(1,3);
	cout<<"*******************************************************************************************************************";
	gotoxy(1,4);
	cout<<"*Ad Soyad                      *Adres                                               *TC            *Telefon       *"<<endl;
	cout<<" *******************************************************************************************************************";
	int i=6;
	int durum=0;
	while(liste!=NULL)
	{
		if(strcmp(liste->adsoyad,"     ")!=0 && strcmp(liste->adres,"     ")!=0 && strcmp(liste->TC,"     ")!=0 && strcmp(liste->telefon,"     ")!=0 )
	{
		durum=0;
		gotoxy(1,i);
		cout<<"|"<<liste->adsoyad;
		gotoxy(32,i);
		if(strlen(liste->adres)>50)
		{
			durum=1;
			int j=0;
			cout<<"|";
			for(j=0;j<50;j++)
			{
				cout<<liste->adres[j];
			}
			i++;
			gotoxy(32,i);
			cout<<"|";
			for(j=50;j<strlen(liste->adres);j++)
			{
				cout<<liste->adres[j];
			}
		}
		else
		{
			cout<<"|"<<liste->adres;
		}
		if(durum==1)
			i--;
		gotoxy(85,i);
		cout<<"|"<<liste->TC;
		gotoxy(100,i);
		cout<<"|"<<liste->telefon;
		gotoxy(115,i);cout<<"|";
		if(durum==1)
		{
			gotoxy(1,i+1);  cout<<"|";
			gotoxy(85,i+1);  cout<<"|";
			gotoxy(100,i+1);  cout<<"|";
			gotoxy(115,i+1);  cout<<"|";
			i+=3;
		}
		else
			i+=2;

		gotoxy(1,i-1);
		cout<<"-------------------------------------------------------------------------------------------------------------------";
		}
		liste=liste->next;
		
	}
	return i+1;
}


void Menu1(int satir)
{

	liste=fadress;
	while(liste->next!=NULL)
	{
		liste=liste->next;
	}
	
	if(strcmp(liste->adsoyad,"     ")!=0 && strcmp(liste->adres,"     ")!=0 && strcmp(liste->TC,"     ")!=0 && strcmp(liste->telefon,"     ")!=0 )
	{
		liste->next=(struct dugum *)malloc(sizeof(struct dugum));
		liste=liste->next;
		liste->next=NULL;
	}
	
	char bilgiler[100];
	gotoxy(1,satir);
	cout<<"/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/";
	satir+=2;
	gotoxy(47,satir);
	cout<<"Yeni Kayit";
	satir++;
	gotoxy(1,satir);
	

	cout<<"Ad Soyad : ";
	gets(bilgiler);
	satir++;
	strcpy(liste->adsoyad,bilgiler);
	

	gotoxy(1,satir);
	cout<<"Adres : ";
	gets(bilgiler);
	satir++;
	strcpy(liste->adres,bilgiler);

	gotoxy(1,satir);
	cout<<"TC Kimlik Numarasi : ";
	gets(bilgiler);
	satir++;
	strcpy(liste->TC,bilgiler);

	gotoxy(1,satir);
	cout<<"Telefon : ";
	gets(bilgiler);
	satir++;
	strcpy(liste->telefon,bilgiler);

	gotoxy(20,satir);
	cout<<"Tebrikler, Kisi Basariyla Kaydedildi. Ana Menuye Yonlendiriliyorsunuz.";
	satir++;
	int sayacc=0;
	gotoxy(33,satir);
	for(sayacc=0;sayacc<12;sayacc++)
	{
		cout<<" o ";
		Sleep(300);
	}
	satir++;
		system("CLS");
		liste=fadress;
		anaMenu();
}






void Menu2(int satir)
{
	int kontrol=0;
	liste=fadress;
	struct dugum* last;
	
	char bilgiler[100];
	gotoxy(1,satir);
	cout<<"/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/";
	satir+=2;
	gotoxy(47,satir);
	cout<<"Kisi Silme";
	satir++;
	gotoxy(1,satir);
	cout<<"Silinecek kisinin TC : ";
	gets(bilgiler);
	satir++;
	last=liste;
	while(liste!=NULL)
	{
		
		if(strcmp(liste->TC,bilgiler)==0)
		{
			kontrol=1;//kontrol 1 ise boyle bir kisi var demektir
			break;
		}
		last=liste;
		liste=liste->next;
	}
	if(kontrol==1)
	{
		if(liste==fadress)
		{
			if(liste->next!=NULL)
			{
				fadress=liste->next;
				free(liste);
			}
			else
			{
				fadress=(struct dugum *)malloc(sizeof(struct dugum));
				free(liste);
				liste=fadress;
				liste->next=NULL;
				strcpy(liste->adsoyad,"     ");
				strcpy(liste->adres,"     ");
				strcpy(liste->TC,"     ");
				strcpy(liste->telefon,"     ");
			}
		}
		else
		{
			last->next=liste->next;
			free(liste);
		}
		gotoxy(21,satir+1);
		cout<<"Kisi basariyla silindi. Ana menuye yonlendiriliyorsunuz.";
	}
	else
	{
		gotoxy(21,satir+1);
		cout<<"Boyle bir kisi bulunamadi. Ana menuye yonlendiriliyorsunuz.";
	}
		
	liste=fadress;
	satir+=2;
	int sayacc=0;
	gotoxy(33,satir);
	for(sayacc=0;sayacc<12;sayacc++)
	{
		cout<<" o ";
		Sleep(300);
	}
	satir++;

	system("CLS");
	anaMenu();
}






void Menu3(int satir)
{
	struct dugum *bulunan=NULL;

	liste=fadress;
	char bilgiler[100];
	gotoxy(1,satir);
	cout<<"/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/";
	satir+=2;
	gotoxy(47,satir);
	cout<<"Kisi Arama";
	satir++;
	gotoxy(1,satir);
	cout<<"Aranacak kisinin TC : ";
	gets(bilgiler);
	satir++;
	
	while(liste!=NULL)
	{
		if(strcmp(liste->TC,bilgiler)==0)
		{
			bulunan=liste;
			break;		
		}
			
		else
			liste=liste->next;
	}

	if(bulunan!=NULL)
	{
		system("CLS");

		gotoxy(45,1);
		cout<<"Bulunan Kisi";
		gotoxy(1,3);
		cout<<"*******************************************************************************************************************";
		gotoxy(1,4);
		cout<<"*Ad Soyad                      *Adres                                               *TC            *Telefon       *"<<endl;
		cout<<" *******************************************************************************************************************";
		int i=6;
		int durum=0;
		durum=0;
		gotoxy(1,i);
		cout<<"|"<<bulunan->adsoyad;
		gotoxy(32,i);
		if(strlen(bulunan->adres)>50)
		{
			durum=1;
			int j=0;
			cout<<"|";
			for(j=0;j<50;j++)
			{
				cout<<bulunan->adres[j];
			}
			i++;
			gotoxy(32,i);
			cout<<"|";
			for(j=50;j<strlen(bulunan->adres);j++)
			{
				cout<<bulunan->adres[j];
			}
		}
		else
		{
			cout<<"|"<<bulunan->adres;
		}
		if(durum==1)
			i--;
		gotoxy(85,i);
		cout<<"|"<<bulunan->TC;
		gotoxy(100,i);
		cout<<"|"<<bulunan->telefon;
		gotoxy(115,i);cout<<"|";
		if(durum==1)
		{
			gotoxy(1,i+1);  cout<<"|";
			gotoxy(85,i+1);  cout<<"|";
			gotoxy(100,i+1);  cout<<"|";
			gotoxy(115,i+1);  cout<<"|";
			i+=3;
		}
		else
			i+=2;

		gotoxy(1,i-1);
		cout<<"-------------------------------------------------------------------------------------------------------------------";
		i++;
		gotoxy(23,i);
		cout<<"Aradiginiz kisi bulundu. Ana menuye donmek icin [ ESC ] tusuna basiniz.";
		while( getch()!=27)
		{
		}

	}

	else
	{
		satir++;
		gotoxy(21,satir);
		cout<<"Aradiginiz kisi bulunamadi. Ana menuye yonlendiriliyorsunuz.";

		satir++;
		int sayacc=0;
		gotoxy(33,satir);
		for(sayacc=0;sayacc<12;sayacc++)
		{
			cout<<" o ";
			Sleep(300);
		}
		satir++;
		
		
	}
	system("CLS");

			anaMenu();
}
	





void Menu4()
{
	system("CLS");
	int satir=1;
	struct dugum *bulunan=NULL;

	liste=fadress;
	char bilgiler[100];
	gotoxy(1,satir);
	cout<<"/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/";
	satir+=2;
	gotoxy(47,satir);
	cout<<"Kisi Guncelleme";
	satir++;
	gotoxy(1,satir);
	cout<<"Bilgisi guncellenecek kisinin TC : ";
	gets(bilgiler);
	satir++;
	
	while(liste!=NULL)
	{
		if(strcmp(liste->TC,bilgiler)==0)
		{
			bulunan=liste;
			break;		
		}
			
		else
			liste=liste->next;
	}
	satir++;
	if(bulunan!=NULL)
	{
			gotoxy(23,satir);
			cout<<"Hangi alan guncellenecek?";
			satir++;
			gotoxy(29,satir);
			cout<<"[ 1 ] Ad-Soyad";
			satir++;
			gotoxy(29,satir);
			cout<<"[ 2 ] Adres";
			satir++;
			gotoxy(29,satir);
			cout<<"[ 3 ] TC";
			satir++;
			gotoxy(29,satir);
			cout<<"[ 4 ] Telefon";
			satir++;

			char tercih;
			gotoxy(28,satir);
			
			cout<<"Seciminiz : ";
			tercih=getchar();
			system("CLS");
			gotoxy(1,1);
			switch(tercih)
			{
				case '1':
					gotoxy(22,3);
					gets(bilgiler);
					cout<<"Ad Soyad : ";
					gets(bilgiler);
					strcpy(bulunan->adsoyad,bilgiler);
					break;

				case '2':
					gotoxy(22,3);
					gets(bilgiler);
					cout<<"Adres : ";
					gets(bilgiler);
					strcpy(bulunan->adres,bilgiler);
					break;

				case '3':
					gotoxy(22,3);
					gets(bilgiler);
					cout<<"TC : ";
					gets(bilgiler);
					strcpy(bulunan->TC,bilgiler);
					break;	

				case '4':
					gotoxy(22,3);
					gets(bilgiler);
					cout<<"Telefon : ";
					gets(bilgiler);
					strcpy(bulunan->telefon,bilgiler);
					break;

				default:
					gotoxy(22,3);
					cout<<"Yanlis tercih yaptiniz. Ana menuye yonlendiriliyorsunuz.";
					
					int i=0;
					gotoxy(32,4);
					for(i=0;i<11;i++)
					{
						cout<<" o ";
						Sleep(300);
					}

					system("CLS");
					anaMenu();
					break;
			}

			gotoxy(22,3);
					cout<<"Bilgiler basariyla guncellendi. Ana menuye yonlendiriliyorunuz.";
					
					int i=0;
					gotoxy(32,4);
					for(i=0;i<11;i++)
					{
						cout<<" o ";
						Sleep(300);
					}

					system("CLS");
					anaMenu();
	}
	else
	{
		system("CLS");
					gotoxy(21,4);
		cout<<"Aradiginiz kisi bulunamadi. Ana menuye yonlendiriliyorsunuz.";


		
					int i=0;
					gotoxy(32,5);
					for(i=0;i<11;i++)
					{
						cout<<" o ";
						Sleep(300);
					}

					system("CLS");
					anaMenu();
	}
		
}








void Menu5()
{
	system("CLS");
	liste=fadress;
	FILE *Rehber;
	Rehber=fopen("Rehber.txt","w");
	while(liste!=NULL)
	{
		fprintf(Rehber," %s ; %s ; %s ; %s ;\n",liste->adsoyad,liste->adres,liste->TC,liste->telefon);
		liste=liste->next;
	}
	fclose(Rehber);
	liste=fadress;
	int satir=RehberiYaz(liste);
	gotoxy(21,satir);cout<<"Rehber listesi not defterine kaydedildi. Ana menuye yonlendiriliyorsunuz.";
	int i=0;
	satir++;
					gotoxy(33,satir);
					for(i=0;i<11;i++)
					{
						cout<<" o ";
						Sleep(300);
					}

					system("CLS");
					anaMenu();
}


void MenuX()
{
	exit(0);
}
