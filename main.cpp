#include <iostream>
#include <ctime>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>


#include "Transaction_data.h"
#include "Block.h"
#include "Blokc_chain.h"

#include "Block_chain.cpp"

#include "Block.cpp"
#include "Vartotojas.cpp"



int main()
{

    std::vector<User> visi_vart=generate_vartot();

    std::vector<Transaction_data>vartot_transac=generate_vartot_transac(visi_vart);

    Blocks_maker(vartot_transac);

/*
    std::vector<Transaction_data> temp_vartot_transac;


    for(int i=0;i<vartot_transac.size();i++)
    {
        temp_vartot_transac.push_back(vartot_transac[i]);
        if(temp_vartot_transac.size()==5)
        {
            What.addBlock(temp_vartot_transac);
            temp_vartot_transac.clear();
        }



    }
    */


    return 0;
}
