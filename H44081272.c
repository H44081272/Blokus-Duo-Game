#include <stdio.h>
#include <stdbool.h>


void compute(int pnumber,int angleamount,int square,int total,int blokusamount);

bool blokussidecheck=false;
bool anglecheck=false;
bool anglenullcheck=false;
bool anglesidecheck=false;
bool angleredsidecheck=false;
bool blokusnullcheck=false;
bool xycheck=false;
bool cannotfindangle=false;
bool reback=true;
bool hasfinal=false;
bool attackterritory=false;



int xboundary=0;
int yboundary=0;
int z=0;
/*z暫放*/
int temp=0;
int i=0;
int a=0;
int x=0;
int y=0;
int j=0;
int k=0;
int e=0;
int m=0;
int tempangles=0;
int angles=0;
int rivalangles=-1;
int temppnumber=0;
int tempblokusamount=0;
int blokusarray[10];
int turnblokusarray[10];
int finalblokusarray[10];
int index=0;
char leftpattern[21];
char temporary[45];
char blokus[14][14];
char color;
char rival;

/*所有適合的角*/
int allanglearray[10000];
/*角數*/
int count=0;

        /*總格子*/
        int number[21][10]={/*01*/{0,0,0,0,0,0,0,0,0,0},
                            /*02*/{0,0,0,1,0,0,0,0,0,0},
                            /*03*/{0,0,0,1,1,1,0,0,0,0},
                            /*04*/{0,0,0,1,0,2,0,0,0,0},
                            /*05*/{0,0,0,1,1,0,1,1,0,0},
                            /*06*/{0,0,-1,0,-1,1,-1,2,0,0},
                            /*07*/{0,0,0,1,0,2,1,1,0,0},
                            /*08*/{0,0,0,1,1,1,1,2,0,0},
                            /*09*/{0,0,0,1,0,2,0,3,0,0},
                            /*10*/{0,0,0,1,0,2,1,0,1,1},
                            /*11*/{0,0,0,1,1,1,2,1,2,0},
                            /*12*/{0,0,0,1,0,2,1,1,2,1},
                            /*13*/{0,0,1,0,2,0,2,1,2,2},
                            /*14*/{0,0,0,1,-1,1,-1,2,-2,2},
                            /*15*/{0,0,1,0,1,1,1,2,2,2},
                            /*16*/{0,0,1,0,1,1,1,2,2,1},
                            /*17*/{0,0,1,-1,1,0,1,1,2,0},
                            /*18*/{0,0,0,1,0,2,0,3,1,0},
                            /*19*/{0,0,0,1,0,2,1,2,1,3},
                            /*20*/{0,0,0,1,0,2,0,3,1,1},
                            /*21*/{0,0,0,1,0,2,0,3,0,4}};

     /*角*/
     int angle[21][16]={/*01*/{-1,-1,1,-1,-1,1,1,1,0,0,0,0,0,0,0,0},
                        /*02*/{-1,-1,1,-1,-1,2,1,2,0,0,0,0,0,0,0,0},
                        /*03*/{-1,-1,1,-1,-1,2,2,0,2,2,0,0,0,0,0,0},
                        /*04*/{-1,-1,1,-1,-1,3,1,3,0,0,0,0,0,0,0,0},
                        /*05*/{-1,-1,-1,2,2,-1,2,2,0,0,0,0,0,0,0,0},
                        /*06*/{1,-1,1,1,-2,-1,-2,3,0,3,0,0,0,0,0,0},
                        /*07*/{-1,-1,1,-1,-1,3,1,3,2,0,2,2,0,0,0,0},
                        /*08*/{-1,-1,-1,2,1,-1,2,0,2,3,0,3,0,0,0,0},
                        /*09*/{-1,-1,1,-1,-1,4,1,4,0,0,0,0,0,0,0,0},
                        /*10*/{-1,-1,-1,3,2,-1,2,2,1,3,0,0,0,0,0,0},
                        /*11*/{-1,-1,-1,2,3,-1,3,2,1,-1,0,0,0,0,0,0},
                        /*12*/{-1,-1,1,-1,-1,3,1,3,3,0,3,2,0,0,0,0},
                        /*13*/{-1,-1,-1,1,3,-1,3,3,1,3,0,0,0,0,0,0},
                        /*14*/{-1,-1,1,-1,1,2,-2,0,0,3,-3,3,-3,1,0,0},
                        /*15*/{-1,-1,-1,1,2,-1,0,3,3,1,3,3,0,0,0,0},
                        /*16*/{-1,-1,-1,1,2,-1,0,3,2,3,3,0,3,2,0,0},
                        /*17*/{-1,-1,-1,1,0,-2,2,-2,3,-1,3,1,2,2,0,2},
                        /*18*/{2,1,1,4,-1,4,2,-1,-1,-1,0,0,0,0,0,0},
                        /*19*/{-1,-1,1,-1,-1,3,2,1,2,4,0,4,0,0,0,0},
                        /*20*/{-1,-1,1,-1,-1,4,1,4,2,0,2,2,0,0,0,0},
                        /*21*/{-1,-1,1,-1,-1,5,1,5,0,0,0,0,0,0,0,0}};
   /*可變換格子數*/
   int changes[21][12]={/*01*/{0,0,0,0,0,0,0,0,0,0,0,0},
                        /*02*/{0,0,0,0,0,0,0,0,0,0,0,0},
                        /*03*/{0,0,0,-1,-1,0,1,1,0,0,0,0},
                        /*04*/{0,0,0,0,0,0,0,0,0,0,0,0},
                        /*05*/{0,0,0,-1,-1,1,0,-1,1,1,0,0},
                        /*06*/{0,0,1,0,0,-2,-1,2,0,0,0,0},
                        /*07*/{0,0,0,-2,-1,1,1,1,0,0,0,0},
                        /*08*/{0,0,0,-1,-1,0,0,-1,1,2,0,0},
                        /*09*/{0,0,0,0,0,0,0,0,0,0,0,0},
                        /*10*/{0,0,0,-2,-1,2,0,-1,1,1,0,0},
                        /*11*/{0,0,0,-1,-2,0,0,1,2,0,0,0},
                        /*12*/{0,0,0,-2,-2,1,2,1,0,0,0,0},
                        /*13*/{0,0,-2,0,0,-2,2,2,0,0,0,0},
                        /*14*/{0,0,0,-1,1,0,0,-1,1,0,-2,2},
                        /*15*/{0,0,-1,0,0,-2,-1,0,2,2,0,0},
                        /*16*/{0,0,-1,0,0,-2,-1,1,2,1,0,0},
                        /*17*/{0,0,-1,1,0,-2,-1,1,2,0,0,0},
                        /*18*/{0,0,0,-3,-1,3,1,0,0,0,0,0},
                        /*19*/{0,0,0,-2,-1,0,0,-1,1,3,0,0},
                        /*20*/{0,0,0,-3,-1,2,1,1,0,0,0,0},
                        /*21*/{0,0,0,0,0,0,0,0,0,0,0,0}};





int  main(int argc,char *argv[]){


    /*我的顏色*/
    color=argv[1][0];//argv[1][0]

    /*對方顏色*/
    if(color=='R'){
      rival='B';
    }else if(color=='B'){
      rival='R';
    }

    /*方塊順序*/
    int pattern[21]={18,16,14,13,21,10,19,15,11,20,12,17,8,7,6,9,5,4,3,2,1};


   /*輸入blokusboard*/
    FILE *fpr;
    fpr=fopen(argv[2],"r");
    char s;

    while(j<14){
       s=fgetc(fpr);
      if(s!='\n'&&s!=','){
        blokus[j][k]=s;
        k++;
        if(k==14){
          j++;
          k=0;
        }

      }
    }
    fclose(fpr);

    /*輸入leftpattern*/
    FILE*fpw2;
    fpw2=fopen(argv[3],"r");
    i=0;
    j=0;
   while (!feof(fpw2)){
    fgets(temporary,45,fpw2);
    }
    while(i<21){
    if(temporary[j]=='0'||temporary[j]=='1'){
    leftpattern[i]=temporary[j];
    i++;
    j++;
    }else{
      j++;
    }
   }

     /*領地在上*/
     if(blokus[4][4]==color){
        for(xboundary = 0; xboundary < 7; xboundary++){
          for(yboundary = 0;yboundary < 14; yboundary++){

          if(blokus[xboundary][yboundary]==rival){
             attackterritory=true;
          }
        }
      }/*領地在下*/
     }else if(blokus[9][9]==color){
         for(xboundary = 7; xboundary < 14; xboundary++){
          for(yboundary = 0;yboundary < 14; yboundary++){

          if(blokus[xboundary][yboundary]==rival){
             attackterritory=true;

          }
        }
      }
     }


     /*標註對手的邊*/
     for(j = 0; j < 14; j++){
      for(k = 0; k < 14; k++){
         if(blokus[j][k]==rival){
            if(0<=j-1&&j-1<14){
              if(blokus[j-1][k]=='N'){
              blokus[j-1][k]='W';
              }
            }
            if(0<=k-1&&k-1<14){
              if(blokus[j][k-1]=='N'){
              blokus[j][k-1]='W';
              }
            }
            if(0<=j+1&&j+1<14){
              if(blokus[j+1][k]=='N'){
              blokus[j+1][k]='W';
              }
            }
            if(0<=k+1&&k+1<14){
              if(blokus[j][k+1]=='N'){
              blokus[j][k+1]='W';
              }
            }
         }
       }
     }

     /*標註對手的角*/
     for(j = 0; j < 14; j++){
      for(k = 0; k < 14; k++){
         if(blokus[j][k]==rival){
           if(0<=j-1&&j-1<14&&0<=k-1&&k-1<14){
            if(blokus[j-1][k-1]=='N'){
              blokus[j-1][k-1]='K';
            }
           }
           if(0<=j-1&&j-1<14&&0<=k+1&&k+1<14){
            if(blokus[j-1][k+1]=='N'){
              blokus[j-1][k+1]='K';
            }
           }
           if(0<=j+1&&j+1<14&&0<=k-1&&k-1<14){
            if(blokus[j+1][k-1]=='N'){
              blokus[j+1][k-1]='K';
            }
           }
           if(0<=j+1&&j+1<14&&0<=k+1&&k+1<14){
            if(blokus[j+1][k+1]=='N'){
              blokus[j+1][k+1]='K';
            }
           }
         }
       }
     }

     /*標註自己的邊*/
     for(j = 0; j < 14; j++){
      for(k = 0; k < 14; k++){
         if(blokus[j][k]==color){
            if(0<=j-1&&j-1<14){
              if(blokus[j-1][k]!='B'&&blokus[j-1][k]!='R'){
              blokus[j-1][k]='S';
              }
            }
            if(0<=k-1&&k-1<14){
              if(blokus[j][k-1]!='B'&&blokus[j][k-1]!='R'){
              blokus[j][k-1]='S';
              }
            }
            if(0<=j+1&&j+1<14){
              if(blokus[j+1][k]!='B'&&blokus[j+1][k]!='R'){
              blokus[j+1][k]='S';
              }
            }
            if(0<=k+1&&k+1<14){
              if(blokus[j][k+1]!='B'&&blokus[j][k+1]!='R'){
              blokus[j][k+1]='S';
              }
            }
         }
       }
     }

     /*標註自己的角*/
     for(j = 0; j < 14; j++){
      for(k = 0; k < 14; k++){
         if(blokus[j][k]==color){
           if(0<=j-1&&j-1<14&&0<=k-1&&k-1<14){
            if(blokus[j-1][k-1]!='S'&&blokus[j-1][k-1]!='B'&&blokus[j-1][k-1]!='R'){
              blokus[j-1][k-1]='A';
            }
           }
           if(0<=j-1&&j-1<14&&0<=k+1&&k+1<14){
            if(blokus[j-1][k+1]!='S'&&blokus[j-1][k+1]!='B'&&blokus[j-1][k+1]!='R'){
              blokus[j-1][k+1]='A';
            }
           }
           if(0<=j+1&&j+1<14&&0<=k-1&&k-1<14){
            if(blokus[j+1][k-1]!='S'&&blokus[j+1][k-1]!='B'&&blokus[j+1][k-1]!='R'){
              blokus[j+1][k-1]='A';
            }
           }
           if(0<=j+1&&j+1<14&&0<=k+1&&k+1<14){
            if(blokus[j+1][k+1]!='S'&&blokus[j+1][k+1]!='B'&&blokus[j+1][k+1]!='R'){
              blokus[j+1][k+1]='A';
            }
           }
         }
       }
     }




   /*對手進入我領地*/
   if(attackterritory==true){

    /*領地在下*/
    if(blokus[9][9]==color){

     for(j = 7; j < 14; j++){
      for(k = 0; k < 14; k++){
         if(blokus[j][k]=='A'){
            allanglearray[count]=j;
            allanglearray[count+1]=k;
            count+=2;
         }
      }
     }
    for(j = 0; j < 7; j++){
      for(k = 0; k < 14; k++){
         if(blokus[j][k]=='A'){
            allanglearray[count]=j;
            allanglearray[count+1]=k;
            count+=2;
         }
      }
    }

    /*領地在上*/
   }else if(blokus[4][4]==color){

    for(j = 6; j >= 0; j--){
      for(k = 13;k >= 0; k--){
         if(blokus[j][k]=='A'){
            allanglearray[count]=j;
            allanglearray[count+1]=k;
            count+=2;
         }
      }
    }

    for(j = 13; j > 6; j--){
      for(k = 13;k >= 0; k--){
         if(blokus[j][k]=='A'){
            allanglearray[count]=j;
            allanglearray[count+1]=k;
            count+=2;
         }
      }
    }

    }
  }
   /*對手沒進入我領地*/
   if(attackterritory==false){
    /*左上*/
    if(blokus[9][9]==color){

     for(j = 0; j < 14; j++){
      for(k = 0; k < 14; k++){
         if(blokus[j][k]=='A'){
            allanglearray[count]=j;
            allanglearray[count+1]=k;
            count+=2;
         }
      }
    }/*右下*/
    }else if(blokus[4][4]==color){

     for(j = 13; j >= 0; j--){
      for(k = 13;k >= 0; k--){
         if(blokus[j][k]=='A'){
            allanglearray[count]=j;
            allanglearray[count+1]=k;
            count+=2;
         }
      }
    }

   }

   }

    if(blokus[4][4]=='N'){
     int temallanglearray[2]={4,4};
     count=2;
     for(a=0;a<2;a++){
      allanglearray[a]=temallanglearray[a];
     }
    }else if(blokus[9][9]=='N'){
      int temallanglearray[2]={9,9};
      count=2;
      for(a=0;a<2;a++){
       allanglearray[a]=temallanglearray[a];
      }
    }

   int setblokus=0;
   do{
    int wall=0;
    for(z;z<21;z++){
    setblokus=pattern[z];
    if(leftpattern[setblokus-1]=='1'){
        temp=z;
        z=100;
    }
   }

    if(z==21){
      setblokus=0;
    }
    z=temp;


    switch(setblokus){

    case 0:
    reback=false;
    break;

    /*1*/
    case 1:
    compute(0,8,1,8,2);
    break;

    /*2*/
    case 2:
    compute(1,8,1,8,4);
    break;

    /*3*/
    case 3:
    compute(2,10,4,10,6);
    break;

    /*4*/
    case 4:
    compute(3,8,1,8,6);
    break;

    /*5*/
    case 5:
    compute(4,8,5,8,8);
    break;

    /*6*/
    case 6:
    compute(5,10,4,10,8);
    break;

    /*7*/
    case 7:
    compute(6,12,4,12,8);
    break;

    /*8*/
    case 8:
    compute(7,12,5,12,8);
    break;

    /*9*/
    case 9:
    compute(8,8,1,8,8);
    break;

    /*10*/
    case 10:
    compute(9,10,5,10,10);
    break;

    /*11*/
    case 11:
    compute(10,10,5,10,10);
    break;

    /*12*/
    case 12:
    compute(11,12,4,12,10);
    break;

    /*13*/
    case 13:
    compute(12,10,4,10,10);
    break;

    /*14*/
    case 14:
    if(blokus[4][4]==color&&blokus[7][8]=='A'){
      if(blokus[7][8]!='S'&&blokus[7][8]!='B'&&blokus[7][8]!='R'){
        wall++;
      }
      if(blokus[7][9]!='S'&&blokus[7][9]!='B'&&blokus[7][9]!='R'){
        wall++;
      }
      if(blokus[6][9]!='S'&&blokus[6][9]!='B'&&blokus[6][9]!='R'){
        wall++;
      }
      if(blokus[6][10]!='S'&&blokus[6][10]!='B'&&blokus[6][10]!='R'){
        wall++;
      }
      if(blokus[5][10]!='S'&&blokus[5][10]!='B'&&blokus[5][10]!='R'){
        wall++;
      }
      if(wall==5){
        blokus[7][8]=color;
        blokus[7][9]=color;
        blokus[6][9]=color;
        blokus[6][10]=color;
        blokus[5][10]=color;
        leftpattern[setblokus-1]='0';
        reback=false;
      }
    }else if(blokus[9][9]==color&&blokus[9][5]=='A'){
      if(blokus[9][5]!='S'&&blokus[9][5]!='B'&&blokus[9][5]!='R'){
        wall++;
      }
      if(blokus[9][4]!='S'&&blokus[9][4]!='B'&&blokus[9][4]!='R'){
        wall++;
      }
      if(blokus[10][4]!='S'&&blokus[10][4]!='B'&&blokus[10][4]!='R'){
        wall++;
      }
      if(blokus[10][3]!='S'&&blokus[10][3]!='B'&&blokus[10][3]!='R'){
        wall++;
      }
      if(blokus[11][3]!='S'&&blokus[11][3]!='B'&&blokus[11][3]!='R'){
        wall++;
      }
      if(wall==5){
        blokus[9][5]=color;
        blokus[9][4]=color;
        blokus[10][4]=color;
        blokus[10][3]=color;
        blokus[11][3]=color;
        leftpattern[setblokus-1]='0';
        reback=false;
      }
    }

    if(wall!=5){
      compute(13,14,6,14,10);
    }
    break;

    /*15*/
    case 15:
    compute(14,12,5,12,10);
    break;

    /*16*/
    case 16:
    if(blokus[4][4]==color&&blokus[5][5]=='A'){
      if(blokus[5][5]!='S'&&blokus[5][5]!='B'&&blokus[5][5]!='R'){
        wall++;
      }
      if(blokus[6][5]!='S'&&blokus[6][5]!='B'&&blokus[6][5]!='R'){
        wall++;
      }
      if(blokus[6][6]!='S'&&blokus[6][6]!='B'&&blokus[6][6]!='R'){
        wall++;
      }
      if(blokus[6][7]!='S'&&blokus[6][7]!='B'&&blokus[6][7]!='R'){
        wall++;
      }
      if(blokus[7][6]!='S'&&blokus[7][6]!='B'&&blokus[7][6]!='R'){
        wall++;
      }
      if(wall==5){
        blokus[5][5]=color;
        blokus[6][5]=color;
        blokus[6][6]=color;
        blokus[6][7]=color;
        blokus[7][6]=color;
        leftpattern[setblokus-1]='0';
        reback=false;
      }
    }else if(blokus[9][9]==color&&blokus[8][8]=='A'){
      if(blokus[7][6]!='S'&&blokus[7][6]!='B'&&blokus[7][6]!='R'){
        wall++;
      }
      if(blokus[8][6]!='S'&&blokus[8][6]!='B'&&blokus[8][6]!='R'){
        wall++;
      }
      if(blokus[8][7]!='S'&&blokus[8][7]!='B'&&blokus[8][7]!='R'){
        wall++;
      }
      if(blokus[8][8]!='S'&&blokus[8][8]!='B'&&blokus[8][8]!='R'){
        wall++;
      }
      if(blokus[9][7]!='S'&&blokus[9][7]!='B'&&blokus[9][7]!='R'){
        wall++;
      }
      if(wall==5){
        blokus[7][6]=color;
        blokus[8][6]=color;
        blokus[8][7]=color;
        blokus[8][8]=color;
        blokus[9][7]=color;
        leftpattern[setblokus-1]='0';
        reback=false;
      }
    }

    if(wall!=5){
      compute(15,14,5,14,10);
    }
    break;

    /*17*/
    case 17:
    compute(16,16,5,16,10);
    break;

    /*18*/
    case 18:
    if(blokus[4][4]=='N'){
      blokus[4][1]=color;
      blokus[4][2]=color;
      blokus[4][3]=color;
      blokus[4][4]=color;
      blokus[5][1]=color;
      leftpattern[setblokus-1]='0';
      reback=false;
    }else if(blokus[9][9]=='N'){
      blokus[9][9]=color;
      blokus[9][10]=color;
      blokus[9][11]=color;
      blokus[9][12]=color;
      blokus[10][9]=color;
      leftpattern[setblokus-1]='0';
      reback=false;
    }else if(blokus[4][4]!='N'&&blokus[9][9]!='N'){
      compute(17,10,4,10,10);
    }
    break;


    /*19*/
    case 19:
    compute(18,12,5,12,10);
    break;


    /*20*/
    case 20:
    compute(19,12,4,12,10);
    break;

    /*21*/
    case 21:
    compute(20,8,1,10,10);
    break;


    }

  }while(reback);

    if(setblokus!=0){


     /*輸出blokusboard*/
     for(j = 0; j < 14; j++){
      for(k = 0; k < 14; k++){
         if(blokus[j][k]=='S'||blokus[j][k]=='A'||blokus[j][k]=='K'||blokus[j][k]=='W'){
            blokus[j][k]='N';
         }
       }
     }
    FILE* fpw;
    fpw=fopen(argv[2],"w");
    for(j = 0; j < 14; j++){
     for(k = 0; k < 14; k++){
        if(k!=0){
         fprintf(fpw,",");
        }
         s=blokus[j][k];
         fwrite(&s,1,1,fpw);
      }
      fprintf(fpw,"\n");
    }
    fclose(fpw);

    /*輸出leftpattern*/
    FILE *fpa;
    fpa=fopen(argv[3],"a");
    fprintf(fpa,"\n");
    fprintf(fpa,"[");
    for(i=0;i<21;i++){
      if(i!=0){
        fprintf(fpa,",");
      }
      s=leftpattern[i];
      fprintf(fpa,"%c",s);
    }
    fprintf(fpa,"]");
    fclose(fpa);

    return 0;

   }else if(setblokus==0){
     return 1;
   }

}



    /*方法*/
    void compute(int pnumber,int angleamount,int square,int total,int blokusamount){
       cannotfindangle=false;
       bool rightside=false;
       bool backside=false;
       angles=0;



   /*找不到適合的角*/
    if(count==0){
      cannotfindangle=true;
    }


        do{
                /*角輪流*/
                if(angles==count){
                 cannotfindangle=true;
                 z++;
                }

                for(angles;angles<count;angles+=2){
                x=allanglearray[angles];
                y=allanglearray[angles+1];
                tempangles=angles;
                angles=1000;
              }
               angles=tempangles+2;


   if(cannotfindangle==false){

    /*可變換格子數*/
    int change;
    for(change=0;change<square;change++){
        /*旋轉*/
        int f;
        for(f=0;f<5;f++){
        /*角數*/
        int c;
        for(c=0;c<total;c+=2){
        int n;
        if(change==0){
          n=0;
        }else if(change==1){
          n=2;
        }else if(change==2){
          n=4;
        }else if(change==3){
          n=6;
        }else if(change==4){
          n=8;
        }else if(change==5){
          n=10;
        }

        if(f==0){
         number[pnumber][c]+=changes[pnumber][n];
         number[pnumber][c+1]+=changes[pnumber][n+1];
        }
        if(f>0){
        int tempnumber=number[pnumber][c];
        number[pnumber][c]=number[pnumber][c+1];
        number[pnumber][c+1]=(-tempnumber);
        }
        blokusarray[c]=number[pnumber][c]+x;
        blokusarray[c+1]=number[pnumber][c+1]+y;
        turnblokusarray[c]=(-number[pnumber][c])+x;
        turnblokusarray[c+1]=number[pnumber][c+1]+y;
     }

       int temprivalangles=0;
       /*正面*/
       for(m=0;m<blokusamount;m+=2){
       xycheck=false;
       blokusnullcheck=false;
       blokussidecheck=false;
       int *p=blokusarray;
       int g=*(p+m);
       int h=*(p+m+1);
       if(0<=g&&g<=13&&0<=h&&h<=13){
         xycheck=true;
         if(blokus[g][h]!='S'&&blokus[g][h]!='B'&&blokus[g][h]!='R'){
           blokusnullcheck=true;
           blokussidecheck=true;
           if(blokus[g][h]=='K'){
             temprivalangles++;
           }
         }
       }
       if((blokussidecheck==false)||(xycheck==false)||(blokusnullcheck==false)){
         m=100;
       }else if(m>=(blokusamount-2)){
        m=100;
        if(temprivalangles>rivalangles){
          hasfinal=true;
          rivalangles=temprivalangles;
          temppnumber=pnumber;
          tempblokusamount=blokusamount;
          for(e=0;e<blokusamount;e++){
           finalblokusarray[e]=blokusarray[e];
          }
        }
       }
     }
       temprivalangles=0;
       /*反面*/
       for(m=0;m<blokusamount;m+=2){
       xycheck=false;
       blokusnullcheck=false;
       blokussidecheck=false;
       int *p=turnblokusarray;
       int g=*(p+m);
       int h=*(p+m+1);
       if(0<=g&&g<=13&&0<=h&&h<=13){
         xycheck=true;
         if(blokus[g][h]!='S'&&blokus[g][h]!='B'&&blokus[g][h]!='R'){
           blokusnullcheck=true;
           blokussidecheck=true;
           if(blokus[g][h]=='K'){
             temprivalangles++;
           }
         }
       }
       if((blokussidecheck==false)||(xycheck==false)||(blokusnullcheck==false)){
         m=100;
       }else if(m>=(blokusamount-2)){
        m=100;
        if(temprivalangles>rivalangles){
          hasfinal=true;
          rivalangles=temprivalangles;
          temppnumber=pnumber;
          tempblokusamount=blokusamount;
          for(e=0;e<blokusamount;e++){
           finalblokusarray[e]=turnblokusarray[e];
          }
        }
       }
     }
     }
    }

  }

  }while(cannotfindangle==false);

     int checkend=0;
     if(pnumber==17||pnumber==15||pnumber==13||pnumber==12||pnumber==20||pnumber==9||pnumber==18||pnumber==14||pnumber==10||pnumber==19||pnumber==11||pnumber==16){
       checkend=16;
     }else if(pnumber==7||pnumber==6||pnumber==5||pnumber==8||pnumber==4){
       checkend=4;
     }else if(pnumber==3||pnumber==2||pnumber==1||pnumber==0){
       checkend=0;
     }
     if(hasfinal==true&&pnumber==checkend){
     blokusamount=tempblokusamount;
     for(a=0;a<blokusamount;a+=2){
      blokus[finalblokusarray[a]][finalblokusarray[a+1]]=color;
     }
     pnumber=temppnumber;
     leftpattern[pnumber]='0';
     reback=false;
     }
  }
