#include <iostream>
using namespace std;
#include <chrono>
#include <random>
#ifndef X
#define X 5
#endif
#ifndef Y
#define Y 5
#endif
#include <thread>

int exitCycle = 0;
enum Direction
{
 up = 1,
 left = 2,
 right = 3,
 down = 4,
 none = 0
};
struct Cell
{
    bool IsEmpty;
    bool IsStopped;
    Direction moveDir;
};
struct Grid
{

    Cell cells[X][Y] = {{Cell{false, false, none}, Cell{false, false, none}, Cell{false, false, none},Cell{false, false, none},Cell{false, false, none}},
                       {Cell{false, false, none}, Cell{false, false, none}, Cell{false, false, none},Cell{false, false, none},Cell{false, false, none}},
                       {Cell{false, false, none}, Cell{false, false, none}, Cell{false, false, none},Cell{false, false, none},Cell{false, false, none}},
                       {Cell{false, false, none}, Cell{false, false, none}, Cell{false, false, none},Cell{false, false, none},Cell{false, false, none}},
                       {Cell{false, false, none}, Cell{false, false, none}, Cell{false, false, none},Cell{false, false, none},Cell{false, false, none}}
                     };

};
void MoveCell(int currX, int currY, Grid &grid)
{
    Cell cell = grid.cells[currX][currY];
    int dir = cell.moveDir;
    if(dir == Direction::up)
    {
        grid.cells[currX][currY].IsEmpty = true;
        grid.cells[currX][currY-1].IsEmpty = true;
    }
    else if(dir == Direction::down)
    {
        grid.cells[currX][currY].IsEmpty = false;
        grid.cells[currX][currY+1].IsEmpty = true;
    }
    else if(dir == Direction::right)
    {
        grid.cells[currX][currY].IsEmpty = false;
        grid.cells[currX+1][currY].IsEmpty = true;
    }
    else if(dir == Direction::left)
    {
        grid.cells[currX][currY].IsEmpty = false;
        grid.cells[currX-1][currY].IsEmpty = true;
    }
    else if(dir == Direction::none)
    {

    }
    else
    {
        cout << "Unknown direction";
    }
    cell.moveDir = Direction::none;   
}
int RandomNumbInRange(int min, int max)
{
    std::random_device rd;    
    std::mt19937 rng(rd());    
    std::uniform_int_distribution<int> uni(min,max);
    return uni(rng);
}
void Tick(Grid grid)
{   
    exitCycle = 0;
    //Step 0: Stop

    for (int i = 0; i < X; i++)
        {
            for (int j = 0; j < Y; j++)
            {
                if(grid.cells[i][j].IsEmpty)
                {
                    if(j + 1 > Y || j - 1 < 0 || i -1 < 0 || i + 1 > X)  
                    {
                        grid.cells[i][j].IsStopped = true;
                    }
                    if(j - 1 > 0  &&  grid.cells[i][j-1].IsEmpty)
                    {
                        grid.cells[i][j-1].IsStopped = true;//down
                        grid.cells[i][j].IsStopped = true;
                    }
                    if(j + 1 < Y &&  grid.cells[i][j+1].IsEmpty)
                    {
                        grid.cells[i][j+1].IsStopped = true;//upper
                        grid.cells[i][j].IsStopped = true;
                    }
                    if(i + 1 < X &&  grid.cells[i+1][j].IsEmpty)
                    {
                        grid.cells[i+1][j].IsStopped = true;//left
                        grid.cells[i][j].IsStopped = true;
                    }
                    if(i - 1 > Y &&  grid.cells[i-1][j].IsEmpty)
                    {
                        grid.cells[i-1][j].IsStopped = true;//upper
                        grid.cells[i][j].IsStopped = true;
                    }   
                }        
            }
        }

    //Step 1: Set directions  

    for (int i = 0; i < X; i++)
    {
        for (int j = 0; j < Y; j++)
        {
           
           if(grid.cells[i][j].IsEmpty && !grid.cells[i][j].IsStopped)
           {
            int dir = RandomNumbInRange(1, 4);
            switch(dir)
            {
                case 1:
                grid.cells[i][j].moveDir = Direction::up;
                break;
                case 2:
                grid.cells[i][j].moveDir = Direction::left;
                break;
                case 3:
                grid.cells[i][j].moveDir = Direction::right;
                break;
                case 4:
                grid.cells[i][j].moveDir = Direction::down;
                break;
                default:
                cout << "Unknown direction";
                break;
            }
           }
        }

        //Step 2: Collide
        
    for(int i = 0; i < X; i++)
    {
        for(int j = 0; j < Y; j++)
        {
            if(!grid.cells[i][j].IsEmpty && !grid.cells[i][j].IsStopped)
            {
                switch(grid.cells[i][j].moveDir)
                {
                    case Direction::left:
                        if(i > 0 && !grid.cells[i-1][j].IsEmpty && !grid.cells[i-1][j].IsStopped)
                        {
                            //collide left
                            grid.cells[i][j].moveDir = Direction::none;
                            grid.cells[i-1][j].moveDir = Direction::none;
                        }
                        break;
                    case Direction::right:
                        if(i < X-1 && !grid.cells[i+1][j].IsEmpty && !grid.cells[i+1][j].IsStopped)
                        {
                            //collide right
                            grid.cells[i][j].moveDir = Direction::none;
                            grid.cells[i+1][j].moveDir = Direction::none;
                        }
                        break;
                    case Direction::up:
                        if(j > 0 && !grid.cells[i][j-1].IsEmpty && !grid.cells[i][j-1].IsStopped)
                        {
                            //collide up
                            grid.cells[i][j].moveDir = Direction::none;
                            grid.cells[i][j-1].moveDir = Direction::none;
                        }
                        break;
                    case Direction::down:
                        if(j < Y-1 && !grid.cells[i][j+1].IsEmpty && !grid.cells[i][j+1].IsStopped)
                        {
                            //collide down
                            grid.cells[i][j].moveDir = Direction::none;
                            grid.cells[i][j+1].moveDir = Direction::none;
                        }
                        break;
                    default:
                        break;
                }
            }
        }
}

        //Step 3: Move    

        for (int i = 0; i < X; i++)
        {
            for (int j = 0; j < Y; j++)
            {      
                if(grid.cells[i][j].IsEmpty && !grid.cells[i][j].IsStopped)
                {
                    MoveCell(i,j, grid);
                    exitCycle = 1;
                }
            }
        }
       
    }

}

void DrawGrid(Grid grid)
{
    for (int i = 0; i < X; ++i)
    {
        for (int j = 0; j < Y; ++j)
        {
            std::cout << grid.cells[i][j].IsEmpty << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;


}
int main()
{
    auto begin = std::chrono::steady_clock::now();
    Grid grid;
    int dislocationsCount = RandomNumbInRange(1, 2);
    for(int i = 0; i < dislocationsCount; i++)
    {
        int x = RandomNumbInRange(0, X-1);
        int y = RandomNumbInRange(0, Y-1);
        grid.cells[x][y].IsEmpty = true;
    }
    while(true)
    {
        std::this_thread::sleep_for(std::chrono::seconds(2));
        DrawGrid(grid);
        Tick(grid);
    }
    auto end = chrono::steady_clock::now();
	auto time_span = chrono::duration_cast<chrono::milliseconds>(end - begin);

}