#include <vector>
#include <stdio.h>
#include <ctime>
#include <string>
#include <iostream>
#include <random>

static std::random_device dev;
static std::mt19937 mt(dev());

class User{
    public:
 std::string vardas;
 std::string public_key;
 int kiekis;
};

std::vector<User> generate_vartot()
{
    User vart;
    std::vector<User> visi;
    for(int i=0;i<1000;i++)
    {
vart.vardas="User"+std::to_string(i);
vart.public_key=kardinalus_pokyciai(vart.vardas);

    std::uniform_int_distribution<std::mt19937::result_type> dist6(100,1000000);
    vart.kiekis=dist6(mt);
    visi.push_back(vart);
    }
    return visi;
}


std::vector<Transaction_data> generate_vartot_transac(std::vector<User> visi)
{
 std::string tdata_hash;
 std::vector<Transaction_data>data_transac;

    for(int j=0;j<300;j++)
    {
        time_t duomenys;
        std::uniform_int_distribution<std::mt19937::result_type> dead_presidents(100,200);
        int amount=dead_presidents(mt);


        int nuo_ko;
        int kam;
       while(1>0){

        nuo_ko=rand()%visi.size();
        kam=rand()%visi.size();


        if(nuo_ko!=kam && visi[nuo_ko].kiekis-amount>=0)
        break;
        }


        tdata_hash=kardinalus_pokyciai(std::to_string(amount)+visi[nuo_ko].vardas+visi[kam].vardas+std::to_string(time(&duomenys)));
        Transaction_data duom(amount,visi[nuo_ko].vardas,visi[kam].vardas,time(&duomenys),tdata_hash);
        data_transac.push_back(duom);


        visi[nuo_ko].kiekis=visi[nuo_ko].kiekis-amount;
        visi[kam].kiekis=visi[kam].kiekis+amount;


    }
    return data_transac;
}
