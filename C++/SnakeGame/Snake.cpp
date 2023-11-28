#include <iostream>
#include <vector>

class Snake { 
    public:
        Snake(int x, int y) : positionX(x), positionY(y) {}

        void Move(int directionX, int directionY) {
            std::cout << "function" << std::endl;
        }
    
    private:
        int positionX;
        int positionY;
        std::vector<std::pair<int, int>> tail; // To store the positions of the tail

};

class Fruit { 
    public:
        Fruit(int x, int y) : positionX(x), positionY(y){}

        void Respawn(int newX, int newY) {
            positionX = newX;
            positionY = newY;
        }
    
    private:
        int positionX;
        int positionY;
};

class Game { 
    public:
        Game() : snake(width / 2, height / 2), fruit(rand() % width, rand() % height), score(0) {}

        void run(){

        }


    private:
        static const int width = 20;
        static const int height = 20;
        
        Snake snake;
        Fruit fruit;
        int score;

};

int main()
{
    Game game;
    game.run();

    return 0;
}