#ifndef __TICTACTOE_PROCESS
#define __TICTACTOE_PROCESS
#define cls() system("cls")

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
            if(board[0]!= X && board[0]!= O){
                board[0] = turn;
                barr[0] += board[0];
                barr[3] += board[0];
                barr[6] += board[0]; 
            }
            else return 0;
            break;
        case 'w':
            if(board[1]!= X && board[1]!= O){
                board[1] = turn;
                barr[1] += board[1]; 
                barr[3] += board[1];
            }
            else return 0;
            break;
        case 'e':
            if(board[2]!= X && board[2]!= O){
                board[2] = turn;
                barr[2] += board[2]; 
                barr[3] += board[2]; 
                barr[7] += board[2]; 
            } 
            else return 0;
            break;
        case 'a':
            if(board[3]!= X && board[3]!= O){
                board[3] = turn;
                barr[0] += board[3];
                barr[4] += board[3];
            }
            else return 0;
            break;
        case 's':
            if(board[4]!= X && board[4]!= O){
                board[4] = turn;
                barr[1] += board[4];
                barr[4] += board[4];
                barr[6] += board[4]; 
                barr[7] += board[4];
            }
            else return 0;
            break;
        case 'd':
            if(board[5]!= X && board[5]!= O){
                board[5] = turn;
                barr[2] += board[5];
                barr[4] += board[5];
            }
            else return 0;
            break;
        case 'z':
            if(board[6]!= X && board[6]!= O){
                board[6] = turn;
                barr[0] += board[6];
                barr[5] += board[6];
                barr[7] += board[6]; 
            }
            else return 0;
            break;
        case 'x':
            if(board[7]!= X && board[7]!= O){
                board[7] = turn;
                barr[1] += board[7];
                barr[5] += board[7];
            }
            else return 0;
            break;
        case 'c':
            if(board[8]!= X && board[8]!= O){
                board[8] = turn;
                barr[2] += board[8];
                barr[5] += board[8];
                barr[6] += board[8]; 
            }
            else return 0;
            break;
        default:
            return 0;
    }
}

int8 updateval(int8 *board, int8 *barr, int8 turn, char val){
    if(!boardlogic(board, barr, turn, val)) return 9;
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
    for(int8 i=0; i<11; i++){
        strc(strmat+(i*28), 28, temp, 28);
        puts(temp);
    }
}

void updateboard(char *strmat, int8 x, char val){
    char c;
    if(x==X) c = 'X';
    else if(x==O) c ='O'; 
    switch(val){
        case 'q':
            if(strmat[61]!= 'X' && strmat[61]!= 'O') *(strmat+2*28+5) = c;
            break;
        case 'w':
            if(strmat[69]!= 'X' && strmat[69]!= 'O') *(strmat+2*28+13) = c;
            break;
        case 'e':
            if(strmat[77]!= 'X' && strmat[77]!= 'O') *(strmat+2*28+21) = c;
            break;
        case 'a':
            if(strmat[145]!= 'X' && strmat[145]!= 'O') *(strmat+5*28+5) = c;
            break;
        case 's':
            if(strmat[153]!= 'X' && strmat[153]!= 'O') *(strmat+5*28+13) = c;
            break;
        case 'd':
            if(strmat[161]!= 'X' && strmat[161]!= 'O') *(strmat+5*28+21) = c;
            break;
        case 'z':
            if(strmat[229]!= 'X' && strmat[229]!= 'O') *(strmat+8*28+5) = c;
            break;
        case 'x':
            if(strmat[237]!= 'X' && strmat[237]!= 'O') *(strmat+8*28+13) = c;
            break;
        case 'c':
            if(strmat[245]!= 'X' && strmat[245]!= 'O') *(strmat+8*28+21) = c;
            break;
    }
}

int8 game(){
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
    boardprint((char*)boardf);
    for(int8 i=0; i<9; i++){
        //for(int il=0; il<8; il++) 
        printf("%d ", i);
        if(cst==1||cst==-1) break;
        printf("\nEnter Your Move: ");
        char v;
        scanf(" %c", &v);
        cst = updateval((int8*)board, (int8*)bste, pturn, v);
        if(cst==9 && i<9) i--;
        else{
            updateboard((char*)boardf, pturn, v);
            cls();
            boardprint((char*)boardf);
            pturn = -pturn;
        }
    }
    if(cst==1) printf("\n> player 'X' won\n");
    else if(cst==-1) printf("\n> player 'O' won\n");
    else printf("> draw!\n");
}

#endif