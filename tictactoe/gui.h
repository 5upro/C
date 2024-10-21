#ifndef __TICTACTOE_GUI_
#define __TICTACTOE_GUI_

#define cls() system("cls")
#define endl "\n"

void wlcmscr(){
    cls();
    char buf[50] ="Welcome to The Tic Tac Toe Player!";
    printf("\n\n\t\t");
    for (int i=0; buf[i]!='\0'; i++){
        printf("%c", buf[i]);
        fflush(stdout);
        usleep(200000);
    }
}
void frntscr(){
    puts(
        "\n\n\n\t                          \x1b[38;5;245m,----\x1b[38;5;45m.." endl
        "\t\x1b[38;5;9m ,\x1b[38;5;245m--,     \x1b[38;5;9m,--,          \x1b[38;5;245m /   \x1b[38;5;45m/   \\\x1b[0m" endl
        "\t\x1b[38;5;9m |'. \x1b[38;5;245m\\   \x1b[38;5;9m/ .`\x1b[38;5;245m|          /   \x1b[38;5;45m.     :" endl
        "\t\x1b[38;5;9m ; \\ \x1b[38;5;245m`\\ \x1b[38;5;9m/' / \x1b[38;5;245m;         .\x1b[38;5;45m   /   ;.  \\" endl
        "\t\x1b[38;5;9m `. \\  /  / \x1b[38;5;245m.'        \x1b[38;5;245m.   \x1b[38;5;45m;   /  \x1b[38;5;45m` ;" endl
        "\t\x1b[38;5;9m  \\  \\/  / \x1b[38;5;245m./         \x1b[38;5;245m;   \x1b[38;5;45m|  ; \x1b[38;5;245m\\ \x1b[38;5;45m; |" endl
        "\t\x1b[38;5;9m   \\  \\.' \x1b[38;5;245m /          \x1b[38;5;245m|   \x1b[38;5;45m:  | \x1b[38;5;245m; \x1b[38;5;45m| '" endl
        "\t\x1b[38;5;9m    \\  ;  \x1b[38;5;245m;           \x1b[38;5;245m.   \x1b[38;5;45m|  ' \x1b[38;5;245m' \x1b[38;5;45m' :" endl
        "\t\x1b[38;5;9m   / \\  \\  \x1b[38;5;245m\\          \x1b[38;5;245m'   \x1b[38;5;45m;  \\\x1b[38;5;45m\x1b[38;5;245m; \x1b[38;5;45m/  |" endl
        "\t\x1b[38;5;9m  ;  /\\  \\  \x1b[38;5;245m\\          \x1b[38;5;245m\\   \x1b[38;5;45m\\  ',  / " endl
        "\t\x1b[38;5;9m./__;  \\  ;  \x1b[38;5;245m\\          \x1b[38;5;245m;   \x1b[38;5;45m:    /  " endl
        "\t\x1b[38;5;9m|   : \x1b[38;5;245m/ \x1b[38;5;9m\\  \\  \x1b[38;5;245m;          \x1b[38;5;245m\\   \x1b[38;5;45m\\ .'   " endl
        "\t\x1b[38;5;9m;   |\x1b[38;5;245m/   \x1b[38;5;9m\\  ' \x1b[38;5;245m|           `---\x1b[38;5;45m`     " endl
        "\t\x1b[38;5;9m`---'     `--`                      \x1b[0m\n" endl
        "\t\t  OPTIONS:\n\t\t   01. PLAY\n\t\t   02. EXIT");
    printf("\t\t  > "); 
}

void endscr(){
    printf("\n\t\t\033[1;91mTERMINATING!\033[0m");
    sleep(1);
    cls();
}

void errtxt(){
    printf("\n\t\t\033[1;91mINVALID INPUT!\033[0m");
    sleep(1);
    cls();
}

#endif