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
    std::random_device rd;
    std::mt19937 g(rd());

    Blockchain What;



    std::vector<User> visi_vart=generate_vartot();

    std::vector<Transaction_data>vartot_transac=generate_vartot_transac(visi_vart);

    std::shuffle(vartot_transac.begin(), vartot_transac.end(), g);

    std::vector<Transaction_data> temp_vartot_transac;

    for(int i=0;i<vartot_transac.size();i++)
    {
        temp_vartot_transac.push_back(vartot_transac[i]);
        if(temp_vartot_transac.size()==100)
        {
            What.addBlock(temp_vartot_transac);
            temp_vartot_transac.clear();
        }
    }





    return 0;
}
