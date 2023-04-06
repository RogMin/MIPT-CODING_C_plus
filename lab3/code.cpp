#include <iostream>
using namespace std;
#include <chrono>
#include <random>
#ifndef X
#define X 8
#endif
#ifndef Y
#define Y 8
#endif
#ifndef N
#define N 5
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
    bool IsIsStopped;
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
                if (abs(objects[i].i-objects[j].i)+abs(objects[i].j-objects[j].j) == 1)
                {
                    
                }
                if(grid.cells[i][j].IsEmpty)
                {
                    if(j + 1 > Y || j - 1 < 0 || i -1 < 0 || i + 1 > X)  
                    {
                        grid.cells[i][j].IsIsStopped = true;
                    }
                    if(j - 1 > 0  &&  grid.cells[i][j-1].IsEmpty)
                    {
                        grid.cells[i][j-1].IsIsStopped = true;//down
                        grid.cells[i][j].IsIsStopped = true;
                    }
                    if(j + 1 < Y &&  grid.cells[i][j+1].IsEmpty)
                    {
                        grid.cells[i][j+1].IsIsStopped = true;//upper
                        grid.cells[i][j].IsIsStopped = true;
                    }
                    if(i + 1 < X &&  grid.cells[i+1][j].IsEmpty)
                    {
                        grid.cells[i+1][j].IsIsStopped = true;//left
                        grid.cells[i][j].IsIsStopped = true;
                    }
                    if(i - 1 > Y &&  grid.cells[i-1][j].IsEmpty)
                    {
                        grid.cells[i-1][j].IsIsStopped = true;//upper
                        grid.cells[i][j].IsIsStopped = true;
                    }   
                }        
            }
        }

    //Step 1: Set directions  

    for (int i = 0; i < X; i++)
    {
        for (int j = 0; j < Y; j++)
        {
           
           if(grid.cells[i][j].IsEmpty && !grid.cells[i][j].IsIsStopped)
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
            if(!grid.cells[i][j].IsEmpty && !grid.cells[i][j].IsIsStopped)
            {
                switch(grid.cells[i][j].moveDir)
                {
                    case Direction::left:
                        if(i > 0 && !grid.cells[i-1][j].IsEmpty && !grid.cells[i-1][j].IsIsStopped)
                        {
                            //collide left
                            grid.cells[i][j].moveDir = Direction::none;
                            grid.cells[i-1][j].moveDir = Direction::none;
                        }
                        break;
                    case Direction::right:
                        if(i < X-1 && !grid.cells[i+1][j].IsEmpty && !grid.cells[i+1][j].IsIsStopped)
                        {
                            //collide right
                            grid.cells[i][j].moveDir = Direction::none;
                            grid.cells[i+1][j].moveDir = Direction::none;
                        }
                        break;
                    case Direction::up:
                        if(j > 0 && !grid.cells[i][j-1].IsEmpty && !grid.cells[i][j-1].IsIsStopped)
                        {
                            //collide up
                            grid.cells[i][j].moveDir = Direction::none;
                            grid.cells[i][j-1].moveDir = Direction::none;
                        }
                        break;
                    case Direction::down:
                        if(j < Y-1 && !grid.cells[i][j+1].IsEmpty && !grid.cells[i][j+1].IsIsStopped)
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
                if(grid.cells[i][j].IsEmpty && !grid.cells[i][j].IsIsStopped)
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
////////////////////////////


enum Direction
{
 up = 1,
 left = 2,
 right = 3,
 down = 4,
};
struct Cell
{
    bool IsStopped;
    Direction direction;
    int x;
    int y;
};
int RandomNumbInRange(int min, int max)
{
    std::random_device rd;    
    std::mt19937 rng(rd());    
    std::uniform_int_distribution<int> uni(min,max);
    return uni(rng);
}
void MakeRandomAtom(Cell (&cells)[N])
{
    int temp = 0;
    int flag = 0;
    while (temp != N)
    {
        cells[temp].x = RandomNumbInRange(0, X - 1);
        cells[temp].y = RandomNumbInRange(0, Y - 1);
        cells[temp].IsStopped = false;
        for (int i = 0; i < k; ++i)
        {
            if ((cells[i].x == cells[temp].x) && (cells[i].y == cells[temp].y))
                flag = 1;
        }
        if (flag != 1)
            temp++;
        flag = 0;
    }
}

void SetDirection(Cell (&cells)[N])
{
    for (int i = 0; i < X; i++)
    {
        int dir = RandomNumbInRange(1, 4);
        switch(dir)
        {
            case 1:
            cells[i].direction = Direction::up;
            break;
            case 2:
            cells[i].direction = Direction::left;
            break;
            case 3:
            cells[i].direction = Direction::right;
            break;
            case 4:
            cells[i].direction = Direction::down;
            break;
            default:
            cout << "Unknown direction";
            break;
        }
    }
}

void MoveCells(Cell (&cells)[N], int &exitCycle)
{
    int flag;
    for (int k = 0; k < N; ++k)
    {
        flag = 0;
        if (!cells[k].IsStopped)
        {
            if (cells[k].direction == Direction::up)
            {
                for (int i = 0; i < N; ++i)
                {
                    if (((cells[k].y - 1) == cells[i].y) && (cells[k].x == cells[i].x))
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0)
                {
                    cells[k].y--;
                    exitCycle = 1;
                }
            }
            else if (cells[k].direction == Direction::left)
            {
                for (int i = 0; i < N; ++i)
                {
                    if (((cells[k].x - 1) == cells[i].x) && (cells[k].y == cells[i].y))
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0)
                {
                    cells[k].x--;
                    exitCycle = 1;
                }
            }
            else if (cells[k].direction == Direction::right)
            {
                for (int i = 0; i < N; ++i)
                {
                    if (((cells[k].x + 1) == cells[i].x) && (cells[k].y == cells[i].y))
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0)
                {
                    cells[k].x++;
                    exitCycle = 1;
                }
            }
            else if (cells[k].direction == Direction::down)
            {
                for (int i = 0; i < N; ++i)
                {
                    if (((cells[k].y + 1) == cells[i].y) && (cells[k].x == cells[i].x))
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0)
                {
                    cells[k].y++;
                    exitCycle = 1;
                }
            }
            else
            {
                cout << "Unknown direction";
            }
        }
    }
}


void Stop(Cell (&cells)[N])
{
    for (int k = 0; k < N; ++k)
    {
        if (!cells[k].IsStopped)
        {
            if ((cells[k].x == 0) || (cells[k].x == (X - 1)) || (cells[k].y == 0) || (cells[k].y == (Y - 1)))
            {
                cells[k].IsStopped = true;
            }
            else
            {
                for (int i = 0; i < N; ++i)
                {
                    if (abs(cells[i].x - cells[k].x) + abs(cells[i].y - cells[k].y) == 1)
                    {
                        cells[k].IsStopped = true;
                    }
                }
            }
        }
    }
}



void Tick(Cell (&cells)[N], int &exitCycle)
{
    exitCycle = 0;
    //Step 1 stop
    Stop(cells);
    //Step 2 set directions
    SetDirection(cells);
    MoveCells(cells, exitCycle);
    Stop(cells);
}







void Print(Cell (&cells)[N])
{
    int flag = 0;
    for (int i = 0; i < X; ++i)
    {
        for (int j = 0; j < Y; ++j)
        {
            flag = 0;
            for (int k = 0; k < N; ++k)
            {
                if (cells[k].x == j && cells[k].y == i)
                {
                    flag = 1;
                    if (cells[k].IsStopped)
                        std::cout << "s"
                                  << " ";
                    else
                        std::cout << "e"
                                  << " ";
                }
            }
            if (flag == 0)
            {
                std::cout << "0"
                          << " ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << std::endl;
}

int main()
{
    int exitCycle = 1;
    Cell cells[N];
    MakeRandomAtom(cells);
    auto begin = std::chrono::steady_clock::now();
    while (exitCycle == 1)
    {
        Tick(cells, exitCycle);
        std::this_thread::sleep_for(std::chrono::seconds(1));
        Print(cells);
    }
    auto end = std::chrono::steady_clock::now();
    auto time_span = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    std::cout << time_span.count() << std::endl;
    return 0;
    
//////////////////////////////////////////////////////////////////////////////////////////////
    auto begin = std::chrono::steady_clock::now();
    Grid grid;
    int dislocationsCount = RandomNumbInRange(1, 3);
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