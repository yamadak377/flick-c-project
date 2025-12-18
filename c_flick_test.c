#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void m_tap_cmd( int x,int y )
{
    char s_cmd[80];
    sprintf( s_cmd,"adb shell input tap %d %d",x,y );
    system( s_cmd );
}
void m_swipe_cmd( int x,int y,int xs,int ys )
{
    char s_cmd[80];
    sprintf( s_cmd,"adb shell input swipe %d %d %d %d",x,y,xs,ys );
    system( s_cmd );
}

int main( int argc,char *argv[] ){
    printf("Test start arvc=%d\n",argc );
    if ( argc != 2 )
    {
        printf("Usage:c_test pixel8a_p/pixel8a_l/pixel8_p/pixel8_l/small_p/small_l\n");        
    }
    printf("Display=%s\n",argv[1]);
    
    static int s_P[6][5] = {
        //      portrate                landscape
        // X1  Y1   X2  Y2   S       X1  Y1  X2  Y2  S
        { 100,1700,320,1850,120 },{ 210,550,680,665,120 },   // pixel8a
        { 130,2130,410,2330,120 },{ 260,670,840,820,120 },   // pixel8
        { 70 ,800 ,215,900 ,120 },{ 110,390,377,455,120 }    // small
    };
    
    int nX,nY,nW,nH,nS;
    int p=0;
    
    if (      strcmp(argv[1],"pixel8a_p" ) == 0 )   p=0;
    else if ( strcmp(argv[1],"pixel8a_l" ) == 0 )   p=1;
    else if ( strcmp(argv[1],"pixel8_p" ) == 0 )    p=2;
    else if ( strcmp(argv[1],"pixel8_l" ) == 0 )    p=3;
    else if ( strcmp(argv[1],"small_p" ) == 0 )     p=4;
    else if ( strcmp(argv[1],"small_l" ) == 0 )     p=5;
    else
    {
        printf("Usage:c_test pixel8a_p/pixel8a_l/pixel8_p/pixel8_l/small_p/small_l\n");   
    }
    nX=s_P[p][0];
    nY=s_P[p][1];
    nW=s_P[p][2]-s_P[p][0];
    nH=s_P[p][3]-s_P[p][1];
    nS=s_P[p][4];
    
    m_tap_cmd( nX+nW,nY );
    m_swipe_cmd( nX+nW,nY, nX+nW-nS,nY );
    m_swipe_cmd( nX+nW,nY, nX+nW,nY-nS );
    m_swipe_cmd( nX+nW,nY, nX+nW+nS,nY );
    m_swipe_cmd( nX+nW,nY, nX+nW,nY+nS );
    m_tap_cmd( nX+nW*2,nY );
    m_swipe_cmd( nX+nW*2,nY, nX+nW*2-nS,nY );
    m_swipe_cmd( nX+nW*2,nY, nX+nW*2,nY-nS );
    m_swipe_cmd( nX+nW*2,nY, nX+nW*2+nS,nY );
    m_swipe_cmd( nX+nW*2,nY, nX+nW*2,nY+nS );
    m_tap_cmd( nX+nW*3,nY );
    m_swipe_cmd( nX+nW*3,nY, nX+nW*3-nS,nY );
    m_swipe_cmd( nX+nW*3,nY, nX+nW*3,nY-nS );
    m_swipe_cmd( nX+nW*3,nY, nX+nW*3+nS,nY );
    m_swipe_cmd( nX+nW*3,nY, nX+nW*3,nY+nS );
    m_tap_cmd( nX+nW,nY+nH );
    m_swipe_cmd( nX+nW,nY+nH, nX+nW-nS,nY+nH );
    m_swipe_cmd( nX+nW,nY+nH, nX+nW,nY+nH-nS );
    m_swipe_cmd( nX+nW,nY+nH, nX+nW+nS,nY+nH );
    m_swipe_cmd( nX+nW,nY+nH, nX+nW,nY+nH+nS );
    m_tap_cmd( nX+nW*2,nY+nH );
    m_swipe_cmd( nX+nW*2,nY+nH, nX+nW*2-nS,nY+nH );
    m_swipe_cmd( nX+nW*2,nY+nH, nX+nW*2,nY+nH-nS );
    m_swipe_cmd( nX+nW*2,nY+nH, nX+nW*2+nS,nY+nH );
    m_swipe_cmd( nX+nW*2,nY+nH, nX+nW*2,nY+nH+nS );
    m_tap_cmd( nX+nW*3,nY+nH );
    m_swipe_cmd( nX+nW*3,nY+nH, nX+nW*3-nS,nY+nH );
    m_swipe_cmd( nX+nW*3,nY+nH, nX+nW*3,nY+nH-nS );
    m_swipe_cmd( nX+nW*3,nY+nH, nX+nW*3+nS,nY+nH );
    m_swipe_cmd( nX+nW*3,nY+nH, nX+nW*3,nY+nH+nS );
    m_tap_cmd( nX+nW,nY+nH*2 );
    m_swipe_cmd( nX+nW,nY+nH*2, nX+nW-nS,nY+nH*2 );
    m_swipe_cmd( nX+nW,nY+nH*2, nX+nW,nY+nH*2-nS );
    m_swipe_cmd( nX+nW,nY+nH*2, nX+nW+nS,nY+nH*2 );
    m_swipe_cmd( nX+nW,nY+nH*2, nX+nW,nY+nH*2+nS );
    m_tap_cmd( nX+nW*2,nY+nH*2 );
    m_swipe_cmd( nX+nW*2,nY+nH*2, nX+nW*2-nS,nY+nH*2 );
    m_swipe_cmd( nX+nW*2,nY+nH*2, nX+nW*2,nY+nH*2-nS );
    m_swipe_cmd( nX+nW*2,nY+nH*2, nX+nW*2+nS,nY+nH*2 );
    m_swipe_cmd( nX+nW*2,nY+nH*2, nX+nW*2,nY+nH*2+nS );
    m_tap_cmd( nX+nW*3,nY+nH*2 );
    m_swipe_cmd( nX+nW*3,nY+nH*2, nX+nW*3-nS,nY+nH*2 );
    m_swipe_cmd( nX+nW*3,nY+nH*2, nX+nW*3,nY+nH*2-nS );
    m_swipe_cmd( nX+nW*3,nY+nH*2, nX+nW*3+nS,nY+nH*2 );
    m_swipe_cmd( nX+nW*3,nY+nH*2, nX+nW*3,nY+nH*2+nS );
    m_tap_cmd( nX+nW*2,nY+nH*3 );
    m_swipe_cmd( nX+nW*2,nY+nH*3, nX+nW*2-nS,nY+nH*3 );
    m_swipe_cmd( nX+nW*2,nY+nH*3, nX+nW*2,nY+nH*3-nS );
    m_swipe_cmd( nX+nW*2,nY+nH*3, nX+nW*2+nS,nY+nH*3 );
    m_swipe_cmd( nX+nW*2,nY+nH*3, nX+nW*2,nY+nH*3+nS );
    
//    m_swipe_cmd( nX+nW*2,nY+nH*3, nX+nW*2,nY+nH*3-nS );
    
    sleep(5);
    
    for( int i=0;i<50;i++ )
    {
        m_tap_cmd( nX+nW*4,nY );
    }
    return 0;
}
