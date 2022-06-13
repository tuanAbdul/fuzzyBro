# fuzzyBro
library fungsi keanggotaan fuzzy
# fuzzyBro
program example.ino mengacu pada contoh soal buku karangan Sri Kusuma Dewi. hasil dari perhitungan mikrokontroller dengan perhitungan buku sangat mendekati.
.kekurangan dari mikrokontroller ini adalah kekuatan pemrosesan yang agak lambat, untuk itu disarankan pengunaan fungsi keanggotaan input/output maksimal 
menggunakan angka 3 digit.
sp1 dan sp2 adalah masukan, nama vaiable tersebut bisa diganti apa saja, bisa dari sensor.

jenis fungsi keanggotaan masih berupa triangular dan trapesium
untuk input ada dua opsi yakni TrapesiumI dan TriangularI
untuk output ada dua opsi yakni TrapesiumO dan TriangularO

cara inisialisasi jenis keanggotaan dan representasi bentuk fungsi, misal bentuk trapesium:

fuzzy f;
f.MF=TrapesiumI;
f.a=0;
f.b=0;
f.c=10;
f.d=15;

wassalamualaikum.
semoga bermanfaat
