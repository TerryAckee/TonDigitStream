#include <ncurses.h>
#include <math.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#define DELAY 50000 

int main() {
    initscr();
    noecho();
    curs_set(FALSE);
    keypad(stdscr, TRUE);
    timeout(0);
    start_color();
    
    // Pair 1: Bright Green, Pair 2: White, Pair 3: Dim Green
    init_pair(1, COLOR_GREEN, COLOR_BLACK); 
    init_pair(2, COLOR_WHITE, COLOR_BLACK); 
    init_pair(3, COLOR_GREEN, COLOR_BLACK); 

    int rows, cols;
    getmaxyx(stdscr, rows, cols);

    double angle = 0.0;
    int drift = 0;
    int frame_counter = 0;
    char lead_digit = '0';

    srand(time(NULL));
    int ch;

    while ((ch = getch()) != 'q') {
        if (ch == KEY_RESIZE) {
            clear(); 
            getmaxyx(stdscr, rows, cols);
        }

        // Hard clear ensures no "staining" or trails
        clear(); 

        int center_y = rows / 2;
        int center_x = cols / 2;
        int radius = rows / 4;

        // 1. Calculate the Lead Position (Single Point)
        int cur_x = (center_x + (int)(radius * 2.0 * cos(angle)) + drift) % cols;
        int cur_y = (center_y + (int)(radius * sin(angle))) % rows;
        
        // Handle wrapping for negative results
        if (cur_x < 0) cur_x += cols;
        if (cur_y < 0) cur_y += rows;

        // 2. Draw the "Whisp" Tail (3 Green Digits tethered behind)
        for (int i = 1; i <= 3; i++) {
            double tail_angle = angle - (i * 0.12);
            int tail_drift = drift - i;
            
            int tx = (center_x + (int)(radius * 2.0 * cos(tail_angle)) + tail_drift) % cols;
            int ty = (center_y + (int)(radius * sin(tail_angle))) % rows;
            
            if (tx < 0) tx += cols;
            if (ty < 0) ty += rows;

            if (i > 2) attron(COLOR_PAIR(3) | A_DIM);
            else attron(COLOR_PAIR(1));
            
            // Tail characters are random digits
            mvaddch(ty, tx, (rand() % 10) + '0');
            
            if (i > 2) attroff(COLOR_PAIR(3) | A_DIM);
            else attroff(COLOR_PAIR(1));
        }

        // 3. Update and Draw the Single White Lead Digit
        // Changes digit every 10 frames for a smoother transition
        if (frame_counter % 10 == 0) {
            lead_digit = (rand() % 10) + '0';
        }

        attron(COLOR_PAIR(2) | A_BOLD);
        mvaddch(cur_y, cur_x, lead_digit);
        attroff(COLOR_PAIR(2) | A_BOLD);

        refresh();
        
        angle += 0.04; 
        drift++;
        frame_counter++; 
        usleep(DELAY);
    }

    endwin();
    return 0;
}
