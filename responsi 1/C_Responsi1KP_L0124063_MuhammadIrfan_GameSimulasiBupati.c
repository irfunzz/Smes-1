#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

//struktur data untuk menyimpan statistik/status kota
typedef struct {
    int anggaran;
    int populasi;
    int kebahagiaan;
    int infrastruktur;
} Kota;

//struktur data untuk menyimpan jenis fasilitas yang akan di bangun
typedef struct {
    char jenisFasilitas[50];
    int biayaPembangunan;
    int dampakMasyarakat;
	int dampakInfrastruktur;
	int dampakPopulasi;
} Fasilitas;

//untuk menghapus/membersihkan layar/terminal (OS windows)
void clear(){
    system("cls");
};

//Deklarasi variabel global untuk kota dan beberapa parameter
Kota kota = {500, 1000, 35, 20};
int persentasePajak = 0;
int aksiCounter = 0;

//fungsi untun menghitung anggaran berdasarkan pajak
void pengelolaanAnggaran() {
	int pendapatanDariPajak = ((persentasePajak * kota.populasi)/100);
	kota.anggaran += pendapatanDariPajak;

    //untuk memastikan anggaran tidak negatif
    if (kota.anggaran < 0) {
        kota.anggaran = 0;
    }
}

//fungsi untuk mengatur seberapa besar pajak yang diterapkan player
int pengaturanPajak(){
	int besarPajak;
    char masukan[10];

    while (1) {
        clear();
        printf("Berapa besar pajak yang kamu inginkan?\n");
        printf("(Ingat semakin besar pajak yang kamu buat, semakin sedih wargamu.)(1-100):");
        fgets(masukan, sizeof(masukan), stdin);

        //untuk memastikan input yang dimasukkan player valid
        if (sscanf(masukan, "%d", &besarPajak) != 1 || besarPajak < 0 || besarPajak > 100) {
            printf("Input tidak valid. Harap masukkan angka antara 0 dan 100.\n");
            continue;
        }
        
        break;
    }
    
	return besarPajak;
};

//fungsi utama penetapan pajak dan dampak besar pajak terhadap game
void pajak(){
	while (1){
		persentasePajak = pengaturanPajak();

		if (persentasePajak == -1 || persentasePajak < 1 || persentasePajak > 100) {
			printf("Nilai pajak tidak valid. Harus antara 1-100.\n");
		}

		int kebahagiaan = (persentasePajak * kota.populasi);
		int infrastruktur = (persentasePajak * kota.populasi);

		if (persentasePajak >= 80 && persentasePajak <= 100) {
			kota.kebahagiaan -= kebahagiaan/2000;
			kota.infrastruktur += infrastruktur/2000;
            kurangiPopulasi(&kota, persentasePajak * kota.populasi / 1000, 10);
		} else if (persentasePajak >= 60 && persentasePajak < 80) {
			kota.kebahagiaan -= kebahagiaan/3000;
			kota.infrastruktur += infrastruktur/3000;
            kurangiPopulasi(&kota, persentasePajak * kota.populasi / 1200, 7);
		} else if (persentasePajak >= 40 && persentasePajak < 60) {
			kota.kebahagiaan -= kebahagiaan/4000;
			kota.infrastruktur += infrastruktur/4000;
            kurangiPopulasi(&kota, persentasePajak * kota.populasi / 1400, 5);
		} else if (persentasePajak >= 20 && persentasePajak < 40) {
			kota.kebahagiaan -= kebahagiaan/5000;
			kota.infrastruktur += infrastruktur/5000;
		} else if (persentasePajak >= 10 && persentasePajak < 20) {
			kota.kebahagiaan -= kebahagiaan/5500;
			kota.infrastruktur += infrastruktur/5500;
		} else if (persentasePajak >= 1 && persentasePajak < 10) {
			kota.kebahagiaan -= kebahagiaan/6000;
			kota.infrastruktur += infrastruktur/6000;
		}
		
		break;
	}
	printf("Kamu menetapkan pajak sebesar %d%%\n", persentasePajak);
	printf("kebahagiaan masyarakat sekarang adalah %d dan infrastruktur %d\n", kota.kebahagiaan, kota.infrastruktur);
	pengelolaanAnggaran();
}

//daftar fasilitas yang bisa dibangun
Fasilitas fasilitas[5] = {
    {"Sekolah", 100, 40, 45,35},
    {"Rumah Sakit", 90, 37, 44, 74},
    {"Pasar", 24, 12, 23, 12},
    {"GrandMall", 78, 30, 40, 26},
    {"City Club", 120, 55, 54, 92}
};

// Fungsi untuk memilih fasilitas yang akan dibangun
int pilihFasilitas(){
	int pilihan;
	printf("Apa yang ingin kamu bangun(1-5):");
	if (scanf("%d", &pilihan) != 1){
		while (getchar() != '\n');
	
	};

	return pilihan - 1;
}

//fungsi untuk proses pembangunan fasilitas
int pembangunanInfrastruktur() {
	while (1) {
		clear();
		printf("=======Apa yang ingin anda bangun=======\n");
		for (int i = 0; i < 5; i++) {
			printf("%d. %s\t%dmiliar\t+%d kebahagiaan\t+%d kemajuan\t+%d populasi\n",
			i+1, 
			fasilitas[i].jenisFasilitas, 
			fasilitas[i].biayaPembangunan, 
			fasilitas[i].dampakMasyarakat, 
			fasilitas[i].dampakInfrastruktur,
			fasilitas[i].dampakPopulasi);
		}
		
		int pilihan = pilihFasilitas();
		if (pilihan >= 0 && pilihan < 5) {
			if (kota.anggaran >= fasilitas[pilihan].biayaPembangunan) {

				kota.anggaran -= fasilitas[pilihan].biayaPembangunan;
				kota.kebahagiaan += fasilitas[pilihan].dampakMasyarakat;
				kota.infrastruktur += fasilitas[pilihan].dampakInfrastruktur;
				kota.populasi += fasilitas[pilihan].dampakPopulasi;

				printf("Anda Membangun %s dengan biaya %d miliar, anda memperoleh %d kebahagiaan, %d kemajuan serta %d penambahan populasi\n", 
				fasilitas[pilihan].jenisFasilitas, 
				fasilitas[pilihan].biayaPembangunan, 
				fasilitas[pilihan].dampakMasyarakat, 
				fasilitas[pilihan].dampakInfrastruktur,
				fasilitas[pilihan].dampakPopulasi);

			} else {
				printf("Anggaran tidak cukup untuk membangun %s\n", fasilitas[pilihan].jenisFasilitas);
				continue;
			}
		} else {
			printf("Pilihan tidak valid\n");
			continue;
		}
		break;
	}
}

//fungsi penambahan populasi sesuai keinginan player
void penambahanPopulasi(Kota *kota) {
	int penambahan;
	printf("Berapa jumlah populasi yang ingin ditambah?:");
	scanf(" %d", &penambahan);
	kota->populasi += penambahan;
	printf("Populasi sekarang: %d\n", kota->populasi);
}

//Fungsi penambahan populasi acak dari 1 - 100
void penambahanPopulasiAcak(Kota *kota) {
	int penambahan = rand() % 100 + 1;
	printf("Populasi bertambah %d\n", penambahan);
	kota->populasi += penambahan;
	printf("Populasi sekarang %d\n", kota->populasi);
}

//Fungsi rekursi untuk mengurangi populasi secara berkala
void kurangiPopulasi(Kota *kota, int jumlah, int langkah) {
    if (langkah == 0 || kota->populasi <= 0) {
        if (kota->populasi < 0) kota->populasi = 0;
        return;
    }
    kota->populasi -= jumlah;
    if (kota->populasi < 0) kota->populasi = 0;
    kurangiPopulasi(kota, jumlah, langkah - 1);
}

//fungsi pilihan penambahan yang ingin player lakukan
void pilihanPenambahan() {
	while (1){
		clear();
		int pilihan;
		printf("Pilih cara penambahan populasi:\n");
		printf("1. Tambah sesuai keinginan\n");
		printf("2. Tambah secara acak\n(1-2):");
		if (scanf(" %d", &pilihan) != 1){
			while (getchar() != '\n');
            continue;
		};

		if (pilihan == 1) {
			penambahanPopulasi(&kota);
		} else if (pilihan == 2) {
			penambahanPopulasiAcak(&kota);
		} else {
			continue;
		}
		break;
	}
}

//Fungsi event bencana gempaBumi
void gempaBumi(){
	int yangKamuPilih;
	do {
		clear();
        printf("Kota Anda diguncang oleh gempa bumi yang sangat dahsyat, seolah-olah bumi mengerang dalam kesakitan. Suara gemuruh menggema, merobek kesunyian malam, saat bangunan-bangunan yang sebelumnya kokoh mulai runtuh satu per satu. Jalanan bergetar dan retak, memisahkan teman dari keluarganya. Warga berlarian dengan wajah penuh ketakutan, mata mereka dipenuhi air mata dan kepanikan. Di tengah kekacauan, teriakan minta tolong terdengar, menggaung di antara puing-puing yang berserakan. Ini adalah malam yang takkan pernah terlupakan, saat segala sesuatu yang dicintai seolah lenyap dalam sekejap mata.\n");
        printf("Kini saatnya kamu menentukan arah nasib kota ini. Apa yang akan kamu pilih?\n");
        printf("1. Membangun kembali kota dengan menggunakan teknologi canggih dan material tahan gempa.\n");
        printf("2. Mengalihkan dana bantuan ke program hiburan dan rekreasi untuk meningkatkan kebahagiaan warga.\n");
        printf("3. Mendirikan kamp pengungsi sementara dan menunda pembangunan infrastruktur.\n");
        printf("4. Memfokuskan semua sumber daya untuk membangun infrastruktur dasar dengan cepat, tanpa mempertimbangkan kebutuhan lainnya.\n");
        printf("(1-4):");
        
        if (scanf("%d", &yangKamuPilih) != 1) {
            while (getchar() != '\n');
            printf("Input tidak valid, silakan masukkan angka 1-4.\n");
            continue;
        }

        if (yangKamuPilih < 1 || yangKamuPilih > 4) {
            printf("Silakan masukkan pilihan yang valid.\n");
            continue;
        }

        switch (yangKamuPilih) {
            case 1:
                kota.anggaran -= 289;
                kota.infrastruktur += 80;
                kota.kebahagiaan += 78;
                printf("Kamu menghabiskan 289 miliar untuk membangun kembali kota.\n");
                printf("Kebahagiaan dan infrastruktur meningkat +78 dan +80.\n");
                break;
            case 2:
                kota.anggaran -= 120;
                kota.infrastruktur -= 120;
                kota.kebahagiaan += 120;
                kota.populasi -= kota.populasi / 30;
                if (kota.populasi < 0) kota.populasi = 0; // Prevent negative population
                printf("Kamu menghabiskan 120 miliar untuk menghibur wargamu.\n");
                printf("Kebahagiaan meningkat +120, tetapi infrastruktur menurun -120.\n");
                printf("Populasi berkurang 30%%.\n");
                break;
            case 3:
                kota.kebahagiaan -= 20;
                kota.infrastruktur -= kota.infrastruktur / 20;
                kota.anggaran -= 98;
                printf("Kamu menghabiskan 98 miliar.\n");
                printf("Kota mengalami kerusakan -20%% dan kebahagiaan berkurang -20.\n");
                break;
            case 4:
                kota.anggaran -= 321;
                kota.infrastruktur += 150;
                kota.kebahagiaan -= 70;
                printf("Kamu menghabiskan 321 miliar.\n");
                printf("Infrastruktur meningkat +150, tetapi kebahagiaan menurun -70.\n");
                break;
        }
        break;
    } while (1);
}

//fungsi event bencana banjir
void banjir(){
    int pilihan;
    do {
		clear();
        printf("Kota Anda dilanda banjir besar akibat hujan deras yang berkepanjangan. Air menggenangi jalan-jalan, merendam bangunan dan memaksa warga untuk dievakuasi.\n");
        printf("Kamu harus segera mengambil tindakan untuk mengatasi dampak banjir ini. Apa yang akan kamu lakukan?\n");
        printf("1. Membangun kanal-kanal dan sistem drainase untuk mencegah banjir di masa depan.\n");
        printf("2. Mengalihkan dana bantuan untuk peralatan evakuasi dan makanan darurat.\n");
        printf("3. Mengabaikan banjir dan mengandalkan evakuasi sementara.\n");
        printf("(1-3):");

        if (scanf("%d", &pilihan) != 1) {
            while (getchar() != '\n');
            printf("Input tidak valid, silakan masukkan angka 1-3.\n");
            continue;
        }

        if (pilihan < 1 || pilihan > 3) {
            printf("Silakan masukkan pilihan yang valid.\n");
            continue;
        }

        switch (pilihan) {
            case 1:
                kota.anggaran -= 200;
                kota.infrastruktur += 60;
                kota.kebahagiaan += 30;
                printf("Kamu menghabiskan 200 miliar untuk membangun kanal dan drainase.\n");
                printf("Infrastruktur meningkat +60 dan kebahagiaan meningkat +30.\n");
                break;
            case 2:
                kota.anggaran -= 150;
                kota.kebahagiaan += 50;
                printf("Kamu menghabiskan 150 miliar untuk peralatan evakuasi dan makanan darurat.\n");
                printf("Kebahagiaan warga meningkat +50.\n");
                break;
            case 3:
                kota.kebahagiaan -= 30;
                printf("Kamu mengabaikan banjir dan mengandalkan evakuasi sementara.\n");
                printf("Kebahagiaan menurun -30.\n");
                break;
        }
        break;
    } while (1);
}

//Fungsi event bencana kebakaranHutan
void kebakaranHutan(){
    int pilihan;
    do {
		clear();
        printf("Kota Anda mengalami kebakaran hutan yang besar dan merembet ke pemukiman warga. Asap tebal menyelimuti kota, membuat udara semakin berbahaya untuk dihirup.\n");
        printf("Bagaimana cara Anda menanggapi situasi ini?\n");
        printf("1. Mengirim bantuan pemadam kebakaran dan membangun sekat bakar.\n");
        printf("2. Memberikan dana untuk membantu warga yang terkena dampak langsung.\n");
        printf("3. Menggunakan dana untuk pembangunan rumah sakit darurat untuk merawat korban asap.\n");
        printf("(1-3):");

        if (scanf("%d", &pilihan) != 1) {
            while (getchar() != '\n');
            printf("Input tidak valid, silakan masukkan angka 1-3.\n");
            continue;
        }

        if (pilihan < 1 || pilihan > 3) {
            printf("Silakan masukkan pilihan yang valid.\n");
            continue;
        }

        switch (pilihan) {
            case 1:
                kota.anggaran -= 180;
                kota.kebahagiaan += 40;
                printf("Kamu mengirim bantuan pemadam kebakaran dan membangun sekat bakar.\n");
                printf("Kebahagiaan meningkat +40.\n");
                break;
            case 2:
                kota.anggaran -= 130;
                kota.kebahagiaan += 50;
                printf("Kamu menghabiskan 130 miliar untuk membantu warga terdampak langsung.\n");
                printf("Kebahagiaan meningkat +50.\n");
                break;
            case 3:
                kota.anggaran -= 160;
                kota.kebahagiaan += 60;
                printf("Kamu membangun rumah sakit darurat untuk merawat korban asap.\n");
                printf("kebahagiaan kota meningkat +60.\n");
                break;
        }
        break;
    } while (1);
}

//fungsi event investasi masuk
void investasiMasuk() {
    int yangKamuPilih;
    do {
        clear();
        printf("Kabar mengejutkan datang! Seorang investor besar dari ibu kota tertarik untuk menanamkan modal di Kota Ketapang!\n");
		printf("Ini adalah kesempatan yang sangat langka, dan bisa mengubah masa depan kotamu selamanya.\n");
		printf("Bagaimana kamu akan memanfaatkan investasi besar ini demi kemajuan Kota Ketapang?\n");
        printf("1. Mengembangkan pusat bisnis dan perkantoran.\n");
        printf("2. Membangun perumahan baru untuk menarik penduduk.\n");
        printf("3. Meningkatkan fasilitas publik dan taman kota.\n");
        printf("4. Menggunakan investasi untuk pendidikan dan pelatihan tenaga kerja.\n");
        printf("(1-4): ");
        
        if (scanf("%d", &yangKamuPilih) != 1) {
            while (getchar() != '\n');
            printf("Input tidak valid, silakan masukkan angka 1-4.\n");
            continue;
        }

        if (yangKamuPilih < 1 || yangKamuPilih > 4) {
            printf("Silakan masukkan pilihan yang valid.\n");
            continue;
        }

        switch (yangKamuPilih) {
            case 1:
                kota.anggaran += 200;
                kota.infrastruktur += 100;
                printf("Pusat bisnis dikembangkan.\n");
                printf("Anggaran bertambah 200, infrastruktur meningkat +100.\n");
                break;
            case 2:
                kota.anggaran += 150;
                kota.populasi += kota.populasi / 10;
                printf("Perumahan baru dibangun.\n");
                printf("Anggaran bertambah 150, populasi meningkat 10%%.\n");
                break;
            case 3:
                kota.anggaran += 100;
                kota.kebahagiaan += 50;
                printf("Fasilitas publik ditingkatkan.\n");
                printf("Anggaran bertambah 100, kebahagiaan meningkat +50.\n");
                break;
            case 4:
                kota.anggaran += 120;
                kota.kebahagiaan += 30;
                kota.infrastruktur += 20;
                printf("Investasi untuk pendidikan.\n");
                printf("Anggaran bertambah 120, kebahagiaan meningkat +30, infrastruktur meningkat +20.\n");
                break;
        }
        break;
    } while (1);
}

//fungsi event kerjasama
void kerjasamaAntarKota() {
    int yangKamuPilih;
    do {
        clear();
        printf("Kota tetangga telah mengulurkan tangan mereka, menawarkan kerjasama strategis untuk meningkatkan perekonomian dan kesejahteraan bersama!\n");
		printf("Ini adalah peluang emas yang bisa mengubah nasib kedua kota. Bagaimana kamu akan memanfaatkan kerjasama ini untuk menciptakan masa depan yang lebih baik?\n");
        printf("1. Fokus pada pengembangan ekonomi.\n");
        printf("2. Meningkatkan jaringan transportasi antar-kota.\n");
        printf("3. Berkolaborasi dalam proyek sosial untuk meningkatkan kebahagiaan warga.\n");
        printf("4. Menyediakan fasilitas pendidikan bersama untuk meningkatkan SDM.\n");
        printf("(1-4): ");
        
        if (scanf("%d", &yangKamuPilih) != 1) {
            while (getchar() != '\n');
            printf("Input tidak valid, silakan masukkan angka 1-4.\n");
            continue;
        }

        if (yangKamuPilih < 1 || yangKamuPilih > 4) {
            printf("Silakan masukkan pilihan yang valid.\n");
            continue;
        }

        switch (yangKamuPilih) {
            case 1:
                kota.anggaran += 100;
                printf("Ekonomi kota meningkat.\n");
                printf("Anggaran bertambah +100.\n");
                break;
            case 2:
                kota.infrastruktur += 80;
                printf("Jaringan transportasi ditingkatkan.\n");
                printf("Infrastruktur meningkat +80.\n");
                break;
            case 3:
                kota.kebahagiaan += 60;
                printf("Proyek sosial meningkatkan kebahagiaan warga.\n");
                printf("Kebahagiaan meningkat +60.\n");
                break;
            case 4:
                kota.kebahagiaan += 30;
                kota.infrastruktur += 40;
                printf("Fasilitas pendidikan bersama dibangun.\n");
                printf("Kebahagiaan meningkat +30, infrastruktur meningkat +40.\n");
                break;
        }
        break;
    } while (1);
}

//fungsi mengacak event apa yang akan terjadi (bisa saja tidak terjadi event)
void randomEvent() {
    int random = rand() % 100 + 1;
    if (random >= 90 && random <= 100) {
        gempaBumi();
    } else if (random >= 75 && random < 90) {
        banjir();
    } else if (random >= 60 && random < 75) {
        kebakaranHutan();
    } else if (random >= 50 && random < 60) {
		investasiMasuk();
	} else if (random >= 40 && random < 50) {
		kerjasamaAntarKota();
	}
}

//fungsi untuk pemanggilan/pengacakan jika player telah melakukan aksi 3x
void cekPanggilRandomEvent(){
	if (aksiCounter >= 3){
		randomEvent();
		aksiCounter = 0;
	}
}

//fungsi untuk menampilkan status kota
void statusKota(Kota *kota){
	clear();
	printf("Anggaran: %d miliar\n", kota->anggaran);
	printf("Populasi: %d manusia\n", kota->populasi);
	printf("Kebahagiaan: %d\n", kota->kebahagiaan);
	printf("Infrastruktur: %d\n", kota->infrastruktur);
}

//fungsi untuk menentukan skor kepemimpinan player selama bermain game
void lihatSkorKepemimpinan(){
	clear();
    int skor = (kota.kebahagiaan * 2 + kota.infrastruktur * 2 + kota.anggaran / 10 + kota.populasi / 100) / 6;

    printf("\n===== Skor Kepemimpinan =====\n");
    printf("Skor Kepemimpinan Anda: %d\n", skor);

    if (skor >= 80) {
        printf("Luar biasa! Anda adalah pemimpin yang dicintai dan dihormati. Kota Anda berkembang dengan pesat,\n"
               "dan warganya bahagia di bawah kepemimpinan Anda. Kota Anda mendekati era keemasan!\n");
    } else if (skor >= 60) {
        printf("Anda adalah pemimpin yang kuat dan kompeten. Meski ada tantangan, kota ini terus maju dan \n"
               "warganya merasa sejahtera. Dengan sedikit usaha lebih, kota ini bisa lebih makmur.\n");
    } else if (skor >= 40) {
        printf("Kepemimpinan Anda mendapat kritik, tetapi kota tetap berjalan. Warga memiliki harapan, \n"
               "meskipun terkadang merasa ragu. Perbaikan di beberapa area dapat meningkatkan kepercayaan masyarakat pada Anda.\n");
    } else if (skor >= 20) {
        printf("Kota Anda menghadapi banyak masalah dan warganya tidak puas dengan kepemimpinan Anda.\n"
               "Jika keadaan tidak segera diperbaiki, kota ini bisa jatuh ke dalam kehancuran.\n");
    } else {
        printf("Kota berada di ambang kehancuran. Warga mulai kehilangan harapan, dan beberapa bahkan menyerukan\n"
               "pergantian pemimpin. Saatnya untuk mengambil tindakan drastis, atau Anda bisa kehilangan segalanya.\n");
    }

    printf("================================\n\n");
}

//fungsi untuk menjalankan game simulasi(menu utama game)
void mainGameBupati(){
	char main, lanjutMain = 'y', nama[50];
    int kerja;

	while (1){
		clear();
		printf("==========Selamat Datang di Kota Ketapang============\n");
		printf("==========Apakah anda ingin menjadi Bupati?==========\n");
		printf("('Y' or 'N)");
		if (scanf("%c", &main) != 1){
			while(getchar() != '\n');
		};

		getchar();

		if (toupper(main) == 'Y') {
            printf("=====Masukkan Nama Anda=====\n");
            scanf("%[^\n]", nama);
            while(getchar() != '\n');
        }

		if (toupper(main) == 'Y') {
			do {
				while (1){
					clear();
					printf("======Selamat Datang di Kota Ketapang, Bupati %s======\n",  nama);

					printf("Apa yang ingin anda lakukan\n");
					printf("1. Membangun fasilitas umum\n");
					printf("2. Menambah populasi\n");
					printf("3. Mengatur Pajak\n");
					printf("4. Melihat status Kota\n");
					printf("5. Melihat skor kepemimpinan\n");
					printf("6. keluar\n");
					printf("Pilih (1-6):");
					if (scanf("%d", &kerja) != 1){
						while(getchar() != '\n');
					};
					switch (kerja)
					{
					case 1:
						pembangunanInfrastruktur(); //membangun fasilitan
						aksiCounter++;
						cekPanggilRandomEvent();
						break;
					case 2:
						pilihanPenambahan(); //menambah populasi
						aksiCounter++;
						cekPanggilRandomEvent();
						break;
					case 3:
						pajak(); //mengatur pajak
						aksiCounter++;
						cekPanggilRandomEvent();
						break;
					case 4:
						statusKota(&kota); //melihat status kota
						break;
					case 5:
						lihatSkorKepemimpinan(); // melihat skor
						break;	
                    case 6:
                        return; //keluar dari game
					default:
						continue;
					}

					printf("Apakah anda ingin lanjut main?(Y/N):");
					getchar();
					if (scanf("%c", &lanjutMain) != 1){
						while (getchar() != '\n');
					}
				}
			} while (toupper(lanjutMain) == 'Y');
			
			if (toupper(lanjutMain) == 'N'){
                printf("Terima kasih telah bermain!\n");
				break;
			}
		} else if (toupper(main) == 'N'){
            clear();
            printf("Kamu cupu!!!!!\n");
			break;
		}
	}
}

//fungsi main untuk memanggil fungsi yang dapat menjalankan game 
int main () {
	srand(time(NULL)); //untuk memastikan waktunya benar benar acak setiap dijalankan
	mainGameBupati(); // memanggil menu utama

	return 0;
}
