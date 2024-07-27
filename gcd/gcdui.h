#ifndef __GDC_UI_
#define __GDC_UI_
#define cls() system("cls")

void wlcmscr(){
    cls();
    char buf[50] ="Welcome to The GDC/LCM Calculator!";
    printf("\n\n\t\t");
    for (int i=0; buf[i]!='\0'; i++){
        printf("%c", buf[i]);
        fflush(stdout);
        usleep(200000);
    }
    
}

void fscr(){
    cls();
    puts("\n\t\x1b[38;5;45m ________  ________  _________  ___  ________  ________   ________       \x1b[0m");
    puts("\t\x1b[38;5;245m|\x1b[38;5;45m\\   __  \\\x1b[38;5;245m|\x1b[38;5;45m\\   __  \\\x1b[38;5;245m|\x1b[38;5;45m\\____   __\\\\  \\\x1b[38;5;245m|\x1b[38;5;45m\\   __  \\\x1b[38;5;245m|\x1b[38;5;45m\\   ___  \\\x1b[38;5;245m|\x1b[38;5;45m\\   ____\\      \x1b[0m");
    puts("\t\x1b[38;5;245m\\ \x1b[38;5;45m\\  \\\x1b[38;5;245m|\x1b[38;5;45m\\  \\ \\  \\\x1b[38;5;245m|\x1b[38;5;45m\\  \\\x1b[38;5;245m|___ \x1b[38;5;45m\\  \\\x1b[38;5;245m_\\ \x1b[38;5;45m\\  \\ \\  \\\x1b[38;5;245m|\x1b[38;5;45m\\  \\ \\  \\\x1b[38;5;245m\\ \x1b[38;5;45m\\  \\ \\  \\___\x1b[38;5;245m|\x1b[38;5;45m_     \x1b[0m");
    puts("\t \x1b[38;5;245m\\ \x1b[38;5;45m\\  \\\x1b[38;5;245m\\\x1b[38;5;45m\\  \\ \\   ____\\\x1b[38;5;245m   \\ \x1b[38;5;45m\\  \\\x1b[38;5;245m \\ \x1b[38;5;45m\\  \\ \\  \\\x1b[38;5;245m\\\x1b[38;5;45m\\  \\ \\  \\\x1b[38;5;245m\\ \x1b[38;5;45m\\  \\ \\_____  \\    \x1b[0m");
    puts("\t  \x1b[38;5;245m\\ \x1b[38;5;45m\\  \\\x1b[38;5;245m\\\x1b[38;5;45m\\  \\ \\  \\\x1b[38;5;245m___|    \\ \x1b[38;5;45m\\  \\\x1b[38;5;245m \\ \x1b[38;5;45m\\  \\ \\  \\\x1b[38;5;245m\\\x1b[38;5;45m\\  \\ \\  \\\x1b[38;5;245m\\ \x1b[38;5;45m\\  \\\x1b[38;5;245m|____|\x1b[38;5;45m\\  \\   \x1b[0m");
    puts("\t   \x1b[38;5;245m\\ \x1b[38;5;45m\\_______\\ \\__\\        \x1b[38;5;245m\\ \x1b[38;5;45m\\__\\\x1b[38;5;245m \\ \x1b[38;5;45m\\__\\ \\_______\\ \\__\\\x1b[38;5;245m\\ \x1b[38;5;45m\\__\\____\x1b[38;5;245m\\\x1b[38;5;45m_\\  \\  \x1b[0m");
    puts("\t    \x1b[38;5;245m\\|_______|\\|__|         \\|__|  \\|__|\\|_______|\\|__| \\|__|\x1b[38;5;45m\\_________\\ \x1b[0m");
    puts("\t                                                            \x1b[38;5;245m\\|_________| \x1b[0m");
}

void gcdscr(){
    cls();
    puts("\n\t\t\x1b[38;5;45m    ________      ________      ________         \x1b[0m");
    puts("\t\t\x1b[38;5;245m   |\x1b[38;5;45m\\   ____\\\x1b[38;5;245m    |\x1b[38;5;45m\\   ____\\\x1b[38;5;245m    |\x1b[38;5;45m\\   ___ \\        \x1b[0m");
    puts("\t\t\x1b[38;5;245m   \\ \x1b[38;5;45m\\  \\\x1b[38;5;245m___|    \\ \x1b[38;5;45m\\  \\\x1b[38;5;245m___|    \\ \x1b[38;5;45m\\  \\\x1b[38;5;245m_|\x1b[38;5;45m\\ \\       \x1b[0m");
    puts("\t\t\x1b[38;5;245m    \\ \x1b[38;5;45m\\  \\  ___   \x1b[38;5;245m\\ \x1b[38;5;45m\\  \\        \x1b[38;5;245m\\ \x1b[38;5;45m\\  \\ \x1b[38;5;245m\\\x1b[38;5;45m\\ \\      \x1b[0m");
    puts("\t\t\x1b[38;5;245m     \\ \x1b[38;5;45m\\  \\\x1b[38;5;245m|\x1b[38;5;45m\\  \\ __\x1b[38;5;245m\\ \x1b[38;5;45m\\  \\____  __\x1b[38;5;245m\\ \x1b[38;5;45m\\  \\_\x1b[38;5;245m\\\x1b[38;5;45m\\ \\ ___ \x1b[0m");
    puts("\t\t\x1b[38;5;245m      \\ \x1b[38;5;45m\\_______\\\\__\\ \\_______\\\\__\\ \\_______\\\\__\\\x1b[0m");
    puts("\t\t\x1b[38;5;245m       \\|_______\\|__|\\|_______\\|__|\\|_______\\|__|\x1b[0m\n");
}

void lcmscr(){
    cls();
    puts("\n\t\t\x1b[38;5;45m    ___           ________      _____ ______         \x1b[0m");
    puts("\t\t\x1b[38;5;245m   |\x1b[38;5;45m\\  \\\x1b[38;5;245m         |\x1b[38;5;45m\\   ____\\\x1b[38;5;245m    |\x1b[38;5;45m\\   _ \\  _   \\        \x1b[0m");
    puts("\t\t\x1b[38;5;245m   \\ \x1b[38;5;45m\\  \\\x1b[38;5;245m        \\ \x1b[38;5;45m\\  \\\x1b[38;5;245m___|    \\ \x1b[38;5;45m\\  \\\x1b[38;5;245m\\\x1b[38;5;45m\\__\\ \\  \\       \x1b[0m");
    puts("\t\t\x1b[38;5;245m    \\ \x1b[38;5;45m\\  \\\x1b[38;5;245m        \\ \x1b[38;5;45m\\  \\\x1b[38;5;245m        \\ \x1b[38;5;45m\\  \\\x1b[38;5;245m\\|__| \x1b[38;5;45m\\  \\      \x1b[0m");
    puts("\t\t\x1b[38;5;245m     \\ \x1b[38;5;45m\\  \\____  __\x1b[38;5;245m\\ \x1b[38;5;45m\\  \\____  __\x1b[38;5;245m\\ \x1b[38;5;45m\\  \\\x1b[38;5;245m    \\ \x1b[38;5;45m\\  \\ ___ \x1b[0m");
    puts("\t\t\x1b[38;5;245m      \\ \x1b[38;5;45m\\_______\\\\__\\ \\_______\\\\__\\ \\__\\    \x1b[38;5;245m\\ \x1b[38;5;45m\\__\\\\__\\\x1b[0m");
    puts("\t\t\x1b[38;5;245m       \\|_______\\|__|\\|_______\\|__|\\|__|     \\|__\\|__|\x1b[0m\n");
}

void inverr(){
    printf("\n\t\t\t\t\t\033[1;91mINVALID INPUT!\033[0m");
    sleep(1);
}

void endscr(){
    printf("\n\t\t\t\t\t\033[1;91mTERMINATING!\033[0m");
    sleep(1);
    cls();
}
#endif