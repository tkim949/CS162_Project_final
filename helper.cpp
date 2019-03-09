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
#include <vector>


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

void showMap(int row, int col) {

    const int RSIZE = 4;
    const int HSIZE = 13;
    std::vector<std::vector<char> > roof(RSIZE, std::vector<char>(12));
    std::vector<std::vector<char> > house(HSIZE, std::vector<char>(32));
    //For the roof


    for(int i=3; i<9; i++) {
        roof[0][i] = '=';
    }
    roof[1][2]='X';
    roof[1][9]='X';
    roof[2][1]='X';
    roof[2][10]='X';
    roof[3][0]='X';
    roof[3][11]='X';

    roof[3][1] ='<';
    roof[3][2] ='S';
    roof[3][3] ='T';
    roof[3][4] ='U';
    roof[3][5] ='D';
    roof[3][6] ='Y';
    roof[3][7] ='R';
    roof[3][8] ='M';
    roof[3][9] ='2';
    roof[3][10] ='>';

    if(row < 3 ){

        roof[row][col] ='*';
    }

    for (int i = 0; i < RSIZE; i++) {
        for (int j = 0; j < 12; j++) {
            std::cout<<roof[i][j]<<' ';
        }
        std::cout<<std::endl;
    }

//For the house


    for (int i = 0; i < HSIZE; i++) {
        for (int j = 0; j < 32; j++) {

            if (i == 0) {
                house[i][j] = '=';
            } else if (i == 6) {
                house[i][j] = '=';
            } else if (i == 12) {
                house[i][j] = '=';
            }

            else if(j == 0) {
                house[i][j] = '|';
            } else if(j == 11) {
                house[i][j] = '|';
            } else if(j == 21) {
                house[i][j] = '|';
            } else if(j == 31) {
                house[i][j] = '|';
            }
        }

    }

    house[3][2] ='<';
    house[3][3] ='B';
    house[3][4] ='E';
    house[3][5] ='D';
    house[3][6] ='R';
    house[3][7] ='M';
    house[3][8] ='1';
    house[3][9] ='>';

    house[3][12] ='<';
    house[3][13] ='R';
    house[3][14] ='E';
    house[3][15] ='S';
    house[3][16] ='T';
    house[3][17] ='R';
    house[3][18] ='M';
    house[3][19] ='2';
    house[3][20] ='>';

    house[3][22] ='<';
    house[3][23] ='B';
    house[3][24] ='E';
    house[3][25] ='D';
    house[3][26] ='R';
    house[3][27] ='M';
    house[3][28] ='2';
    house[3][29] ='>';

    house[9][1] ='<';
    house[9][2] ='S';
    house[9][3] ='T';
    house[9][4] ='U';
    house[9][5] ='D';
    house[9][6] ='Y';
    house[9][7] ='R';
    house[9][8] ='M';
    house[9][9] ='1';
    house[9][10] ='>';

    house[9][12] ='<';
    house[9][13] ='R';
    house[9][14] ='E';
    house[9][15] ='S';
    house[9][16] ='T';
    house[9][17] ='R';
    house[9][18] ='M';
    house[9][19] ='1';
    house[9][20] ='>';

    house[9][22] ='<';
    house[9][23] ='K';
    house[9][24] ='I';
    house[9][25] ='T';
    house[9][26] ='C';
    house[9][27] ='H';
    house[9][28] ='E';
    house[9][29] ='N';
    house[9][30] ='>';

    if (row > 3) {
        house[row][col] = '*';
    }


    for (int i = 0; i < HSIZE; i++) {
        for (int j = 0; j < 32; j++) {
            std::cout<<house[i][j]<<' ';
        }
        std::cout<<std::endl;
    }


}

