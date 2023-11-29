#include <iostream>
#include <vector>
#include <conio.h>  // Only if you are on Windows
#include <unistd.h>
#include <ctime>

class Snake { 
    public:
        Snake(int x, int y) : head(x,y) {}

        void Move(int directionX, int directionY) {
            
            //Move tail:
            if (!tail.empty()){
                for (auto t = tail.rbegin(); t != tail.rend() -1; ++t) {
                    *t = *(t - 1);
                }
                tail.front() = head;
            }

            // Move head:
            head.first += directionX;
            head.second += directionY;
        }

        void growSnake() {
            if (tail.empty()) {
                tail.push_back(head); // If there's no tail, the new segment starts where the head is
            } else {
                tail.push_back(tail.back()); // Otherwise, add the new segment at the position of the last segment
            }
        }

        // getter: 
        std::pair<int, int> getHeadPosition(){
            return head;
        }

        std::vector<std::pair<int, int>> getTailPosition(){
            return tail;
        }
    
    private:
        std::pair<int, int> head;

        std::vector<std::pair<int, int>> tail; // To store the positions of the tail

};

class Fruit { 
    public:
        Fruit(int x, int y) : fruit(x,y){}

        void Respawn(int width, int hight) {
            fruit.first = rand() % (width);
            fruit.second = rand() % (hight);
        }

        // getter:
        std::pair<int, int> getFruitPosition(){
            return fruit;
        }
    
    private:
        std::pair<int, int> fruit;
};

class Game { 
    public:
        Game() : snake(width / 2, height / 2), fruit(rand() % width, rand() % height), score(0) {}

        void run(){
            while (1)
            {
                // processing user input
                userInput();

                // updating the game state
                updateGameState();

                // render the game state
                renderGame(); //draw the game to the window

                // sleep for a short time
                usleep(50000); // sleep for 500 milliseconds or 0.5 seconds
            }
        }

    private:
        // Game board:
        static const int width = 100;
        static const int height = 20;
        static const char SNAKE_HEAD = 'O';
        static const char SNAKE_TAIL = 'o';
        static const char FRUIT = 'X';
        static const char BORDER = '#';
        
        Snake snake;
        Fruit fruit;

        int score = 0;

        // Directions of the snake
        enum eDirection {LEFT, RIGHT, UP, DOWN};
        eDirection dir = RIGHT;

        void userInput() {
            if (kbhit()) { // check if key is pressed
                char ch = getch(); // get which key
                switch (ch) {
                    case 'a': dir = LEFT;  break;
                    case 'd': dir = RIGHT;  break;
                    case 'w': dir = UP;  break;
                    case 's': dir = DOWN;  break;
                    default: dir = DOWN;  break;
                }
            }
        }

        bool isFruitEaten(){
            auto snakeHead_pos = snake.getHeadPosition();
            auto fruit_pos = fruit.getFruitPosition();

            return (snakeHead_pos.first == fruit_pos.first && snakeHead_pos.second == fruit_pos.second);
        }

        void updateGameState(){
            switch (dir)
            {
                case LEFT: snake.Move(-1,0); break;
                case RIGHT: snake.Move(1,0); break;
                case UP: snake.Move(0,-1); break;
                case DOWN: snake.Move(0,1); break;
                default: break;
            }

            if (isFruitEaten()){
                score++;
                snake.growSnake();
                fruit.Respawn(width,height);
            }
        }



        void renderGame(){
            system("cls");  // Clear the console screen

            char gameBoard[width][height];

             // Initialize the game board with (empty spaces)
            std::fill(&gameBoard[0][0], &gameBoard[0][0] + width * height, ' ');

            // Add a border around the game board
            for (int x = 0; x < width; x++) {
                gameBoard[x][0] = BORDER;         // Top border
                gameBoard[x][height - 1] = BORDER; // Bottom border
            }
            for (int y = 0; y < height; y++) {
                gameBoard[0][y] = BORDER;          // Left border
                gameBoard[width - 1][y] = BORDER;  // Right border
            }

            // place head on board:
            auto snakeHead_pos = snake.getHeadPosition();
            gameBoard[snakeHead_pos.first][snakeHead_pos.second] = SNAKE_HEAD;
            //place tail on board:
            auto snakeTail_pos = snake.getTailPosition();
            for (const auto& pos : snakeTail_pos) {
                gameBoard[pos.first][pos.second] = SNAKE_TAIL;
                //std::cout << pos.first << "  " << pos.second << std::endl;
            }

            //place fruit on board:
            auto fruit_pos = fruit.getFruitPosition();
            gameBoard[fruit_pos.first][fruit_pos.second] = FRUIT;

            // Print the board
            for (size_t i = 0; i < height; i++) {
                for (size_t j = 0; j < width; j++) {
                    std::cout << gameBoard[j][i];
                }
                std::cout << std::endl;
            }
            
        }

};

int main()
{   
     /* initialize random seed: */
    srand (time(NULL));

    Game game;
    game.run();

    return 0;
}