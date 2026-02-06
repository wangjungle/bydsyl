#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>
#include <string.h>

void draw_cake(int y, int x) {
    attron(COLOR_PAIR(1));
    mvprintw(y, x + 9,  "* * *");
    attroff(COLOR_PAIR(1));

    attron(COLOR_PAIR(2));
    mvprintw(y+1, x + 9, "|  |  |");
    attroff(COLOR_PAIR(2));

    attron(COLOR_PAIR(3));
    mvprintw(y+2, x + 5, " [*********]");
    mvprintw(y+3, x + 3, " [***********]");
    mvprintw(y+4, x + 1, "[***************]");
    attroff(COLOR_PAIR(3));
}

int main() {
    initscr();
    start_color();
    curs_set(0);
    noecho();

    init_pair(1, COLOR_YELLOW, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_WHITE, COLOR_BLACK);
    init_pair(4, COLOR_CYAN, COLOR_BLACK);

    int max_y, max_x;
    getmaxyx(stdscr, max_y, max_x);

    int start_y = max_y / 2 - 5;
    int start_x = max_x / 2 - 10;

    for (int i = 0; i < 100; i++) {
        clear();
        draw_cake(start_y, start_x);
        
        if (i % 2 == 0) mvprintw(start_y, start_x + 9, ".  .  .");
        
        attron(COLOR_PAIR(4) | A_BOLD);
        const char* msg = "HAPPY BIRTHDAY,SYL!";
        mvprintw(start_y + 6, (max_x - strlen(msg)) / 2, "%s", msg);
        attroff(COLOR_PAIR(4));

        refresh();
        usleep(300000);
    }

    attron(A_BLINK);
    mvprintw(max_y - 2, (max_x - 20) / 2, "Press any key to exit");
    refresh();
    getch();
    endwin();

    return 0;
}