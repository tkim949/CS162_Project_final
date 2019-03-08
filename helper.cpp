/****************************************************************************************************
 * * Program name: CS162 Final Project
 * * Author: Taekyoung Kim
 * * Date: 03/03/2019
 * * Description: This is inputVal.h file for CS162 Final Project
 * * This project implements text-based game.
 ******************************************************************************************************/


#include "helper.h"
#include <iostream>
#include <climits>
#include <cctype>
#include <algorithm>
#include <random>


/*********************************************************************
 * * This function get double parameter and return an integer value
 * * after checking if it is digit and positive number and double.
 * * and it checks that number is between 1 and 3.
 **********************************************************************/

int inputVal(double in) {

    // Check type validation first using std::cin.fail()
    if( std::cin.good() && in > 0 && in < 6 && (in - (int)in == 0)) {
        return (int)in;
    }

    else{

        do {

            std::cout << "Wrong input! You need to input proper value!" << std::endl;

            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');

            std::cout << "Please try again. Input here: " << std::endl;
            std::cin >> in;

        } while(!(std::cin.good() && in > 0 && in < 6 && (in - (int)in == 0) ));

    }

    return (int)in;
}



/****************************************************************************************
 * * This function get double parameter and return an integer value
 * * after checking if it isn't double and only valid integer between 1 and 100.
 *****************************************************************************************/
int inputNum(double in) {

    // Check type validation first using std::cin.fail()
    if( std::cin.good() && in > 0 && in < 101 && (in - (int)in == 0)) {
        return (int)in;
    }

    else{

        do {

            std::cout << "Wrong input! You need to input proper value!" << std::endl;

            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');

            std::cout << "Please try again. Input here: ";
            std::cin >> in;


        } while(!(std::cin.good() && in > 0 && in < 101 && (in - (int)in == 0) ));

    }

    return (int)in;
}


int randomNum(int input) {

    std::random_device ran;
    std::mt19937 mt(ran());
    std::uniform_int_distribution <int> dist(1, input);

    return dist(mt);
}

void showMap(char **roof, char **house, int RSIZE, int HSIZE, int row, int col) {

    //For the roof
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

    roof[6][3] ='S';
    roof[6][4] ='t';
    roof[6][5] ='u';
    roof[6][6] ='d';
    roof[6][7] ='y';
    roof[6][8] ='R';
    roof[6][9] ='m';
    roof[6][10] ='2';

    if(row < 4 ){

        roof[row][col] ='*';
    }

    for (int i = 0; i < RSIZE; i++) {
        for (int j = 0; j < RSIZE*2-1; j++) {
            std::cout<<roof[i][j]<<" ";
        }
        std::cout<<std::endl;
    }

    //For the house

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

    house[3][13] ='R';
    house[3][14] ='e';
    house[3][15] ='s';
    house[3][16] ='t';
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

    house[12][13] ='R';
    house[12][14] ='e';
    house[12][15] ='s';
    house[12][16] ='t';
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

    if (row > 4) {
        house[row][col] = '*';
    }

    for (int i = 0; i < HSIZE; i++) {
        for (int j = 0; j < 32; j++) {
            std::cout<<house[i][j]<<" ";
        }
        std::cout<<std::endl;
    }



}

