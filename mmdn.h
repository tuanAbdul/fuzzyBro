#ifndef __mmdn
#define __mmdn
#include "fuzzy.h"

class mmdn{
  public:
  int x,D;
  float y,y1,y2,y3,xy;
  
  float deFuz(fuzzy MF[],int n){
    y1=0;
    y2=0;
    D=getD(MF,n);
    int i,x=0;
    y=MF[0]._y2;
    MF[0].calc();
    for(x=0;x<1000;x++){
      for(i=0;i<n;i++){
        MF[i].x=x;
        MF[i].calc();
      }      
      for(i=0;i<n;i++){
        if(y<MF[i]._y2){
          y=MF[i]._y2;
        }
      }
      y1=y1+y; 
      y2=y*x+y2;      
    }
    y3=y2/y1;
    return y3;
  }
  float getD(fuzzy mf[],int n){
    int i;
    float y;    
    for(i=0;i<n;i++){
      y=mf[0].d;
      if(y<mf[i].d){
        y=mf[i].d;
      }
    }
    return y;
  }
};

#endif
