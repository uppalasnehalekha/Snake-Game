#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
struct node{
    int x,y,d;
}nodes[50];
//struct node nodes[30];
int n=1,d=1,p=0,cc;
int w=480,h=480;
int xc=-60,yc=-60;
int exf=0;
int rx=nodes[0].x,ry=nodes[0].y;
int status =1;
int fstatus=0;
void move();
void food();
void foodx();
void exfood();
void exfoods();
void score();
int exfs=0;
void timer(int );
int foods();
int ss=-1;
int sc=ss;
int direction;
bool pstatus=true;

void grid(){
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POINTS);
    for(int i=30;i<h;i+=30){
        for(int j=0;j<w;j+=5){
            glVertex2d(j,i);
        }
    }
    for(int i=30;i<w;i+=30){
        for(int j=0;j<h;j+=5){
            glVertex2d(i,j);
        }
    }
    glEnd();
}
void display()
{

    if(p==0){
    glClear(GL_COLOR_BUFFER_BIT);
    //glTranslated(10,10,0);

    grid();
    for(int i=0;i<=n-1;i++){
    if(i==0){
    /*glBegin(GL_POLYGON);
        glColor3ub(255,0,0);
        glVertex2i(nodes[i].x,nodes[i].y);
        glColor3ub(0,255,0);
        glVertex2i(nodes[i].x+30,nodes[i].y);
        glColor3ub(0,0,255);
        glVertex2i(nodes[i].x+30,nodes[i].y+30);
        glColor3ub(255,255,0);
        glVertex2i(nodes[i].x,nodes[i].y+30);
    glEnd();*/
    glColor3d(0,0,1);
    for(double h1=0;h1<=360;h1++){
        glBegin(GL_TRIANGLES);
        glColor3d(0,0,1);
        glVertex2d(nodes[i].x+15,nodes[i].y+15);
        glColor3d(0,0,0.5);
        glVertex2d(nodes[i].x+15+cos(h1)*15,nodes[i].y+15+sin(h1)*15);
        glColor3d(0,0,0.5);
        glVertex2d(nodes[i].x+15+cos(h1+1)*15,nodes[i].y+15+sin(h1+1)*15);
        glEnd();
    }
    }
    else{
            //glColor3f(0.0,0.0,1.0);
        //glRectd(nodes[i].x,nodes[i].y,nodes[i].x+30,nodes[i].y+30);
        glColor3d(1,1,0);
        for(double h1=0;h1<=360;h1++){
            glBegin(GL_TRIANGLES);
            glColor3d(1,1,0);
            glVertex2d(nodes[i].x+15,nodes[i].y+15);
            glColor3d(0.5,0.5,0);
            glVertex2d(nodes[i].x+15+cos(h1)*15,nodes[i].y+15+sin(h1)*15);
            glColor3d(0.5,0.5,0);
            glVertex2d(nodes[i].x+15+cos(h1+1)*15,nodes[i].y+15+sin(h1+1)*15);
            glEnd();
        }
       /* glColor3f(0.0,0.0,0.0);
        glBegin(GL_POINTS);
        for(int m=nodes[i].x;m<=nodes[i].x+30;m+=5) glVertex2d(m,nodes[i].y);
        for(int m=nodes[i].x;m<=nodes[i].x+30;m+=5) glVertex2d(m,nodes[i].y+30);
        for(int m=nodes[i].y;m<=nodes[i].y+30;m+=5) glVertex2d(nodes[i].x,m);
        for(int m=nodes[i].y;m<=nodes[i].y+30;m+=5) glVertex2d(nodes[i].x+30,m);
        glEnd();*/
    }
    }

    glColor3f(0.0,1.0,0.0);
    glBegin(GL_TRIANGLES);
    //glVertex2d(rx,ry+15);
    //glVertex2d(rx+15,ry+30);
    //glVertex2d(rx+30,ry+15);
    //glVertex2d(rx+15,ry);
    glColor3f(0.0,0.3,0.0);
    glVertex2d(rx,ry);
    glColor3f(0.0,1.0,0.0);
    glVertex2d(rx,ry+15);
    glColor3f(0.0,0.3,0.0);
    glVertex2d(rx+6,ry);
    /*glVertex2d(rx+15,ry+30);
    glVertex2d(rx+18,ry);
    glVertex2d(rx+30,ry+15);
    glVertex2d(rx+30,ry);*/
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.0,0.3,0.0);
    glVertex2d(rx+6,ry);
    glColor3f(0.0,1.0,0.0);
    glVertex2d(rx+6,ry+22);
    glColor3f(0.0,0.3,0.0);
    glVertex2d(rx+12,ry);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.0,0.3,0.0);
    glVertex2d(rx+12,ry);
    glColor3f(0.0,1.0,0.0);
    glVertex2d(rx+15,ry+30);
    glColor3f(0.0,0.3,0.0);
    glVertex2d(rx+18,ry);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.0,0.3,0.0);
    glVertex2d(rx+18,ry);
    glColor3f(0.0,1.0,0.0);
    glVertex2d(rx+24,ry+22);
    glColor3f(0.0,0.3,0.0);
    glVertex2d(rx+24,ry);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.0,0.3,0.0);
    glVertex2d(rx+24,ry);
    glColor3f(0.0,1.0,0.0);
    glVertex2d(rx+30,ry+15);
    glColor3f(0.0,0.3,0.0);
    glVertex2d(rx+30,ry);
    glEnd();
    /*for(double h1=0;h1<=360;h1++){
        glBegin(GL_TRIANGLES);
        glVertex2d(xc+15,yc+15);
        glVertex2d(xc+15+cos(h1)*15,yc+15+sin(h1)*15);
        glVertex2d(xc+15+cos(h1+1)*15,yc+15+sin(h1+1)*15);
        glEnd();
    }*/
    glColor3f(1.0,0.0,0.0);
        glRasterPos2i(w-70,h-20);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,'S');
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,'C');
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,'O');
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,'R');
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,'E');
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,':');
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,'-');
        score();
    glFlush();}
}

void food()
{
    foodx();
    //foody();
}

void foodx()
{
    int repeat=1;
    for(int i=0;repeat!=0;i++)
    {
        repeat=0;
        rx=((rand()%((w-30)/30))*30)+30;
        ry=((rand()%((h-30)/30))*30)+30;
        for(int j=0;j<=n-1;j++){
            if(rx==nodes[j].x&&ry==nodes[j].y||rx==xc&&ry==yc) repeat=1;
        }
        //if(repeat==0) break;
    }
}

void exfood()
{
    int repeat=1;
    for(int i=0;repeat!=0;i++)
    {
        repeat=0;
        xc=((rand()%((w-30)/30))*30)+30;
        yc=((rand()%((h-30)/30))*30)+30;
        for(int j=0;j<=n-1;j++){
            if(xc==nodes[j].x&&yc==nodes[j].y||xc==rx&&yc==ry) repeat=1;
        }
        //if(repeat==0) break;
    }
}

int foods()
{
    if((nodes[0].x==rx)&&(nodes[0].y==ry)&&(nodes[0].x+30==rx+30)&&(nodes[0].y+30==ry+30))
    {
        return 0;
    }
    return 1;
}

void exfoods()
{
    if((nodes[0].x==xc)&&(nodes[0].y==yc)&&(nodes[0].x+30==xc+30)&&(nodes[0].y+30==yc+30))
    {
        xc=-60;yc=-60;
        exfs=0;
        //return 0;
    }
    //return 1;
}

void score()
{
    int a[10];
    int c=0;
    sc=ss+1;
    for(int i=0;sc!=0;i++)
    {
        a[i]=sc%10;
        sc=sc/10;
        c++;
    }
    for(int i=c-1;i>=0;i--)
    {
         glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,48+a[i]);
    }
    glFlush();
}

void key(unsigned char k,int p,int q)
{
    q=h-q;
    switch(k)
    {
        case 'p':if(fstatus)fstatus=false;else fstatus=true;if(fstatus)printf("hi");else printf("hello");break;
        //case 'p':p=1;break;
        //case 'r':p=0;break;
    }
}

void keyb(int k,int p,int q)
{
    q=h-q;
    switch(k)
    {
        case GLUT_KEY_UP:if(nodes[0].d!=3&&nodes[0].d!=1) {nodes[0].d=1;move();cc=0;}break;
        case GLUT_KEY_LEFT:if(nodes[0].d!=4&&nodes[0].d!=2) {nodes[0].d=2;move();cc=0;}break;
        case GLUT_KEY_DOWN:if(nodes[0].d!=1&&nodes[0].d!=3) {nodes[0].d=3;move();cc=0;}break;
        case GLUT_KEY_RIGHT:if(nodes[0].d!=2&&nodes[0].d!=4) {nodes[0].d=4;move();cc=0;}break;
        //case 'p':p=1;break;
        //case 'r':p=0;break;
    }
}

void timer(int value)
{
    int t=ss/1;
    t=t+1;
    if(cc!=0)
        move();
    cc++;
    if(status!=0)
        glutPostRedisplay();
    /*else if(!pstatus){
        glColor3f(1.0,1.0,0.0);
        glRasterPos2i((w/2)-7,h/2);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,'P');
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,'A');
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,'U');
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,'S');
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,'E');
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,'D');
    }*/
    else
    {
        glPointSize(3);
        glColor3f(1.0,1.0,0.0);
        glRasterPos2i((w/2)-7,h/2);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,'G');
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,'A');
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,'M');
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,'E');
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,' ');
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,'O');
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,'V');
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,'E');
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,'R');
        glFlush();
    }
    glutTimerFunc((300-(t*10)),timer,0);
    return;

}

void move(){
    for(int i=n-1;i>0;i--){
        if(i!=0){
            nodes[i].d=nodes[i-1].d;
        }
    }
    for(int i=n-1;i>=1;i--){
        nodes[i].x = nodes[i-1].x;
        nodes[i].y = nodes[i-1].y;
    }

        switch(nodes[0].d)
        {
            case 1:nodes[0].y=nodes[0].y+30;break;
            case 2:nodes[0].x=nodes[0].x-30;break;
            case 3:nodes[0].y=nodes[0].y-30;break;
            case 4:nodes[0].x=nodes[0].x+30;break;
        }


    if(nodes[0].y+30>h) nodes[0].y=0;
    if(nodes[0].y<0) nodes[0].y=h-30;
    if(nodes[0].x+30>w) nodes[0].x=0;
    if(nodes[0].x<0) nodes[0].x=w-30;
    for(int i=3;i<=n-1;i++){
        if(nodes[0].x==nodes[i].x&&nodes[0].y==nodes[i].y) status=0;
    }
    fstatus = foods();
    //printf("\n%d",fstatus);
   if(fstatus==0)
    {
        n++;
        nodes[n-1].x=nodes[n-2].x;
        nodes[n-1].y=nodes[n-2].y;
        food();
        ss+=1;
        exf++;
        //printf("\n%d",rx);
        //printf("\n%d",ry);
       // fstatus=1;
    }
    //exfs = exfoods();
    exfoods();
    if(exf>=5&&exf%5==0&&exfs==0){
        exfood();
        exfs=1;
    }
}

void myreshape(int w1,int h1)
{
    //glViewport(0,0,1000,1000);
    if(h1=0) h1=1;
    if(w1=0) w1=1;

    if(w1<h1)
    {
        w1=w*w1/h1;
        h1=h;
    }

    if(w1>h1)
    {
        h1=h*h1/w1;
        w1=w;
    }
    //gluOrtho2D(0,w1,0,h1);
}

void reshape (int w, int h)
{
   glViewport (0, 0,  w,  h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   gluPerspective(60.0, (float)w/h, 1.0, 20.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   gluLookAt (0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}
void init()
{
    glClearColor(1.0,1.0,1.0,1.0);
    //glClearColor(0.7,0.9,0.8,1.0);
    gluOrtho2D(0,w,0,h);
}

int main(int argc,char ** argv)
{
    nodes[0].x=30;
    nodes[0].y=30;
    nodes[0].d=1;
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowPosition(10,10);
    glutInitWindowSize(w,h);
    glutCreateWindow("motion");
    glutDisplayFunc(display);
   // glutKeyboardFunc(key);
    glutSpecialFunc(keyb);
    glutTimerFunc(100,timer,0);
    glutReshapeFunc(myreshape);
    init();
    glutMainLoop();
    return 0;
}
