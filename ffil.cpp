#include<stdio.h>
#include<graphics.h>
int xwmax,ywmax,xwmin,ywmin,a=0,x1,y1,x2,y2,x11,y11;
float r[4],u1=0.0,u2=1.0,p[4],q[4];
void draw()
{
    int i;
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"");
    line(xwmin,ywmin,xwmin,ywmax);
    line(xwmin,ywmin,xwmax,ywmin);
    line(xwmax,ywmax,xwmin,ywmax);
     line(xwmax,ywmax,xwmax,ywmin);
    for(i=0;i<4;i++)
    {
        if(p[i]!=0)
        {
            r[i]=q[i]/p[i];
        }
    }
    for(i=0;i<4;i++)
    {
        if(p[i]<0)
        {
            if(r[i]>u1)
                u1=r[i];
        }
        if(p[i]>0)
        {
            if(r[i]<u2)
                u2=r[i];
        }
    }
    if(u1<=u2)
    {
        x11=x1+(u1*p[1]);
        y11=y1+(u1*p[3]);
        x2=x1+(u2*p[1]);
        y2=y1+(u2*p[3]);
        line(x11,y11,x2,y2);
    }
    getch();
    closegraph();
}
int main()
{
    int i;
    printf("\nenter Xwmin and Ywmin:");
    scanf("%d%d",&xwmin,&ywmin);
    printf("\nenter Xwmax and Ywmax:");
    scanf("%d%d",&xwmax,&ywmax);
    printf("\nenter starting line co-ordinate(x1,y1):");
    scanf("%d%d",&x1,&y1);
    printf("\nenter terminating line co-ordinate(x2,y2):");
    scanf("%d%d",&x2,&y2);
    p[0]=-(x1-x2);
    p[1]=(x1-x2);
    p[2]=-(y1-y2);
    p[3]=y1-y2;
    q[0]=x1-xwmin;
    q[1]=xwmax-x1;
    q[2]=y1-ywmin;
    q[3]=ywmax-y1;
    for(i=0;i<4;i++)
    {
        if(p[i]==0)
        {
            if(q[i]<0)
                a++;
        }
    }
    if(a==0)
        draw();
    else
        printf("\nline is outside\n");
    return 0;
}
