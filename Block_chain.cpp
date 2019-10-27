#include <stdio.h>
#include <ctime>
#include <string>
#include <iostream>
#include <chrono>

#include "Block.h"
#include "Blokc_chain.h"
#include "Kodadvimas_2.cpp"
#include "Kodavimas.cpp"

#include <vector>


Block Blockchain::create_genesis_block()
{
long long int  current = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
std::string genesis_version="1.0";

std::vector<Transaction_data> genesis_vec;

std::vector<std::string> genesis_transaction_hashes;

Transaction_data d(0,"Genesis","Genesis",current,"1");

genesis_vec.push_back(d);

genesis_transaction_hashes.push_back(kardinalus_pokyciai(std::to_string(d.amount))+d.send_key+d.receive_key+std::to_string(d.timestamp));

std::string merkel_genesis=ComputeMerkleRoot(genesis_transaction_hashes);

std::string prev_genesis="0";
std::string hash_genesis;
int nonce_genesis=0;

std::string default_target_genesis="A";

do{
 hash_genesis=kardinalus_pokyciai(merkel_genesis+prev_genesis+std::to_string(current)+std::to_string(nonce_genesis)+default_target_genesis);
nonce_genesis++;

}while(hash_genesis.at(0)!=default_target_genesis.at(0));


Block genesis(hash_genesis,prev_genesis,merkel_genesis,current,genesis_vec,nonce_genesis,default_target_genesis,genesis_version);

return genesis;
}

void Blockchain::check_trans_id(std::vector<Transaction_data> data)
{


    std::string check_send;
    std::string check_receive;
    std::string check_amount;
    std::string  check_timestamp;
    std::string check_thash;
    std::string to_string_amount;
    std::string to_string_timestamp;

    for(int i=0;i<data.size();i++)
    {

        check_send=data[i].send_key;
        check_receive=data[i].receive_key;
        check_amount=std::to_string(data[i].amount);
        check_timestamp=std::to_string(data[i].timestamp);

        check_thash=kardinalus_pokyciai(check_amount+check_send+check_receive+check_timestamp);

        if(check_thash!=data[i].thash) {
          std::cout<<"NESUTAMPA TRANSAKCIJOS DUOMENYS"<<std::endl;
        }
    }
}



int Blockchain::addBlock(std::vector<Transaction_data>data,int sec_counter,int block_id,std::vector<int> &vec_id )
{

std::string block_version="2.0";

check_trans_id(data);


   if(chain.size()==0)
    {

    Block genesis = create_genesis_block();
    chain.push_back(genesis);
    print_block();


    }
std::cout<<std::endl;
std::cout<<"Laikas skirtas mininti : "<<sec_counter<<"s"<<std::endl;
std::cout<<"Blocko id : "<<block_id<<std::endl;
std::cout<<std::endl;
    std::cout<<"PROOF OF WORK : "<<std::endl;
    std::cout<<std::endl;
    std::vector<std::string>transaction_hashes;

    for(int i=0;i<data.size();i++)
    {
        transaction_hashes.push_back(data[i].thash);
    }
    std::string merkel=ComputeMerkleRoot(transaction_hashes);
    std::string previous = chain.back().block_hash;

     std::string hash_b;
     std::string default_t="00";
     std::string laikinas;
     std::string laikinas_2;
     std::string abu;
     long long int beginning = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
     int nonce;


    auto start = std::chrono::steady_clock::now();

    do{
    nonce=vec_id[block_id];
    hash_b=kardinalus_pokyciai(merkel+previous+std::to_string(beginning)+std::to_string(nonce)+default_t+block_version);
    laikinas=hash_b.at(0);
    laikinas_2=hash_b.at(1);
    abu=laikinas+laikinas_2;


    nonce++;
    vec_id[block_id]=nonce;
    std::cout<<hash_b<<" NONCE : "<<nonce<<std::endl;

    auto end = std::chrono::steady_clock::now();



    if(std::chrono::duration_cast<std::chrono::seconds>(end - start).count()>sec_counter)
    {
        std::cout<<"Neuzteko laiko iskasti bloko"<<std::endl;
        std::cout<<std::endl;
        return 1;
        break;


    }

}while(abu!=default_t);


Block newBlock(hash_b,previous,merkel,beginning,data,nonce,default_t,block_version);
chain.push_back(newBlock);
print_block();
return 0;
}

void Blocks_maker(std::vector<Transaction_data> vartot_transac)
{

    Blockchain What;
    std::vector<int>vec_id{0,0,0,0,0};
    std::random_device rd;
    std::mt19937 g(rd());
    std::vector<Transaction_data> temp_catch;
    std::vector<std::vector<Transaction_data>> catch_transaction;
    int rand_1;

   for(int i=0;i<5;i++)
   {
       for(int k=0;k<100;k++)
       {
           rand_1=rand()%vartot_transac.size();
           temp_catch.push_back(vartot_transac[rand_1]);
           vartot_transac.erase(vartot_transac.begin()+rand_1);
       }
       catch_transaction.push_back(temp_catch);
       temp_catch.clear();

   }

   std::vector<int>rand_vec{0,1,2,3,4};
   std::shuffle(rand_vec.begin(), rand_vec.end(), g);

int count_sec=1;
int found=0;


while(found<1){
   for(int i=0;i<rand_vec.size();i++)
   {
       if(What.addBlock(catch_transaction[i],count_sec,i,vec_id)==0)
       {
           found=1;
           break;
       }
   }
   count_sec++;
}

}


void Blockchain::print_block()
{

        Block current_block=chain.back();
        std::cout<<std::endl;
        std::cout<<"Block ============================================================================"<<std::endl;
        std::cout<<std::endl;
        /*std::cout<<"Bloke atliktos transakcijos : "<<std::endl;
        for(int k=0;k<current_block.data.size();k++)
        {
            std::cout<<current_block.data[k].send_key<<" -> "<<current_block.data[k].receive_key<<std::endl;
            std::cout<<"Kiekis : "<<current_block.data[k].amount<<std::endl;
            std::cout<<"Timestamp'as : "<<current_block.data[k].timestamp<<std::endl;
            std::cout<<"Transakcijos hash'as "<<current_block.data[k].thash<<std::endl;
            std::cout<<std::endl;
        }
        std::cout<<"-----------------------"<<std::endl;*/
        std::cout<<"Block timestamp: "<<current_block.start<<std::endl;
        std::cout<<std::endl;
        std::cout<<"Block hash: "<<current_block.block_hash<<std::endl;
        std::cout<<std::endl;
        std::cout<<"Previous block Hash: "<<current_block.previous_hash<<std::endl;
        std::cout<<std::endl;
        std::cout<<"Merkel tree: "<<current_block.merkel<<std::endl;
        std::cout<<std::endl;
        std::cout<<"Nonce : "<<current_block.nonce<<std::endl;
        std::cout<<std::endl;
        std::cout<<"Version : "<<current_block.version<<std::endl;
        std::cout<<std::endl;
        std::cout<<"===================================================="<<std::endl;
        std::cout<<std::endl;


}

