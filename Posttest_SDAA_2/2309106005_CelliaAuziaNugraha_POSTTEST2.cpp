#include <iostream>
#include <string>
using namespace std;

struct bunga {
    int kode;
    string nama;
    string warna;
    double harga;
    int stock;
    string asal;
};

void tambah_bunga(bunga* ptrBunga){
    cout<<"Masukkan kode bunga: "<<endl;
    cin>>ptrBunga->kode;
    cout<<"Masukkan nama bunga: "<<endl;
    cin>>ptrBunga->nama;
    cout<<"Masukkan warna bunga: "<<endl;
    cin>>ptrBunga->warna;
    cout<<"Masukkan harga bunga: "<<endl;
    cin>>ptrBunga->harga;
    cout<<"Masukkan stock bunga: "<<endl;
    cin>>ptrBunga->stock;
    cout<<"Masukkan asal bunga: "<<endl;
    cin>>ptrBunga->asal;

    cout<<"Bunga berhasil ditambahkan"<<endl;
};

//variabel arr untuk pointer dari arrBunga
void tampilkan_bunga(bunga* arr, int jmlhBunga){
    if (jmlhBunga == 0) {
    cout<<"Data Bunga Kosong!!"<<endl;
    return;
    }

    cout<<"\nData Bunga: \n"<<endl;
    cout<<"Kode\tNama\tWarna\tHarga\tStock\tAsal"<<endl;
    for (int i = 0; i < jmlhBunga; i++) {
        cout<<arr[i].kode<<"\t"<<arr[i].nama<<"\t"<<arr[i].warna<<"\t"<<arr[i].harga<<"\t"<<arr[i].stock<<"\t"<<arr[i].asal<<"\t"<<endl;
    };

};

void ganti_bunga(bunga* arr, int jmlhBunga){
    int kode;
    bool found = false;

    cout<<"Masukkan kode bunga yang ingin diganti datanya: "<<endl;
    cin>>kode;

    for (int i = 0; i < jmlhBunga; i++){
        if (arr[i].kode == kode){
        cout<<"Masukkan Nama Baru: "<<endl;
        cin>>arr[i].nama;
        cout<<"Masukkan Warna Baru: "<<endl;
        cin>>arr[i].warna;
        cout<<"Masukkan Harga Baru: "<<endl;
        cin>>arr[i].harga;
        cout<<"Masukkan Stock Baru: "<<endl;
        cin>>arr[i].stock;
        cout<<"Masukkan Asal Baru: "<<endl;
        cin>>arr[i].asal;
        
        found = true;
        cout<<"Data Bunga Ditemukan!"<<endl;
        break;
        };
    };

    if (!found){
        cout<<"Data Bunga Tidak Ditemukan!"<<endl;

    };
};

void hapus_bunga(bunga* arr, int* jmlhBunga){
    int kode;
    bool found = false;

    cout<<"Masukkan kode bunga yang ingin dihapus datanya: "<<endl;
    cin>>kode;

    for (int i = 0; i < *jmlhBunga; i++) {
        if (arr[i].kode == kode){
            for (int j = i; j < *jmlhBunga; j++){
                arr[j] = arr[j+1];
            };
            (*jmlhBunga)--;
            found = true;
            cout<<"Data Bunga Berhasil Dihapus!"<<endl;
            break; 
        };
    };

    if(!found){
        cout<<"Data Bunga Tidak Ditemukan!"<<endl;
    };
};

int main (){
    bunga arrBunga[100] = {
        {1, "Mawar", "merah", 20000, 10, "Eropa dan Asia"},
        {2, "Melati", "putih", 10000, 20, "Himalaya Asia"},
        {3, "Lily", "putih", 30000, 20, "Eropa"}
    };
    
    int jmlhBunga = 3; //inisialisasi variabel untuk total bunga yang ada sekarang
    int pilih;

    do {
        cout<<"-----Manajemen Toko Bunga-----"<<endl;
        cout<<"1. Tambah Bunga"<<endl;
        cout<<"2. Tampilkan Data Bunga"<<endl;
        cout<<"3. Update Data Bunga"<<endl;
        cout<<"4. Hapus Data Bunga"<<endl;
        cout<<"5. Keluar"<<endl;
        cout<<"Pilih Menu (1-5): "<<endl;
        cin>>pilih;

    switch(pilih){
        case 1:
            tambah_bunga(&arrBunga[jmlhBunga]);
            jmlhBunga++;
            break;
        case 2:
            tampilkan_bunga(arrBunga, jmlhBunga);
            break;
        case 3:
            ganti_bunga(arrBunga, jmlhBunga);
            break;
        case 4:
            hapus_bunga(arrBunga, &jmlhBunga);
            break;
        case 5:
        cout<<"Keluar Dari Program"<<endl;
        break;
        default:
        cout<<"Pilihan Tidak Valid!"<<endl;
    }
    } while (pilih != 5);
    return 0;
}