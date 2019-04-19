/****************************************************************************************************
 * * Program name: CS162 Final Project
 * * Author: Taekyoung Kim
 * * Date: 03/03/2019
 * * Description: This is helper.cpp file for CS162 Final Project
 * * This project implements text-based game.
 * * A user(you) need to find a USB that has financial info of his deceased father.
 * * There are total 7 rooms in the house and 5 of them might have the USB.
 * * And each room has three places that the USB might be.
 * * Also, there is an obstacles, his/her step mother and brother.
 * * If the user ran into them, he might lose his strength or jewelry.
 * * User has a container and its capacity is 3, but he/she needs to keep the PASSWORD for the usb,
 * * actual capacity would be 2. Users can find jewelry in the house and keep and use it.
 * * Users can search for a room one at a time, and he has 15 turns to change rooms.
 * * The last two rooms of 7 are the places for user to rest and get a chance to have something good.
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
 * * and it checks that number is between 1 and 5.
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
 * * after checking if it isn't double and only valid integer between 1 and 2.
 *****************************************************************************************/
int choiceTwo(double in) {

    // Check type validation first using std::cin.fail()
    if( std::cin.good() && in > 0 && in < 3 && (in - (int)in == 0)) {
        return (int)in;
    }

    else{

        do {

            std::cout << "Wrong input! You need to input proper value!" << std::endl;

            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');

            std::cout << "Please try again. Input here: ";
            std::cin >> in;


        } while(!(std::cin.good() && in > 0 && in < 3 && (in - (int)in == 0) ));

    }

    return (int)in;
}

/****************************************************************************************
 * * This function get double parameter and return an integer value
 * * after checking if it isn't double and only valid integer between 1 and 3.
 *****************************************************************************************/

int choiceThree(double in) {

    // Check type validation first using std::cin.fail()
    if( std::cin.good() && in > 0 && in < 4 && (in - (int)in == 0)) {
        return (int)in;
    }

    else{

        do {

            std::cout << "Wrong input! You need to input proper value!" << std::endl;

            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');

            std::cout << "Please try again. Input here: ";
            std::cin >> in;


        } while(!(std::cin.good() && in > 0 && in < 4 && (in - (int)in == 0) ));

    }

    return (int)in;
}

/**********************************************************************************************
 * This randomNum function take integer number as parameter, which decides the maximum limits
 * * and returns random integer number between 1 and the miximum limit number
 * * @param input @return
 **********************************************************************************************/

int randomNum(int input) {

    std::random_device ran;
    std::mt19937 mt(ran());
    std::uniform_int_distribution <int> dist(1, input);

    return dist(mt);
}

/***********************************************************************************************
 * * This showMap function show map of the house using vector 2D char.
 * * it takes two integer numbers for column and row and points to where the user is in the map.
 * * @param row @param col
 ************************************************************************************************/

void showMap(int row, int col) {

    const int RSIZE = 4;
    const int HSIZE = 13;
    std::vector<std::vector<char> > roof(RSIZE, std::vector<char>(12));
    std::vector<std::vector<char> > house(HSIZE, std::vector<char>(32));

//For the roof

	int i;
	int j;
	//first row
	
	for(i=0; i<3; i++){
		roof[0][i]='-';
	}
    for(i=3; i<9; i++) {
        roof[0][i] = 'X';
    }
	for(i=9; i<12; i++){
	roof[0][i]='-';
	}
	
	//second row
		for(j = 3; j<9; j++){
		roof[1][j] ='-'; }
		
		roof[1][0]='-';
		roof[1][1]='-';
		roof[1][10]='-';
		roof[1][11]='-';
		roof[1][2]='X';
        roof[1][9]='X';
		
	//third row	
		for(j=2; j<10; j++){
			roof[2][j]='-';
		}
		roof[2][0]='-';
		roof[2][11]='-';
		roof[2][1]='X';
        roof[2][10]='X';
		
	//Fourth row
    roof[3][0]='X';
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
	roof[3][11]='X';


    if(row < 3 ){

        roof[row][col] ='*';
    }

    for (i = 0; i < RSIZE; i++) {
        for (j = 0; j < 12; j++) {
            std::cout<<roof[i][j]<<' ';
        }
        std::cout<<std::endl;
    }

//For the house

    for (i = 0; i < HSIZE; i++) {
        for (j = 0; j < 32; j++) {
            
            if (i == 0) {
                house[i][j] = '=';
            } else if (i == 6) {
                house[i][j] = '=';
            } else if (i == 12) {
                house[i][j] = '=';
            } else if( i == 1 || i == 2 || i == 4|| i == 5||i == 7|| i == 8|| i == 10||i == 11){
				for(j=1; j<11; j++){
					house[i][j] ='-';
				}
				for(j=12; j<21; j++){
					house[i][j] ='-';
				}
				for(j=22; j<31; j++){
					house[i][j]='-';
				}
            }

        }

    }
	for (i = 0; i < HSIZE; i++) {
        for (j = 0; j < 32; j++) {
			if (j == 0 || j==11 || j== 21|| j==31) {
               for(i=1 ; i < 6; i++){
                house[i][j] = '|';
			   }
			   for(i=7 ; i<12; i++){
				   house[i][j] ='|';
			   }
	}}}
	

	house[3][1]= '-';
    house[3][2] ='<';
    house[3][3] ='B';
    house[3][4] ='E';
    house[3][5] ='D';
    house[3][6] ='R';
    house[3][7] ='M';
    house[3][8] ='1';
    house[3][9] ='>';
	house[3][10]='-';
	

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
	house[3][30] ='-';


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


    for (i = 0; i < HSIZE; i++) {
        for (j = 0; j < 32; j++) {
            std::cout<<house[i][j]<<' ';
        }
        std::cout<<std::endl;
    }

}

