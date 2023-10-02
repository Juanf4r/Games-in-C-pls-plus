#include<iostream>
#include<conio.h>
#include<Windows.h>

enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
Direction dir;
bool gameOver;
char start;
const int height = 20;
const int width = 20;
int headX, headY, fruitX, fruitY, score;
int tailx[100], taily[100];
int tail_len;

void setup();
void draw();
void input();
void logic();
void play();

int main() 
{
    std::cout << "\t-------------------------------" << std::endl;
    std::cout << "\t\t :Snake King:" << std::endl;
    std::cout << "\t-------------------------------" << std::endl;
    std::cout << "\tPress 's' to option: ";
    std::cin >> start;

    while (start != 'S' and start != 's' and start != 'N' and start != 'n')
    {
        std::cout << "\n\tError. Digit S or N\t"; Sleep(500); std::cin >> start;
    }

    play();
}

void setup() 
{
    gameOver = false;
    dir = STOP;
    headX = width / 2;
    headY = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
}

void draw() 
{
    system("cls");

    // Uper Border
    std::cout << "\t\t";
    for (int i = 0; i < width - 8; i++) 
    {
        std::cout << "||";
    }
    std::cout << std::endl;

    // Snake, fruit, space and side borders
    for (int i = 0; i < height; i++) 
    {
        for (int j = 0; j < width; j++) 
        {
            // left border
            if (j == 0) 
            {
                std::cout << "\t\t||";
            }
            // snake head
            if (i == headY && j == headX) 
            {
                std::cout << "O";
            }
            // fruit
            else if (i == fruitY && j == fruitX) 
            {
                std::cout << "*";
            }
            // space, snake tail
            else 
            {
                bool print = false;
                // tail
                for (int k = 0; k < tail_len; k++) 
                {
                    if (tailx[k] == j && taily[k] == i) 
                    {
                        std::cout << "o";
                        print = true;
                    }
                }
                // space
                if (!print) 
                {
                    std::cout << " ";
                }
            }
            // right border
            if (j == width - 1) 
            {
                std::cout << "||";
            }
        }
        std::cout << std::endl;
    }
    // Lower Border
    std::cout << "\t\t";
    for (int i = 0; i < width - 8; i++) 
    {
        std::cout << "||";
    }
    std::cout << std::endl;
    std::cout << "\t\t\tScore: " << score << std::endl;
}

void input() 
{
    if (_kbhit())
    switch (_getch())
    {
        case 'a':
            dir = LEFT;
            break;

        case 'd':
            dir = RIGHT;
            break;

        case 'w':
            dir = UP;
            break;

        case 's':
            dir = DOWN;
            break;

        default:
            break;
    }
}

void play()
{
    if (start == 's')
    {
        setup();
        while (!gameOver)
        {
            draw();
            input();
            logic();
            Sleep(100);
            system("cls");
        }
    }
}

void logic() 
{
    // tail logic
    int prevx = tailx[0];
    int prevy = taily[0];
    int prev2x, prev2y;
    tailx[0] = headX;
    taily[0] = headY;
    for (int i = 1; i < tail_len; i++) 
    {
        prev2x = tailx[i];
        prev2y = taily[i];
        tailx[i] = prevx;
        taily[i] = prevy;
        prevx = prev2x;
        prevy = prev2y;
    }

    // direction logic
    switch (dir)
    {
    case LEFT:
        headX--;
        break;

    case RIGHT:
        headX++;
        break;

    case UP:
        headY--;
        break;

    case DOWN:
        headY++;
        break;

    default:
        break;
    }

    // touch walls
    if (headX >= width) 
    {
        headX = 0;
    }
    else if (headX < 0) 
    {
        headX = width - 1;
    }
    if (headY >= height) 
    {
        headY = 0;
    }
    else if (headY < 0) 
    {
        headY = height - 1;
    }

    // snake bite itself
    for (int i = 0; i < tail_len; i++) 
    {
        if (tailx[i] == headX && taily[i] == headY) 
        {
            gameOver = true;
        }
    }

    // snake eat fruit
    if (headX == fruitX && headY == fruitY) 
    {
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
        tail_len++;
    }
}