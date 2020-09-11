#include <stdio.h>
#include <stdlib.h>

short int loop = 0;
struct MCP{
    // OR dan AND
    short int www;
    short int ttt;
    short int xxx[3];
    short int yyy;
    unsigned short int hasil;
    //  XOR
    short int w1, w2, w3, w4, w5, w6;
    short int o1, o2, o3, z1, z2;
}pitts;

void orr(short int jml_input){
    pitts.www = 2;
    pitts.ttt = 2;
    printf("Operasi OR\n");
    for(loop = 0; loop < jml_input; loop++){
        printf("Input x[%d]: ",loop+1);
        scanf("%d",&pitts.xxx[loop]);
    }
    if(jml_input == 2){
        pitts.yyy = pitts.www*pitts.xxx[0] + pitts.www*pitts.xxx[1];
    }else{
        pitts.yyy = pitts.www*pitts.xxx[0] + pitts.www*pitts.xxx[1] + pitts.www*pitts.xxx[2];
    }
    if(pitts.yyy >= pitts.ttt){
        pitts.hasil = 1;
    }else{
        pitts.hasil = 0;
    }
    printf("Hasil: %d",pitts.hasil);
}

void xorr(short int jml_input){
    pitts.w1 = 2;
    pitts.w2 = -1;
    pitts.w3 = pitts.w1;
    pitts.w4 = pitts.w2;
    pitts.w5 = 2;
    pitts.w6 = pitts.w5;
    pitts.ttt = 2;

    for(loop = 0; loop < 3; loop++){
        printf("Input x[%d]: ",loop+1);
        scanf("%d",&pitts.xxx[loop]);
    }

    pitts.o1 = pitts.w1*pitts.xxx[0] + pitts.w2*pitts.xxx[1];
    if(pitts.o1 >= pitts.ttt){
        pitts.z1 = 1;
    }else{
        pitts.z1 = 0;
    }

    pitts.o2 = pitts.w2*pitts.xxx[0] + pitts.w3*pitts.xxx[1];
    if(pitts.o2 >= pitts.ttt){
        pitts.z2 = 1;
    }else{
        pitts.z2 = 0;
    }

    pitts.o3 = pitts.w5*pitts.z1 + pitts.w6*pitts.z2;
    if(pitts.o3 >= pitts.ttt){
        pitts.yyy = 1;
    }else{
        pitts.yyy = 0;
    }

    if(jml_input == 3){
        pitts.o1 = pitts.w1*pitts.yyy + pitts.w2*pitts.xxx[2];
        if(pitts.o1 >= pitts.ttt){
            pitts.z1 = 1;
        }else{
            pitts.z1 = 0;
        }

        pitts.o2 = pitts.w2*pitts.yyy + pitts.w3*pitts.xxx[2];
        if(pitts.o2 >= pitts.ttt){
            pitts.z2 = 1;
        }else{
            pitts.z2 = 0;
        }

        pitts.o3 = pitts.w5*pitts.z1 + pitts.w6*pitts.z2;
        if(pitts.o3 >= pitts.ttt){
            pitts.hasil = 1;
        }else{
            pitts.hasil = 0;
        }
        printf("Hasil: %d",pitts.hasil);
    }else{
        printf("Hasil: %d",pitts.yyy);
    }
}

void andd(short int jml_input){
    pitts.www = 1;
    pitts.ttt = jml_input;

    for(loop = 0; loop < 3; loop++){
        printf("Input x[%d]: ",loop+1);
        scanf("%d",&pitts.xxx[loop]);
    }

    if(jml_input == 2){
        pitts.yyy = pitts.www*pitts.xxx[0] + pitts.www*pitts.xxx[1];
    }else{
        pitts.yyy = pitts.www*pitts.xxx[0] + pitts.www*pitts.xxx[1] + pitts.www*pitts.xxx[2];
    }

    if(pitts.yyy >= pitts.ttt){
        pitts.hasil = 1;
    }else{
        pitts.hasil = 0;
    }
    printf("Hasil: %d",pitts.hasil);
}

int main()
{
    //orr(3);
    //xorr(3);
    andd(3);
    return 0;
}
