#include<cstdlib>
const int rows = 15;
const int columns = 40;

class life{
    public:
        void initialize();
        void print();
        void run();
        void rule();
        void printNTimes(char, int);  //Funtion to print character n times
        
    private:
        int grid[rows+2][columns+2];
        void update();
        int neighbors(int, int);

               
};

void life::rule(){
    printNTimes('=', 50);
    cout << " Welcome to the GAME OF LIFE ";
    printNTimes('=', 50);
    cout << endl;
    cout << "Rules:\n";
    printNTimes('-', 6);
    cout << " \n 1) Any live cell with fewer than two live neighbours dies, as if by underpopulation." << endl;
    cout << " 2) Any live cell with two sor three live neighbours lives on to the next generation." << endl;
    cout << " 3) Any live cell with more than three live neighbours dies, as if by overpopulation." << endl;
    cout << " 4) Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction." << endl << endl;
    cout << " Instruction: " << endl;
    printNTimes('-', 13);
    cout << endl;
    //cout << " \n You can make your own grid of rows and columns or go with defult 15*40 one." << endl;
    cout << " 1) You can play either with the random live and dead cell.\n 2) You can assign the position of cell's. " << endl;
    printNTimes('=', 130);
    cout << endl;

    cout << "Press Enter to play." << endl;
    cin.ignore();

}
void life::printNTimes(char c, int n){   //Function to print character n times
    cout << string(n, c);
}

int life::neighbors(int r, int c){
    int count = 0;
    for(int dr = -1; dr <= 1; dr++){
        for(int dc = -1; dc <=1; dc++){
            count += grid[r+dr][c+dc];
        }
    }
    count -= grid[r][c];
    return count;
}

void life::update(){
   int count;
   int tempgrid[rows+2][columns+2];
   for(int r = 1; r < rows+1; r++){
     for(int c = 1; c < columns+1; c++){
        count = neighbors(r,c);
        tempgrid[r][c] = 0;
        if(count == 3){
           tempgrid[r][c] = 1;
        }
        if(count == 2){
           tempgrid[r][c] = grid[r][c];
        }
     }
   }
   for(int r = 1; r < rows+1; r++){
     for(int c = 1; c < columns+1; c++){
       grid[r][c] = tempgrid[r][c];
     }
   }
}

void life::run(){
  int steps;
  do{
    cout << "How many times do you want to try? :";
    cin >> steps;
    for(int s = 0; s < steps; s++){
       update();
       print();
       cout << endl;
       printNTimes('=', 86);
       cout << endl;
    }
  }while(steps!=0);
}

void life::print(){
    for(int r = 1; r < rows+1; r++){
        for (int c = 1; c < columns+1; c++){
            if(grid[r][c]== 0){
                cout << "  ";
            }
            if(grid[r][c]== 1){
                cout << " #";
            }
        }
        cout << endl;
    }
}

void life::initialize(){
    for(int r = 0; r < rows+2; r++){
        for(int c = 0; c < columns+2; c++){
            grid[r][c] = 0;
        }
    }
    int num;
    cout << "What do you want to do: \n1) Select your own live or dead cell. \n2) Go with the random cell" << endl;   
    cout << "Choice: ";
    cin >> num;
    cout << endl;
    
    
        if(num == 1){
            int livecellR,livecellC;
            cout << "NOTE:: If you want to stop entering the values of rows and columns, then you can enter -1 and -1 to stop." << endl << endl;;
            while (livecellR!=-1 || livecellC!=-1){
                cout<<"Enter the position for ROWS AND COLUMNS."<<endl;
                cout << "Row: "; cin >> livecellR;
                cout << "Columns: "; cin >> livecellC;
                cout << endl;
                grid[livecellR][livecellC]=1;
            }
        }

        if(num == 2){

            // fill in non-zero vslues. based on user choice
            for(int r = 1; r< rows+1; r++){
                for(int c = 1; c < columns+1; c++){
                    grid[r][c] = rand() % 2;
                }
            }
        }
        print();
        run();
        exit(1);
}



