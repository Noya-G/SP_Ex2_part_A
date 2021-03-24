/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: <Please write your names here>
 * 
 * Date: 2020-02
 */

#include "doctest.h"
#include "Board.hpp"
#include "Direction.hpp"
#include <stdexcept>
#include <ctime>
using namespace ariel;
#include <string>
using namespace std;


TEST_CASE("Basic Test -Horizontal") {
    Board board;
    string right = "right massege";
    board.post(100,200,Direction::Horizontal,right);
    CHECK(board.read(100,200,Direction::Horizontal,13)==right);
}

TEST_CASE("Basic Test -Vertical") {
    Board board;
    string right = "right massege";
    board.post(100,200,Direction::Vertical, right);
    CHECK(board.read(100,200,Direction::Vertical,13)==right);
}

TEST_CASE("Test for a row"){
    Board board;
    string right = "right massege";
    string wrong = "worng massege";
    board.post(14,15,Direction::Horizontal,right);
    CHECK(board.read(14,0,Direction::Horizontal,17)==right);

}

TEST_CASE("Test for a column"){
    Board board;
    string right = "right massege";
    string wrong = "worng massege";
    board.post(14,15,Direction::Vertical,right);
    CHECK(board.read(14,0,Direction::Vertical,17)==wrong);

}

TEST_CASE("overwrite massege -Vertical"){
    Board board;
    string right = "right massege";
    string wrong = "worng massege";
    board.post(0,0,Direction::Vertical,wrong);
    board.post(0,0,Direction::Vertical,right);
    CHECK(board.read(0,0,Direction::Vertical,7)==right);
}

TEST_CASE("overwrite massege -Horizontal"){
    Board board;
    string right = "right massege";
    string wrong = "worng massege";
    board.post(0,0,Direction::Horizontal,wrong);
    board.post(0,0,Direction::Horizontal,right);
    CHECK(board.read(0,0,Direction::Horizontal,7)==right);
}

TEST_CASE("write small message"){
    Board board;
    string s="";
    for (int i = 0; i < 200; i++)
    {
        s=s+"a";
    }
    
    board.post(23,67,Direction::Vertical,s);
    CHECK(board.read(23,67,Direction::Vertical,7)==s);
}

TEST_CASE("write medum message"){
    Board board;
    string s="";
    for (int i = 0; i < 20000; i++)
    {
        s=s+"b";
    }
    
    board.post(23,67,Direction::Vertical,s);
    CHECK(board.read(23,67,Direction::Vertical,7)==s);
}

TEST_CASE("write long message"){
    Board board;
    string s="";
    for (int i = 0; i < 70000; i++)
    {
        s=s+"c";
    }
    
    board.post(23,67,Direction::Vertical,s);
    CHECK(board.read(23,67,Direction::Vertical,7)==s);
}

TEST_CASE("randomize location on the board -Horizontal"){
    int column;
    int row;
    for (int i = 0; i < 100; i++)
    {
Board board;
    srand((unsigned)time(NULL));
    column = rand() %10000;
    row = rand() %10000;
    board.post(row,column,Direction::Horizontal,"Hi");
    CHECK( board.read(row, column, Direction::Horizontal, 7)=="Hi");
    }
}

TEST_CASE("randomize location on the board -Vertical"){
    int column;
    int row;
    for (int i = 0; i < 100; i++)
    {
    Board board;
    srand((unsigned)time(NULL));
    column = rand() %10000;
    row = rand() %10000;
    board.post(row,column,Direction::Vertical,"Hi");
    CHECK( board.read(row, column, Direction::Vertical, 7)=="Hi");
    }
}

