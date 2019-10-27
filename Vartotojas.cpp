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

    std::uniform_int_distribution<std::mt19937::result_type> dist6(100,100000);
    vart.kiekis=dist6(mt);
    visi.push_back(vart);
    }

    return visi;
}


std::vector<Transaction_data> generate_vartot_transac(std::vector<User> visi)
{

 std::string tdata_hash;
 std::vector<Transaction_data>data_transac;

 std::string pakeistas;

    int nuo_ko;
    int kam;
    for(int j=0;j<2000;j++)
    {
        long long int  now = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        std::uniform_int_distribution<std::mt19937::result_type> dead_presidents(0,100000);
        int amount=dead_presidents(mt);


       while(1>0){

        nuo_ko=rand()%visi.size();
        kam=rand()%visi.size();


        if(nuo_ko!=kam)
        break;
        }

        tdata_hash=kardinalus_pokyciai(std::to_string(amount)+visi[nuo_ko].vardas+visi[kam].vardas+std::to_string(now));

        Transaction_data duom(amount,visi[nuo_ko].vardas,visi[kam].vardas,now,tdata_hash);
        data_transac.push_back(duom);

        pakeistas=std::to_string(amount);

        visi[nuo_ko].kiekis=visi[nuo_ko].kiekis-amount;
        visi[kam].kiekis=visi[kam].kiekis+amount;


    }

    return data_transac;

}
std::vector<Transaction_data>find_only_gut_transactions(std::vector<Transaction_data> all,std::vector<User>&users)
{
    for(int i=0;i<all.size();i++)
    {
        for(int j=0;j<users.size();j++)
        {
            if(all[i].send_key==users[j].vardas && users[j].kiekis-all[i].amount<0)
            {

                all.erase(all.begin()+i);
                i--;
                break;


            }

            else if(all[i].send_key==users[j].vardas && users[j].kiekis-all[i].amount>=0)

            {

                users[j].kiekis=users[j].kiekis-all[i].amount;
                for(int k=0;k<users.size();k++)
                {
                    if(all[i].receive_key==users[k].vardas)
                    {
                        users[k].kiekis=users[k].kiekis+all[i].amount;
                    }
                }

            }

        }
    }
    return all;
}
