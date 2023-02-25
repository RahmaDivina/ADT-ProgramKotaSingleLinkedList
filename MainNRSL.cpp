	/* File        : mainNRSL.cpp */
/* Deskripsi   : Driver / main program untuk ADT Non Restricted Single Linked/Linear List */
/* Dibuat oleh : Ade Chandra Nugraha*/
/* Tanggal     : 25-10-2001 */
/* Diupdate oleh : Santi Sundari, 6-4-2011, hanya tdd operasi2 dasar */

#include "spnrsll.h"
#include "bodynrsl.cpp"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define NAMA 50

void Menu();

int main(){
	/* Kamus Lokal */
		List Kota[5];
		
		int i;
		int pilihMenu;
		int pilih;
		infotype X;

	/* Program */
	CreateList (&Kota[0]);
	CreateList (&Kota[1]);
	CreateList (&Kota[2]);
	CreateList (&Kota[3]);
	CreateList (&Kota[4]);
	
	do{
		system("cls");
		printf("=======================\n");
		i = 0;
		for(i;i<5;i++){
			if(First(Kota[i]) != Nil){
				printf("%d. %s\n",i+1,Info(First(Kota[i])));
			}
			else{
				printf("%d. Inputkan nama kota\n",i+1);
			}
		}
		printf("\n=======================\n");
		Menu();
		scanf("%d",&pilihMenu);

		switch(pilihMenu){
			case 1 : 
				printf("Pilih Nomor Kota : ");
				scanf("%d",&pilih);
				X = (infotype) malloc (NAMA);
				printf("Input Nama Kota : ");
				scanf("%s",X);
				
				if(pilih >= 1 && pilih <= 5){	
					if(First(Kota[pilih-1]) == Nil){
						InsVFirst(&Kota[pilih-1],X);		
					}
					else{		
						printf("Kota sudah ada !");		
					}
				}
				else{
					printf("Inputkan Kembali Nomor Kota Yang Valid !");
				}
				getch();
				system("cls");			
				break;
				
			case 2 :
				printf("Pilih Nomor Kota : ");
				scanf("%d",&pilih);
				X = (infotype) malloc (NAMA);
				printf("Input Nama Warga : ");
				scanf("%s",X);
				
				if(pilih >= 1 && pilih <= 5){	
					if(First(Kota[pilih-1]) != Nil){
						InsVLast(&Kota[pilih-1],X);		
					}
					else{		
						printf("Kota Tidak Tersedia");
					}
				}
				else{
					printf("Inputkan Kembali Nomor Kota Yang Valid !");
				}
				getch();		
				break;
				
			case 3 :
				printf("Pilih Nomor Kota Yang Akan Di Hapus : ");
				scanf("%d",&pilih);
				
				if(pilih >= 1 && pilih <= 5){
					if(First(Kota[pilih-1]) != Nil){
						printf("Kota %s Berhasil Dihapus !",Info(First(Kota[pilih-1])));
						DelAll (&Kota[pilih-1]);
					}
					else{
						printf("Kota Tidak Tersedia !");
					}
				}
				
				getch();		
				break;
				
			case 4 :
				printf("Pilih Nomor Kota Dari Warga Yang Akan Di Hapus : ");
				scanf("%d",&pilih);
				
				X = (infotype) malloc (NAMA);
				printf("Inputkan Nama Warga Yang Ingin Dihapus");
				scanf("%s",X);
				
				if(pilih >= 1 && pilih <= 5){
					DelP (&Kota[pilih-1], X);
				}
				else{
						printf("Kota Tidak Tersedia !");
				}
				
				getch();		
				break;
					
			case 5 : 
				i = 0;
				for(i;i<5;i++){
					printf("==============\n");
					printf("%d. ",i+1);
					PrintInfo(Kota[i]);
					printf("==============\n\n");
				}
				getch();
				break;
				
			case 6 :
				printf("Program dihentikan!");
				break;
			default : printf("Inputkan Insert yang valid");
				break;
			}

		}while(pilihMenu != 6);
}


