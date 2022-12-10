/*

Animal Lib


*/
#pragma once

#include <string>



class baseAnimal
{
    // int food;
    std::string name = "empty";
    long speed;
    // long birthrate;


public:
    baseAnimal(std::string nameIn, long speedIn = 0)
        :
        name(nameIn),
        speed(speedIn)
        //  birthrate(val2)

    {
        //   cerr << "base created:  " << this << '\n';
    }
    baseAnimal(const baseAnimal & b)
        :
        name(b.name),
        speed(b.speed)
    {
        //   cerr << "base (copy) created:  " << this << '\n';
    }
    virtual ~baseAnimal(void)
    {
        //   cerr << "base destroyed (" << this << ")\n";
    }

    baseAnimal & operator=(const baseAnimal & c) = default;


    //getters and setters
    long get_speed(void) const
    {

        return speed;
    }

    bool set_speed(long val)
    {
        bool okay = false;

        if(val >=0 )  //hardcoded
        {
            speed = val;
            okay = true;
        }

        return okay;
    }


    std::string get_name(void) const
    {

        return name;
    }

    void set_name(std::string nameIN)
    {
        name = nameIN;
    }







};


class prey : public baseAnimal
{
    long food;


public:
    prey(std::string nameIn,long speedIn = 0,long foodIn = 0)
        :
        baseAnimal(nameIn,speedIn),
        food(foodIn)

    {
        //   cerr << "prey created:  " << this << '\n';
    }
    prey(const prey & b)
        :
        baseAnimal(b),
        food(b.food)
    {
        //   cerr << "prey (copy) created:  " << this << '\n';
    }
    virtual ~prey(void)
    {
        //    cerr << "prey destroyed (" << this << ")\n";
    }

    prey & operator=(const prey & c) = default;


    //getters and setters
    long get_food(void) const
    {

        return food;
    }

    bool set_food(long val)
    {
        bool okay = false;

        if(val >=0 )  //hardcoded
        {
            food = val;
            okay = true;
        }

        return okay;
    }




};

class predator : public baseAnimal
{
    long maxHunger;
    long hunger;


public:
    predator(std::string nameIn, long speedIn = 0,long hungerIn = 0)
        :
        baseAnimal(nameIn,speedIn),
        maxHunger(hungerIn),
        hunger(hungerIn)


    {
        //   cerr << "predator created:  " << this << '\n';
    }
    predator(const predator & b)
        :
        baseAnimal(b),
        maxHunger(b.maxHunger),
        hunger(b.hunger)

    {
        //   cerr << "predator (copy) created:  " << this << '\n';
    }
    virtual ~predator(void)
    {
        //   cerr << "predator destroyed (" << this << ")\n";
    }

    predator & operator=(const predator & c) = default;

    //getters and setters
    long get_hunger(void) const
    {

        return hunger;
    }

    bool set_hunger(long val)
    {
        bool okay = false;

        if(val >=0 )  //hardcoded
        {
            hunger = val;
            okay = true;
        }

        return okay;
    }


    void resetHunger()
    {
        hunger = maxHunger;
    }

    //stops being called when hunger is less than or equal to 0
    bool eat(prey & p)
    {
        bool returnVal = false;

        if(baseAnimal::get_speed() > p.baseAnimal::get_speed()
                && hunger > 0)
        {
            hunger -= p.get_food();
            returnVal = true;

        }

        return returnVal;

    }



};


















