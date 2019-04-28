#include<graphics.h>
#include<math.h>
#include<stdio.h>

int main()
{
    int gd=0,gm=0,x0,y0,x1,y1,p,x,y,dx,dy,length;
    printf("\nEnter starting co-ordinate of line(x0,y0):");
    scanf("%d%d",&x0,&y0);
    printf("\nEnter end point co-ordinate of line(x1,y1):");
    scanf("%d%d",&x1,&y1);
    dx=x1-x0;
    dy=y1-y0;
    if(abs(dx)>abs(dy))
        length=abs(dx);
    else
        length=abs(dy);
    p=2*dy-dx;
    x=x0;
    y=y0;
    initgraph(&gd,&gm,"");
    putpixel(x,y,15);
    while(length--)
    {


        if(p<0)
        {
            x=x+1;
            if(length%2==0){
            putpixel(x,y,15);}
            p=p+2*dy;
        }
        else
        {
          x=x+1;
          y=y+1;
          if(length%2==0)
          {
          putpixel(x,y,15);}
          p=p+2*dy-2*dx;
        }

    }
    getch();
    closegraph();
    return 0;
}
