#include<iostream>
#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
///include fstream for map editor

using namespace std;

char maze[19][20];
int back[19][20];
int darray[19][20];
char direction;

void display(char array[18][20]){
    HANDLE hColor;
    hColor=GetStdHandle(STD_OUTPUT_HANDLE);  //SetConsoleTExtAtribute(hColor,color); red=12 blue=9 yellow=14
    for(int q=0;q<19;q++){
        for(int w=0;w<20;w++){
            if(maze[q][w]==char(219)){
               SetConsoleTextAttribute(hColor,9);
            }
            if(maze[q][w]==char(249)){
               SetConsoleTextAttribute(hColor,14);
            }
            if(maze[q][w]=='M'){
               SetConsoleTextAttribute(hColor,12);
            }
            if((maze[q][w]=='>')||(maze[q][w]=='<')||(maze[q][w]=='^')||(maze[q][w]=='v')){
               SetConsoleTextAttribute(hColor,14);
            }
            cout<<array[q][w];
        }
        cout<<endl;
    }
}


void move(int &d, int &r, int &p, char &g){
    if(((GetAsyncKeyState(65))||(GetAsyncKeyState(VK_LEFT)))&&(maze[d][r-1]!=char(219))){
        if(maze[d][r-1]==char(249)){
            p++;
            back[d][r-1]=0;
        }
        else if(maze[d][r-1]=='M'){
            g='g';
        }
        maze[d][r]=' ';
        r--;
        maze[d][r]='>';
    }
    else if(((GetAsyncKeyState(68))||(GetAsyncKeyState(VK_RIGHT)))&&(maze[d][r+1]!=char(219))){
        if(maze[d][r+1]==char(249)){
            p++;
            back[d][r+1]=0;
        }
        else if(maze[d][r+1]=='M'){
            g='g';
        }
        maze[d][r]=' ';
        r++;
        maze[d][r]='<';
    }
    else if(((GetAsyncKeyState(87))||(GetAsyncKeyState(VK_UP)))&&(maze[d-1][r]!=char(219))){
        if(maze[d-1][r]==char(249)){
            p++;
            back[d-1][r]=0;
        }
        else if(maze[d-1][r]=='M'){
            g='g';
        }
        maze[d][r]=' ';
        d--;
        maze[d][r]='v';
    }
    else if(((GetAsyncKeyState(83))||(GetAsyncKeyState(VK_DOWN)))&&(maze[d+1][r]!=char(219))){
        if(maze[d+1][r]==char(249)){
            p++;
            back[d+1][r]=0;
        }
        else if(maze[d+1][r]=='M'){
            g='g';
        }
        maze[d][r]=' ';
        d++;
        maze[d][r]='^';
    }
}

void ghost(int &gd, int &gr, char &g){
    int ggd=gd;
    int ggr=gr;
    int x;
    int y;
    y=rand()%8;
    if(y==0){
        direction='q';
    }
    if((direction=='u')&&(maze[ggd-1][ggr]!=char(219))){
        ggd--;
        direction='u';
    }
    else if((direction=='d')&&(maze[ggd+1][ggr]!=char(219))){
        ggd++;
        direction='d';
    }
    else if((direction=='l')&&(maze[ggd][ggr-1]!=char(219))){
        ggr--;
        direction='l';
    }
    else if((direction=='r')&&(maze[ggd][ggr+1]!=char(219))){
        ggr++;
        direction='r';
    }
    else{
        do{
            ggd=gd;
            ggr=gr;
            x=rand()%100;
            if(x<25){
                ggd--;
                direction='u';
            }
            else if(x<50){
                ggd++;
                direction='d';
            }
            else if(x<75){
                ggr++;
                direction='r';
            }
            else if(x<100){
                ggr--;
                direction='l';
            }
        }while(maze[ggd][ggr]==char(219));
    }
    if(back[gd][gr]==1){
        maze[gd][gr]=char(249);
    }
    else{
        maze[gd][gr]=' ';
    }
    gd=ggd;
    gr=ggr;
    if((maze[gd][gr]=='>')||(maze[gd][gr]=='<')||(maze[gd][gr]=='^')||(maze[gd][gr]=='v')){
       g='g';
    }
    maze[gd][gr]='M';
}

void ghost2(int &gd, int &gr, char &g, int pd, int pr){
    int ggd=gd;
    int ggr=gr;
    int y;
    y=rand()%5;
    if(y==0){
        direction='q';
    }
    if((direction=='u')&&(maze[ggd-1][ggr]!=char(219))){
        ggd--;
        direction='u';
    }
    else if((direction=='d')&&(maze[ggd+1][ggr]!=char(219))){
        ggd++;
        direction='d';
    }
    else if((direction=='l')&&(maze[ggd][ggr-1]!=char(219))){
        ggr--;
        direction='l';
    }
    else if((direction=='r')&&(maze[ggd][ggr+1]!=char(219))){
        ggr++;
        direction='r';
    }
    else{
    for(int m=0;m<19;m++){
        for(int n=0;n<20;n++){
            if(maze[m][n]==char(219)){
                darray[m][n]=1111;
            }
            else if((maze[m][n]=='>')||(maze[m][n]=='<')||(maze[m][n]=='v')||(maze[m][n]=='^')){
                darray[m][n]=0;
            }
            else{
                darray[m][n]=9999;
            }
        }
    }
    int control=0;
    while(darray[gd][gr]==9999){
        for(int b=0;b<19;b++){
            for(int v=0;v<20;v++){
                if(darray[b][v]==control){
                    if(darray[b-1][v]==9999){
                        darray[b-1][v]=control+1;
                    }
                    if(darray[b+1][v]==9999){
                        darray[b+1][v]=control+1;
                    }
                    if(darray[b][v-1]==9999){
                        darray[b][v-1]=control+1;
                    }
                    if(darray[b][v+1]==9999){
                        darray[b][v+1]=control+1;
                    }
                }
            }
        }
        control++;
    }
    if(darray[ggd-1][ggr]==control-1){
        ggd--;
        direction='u';
    }
    else if(darray[ggd+1][ggr]==control-1){
        ggd++;
        direction='d';
    }
    else if(darray[ggd][ggr-1]==control-1){
        ggr--;
        direction='l';
    }
    else if(darray[ggd][ggr+1]==control-1){
        ggr++;
        direction='r';
    }
    }
     if(back[gd][gr]==1){
        maze[gd][gr]=char(249);
    }
    else{
        maze[gd][gr]=' ';
    }
    gd=ggd;
    gr=ggr;
    if((maze[gd][gr]=='>')||(maze[gd][gr]=='<')||(maze[gd][gr]=='^')||(maze[gd][gr]=='v')){
       g='g';
    }
    maze[gd][gr]='M';

}

void ghost3(int &gd, int &gr, char &g, int pd, int pr){
    for(int m=0;m<19;m++){
        for(int n=0;n<20;n++){
            if(maze[m][n]==char(219)){
                darray[m][n]=1111;
            }
            else if((maze[m][n]=='>')||(maze[m][n]=='<')||(maze[m][n]=='v')||(maze[m][n]=='^')){
                darray[m][n]=0;
            }
            else{
                darray[m][n]=9999;
            }
        }
    }
    int control=0;
    while(darray[gd][gr]==9999){
        for(int b=0;b<19;b++){
            for(int v=0;v<20;v++){
                if(darray[b][v]==control){
                    if(darray[b-1][v]==9999){
                        darray[b-1][v]=control+1;
                    }
                    if(darray[b+1][v]==9999){
                        darray[b+1][v]=control+1;
                    }
                    if(darray[b][v-1]==9999){
                        darray[b][v-1]=control+1;
                    }
                    if(darray[b][v+1]==9999){
                        darray[b][v+1]=control+1;
                    }
                }
            }
        }
        control++;
    }
    if(back[gd][gr]==1){
        maze[gd][gr]=char(249);
    }
    else{
        maze[gd][gr]=' ';
    }
    if(darray[gd-1][gr]==control-1){
        gd--;
    }
    else if(darray[gd+1][gr]==control-1){
        gd++;
    }
    else if(darray[gd][gr-1]==control-1){
        gr--;
    }
    else if(darray[gd][gr+1]==control-1){
        gr++;
    }
    if((maze[gd][gr]=='>')||(maze[gd][gr]=='<')||(maze[gd][gr]=='^')||(maze[gd][gr]=='v')){
       g='g';
    }
    maze[gd][gr]='M';

}

int main(){
    char again;
    HANDLE hColor;
    hColor=GetStdHandle(STD_OUTPUT_HANDLE);
    srand(time(NULL));
    char gg;
    int points=0;
    int dif;
    do{
    points=0;
    SetConsoleTextAttribute(hColor,14);
    cout<<"Enter difficulty level [ 1 | 2 | 3 ]\n>>>";
    cin>>dif;
    system("cls");

    for(int m=0;m<19;m++){
        for(int n=0;n<20;n++){
            maze[m][n]=char(249);
        }
    }


    //place maze
    for(int e=0;e<19;e++){
        for(int r=0;r<20;r++){
            if((r==0)||(r==19)||(e==0)||(e==18)){
               maze[e][r]=char(219);
            }
            else{
                maze[e][r]=char(249);
            }
        }
    }

    for(int y=0;y<18;y++){
        for(int u=0;u<20;u++){
            back[y][u]=1;
        }
    }


    for(int t=0;t<1;t++){
        back[9][10]=1;
        maze[9][10]='M';
        maze[17][18]='>';
        back[17][18]=0;
        maze[2][2]=char(219);
        maze[2][3]=char(219);
        maze[2][4]=char(219);
        maze[2][17]=char(219);
        maze[2][16]=char(219);
        maze[2][15]=char(219);
        maze[3][2]=char(219);
        maze[4][2]=char(219);
        maze[16][2]=char(219);
        maze[15][2]=char(219);
        maze[14][2]=char(219);
        maze[3][17]=char(219);
        maze[4][17]=char(219);
        maze[16][17]=char(219);
        maze[15][17]=char(219);
        maze[14][17]=char(219);
        maze[16][16]=char(219);
        maze[16][15]=char(219);
        maze[16][3]=char(219);
        maze[16][4]=char(219);
        maze[9][8]=char(219);
        maze[8][8]=char(219);
        maze[10][8]=char(219);
        maze[10][9]=char(219);
        maze[10][10]=char(219);
        maze[10][11]=char(219);
        maze[1][8]=char(219);
        maze[1][9]=char(219);
        maze[1][10]=char(219);
        maze[1][11]=char(219);
        maze[17][8]=char(219);
        maze[17][9]=char(219);
        maze[17][10]=char(219);
        maze[17][11]=char(219);
        maze[9][11]=char(219);
        maze[8][11]=char(219);
        maze[5][7]=char(219);
        maze[5][8]=char(219);
        maze[5][9]=char(219);
        maze[5][10]=char(219);
        maze[5][11]=char(219);
        maze[5][12]=char(219);
        maze[13][7]=char(219);
        maze[13][8]=char(219);
        maze[13][9]=char(219);
        maze[13][10]=char(219);
        maze[13][11]=char(219);
        maze[13][12]=char(219);
        maze[7][5]=char(219);
        maze[8][5]=char(219);
        maze[9][5]=char(219);
        maze[10][5]=char(219);
        maze[11][5]=char(219);
        maze[7][1]=char(219);
        maze[8][1]=char(219);
        maze[9][1]=char(219);
        maze[10][1]=char(219);
        maze[11][1]=char(219);
        maze[7][14]=char(219);
        maze[8][14]=char(219);
        maze[9][14]=char(219);
        maze[10][14]=char(219);
        maze[11][14]=char(219);
        maze[7][18]=char(219);
        maze[8][18]=char(219);
        maze[9][18]=char(219);
        maze[10][18]=char(219);
        maze[11][18]=char(219);

    }


    for(int q=0;q<18;q++){
        for(int w=0;w<20;w++){
            if(maze[q][w]==char(249)){
                back[q][w]=1;
            }
        }
    }

    gg='m';
    int balld=17;
    int ballr=18;
    int ghostd=9;
    int ghostr=10;
    display(maze);
    cout<<endl;
    for(int i=0;i<19;i++){
        for(int j=0;j<20;j++){
            if((i==0)||(i==9)||(i==18)||(j==19)){
                cout<<char(219);
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
    Sleep(1000);
    system("cls");
    display(maze);
    cout<<endl;
    for(int i=0;i<19;i++){
        for(int j=0;j<20;j++){
            if((i==0)||(i==9)||(i==18)){
                cout<<char(219);
            }
            else if(((j==0)&&(i>9))||((j==19)&&(i<9))){
                cout<<char(219);
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
    Sleep(1000);
    system("cls");
    display(maze);
    cout<<endl;
    for(int i=0;i<19;i++){
        cout<<"          "<<char(219)<<endl;
    }
    Sleep(1000);
    system("cls");
    do{
        move(balld,ballr,points,gg);
        if(dif==1){
            ghost(ghostd,ghostr,gg);
        }
        else if(dif==2){
            ghost2(ghostd,ghostr,gg,balld,ballr);
        }
        else if(dif==3){
            ghost3(ghostd,ghostr,gg,balld,ballr);
        }
        system("cls");
        display(maze);
        Sleep(50);
        HANDLE hColor;
        hColor=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hColor,14);
        cout<<"SCORE: "<<points<<endl;

    }while((points!=237)&&(gg!='g'));
    system("cls");
    if(gg=='g'){
        cout<<"UH OH!\nYOU LOST!\n";
    }
    else if(points==237){
        HANDLE hColor;
        hColor=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hColor,14);
        cout<<"YAY!\nYOU WON!\n";
        cout<<"         _    _           \n";
    cout<<"        (_)  (_)          \n";
    cout<<"       __________         \n";
    cout<<"       \\________/        \n";
    cout<<endl;
    cout<<"  \\        /\\        /  \n";
    cout<<"   \\      /  \\      /   \n";
    cout<<"    \\    /    \\    /    \n";
    cout<<"     \\  /      \\  /     \n";
    cout<<"      \\/        \\/      \n";
    cout<<"       __________         \n";
    cout<<"      /          \\       \n";
    cout<<"     |            |       \n";
    cout<<"     |            |       \n";
    cout<<"      \\__________/       \n";
    cout<<"                          \n";
    cout<<"  \\        /\\        /  \n";
    cout<<"   \\      /  \\      /   \n";
    cout<<"    \\    /    \\    /    \n";
    cout<<"     \\  /      \\  /     \n";
    cout<<"      \\/        \\/      \n";
    }
    Sleep(1000);
    cout<<"Do you want to play again? [ y | n ]\n>>>";
    cin>>again;
    }while(again=='y');
}
