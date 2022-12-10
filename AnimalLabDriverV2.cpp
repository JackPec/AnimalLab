#include <iostream>
#include <string>
#include <vector>
#include "randVal.h"
#include "animalV2.h"

using namespace std;

int main(void)
{

    vector<prey> preylist;
    vector<predator> predatorlist;

    string preyName;
    string predatorName;

    long preyPop;
    long predPop;

    long speedLower;
    long speedUpper;

    long foodUpper;
    long foodLower;

    long birthUpperPrey;
    long birthLowerPrey;

    long deathUpperPrey;
    long deathLowerPrey;

    long birthUpperPred;
    long birthLowerPred;

    long deathUpperPred;
    long deathLowerPred;

    long hungerUpper;
    long hungerLower;

    long numOfPredEats;

    size_t gen;

    cout << "Enter prey name: ";
    cin >> preyName;

    cout << "Enter predator name: ";
    cin >> predatorName;

    cout << "Enter Prey population: ";
    cin >> preyPop;

    cout << "Enter Predator population: ";
    cin >> predPop;


    cout << "Enter how many generations: ";
    cin >> gen;

    cout << "Enter lower bound for speed: ";
    cin >> speedLower;
    cout << "Enter Upper bound for speed: ";
    cin >> speedUpper;
    cout << "Enter lower bound for food: ";
    cin >> foodLower;
    cout << "Enter Upper bound for food: ";
    cin >> foodUpper;


    cout << "\nFor Prey\n";
    cout << "Enter lower bound for birthrate: ";
    cin >> birthLowerPrey;
    cout << "Enter Upper bound for birthrate: ";
    cin >> birthUpperPrey;

    cout << "Enter lower bound for death rate: ";
    cin >> deathLowerPrey;
    cout << "Enter Upper bound for death rate: ";
    cin >> deathUpperPrey;

    cout << "\nFor Predators\n";
    cout << "Enter lower bound for birthrate: ";
    cin >> birthLowerPred;
    cout << "Enter Upper bound for birthrate: ";
    cin >> birthUpperPred;

    cout << "Enter lower bound for death rate: ";
    cin >> deathLowerPred;
    cout << "Enter Upper bound for death rate: ";
    cin >> deathUpperPred;


    //when pred hunger becomes  < 0, they stop eating
    cout << "Enter lower bound for hunger for predators: ";
    cin >> hungerLower;
    cout << "Enter Upper bound for hunger for predators: ";
    cin >> hungerUpper;

    cout << "Enter Upper bound how many predators could eat prey: ";
    cin >> numOfPredEats;

    //sets up beginning pops
    for(size_t i = 0; i < static_cast<size_t>(preyPop); i++)
    {
        prey temp1(preyName,
                   rand_range(static_cast<long>(speedLower),
                              static_cast<long>(speedUpper)),
                   rand_range(static_cast<long>(foodLower),
                              static_cast<long>(foodUpper)));

        preylist.push_back(temp1);

    }

    for(size_t i = 0; i < static_cast<size_t>(predPop); i++)
    {
        long predHunger = rand_range(hungerLower,hungerUpper);

        long predSpeed = rand_range(speedLower,speedUpper);

        predator temp2(predatorName,
                       predSpeed,
                       predHunger);

        predatorlist.push_back(temp2);

    }







    std::cout << "Initial Predator Pop: " << predatorlist.size() << "\n";
    std::cout << "Initial Prey Pop: " << preylist.size() << "\n";



    // main do loop
    do
    {


        for(size_t i = 0; i < static_cast<size_t>(
                    rand_range(1, numOfPredEats)); i++ )
        {

            if(predatorlist.size() > 0 && preylist.size() > 0)
            {
                //get's a random index in prey list
                size_t k = static_cast<size_t>(
                               rand_range(0,
                               static_cast<long>(preylist.size()-1)));

                //get's a random index in predator list
                size_t p = static_cast<size_t>(
                               rand_range(0,
                               static_cast<long>(predatorlist.size()-1)));


                // predator will only attempt to eat if they
                //still have hunger
                //and if true..
                if(predatorlist[p].eat(preylist[k]))
                {
                    preylist.erase(preylist.begin() + k);

                }


                //hunger reset


                for(size_t b = 0; b <  predatorlist.size(); b++ )
                {
                    predatorlist[b].resetHunger();
                    //reset to hunger they had
                    //when formed in list

                }
            }

        }


        //deathrate

        //prey
        for(size_t i = 0; i < static_cast<size_t>(
                    rand_range(deathLowerPrey, deathUpperPrey)); i++ )
        {

            if(preylist.size() > 0)
            {
                preylist.pop_back();
            }
        }

        //pred
        for(size_t i = 0; i < static_cast<size_t>(
                    rand_range(deathLowerPred, deathUpperPred)); i++ )
        {

            if(predatorlist.size() > 0)
            {
                predatorlist.pop_back();
            }
        }


        //birthrate

        //prey
        for(size_t i = 0; i < static_cast<size_t>(
                    rand_range(birthLowerPrey,birthUpperPrey)); i++ )
        {

            //long predandpreyBirth = rand_range(birthLower,birthUpper);

            //long predHunger = rand_range(hungerLower,hungerUpper);

            //long predSpeed = rand_range(speedLower,speedUpper);

            prey temp1(preyName,rand_range(static_cast<long>(speedLower),
                                           static_cast<long>(speedUpper)),
                       rand_range(static_cast<long>(foodLower),
                                  static_cast<long>(foodUpper)));

            preylist.push_back(temp1);

        }

        //pred
        for(size_t i = 0; i < static_cast<size_t>(
                    rand_range(birthLowerPred, birthUpperPred)); i++ )
        {
            long predSpeed = rand_range(speedLower,speedUpper);

            long predHunger = rand_range(hungerLower,hungerUpper);

            predator temp2(predatorName,
                           predSpeed,
                           predHunger);

            predatorlist.push_back(temp2);


        }



        std::cout << "Number of predators left: "
                  << predatorlist.size() << "\n";

        std::cout << "Number of prey left: " << preylist.size() << "\n";


        --gen;
    }while(!predatorlist.empty() && !preylist.empty() && gen != 0);

    return 0;
}



