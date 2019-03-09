#include <iostream>
#include "helper.h"
#include "Game.h"

int main() {

    Game game;
    game.play();

/****************************************************
    //For roof
    const int RSIZE =7;
    char **roof;
    roof = new char *[RSIZE];

    for (int i = 0; i < RSIZE; i++) {
        roof[i] = new char[RSIZE];
    }

    for (int i = 0; i < RSIZE; i++) {
        for (int j = 0; j < RSIZE*2-1; j++) {
            roof[i][j] = ' ';
        }
    }


    int r = RSIZE-1 ;
    int l = RSIZE-1 ;

    for (int i = 0; i < RSIZE; i++) {
        for (int j = 0; j < RSIZE*2-1; j++) {

            if (i == 0 && j == (RSIZE-1)) {

                roof[i][j] = 'x';  }
            else if (i > 0 && (j == l)) {

                roof[i][j] ='x';  }

            else if (i > 0 && (j == r)) {

                roof[i][j] ='x';  }

        }

        r++;
        l--;
    }
    //roof[3][6] ='*';
    roof[6][3] ='S';
    roof[6][4] ='t';
    roof[6][5] ='u';
    roof[6][6] ='d';
    roof[6][7] ='y';
    roof[6][8] ='R';
    roof[6][9] ='m';
    roof[6][10] ='2';

    for (int i = 0; i < RSIZE; i++) {
        for (int j = 0; j < RSIZE*2-1; j++) {
            std::cout<<roof[i][j]<<" ";
        }
        std::cout<<std::endl;
        }

//For House
    const int HSIZE = 20;
    char **house;
    house = new char *[HSIZE];

    for (int i = 0; i < HSIZE; i++) {
        house[i] = new char[HSIZE];
    }

    for (int i = 0; i < HSIZE; i++) {
        for (int j = 0; j < 32; j++) {
            house[i][j] = ' ';
        }
    }



    for (int i = 0; i < HSIZE; i++) {
        for (int j = 0; j < 32; j++) {

            if (i == 0) {
                house[i][j] = '-';
            } else if (i == 9) {
                house[i][j] = '-';
            } else if (i == 19) {
                house[i][j] = '-';
            }

            else if(j == 0) {
                house[i][j] = '|';
            } else if(j == 12) {
                house[i][j] = '|';
            } else if(j == 21) {
                house[i][j] = '|';
            } else if(j == 31) {
                house[i][j] = '|';
            }
        }

    }

    house[3][3] ='B';
    house[3][4] ='e';
    house[3][5] ='d';
    house[3][6] ='R';
    house[3][7] ='m';
    house[3][8] ='1';
    //house[5][6] ='*';

    house[3][13] ='B';
    house[3][14] ='a';
    house[3][15] ='t';
    house[3][16] ='h';
    house[3][17] ='R';
    house[3][18] ='m';
    house[3][19] ='2';
    //house[5][16] ='*';

    house[3][23] ='B';
    house[3][24] ='e';
    house[3][25] ='d';
    house[3][26] ='R';
    house[3][27] ='m';
    house[3][28] ='2';
    //house[5][26] ='*';

    house[12][2] ='S';
    house[12][3] ='t';
    house[12][4] ='u';
    house[12][5] ='d';
    house[12][6] ='y';
    house[12][7] ='R';
    house[12][8] ='m';
    house[12][9] ='1';
    //house[14][6] ='*';

    house[12][13] ='B';
    house[12][14] ='a';
    house[12][15] ='t';
    house[12][16] ='h';
    house[12][17] ='R';
    house[12][18] ='m';
    house[12][19] ='1';
    //house[14][16] ='*';

    house[12][23] ='K';
    house[12][24] ='i';
    house[12][25] ='t';
    house[12][26] ='c';
    house[12][27] ='h';
    house[12][28] ='e';
    house[12][29] ='n';
    //house[14][26] ='*';


    for (int i = 0; i < HSIZE; i++) {
        for (int j = 0; j < 32; j++) {
            std::cout<<house[i][j]<<" ";
        }
        std::cout<<std::endl;
    }

  showMap(roof, house, RSIZE, HSIZE, 14, 16);

  for(int k=0; k<RSIZE; k++) {
      delete[] roof[k];
  }
  delete[] roof;

  for(int m=0; m <HSIZE; m++) {
      delete[] house[m];
  }
  delete[] house;

    ******************************************************/

    return 0;
}