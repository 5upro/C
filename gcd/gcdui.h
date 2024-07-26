#define cls() system("cls")

void fmsg(){
    cls();
    puts("\033[1;91m\n\t   @@@@@@@@         @@@@@@       @@@@@@@     \n\t  @@      @@       @@    @@      @@    @@    \n\t @@               @@             @@     @@   \n\t @@               @@             @@     @@   \n\t @@    @@@@@      @@             @@     @@   \n\t  @@      @@  @@   @@    @@  @@  @@    @@  @@\n\t   @@@@@@@@   @@    @@@@@@   @@  @@@@@@@   @@ \n\033[0m");
        
}

void endscr(){
    printf("\n\t\t\t\033[1;91mTERMINATING!\033[0m");
    sleep(1);
    cls();
}