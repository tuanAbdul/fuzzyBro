#include "fuzzy.h"
#include "mmdn.h"
float y,y2;
float sp1,sp2;

fuzzy pmt[2],psd[2],prod[2],rule[4];

mmdn defuz;
void setup() {
  Serial.begin(9600);
  //setup fungsi keanggotaan input

  //permintaan
  pmt[0].MF=TrapesiumI;
  pmt[0].a=0;
  pmt[0].b=0;
  pmt[0].c=1000;
  pmt[0].d=5000;

  pmt[1].MF=TrapesiumI;
  pmt[1].a=1000;
  pmt[1].b=5000;
  pmt[1].c=5000;
  pmt[1].d=5000;
  
  //persediaan
  psd[0].MF=TrapesiumI;
  psd[0].a=0;
  psd[0].b=0;
  psd[0].c=100;
  psd[0].d=600;

  psd[1].MF=TrapesiumI;
  psd[1].a=100;
  psd[1].b=600;
  psd[1].c=600;
  psd[1].d=600;

  //setup fungsi keanggotaan output
  prod[0].MF=TrapesiumO;
  prod[0].a=0;
  prod[0].b=0;
  prod[0].c=2000;
  prod[0].d=7000;

  prod[1].MF=TrapesiumO;
  prod[1].a=2000;
  prod[1].b=7000;
  prod[1].c=7000;
  prod[1].d=7000;
  
  //setup resolusi integral diskrit
  defuz.res=100;

}

void loop() {
  //nilai masukan bisa diganti dengan sensor
  sp1=4000;
  sp2=300;

  //fuzzyfikasi nilai masukan
  pmt[0].x=sp1;
  pmt[1].x=sp1;
  psd[0].x=sp2;
  psd[1].x=sp2;
  
  //if permintaan TURUN and persediaan BANYAK maka produksi BERKURANG
  rule[0]=prod[0];
  rule[0].yy=min(pmt[0].calc(),pmt[1].calc());
  //if permintaan TURUN and persediaan SEDIKIT maka produksi BERKURANG
  rule[1]=prod[0];
  rule[1].yy=min(pmt[0].calc(),psd[0].calc());
  //if permintaan NAIK and persediaan BANYAK maka produksi BERTAMBAH
  rule[2]=prod[1];
  rule[2].yy=min(pmt[1].calc(),psd[1].calc());
  //if permintaan NAIK and persediaan SEDIKIT maka produksi BERTAMBAH
  rule[3]=prod[1];
  rule[3].yy=min(pmt[1].calc(),psd[0].calc());
  
  
  y=defuz.MoM(rule,sizeof(rule)/sizeof(rule[0]));
  Serial.println("=========");
  Serial.print("y1=");
  Serial.println(y);

}
