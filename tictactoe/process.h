#ifndef __TICTACTOE_PROCESS
#define __TICTACTOE_PROCESS

typedef signed char int8;
typedef short int16;
typedef int int32;

enum{
    X = 1,
    O = -1,
    _ = 0,
};

int8 selfcmp(const char *a, const char *b){
    int i=0;
    while(a[i]!='\0'&& b[i]!='\0'){
        if(!(a[i]==b[i])) return 0;
        i++;
    }
    return 1;
}

int8 boardlogic(int8 *board, int8 *barr, int8 turn, char val){
    switch(val){
        case 'q':
            if(board[0] == _){
                board[0] = turn;
                barr[0] += turn;
                barr[3] += turn;
                barr[6] += turn; 
            }
            else return 0;
            break;
        case 'w':
            if(board[1] == _){
                board[1] = turn;
                barr[1] += turn; 
                barr[3] += turn;
            }
            else return 0;
            break;
        case 'e':
            if(board[2] == _){
                board[2] = turn;
                barr[2] += turn; 
                barr[3] += turn; 
                barr[7] += turn; 
            } 
            else return 0;
            break;
        case 'a':
            if(board[3] == _){
                board[3] = turn;
                barr[0] += turn;
                barr[4] += turn;
            }
            else return 0;
            break;
        case 's':
            if(board[4] == _){
                board[4] = turn;
                barr[4] += turn;
                barr[1] += turn;
                barr[6] += turn; 
                barr[7] += turn;
            }
            else return 0;
            break;
        case 'd':
            if(board[5] == _){
                board[5] = turn;
                barr[2] += turn;
                barr[4] += turn;
            }
            else return 0;
            break;
        case 'z':
            if(board[6] == _){
                board[6] = turn;
                barr[0] += turn;
                barr[5] += turn;
                barr[7] += turn; 
            }
            else return 0;
            break;
        case 'x':
            if(board[7] == _){
                board[7] = turn;
                barr[1] += turn;
                barr[5] += turn;
            }
            else return 0;
            break;
        case 'c':
            if(board[8] == _){
                board[8] = turn;
                barr[2] += turn;
                barr[5] += turn;
                barr[6] += turn; 
            }
            else return 0;
            break;
        default:
            return 0;
    }
}

int8 updateval(int8 *board, int8 *barr, int8 turn, char val){
    if(!boardlogic(board, barr, turn, val)) return 9; //here 9 represent an error value
    for(int i=0; i<8; i++){
        if(barr[i]==3) return 1;
        if(barr[i]==-3) return -1;
    }
    return 0;
}

int8 strc(char *basestr, int16 len0, char *cpystr, int16 len1){
    if(len0<=len1){
        for(int i=0; i<28; i++) *(cpystr+i) = *(basestr+i);
        return 0;
    }
    else return 1;
}

void boardprint(char *strmat){
    char temp[28];
    puts("");
    for(int8 i=0; i<11; i++){
        strc(strmat+(i*28), 28, temp, 28);
        printf("\t ");
        puts(temp);
    }
}

void updateboard(char *strmat, int8 x, char val){
    char c = (x==X) ? 'X' : 'O';
    void invalupdate(char *ptr, char vc){
        if(*ptr==' ') *ptr = vc;
    }
    switch(val){
        case 'q':
            invalupdate((strmat+61), c);
            break;
        case 'w':
            invalupdate((strmat+69), c);
            break;
        case 'e':
            invalupdate((strmat+77), c);
            break;
        case 'a':
            invalupdate((strmat+145), c);
            break;
        case 's':
            invalupdate((strmat+153), c);
            break;
        case 'd':
            invalupdate((strmat+161), c);
            break;
        case 'z':
            invalupdate((strmat+229), c);
            break;
        case 'x':
            invalupdate((strmat+237), c);
            break;
        case 'c':
            invalupdate((strmat+245), c);
            break;
    }
}

void prtTurn(int8 x){
    printf("\t\t  %c\'s Turn\n", x==1 ? 'X' : 'O');
}

void finres(int8 x){
    if(x==0) printf("\n\t\t  DRAW!\n");
    else printf("\n\t\t  %c WON!\n", x==1 ? 'X' : 'O');
}

int8 rnd(){
    int8 pturn=1, cst=0, bste[8] = {0};
    int8 board[3][3] ={
        {_, _, _},
        {_, _, _},
        {_, _, _},
    };
    char boardf[11][28] = {
        "",
        "         |       |         ",
        "         |       |         ",
        "  _______|_______|_______  ",
        "         |       |         ",
        "         |       |         ",
        "  _______|_______|_______  ",
        "         |       |         ",
        "         |       |         ",
        "         |       |         ",
        ""
    };
    prtTurn(pturn);
    boardprint((char*)boardf);
    
    for(int8 i=0; i<9; i++){
        //for(int il=0; il<8; il++)
        //printf("%d ", i);
        if(cst==1||cst==-1) break;
        printf("\n\t\t %c\'s Move: ", pturn==1 ? 'X' : 'O');
        char v;
        scanf(" %c", &v);
        cst = updateval((int8*)board, (int8*)bste, pturn, v);
        if(cst==9 && i<9){
            i--;
            cls();
            prtTurn(pturn);
            boardprint((char*)boardf);
        }
        else{
            updateboard((char*)boardf, pturn, v);
            cls();
            pturn = -pturn;
            prtTurn(pturn);
            boardprint((char*)boardf);
        }
    }
    finres(cst);
} 

int8 game(){
    int8 rval=9;
    while(1){
        cls();
        rnd();
        char buf[10];
        printf("\t\t  > ");
        fflush(stdin);
        fgets(buf, 10, stdin);
        if(selfcmp(buf,"exit")){
            rval = 0;
            break;
        }
        else if(selfcmp(buf,"back")){
            rval = 1;
            break;
        }
        else if(buf[0] == 0x0A){
            continue;
        }
        else{
            errtxt();
            cls();
        }
    }
    return rval;
}

#endif