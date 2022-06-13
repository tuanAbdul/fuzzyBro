# fuzzyBro
library fungsi keanggotaan fuzzy
# fuzzyBro
program example.ino mengacu pada contoh soal buku karangan Sri Kusuma Dewi. hasil dari perhitungan mikrokontroller dengan perhitungan buku sangat mendekati.
.kekurangan dari mikrokontroller (pada umumnya) dibandingkan prosesor x86 dan SoC adalah kekuatan komputasi yang lebih lambat, untuk itu disarankan pengunaan fungsi keanggotaan input/output maksimal menggunakan angka 3 digit atau kurang.
sp1 dan sp2 adalah masukan, nama variable tersebut bisa diganti apa saja, bisa dari sensor atau dari pin ADC dari arduino.

mode operator bisa diganti dengan operator OR (Maks) pada contoh menggunakan operator AND (Min)

jenis fungsi keanggotaan masih terbatas berupa triangular dan trapesium
cara inisialisasi jenis keanggotaan dan representasi bentuk fungsi, misal bentuk trapesium:

fuzzy f;
f.MF=TrapesiumI;
f.a=0;
f.b=0;
f.c=10;
f.d=15;


untuk input ada dua opsi yakni TrapesiumI dan TriangularI
untuk output ada dua opsi yakni TrapesiumO dan TriangularO

metode defuzzifikasi menggunakan komposisi aturan MAMDANI Mean of Maximum (MoM) yaitu dengan cara mengintegralkan dan mencari maksimum dari kombinasi output 
dari aturan-aturan.
secara program cara defuzzifikasi hanya dengan memanggil perintah deFuz(bla...). contoh:

mmdn defuz;
float y;
fuzzy f[4];
f[0]=bla..
f[1]=bla..
f[2]=bla..
f[3]=bla..

y=defuz.deFuz(f,sizeof(f)/sizeof(f[0]));

instruksi "sizeof(f)/sizeof(f[0])" adalah untuk mencari ukuran array objek f. 


wassalam.
semoga bermanfaat
