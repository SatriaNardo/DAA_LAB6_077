#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <windows.h>
#define nmax 5 
using namespace std;

int n = 0; 
struct data
{ 
    int nim;
    char nama[20];
    char kom;
};
struct data maba[nmax]; 
void tambah_data();    
void hapus_data();
void tampilkan_data();
void update_data();
main()
{
    int pil;
menu:
	system("CLS");
    cout << " \t\t MENU \n";
    cout << "1. tambah data\n";
    cout << "2. hapus data \n";
    cout << "3. tampilkan data \n";
    cout << "4. update data \n";
    cout << "5. keluar \n";
    cout << "\n Pilih menu (1/2/3/4/5) ? ";
    cin >> pil;
    if (pil == 1)
        tambah_data();
    else if (pil == 2)
        hapus_data();
    else if (pil == 3)
        tampilkan_data();
    else if (pil == 4)
    	update_data();
    else if (pil == 5)
        exit(1);
    else
    {
        cout << "pilihan tak tersedia...!!!\n";
		Sleep(3000);
    }
    goto menu;
    getch();
}

void tambah_data()
{
	system("CLS");
    if (n < nmax)
    {
        cout << "Nama : ";
        cin >> maba[n].nama;
        cout << "NIM : ";
        cin >> maba[n].nim;
        cout << "Kom : ";
        cin >> maba[n].kom;
        n++;
    }
    else
    {
        cout << "\n data telah melebihi...!!!\n maksimal data = " << nmax;
		Sleep(3000);
	}
}
void hapus_data()
{
	system("CLS");
    int x;
    cout << "pilih data yang akan dihapus (1 s.d. 5) : ";
    cin >> x;
    if (x < n && x > 0)
    {
        for (int i = x; i < n; i++)
        {
            strcpy(maba[i - 1].nama, maba[i].nama);
            maba[i - 1].nim = maba[i].nim;
            maba[i - 1].kom = maba[i].kom;
        }
        n--;
    }
    else if (x == n)
        n--;
    else
    {
        cout << "\nData yang ingin dihapus tidak ada...!!!\n";
		Sleep(3000);
	}
}
void tampilkan_data()
{
	system("CLS");
	char x;
    if (n == 0)
    {
        cout << "Tidak ada data yang disimpan...!!!\n";
        Sleep(3000);
	}
    else
    {
        for (int i = 0; i < n; i++)
        {
            cout << "Data ke-" << i + 1 << " : ";
            cout << "\nNama : " << maba[i].nama;
            cout << "\nNIM : " << maba[i].nim;
            cout << "\nKom : " << maba[i].kom;
            cout << endl << endl;
            
        }
        cin >> x;
    }
}
void update_data()
{
	system("CLS");
	int a,b;
	if(n == 0)
	{
		cout << "Tidak ada data untuk di-update!!!\n";
		Sleep(3000);
	}
	else
	{
		cout << "Banyak data yang ingin di update :\n";
		cin >> a;
		if(a > n)
		{
			cout << "Data yang ingin diupdate melebihi maksimum!!!";
			Sleep(3000);
		}
		else if(a == 0)
		{
			cout << "Tidak dapat mengupdate 0 data";
			Sleep(3000);
		}
		else
		{
			for (int i = 0; i < a; i++)
			{
			cout << "Data Ke-";cin >> b;
			cout << "Nama : ";cin >> maba[b-1].nama;
            cout << "NIM : " ;cin >> maba[b-1].nim;
            cout << "Kom : " ;cin >> maba[b-1].kom;
            cout << endl;
			}
		}
	}
}
