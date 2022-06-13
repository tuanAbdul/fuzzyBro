#ifndef __fuzzy
#define __fuzzy
#define TriangleI 0
#define TrapesiumI 1
#define TriangleO 2
#define TrapesiumO 3

class fuzzy{
  public:
	  int cc;
    float x,a,b,c,d,yy,_y2;
	  int MF;

    float calc(){
      switch(MF){
        case TriangleI:return TriMFI(x,a,b,c);
          break;
        case TrapesiumI:return TrapMFI(x, a, b, c, d);
          break;
        case TriangleO:return TriMFO(x,a,b,c,yy);
          break;
        case TrapesiumO:_y2=TrapMFO(x,a,b,c,d,yy);
          return TrapMFO(x,a,b,c,d,yy);
          break;
      }
    }
	fuzzy(){
		cc++;
	}
	//fungsi keanggotaan input bentuk segitiga/triangle

    float TriMFI(float x,float a,float b,float c){
      //return TrapMFO(x,a,b,c,d,1);
      return TrapMFO(x,a,b,b,c,1);
    }
    //fungsi keanggotaan input bentuk trapesium
    float TrapMFI(float x,float a,float b,float c,float d){
        return TrapMFO(x,a,b,c,d,1);
    }
    //fungsi keanggotaan output bentuk trapesium
    float TrapMFO(float x,float a,float b,float c,float d,float y=1){
        
        if(x<=a||x>=d){
          return 0;
        }else if(x >=a && x<=(b-y2(y,a,b))){
          return y*((x-a)/((b-y2(y,a,b))-a));
        }else if(x>=(b-y2(y,a,b))&&x<=(c+y2(y,c,d))){
          return y;
        }else if(x<=d && x>=(c+y2(y,c,d))){
          return -y * ((x - (c + y2(y, c, d))) / (d - (c + y2(y, c, d)))) + y;
        }
      }
      //fungsi keanggotaan output bentuk segitiga/triangle
      float TriMFO(float x,float a,float b,float c,float y){
        d=c;
        return TrapMFO(x,a,b,b,c,y);
      }
      float y2(float y,float c,float d){
        return ((d-c)*(1-y));
      }
      float maxx(float a,float b){
        if(a>b){
          return a;
        }else{
          return b;
        }
        
      }
    
  };
  
#endif
