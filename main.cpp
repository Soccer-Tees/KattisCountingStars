/**
 * Move left to right, top to bottom. Each time '-' is found, fill all connected '-' with a's, then add 1 to totalStars
 */
#include <iostream>
#include <string>
#include <cstring>

int width=0;
int height=0;
char grid[100][100];

void printGrid();
void fillStar(int x, int y);

int main() {
    std::string line;
    int totalStars=0;
    int caseNum=1;

    //read input until no more grid sizes are found as per instructions
    while(std::cin >> height && std::cin >> width){
        totalStars=0;
        memset(grid, 0, sizeof(grid));
        for(int y = 0; y < height; y++){
            std::cin >> line;
            for(int x = 0; x < width; x++){
                grid[x][y]=line[x];
            }
        }

        //move left to right, each time '-' is found fill all connected dashes with 'a' then keep going
        for(int y=0; y < height;y++){
            for(int x=0;x<width;x++){
                if(grid[x][y]=='-'){
                    fillStar(x,y);
                    totalStars++;
                }

            }
        }
        std::cout << "Case " << caseNum << ": " << totalStars << "\n";
        caseNum++;
    }
    return 0;
}


void fillStar(int x, int y){
    if(grid[x][y]=='-'){
        grid[x][y]='a';
        fillStar(x,y+1); //up
        fillStar(x,y-1); //down
        fillStar(x-1,y); //left
        fillStar(x+1,y);  //right
        fillStar(x-1,y+1); //upleft
        fillStar(x+1,y+1); //upright
        fillStar(x-1,y-1); //downleft
        fillStar(x+1,y-1); //downright
    }
}

void printGrid(){
    for(int y=0; y<height;y++){
        for(int x=0;x<width;x++){
            std::cout<<grid[x][y];
        }
        std::cout << "\n";
    }
}