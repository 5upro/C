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

int8 updateval(int8 *board, int8 turn, char val){
    if(turn==X){
        switch(val){
            case 'q':
                if(*(board+0)!= X && *(board+0)!= O) *(board+0) = X;
                break;
            case 'w':
                if(*(board+1)!= X && *(board+1)!= O) *(board+1) = X;
                break;
            case 'e':
                if(*(board+2)!= X && *(board+2)!= O) *(board+2) = X;
                break;
            case 'a':
                if(*(board+3)!= X && *(board+3)!= O) *(board+3) = X;
                break;
            case 's':
                if(*(board+4)!= X && *(board+4)!= O) *(board+4) = X;
                break;
            case 'd':
                if(*(board+5)!= X && *(board+5)!= O) *(board+5) = X;
                break;
            case 'z':
                if(*(board+6)!= X && *(board+6)!= O) *(board+6) = X;
                break;
            case 'x':
                if(*(board+7)!= X && *(board+7)!= O) *(board+7) = X;
                break;
            case 'c':
                if(*(board+8)!= X && *(board+8)!= O) *(board+8) = X;
                break;
        }
    }
    else if(turn==O){
        switch(val){
            case 'q':
                if(*(board+0)!= X && *(board+0)!= O) *(board+0) = -1;
                break;
            case 'w':
                if(*(board+1)!= X && *(board+1)!= O) *(board+1) = -1;
                break;
            case 'e':
                if(*(board+2)!= X && *(board+2)!= O) *(board+2) = -1;
                break;
            case 'a':
                if(*(board+3)!= X && *(board+3)!= O) *(board+3) = -1;
                break;
            case 's':
                if(*(board+4)!= X && *(board+4)!= O) *(board+4) = -1;
                break;
            case 'd':
                if(*(board+5)!= X && *(board+5)!= O) *(board+5) = -1;
                break;
            case 'z':
                if(*(board+6)!= X && *(board+6)!= O) *(board+6) = -1;
                break;
            case 'x':
                if(*(board+7)!= X && *(board+7)!= O) *(board+7) = -1;
                break;
            case 'c':
                if(*(board+8)!= X && *(board+8)!= O) *(board+8) = -1;
                break;
        }
    }
}

int8 state(int8 *board, int8 *barr){
    for(int x=0; x<3; x++){
        for(int y=0; y<3; y++){
            switch(x){
                case 0:
                    barr[3] += *(board+x*3+y);    
                    switch(y){
                        case 0:
                            barr[0] += *(board+x*3+y);
                            barr[6] += *(board+x*3+y);
                            break;
                        case 1:
                            barr[1] += *(board+x*3+y);
                            break;
                        case 2:
                            barr[2] += *(board+x*3+y);
                            barr[7] += *(board+x*3+y);
                            break;
                    }
                    break;
                case 1:
                    barr[4] += *(board+x*3+y);
                    switch(y){
                        case 0:
                            barr[0] += *(board+x*3+y);
                            break;
                        case 1:
                            barr[1] += *(board+x*3+y);
                            barr[6] += *(board+x*3+y);
                            barr[7] += *(board+x*3+y);
                            break;
                        case 2:
                            barr[2] += *(board+x*3+y);
                            break;
                    }
                    break;
                case 2:
                    barr[5] += *(board+x*3+y);
                    switch(y){
                        case 0:
                            barr[0] += *(board+x*3+y);
                            barr[7] += *(board+x*3+y);
                            break;
                        case 1:
                            barr[1] += *(board+x*3+y);
                            break;
                        case 2:
                            barr[2] += *(board+x*3+y);
                            barr[6] += *(board+x*3+y);
                            break;
                    }
                    break;
            }
        }
    }
    for(int i=0; i<8; i++){
        if(barr[i]==3) return 1;
        else if(barr[i]==-3) return -1; 
    }
    return 0;
}

int strc(char *basestr, int len0, char *cpystr, int len1){
    if(len0<=len1){
        for(int i=0; i<28; i++) *(cpystr+i) = *(basestr+i);
        return 0;
    }
    else return 1;
}

void boardprint(char *strmat){
    char temp[28];
    for(int i=0; i<11; i++){
        strc(strmat+(i*28), 28, temp, 28);
        puts(temp);
    }
}

void updateboard(char *strmat, int x, char val){
    if(x==X){
        switch(val){
            case 'q':
                if(*(strmat+2*28+5)!= 'X' && *(strmat+2*28+5)!= 'O') *(strmat+2*28+5) = 'X';
                break;
            case 'w':
                if(*(strmat+2*28+13)!= 'X' && *(strmat+2*28+13)!= 'O') *(strmat+2*28+13) = 'X';
                break;
            case 'e':
                if(*(strmat+2*28+21)!= 'X' && *(strmat+2*28+21)!= 'O') *(strmat+2*28+21) = 'X';
                break;
            case 'a':
                if(*(strmat+5*28+5)!= 'X' && *(strmat+5*28+5)!= 'O') *(strmat+5*28+5) = 'X';
                break;
            case 's':
                if(*(strmat+5*28+13)!= 'X' && *(strmat+5*28+13)!= 'O') *(strmat+5*28+13) = 'X';
                break;
            case 'd':
                if(*(strmat+5*28+21)!= 'X' && *(strmat+5*28+21)!= 'O') *(strmat+5*28+21) = 'X';
                break;
            case 'z':
                if(*(strmat+8*28+5)!= 'X' && *(strmat+8*28+5)!= 'O') *(strmat+8*28+5) = 'X';
                break;
            case 'x':
                if(*(strmat+8*28+13)!= 'X' && *(strmat+8*28+13)!= 'O') *(strmat+8*28+13) = 'X';
                break;
            case 'c':
                if(*(strmat+8*28+21)!= 'X' && *(strmat+8*28+21)!= 'O') *(strmat+8*28+21) = 'X';
                break;
        }
    }
    else if(x==O){
        switch(val){
            case 'q':
                if(*(strmat+2*28+5)!= 'X' && *(strmat+2*28+5)!= 'O') *(strmat+2*28+5) = 'O';
                break;
            case 'w':
                if(*(strmat+2*28+13)!= 'X' && *(strmat+2*28+13)!= 'O') *(strmat+2*28+13) = 'O';
                break;
            case 'e':
                if(*(strmat+2*28+21)!= 'X' && *(strmat+2*28+21)!= 'O') *(strmat+2*28+21) = 'O';
                break;
            case 'a':
                if(*(strmat+5*28+5)!= 'X' && *(strmat+5*28+5)!= 'O') *(strmat+5*28+5) = 'O';
                break;
            case 's':
                if(*(strmat+5*28+13)!= 'X' && *(strmat+5*28+13)!= 'O') *(strmat+5*28+13) = 'O';
                break;
            case 'd':
                if(*(strmat+5*28+21)!= 'X' && *(strmat+5*28+21)!= 'O') *(strmat+5*28+21) = 'O';
                break;
            case 'z':
                if(*(strmat+8*28+5)!= 'X' && *(strmat+8*28+5)!= 'O') *(strmat+8*28+5) = 'O';
                break;
            case 'x':
                if(*(strmat+8*28+13)!= 'X' && *(strmat+8*28+13)!= 'O') *(strmat+8*28+13) = 'O';
                break;
            case 'c':
                if(*(strmat+8*28+21)!= 'X' && *(strmat+8*28+21)!= 'O') *(strmat+8*28+21) = 'O';
                break;
        }
    }
}

void game(){
    int8 pturn = 1;
    int8 board[3][3] ={
        {X, O, _},
        {_, _, _},
        {_, _, _},
    };
    int8 bste[8] = {0};
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
    for(int8 i=0, st; i<=9; i++){
        st = state((int8*)board, (int8*)bste);
        cls();
        boardprint((char*)boardf);
        for(int il=0; il<8; il++) printf("%d ", bste[il]);
        printf("\nEnter Your Move: ", st);
        char v;
        scanf(" %c", &v);
        updateval((int8*)board, pturn, v);
        updateboard((char*)boardf, pturn, v);
        pturn = -pturn;
    }
}

#endif