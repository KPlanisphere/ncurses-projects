# Ncurses Projects in C

## Description
This project contains a series of C programs that utilize the ncurses library to create text-based user interfaces. These programs demonstrate various features of ncurses such as window management, color manipulation, and handling user input. Each file showcases different aspects of ncurses programming, providing a comprehensive overview of its capabilities.

### Key Features
- **Ncurses Initialization**: Examples of initializing ncurses, setting up windows, and ending ncurses mode.
- **Color Handling**: Demonstrations of initializing color pairs and applying them to text and backgrounds.
- **User Input**: Handling user input, including masked input for password fields.
- **Window Management**: Creating and managing multiple windows within the terminal screen.

### Files
1. **A1P2.c**
    - Demonstrates basic ncurses setup and text display.
    - **Key Code Snippet**:
        ```c
        #include <ncurses.h>

        int main() {
            initscr();
            move(10, 12);
            printw("Hola linux");
            refresh();
            getch();
            endwin();
            return 0;
        }
        ```
        This code initializes ncurses, moves the cursor to a specified position, prints a message, waits for user input, and then ends ncurses mode.

2. **A2P2.c**
    - Illustrates the use of colors and text attributes in ncurses.
    - **Key Code Snippet**:
        ```c
        #include <stdlib.h>
        #include <ncurses.h>
        #include <errno.h>
        #include <unistd.h>

        int main() {
            initscr();
            start_color();
            init_pair(1, COLOR_BLUE, COLOR_YELLOW);
            init_pair(2, COLOR_RED, COLOR_YELLOW);
            bkgd(COLOR_PAIR(2));
            attron(COLOR_PAIR(1) | A_UNDERLINE);
            move(10, 40);
            attron(A_REVERSE);
            printw("HOLA MUNDO");
            getch();
            endwin();
            exit(0);
        }
        ```
        This code initializes ncurses, sets up color pairs, applies text attributes, and displays a message with reversed and underlined text.

3. **A3P2.c**
    - Focuses on window management, user input handling, and masked input for passwords.
    - **Key Code Snippet**:
        ```c
        #include <stdlib.h>
        #include <ncurses.h>
        #include <errno.h>
        #include <unistd.h>

        int main() {
            int c, i = 0;
            int xmax, ymax;
            char cadena[80];
            WINDOW *punt_ven;

            initscr();
            getmaxyx(stdscr, ymax, xmax);
            if (has_colors())
                start_color();
            init_pair(1, COLOR_RED, COLOR_GREEN);
            attron(COLOR_PAIR(1));
            punt_ven = subwin(stdscr, 3, 40, 8, 20);
            box(punt_ven, ACS_VLINE, ACS_HLINE);
            mvwaddstr(punt_ven, 1, 1, "Contraseña: ");
            noecho();

            while ((c = getch()) != '\n' && i < 80) {
                cadena[i++] = c;
                waddch(punt_ven, '*');
                wrefresh(punt_ven);
            }

            echo();
            cadena[i] = '\0';
            mvwprintw(punt_ven, 1, 1, "El Password es %s\n", cadena);
            wrefresh(punt_ven);
            sleep(3);
            delwin(punt_ven);
            endwin();
            return 0;
        }
        ```
        This code demonstrates creating a subwindow, handling user input with masking for passwords, and displaying the entered password after input is complete.

## How to Use
1. **Compilation**: Each C file can be compiled using a C compiler such as `gcc`.
    ```bash
    gcc A1P2.c -o A1P2 -lncurses
    ```
2. **Execution**: Run the compiled programs to see the output of the ncurses operations.
    ```bash
    ./A1P2
    ```