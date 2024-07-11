#include <stdio.h>

char nama[50], alamat[200];
char *kategori[50];
int beratPakaian, opsiPengambilan, dataWarning, opsiKategori, konfirmasi, nomorTransaksi;
long long int teleponNumber;

void data()
{
    do
    {
    printf("\nMasukkan Nama Customer : ");
    fflush(stdin);
    gets(nama);
    printf("Masukkan Nomor Telepon : ");
    scanf("%lld", &teleponNumber);
    do
    {

        printf("Masukkan Berat Pakaian : ");
        scanf("%d", &beratPakaian);

    }
    while (beratPakaian > 10 || beratPakaian <= 0);
    printf("\n================================");
    printf("\nCustomer : %s", nama);
    printf("\nNomor Telepon : 0%lld", teleponNumber);
    printf("\nBerat Pakaian : %dKG", beratPakaian);
    printf("\n================================");

    printf ("\n\nApakah Data Sudah Benar ? \n1. Benar\n2. Salah\n");

    printf("\nInput : ");
    scanf("%d", &dataWarning);
    }
    while (dataWarning != 1);
}

void takeOrDelivery()
{
    printf("\n\nSilahkan Pilih Metode Pengambilan Laundry: \n1. Pick Up\n2. Delivery\n");
    printf("\nInput : ");
    scanf("%d", &opsiPengambilan);
    switch (opsiPengambilan)
    {
    case 1:
        printf("\n[Metode Pengambilan Customer : Pick Up]");
        break;
    case 2:
        printf("\n[Metode Pengambilan Customer : Delivery]\n");
        printf("\nMasukan Alamat Customer : ");
        fflush(stdin);
        gets(alamat);
        break;
    default :
        return takeOrDelivery();
        break;
    }
}

int kategoriLaundry()
{
    printf("\n\nSilahkan Pilih Kategori Laundry: \n1. CKL atau Cuci Kering Lipat\n2. CKG atau Cuci Kering Gantung\n");
    printf("\nInput : ");
    scanf("%d", &opsiKategori);
    switch (opsiKategori)
    {
    case 1:
        printf("\n[Kategori Customer: CKL]\n");
        *kategori = "Cuci Kering Lipat";
        break;
    case 2:
        printf("\n[Kategori Customer: CKG]\n");
        *kategori = "Cuci Kering Gantung";
        break;
    default:
        return kategoriLaundry();
        break;
    }

}

int userConfirm(int nomorTransaksi)
{
    printf("\n\nKONFIRMASI INPUT!!!\n\n");
    printf("Yakin Order ?\n1. Ya");
    printf("\n2. Tidak  [Anda akan di arahkan ke halaman paling awal]\n");
    printf("\nInput : ");
    scanf("%d", &konfirmasi);
    switch (konfirmasi)
    {
    case 1:
        printf("\n\nORDERAN SUDAH  TERKONFIRMASI !!!");
        nomorTransaksi++;
        printf("\n\n\n");
        printf("====================================================\n");
        printf("Nama Customer : %s", nama);
        printf("\nNomor Telepon : 0%lld", teleponNumber);
        if(opsiPengambilan == 1)
        {
            printf("\nJenis Pengambilan Pakaian : Pick Up");
        }
        else if(opsiPengambilan == 2)
        {
            printf("\nJenis Pengambilan Pakaian : Delivery\nAlamat Pengambilan : %s", alamat);
        }
        printf("\nKategori Laundry : %s", *kategori);
        printf("\nNomor Transaksi : #%d", nomorTransaksi);
        printf("\n====================================================\n\n\n");
        break;
    default:
        printf("\n\nSILAHKAN INPUT ULANG !!!\n\n");
        break;
    }
    return 0;
}

int main()
{
    int bukaKasir;

    printf("==========================");
    printf("\nWELCOME TO OUR LAUNDRY !!!");
    printf("\n==========================\n\n");
    printf("Apakah Ada Customer Yang Datang ?\n");
        printf("1. Ya\n");
        printf("2. Tidak\n");
        printf("\nInput : ");
        scanf("%d", &bukaKasir);
            switch (bukaKasir){
                case 1:
                    data();
                    kategoriLaundry();
                    takeOrDelivery();
                    userConfirm(nomorTransaksi);
                    nomorTransaksi++;
                    return main();
                    break;
                default:
                    printf("\nLAUNDRY CLOSED !!!\n");
                    break;
    }

    return 0;
}
