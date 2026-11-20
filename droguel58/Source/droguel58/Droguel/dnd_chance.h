#pragma once

class dnd_chance
{
public:

    dnd_chance();
    ~dnd_chance();

   static bool pickRandom();
   static int randomBetween(int x1, int x2);
   static bool randomBetweenSafe(int x1, int x2, int& randnum, int padding, int min);
   static int randomSplit(int x1, int x2, int padding);
   static int getRandomIntWithProbability();
   static int getRandomInt(int minval, int maxval);
   static bool perChance(int percent);
};
