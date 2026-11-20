#include "dnd_chance.h"
#include <string>
#include <ctime>
#include <cstdlib>
#include <random>
#include <iostream>


dnd_chance::dnd_chance()
{
}


dnd_chance::~dnd_chance()
{
}


bool dnd_chance::pickRandom()
{
    int flip;
    flip = rand() % 2 + 1;// assign random numbers
    return (flip == 1);
}


//21 22 23 24 25 26 27 28 29 30
int dnd_chance::randomBetween(int x1, int x2)
{
    int diff = x2 - x1 + 1;
    int randnum = (rand() % diff);
    randnum = randnum + x1;// -1;
    return randnum;
}

bool dnd_chance::randomBetweenSafe(int x1, int x2, int& randnum, int padding, int min)
{
    int diff = (x2 - padding) - (x1 + padding) + 1;
    bool safe = diff > 0;

    if (safe)
    {
        safe = (diff >= min);
    }

    if (safe)
    {
        randnum = (rand() % diff);
        randnum = randnum + (x1 + padding);// -1;
    }
    return safe;
}

// 1 2 3 4 5 6 7 8 9 
int dnd_chance::randomSplit(int x1, int x2, int padding)
{
    int split = 0;

    int diff = (x2 - padding) - (x1 + padding) + 1;

    if (diff > 0)
    {
        split = (rand() % diff);
        split = split + (x1 + padding);// -1;
    }
    return split;
}

//https://cplusplus.com/reference/random/normal_distribution/
int dnd_chance::getRandomIntWithProbability()
{
    const int nrolls = 10000;  // number of experiments
    const int nstars = 100;    // maximum number of stars to distribute

    std::default_random_engine generator;
    std::normal_distribution<double> distribution(5.0, 2.0);

    int p[10] = {};

    for (int i = 0; i < nrolls; ++i) {
        double number = distribution(generator);
        if ((number >= 0.0) && (number < 10.0)) ++p[int(number)];
    }

    std::cout << "normal_distribution (5.0,2.0):" << std::endl;

    for (int i = 0; i < 10; ++i) {
        std::cout << i << "-" << (i + 1) << ": ";
        std::cout << std::string(p[i] * nstars / nrolls, '*') << std::endl;
    }

    return 0;
}


int dnd_chance::getRandomInt(int minval, int maxval)
{
    //srand(time(0));
    int range = maxval - minval + 1;
    return ((rand() % range) + minval);
}



bool dnd_chance::perChance(int percent)
{
    //bool hit = false;

    //std::srand(std::time(nullptr)); // seed the random number generator

    int randomNumber = std::rand() % 100 + 1; // generate a random number between 1 and 100

    if (randomNumber <= percent) 
    {
        return true;
    }
    else 
    {
        return false;
    }

    //return hit;
}