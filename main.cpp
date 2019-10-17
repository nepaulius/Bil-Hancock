#include <iostream>
#include <ctime>
#include <vector>
#include <random>

#include "Transaction_data.h"
#include "Block.h"
#include "Blokc_chain.h"

#include "Block_chain.cpp"

#include "Block.cpp"
#include "Vartotojas.cpp"

static std::random_device dev;
static std::mt19937 rng(dev());


int main()
{

    std::vector<User> visi;
    User vart;
    for(int i=0;i<10;i++)
    {
vart.vardas="User"+std::to_string(i);
vart.public_key=kardinalus_pokyciai(vart.vardas);

    std::uniform_int_distribution<std::mt19937::result_type> dist6(100,1000000);
vart.kiekis=dist6(rng);
visi.push_back(vart);
    }



Blockchain What;
std::vector<Transaction_data>bandymas;

std::string tdata_hash;
    for(int j=0;j<10;j++)
    {
        time_t duomenys;
        int a=rand() % 100;

        int nuo_ko=rand()%3;
        int kam=rand()%2+3;


        tdata_hash=kardinalus_pokyciai(std::to_string(a)+visi[nuo_ko].vardas+visi[kam].vardas+std::to_string(time(&duomenys)));
        Transaction_data duom(a,visi[nuo_ko].vardas,visi[kam].vardas,time(&duomenys),tdata_hash);
        bandymas.push_back(duom);


        visi[nuo_ko].kiekis=visi[nuo_ko].kiekis-a;
        visi[kam].kiekis=visi[kam].kiekis+a;



    }

     What.addBlock(bandymas);

    What.print_chain();




    return 0;
}
