#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// deklarasi function
void buatTiket(string nomorTiket, int jumlahPesanan, int pilihBus);
void openTiket(string nomorTiket);
void pembatalanPesanan(char pilihan);
void PilihanBus();

struct dataTiket
{
    string nomorTiket, openData;
    int jumlahPesanan, mode, pilihBus;
    char pilihan, jawab;
};


// project app
int main() {
    dataTiket data;

        /* PROGRAM APP CREATE READ DELETE */
        cout << "======================================================" << endl;
        cout << " SELAMAT DATANG DI APPS SEDERHANA SEMOGA MEMBANTU ANDA" << endl;
        cout << "\t\tNAMA" << endl;
        cout << "\t\tLINDAN MAULANA" << endl;
        cout << "\t\tDIAN ARDIANSYAH" << endl;
        cout << "======================================================" << endl;

    do {
        cout << endl;
        cout << "======================================================" << endl;
        cout << "\t\tPilihan Mode" << endl;
        cout << "\t1.Pesan Tiket 2.Lihat Tiket 3.Hapus Tiket" << endl;
        cout << "  Apa yang ingin anda lakukan : ";
        cin >> data.mode;
        cout << "======================================================" << endl;
        cout << endl;

        /* MODE 1 MEMBUAT FILE(.TXT) DAN MENGINPUT DATA */
        if(data.mode == 1) {
            // membuat file dengan memasukan nama file(.txt)
            cout << "Masukan nomorTiket anda format(.txt) : ";
            cin >> data.nomorTiket;

            cout << "Ingat baik baik nomor tiket anda!!!!" << endl;
            cout << endl;


            PilihanBus();
            cout << "Pilih bus yang ingin anda pesan : ";
            cin >> data.pilihBus;

            // masukan jumlah data yang ingin di simpan
            cout << "Masukan jumlah pelanggan yang memesan tiket : ";
            cin >> data.jumlahPesanan;

            // memanggil fungsi agar program membuat file berjalan
            buatTiket(data.nomorTiket, data.jumlahPesanan, data.pilihBus);

        /* MODE 2 MENGECEK / MELIHAT DATA FILE YANG SUDAH ADA */
        } else if(data.mode == 2) {
            // read file
            cout << "masukan nomorTiket yang ingin anda lihat, format(.txt) ? ";
            cin >> data.openData;
            cout << endl;

            // function open in call this function main app
           openTiket(data.openData);

        /* MODE 3 MENGHAPUS FILE */
        } else if(data.mode == 3) {
            cout << "apa kamu mau membatalkan pesanan (y/n) ? ";
            cin >> data.pilihan;

            pembatalanPesanan(data.pilihan);
        } else {
            cout << "pilihan anda tidak valid!!!" << endl;
        };


        cout << "pemesanan tiket berhasil apa masih ada yang ingin anda lakukan (y/n) ?";
        cin >> data.jawab;

    } while(data.jawab == 'y' || data.jawab == 'Y');
    

    /* PENUTUP PROGRAM */
    cout << endl;
    cout << "program selesai" << endl;
    cout << endl;
    cout << "TERIMAKASIH SUDAH MEMESAN TIKET DI LINDANDIAN TRANS, SEKIAN PROJECT PEMESANAN TIKET, MAHASISWA TEKNIK INFORMATIKA UNIKU " << endl;
    cout << "                          programming is so much more than just writing code                         " << endl;
    cout << "                                       it is a reflection of you                                     " << endl;

    return 0;
};

// function create file and input data this file
void buatTiket(string nomorTiket, int jumlahPesanan, int pilihBus) {
    string data, openData, bus;
    int harga;

    if(pilihBus == 1) {
        bus = "Faeyza";
        harga = 100000 * jumlahPesanan;
    } else if(pilihBus == 2) {
        bus = "Meteor";
        harga = 95000 * jumlahPesanan;
    } else {
        bus = "Patas Depok";
        harga = 120000 * jumlahPesanan;
    };

    ofstream buatTiket(nomorTiket, ios::app);

    if(buatTiket.is_open()) {
        cout << "=============================================";
        buatTiket << "Nama Bus : " << bus << endl;
        buatTiket << "Jumlah Tagihan : Rp " << harga << endl;

        buatTiket << "Data pemesan :" << endl;
        for(int i = 1; i <= jumlahPesanan; i++) {
            cout << "masukan nama pemesan ke- " << i << " : ";
            cin >> data;

            buatTiket << i << ". " << data << endl;
        };

        buatTiket << "LindanDian Trans Aman Nyaman Sopan" << endl;
        buatTiket.close();

        cout << "tiket berhasil di pesan!!" << endl;
        cout << "=============================================";
        cout << endl;
    };
};

// function open file and read data this file
void openTiket(string nomorTiket) {
    ifstream openData(nomorTiket);

    if(openData.is_open()) {
        string data;
        cout << "tiket tersedia!!!" << endl;

        cout << "=============================================" << endl;
        while(getline(openData, data)) {
            cout << data << endl;
        };
        cout << "=============================================" << endl;

        openData.close();

    } else {
        cout << "tiket tidak tersedia!!" << endl;
    };
};

// function remove file
void pembatalanPesanan(char pilihan) {
    string nomorTiket;

    if(pilihan == 'y' || pilihan == 'Y') {
        cout << "masukan nomor tiket.txt yang ingin anda batalkan ? ";
        cin >> nomorTiket;

        ofstream file(nomorTiket, ios::trunc);

        if(file.is_open()) {
            file.close();

            remove(nomorTiket.c_str());

            cout << "Pembatalan tiket :  successfully" << endl;
            cout << endl;
        } else {
            cout << "terjadi kesalahan saat pembatalan tiket : unsuccessfully" << endl;
        };

    } else {
        cout << "tiket tetap aktif!!" << endl;
    };
};

void PilihanBus() {
    cout << "Bus Bus yang tersedia" << endl;
    cout << "1. Faeyza" << endl;
    cout << "2. Meteor" << endl;
    cout << "3. Patas Depok" << endl;
}
