#include <stdio.h>
#include <ctime>
#include <string>
#include <iostream>

#include "Block.h"
#include "Blokc_chain.h"
#include "Kodadvimas_2.cpp"
#include "Kodavimas.cpp"

#include <vector>


Block Blockchain::create_genesis_block()
{
std::time_t current;

std::vector<Transaction_data> genesis_vec;

std::vector<std::string> genesis_transaction_hashes;

Transaction_data d(0,"Genesis","Genesis",time(&current),"1");

genesis_vec.push_back(d);

genesis_transaction_hashes.push_back(kardinalus_pokyciai(std::to_string(d.amount))+d.send_key+d.receive_key+std::to_string(d.timestamp));

std::string merkel_genesis=ComputeMerkleRoot(genesis_transaction_hashes);

std::string prev_genesis="0";
std::string hash_genesis;
int nonce_genesis=0;

std::string default_target_genesis="A";

do{
 hash_genesis=kardinalus_pokyciai(merkel_genesis+prev_genesis+std::to_string(time(&current))+std::to_string(nonce_genesis)+default_target_genesis);
nonce_genesis++;

}while(hash_genesis.at(0)!=default_target_genesis.at(0));


Block genesis(hash_genesis,prev_genesis,merkel_genesis,time(&current),genesis_vec,nonce_genesis,default_target_genesis);

return genesis;
}



void Blockchain::addBlock(std::vector<Transaction_data>data)
{

   if(chain.size()==0)
    {

    Block genesis = create_genesis_block();
    chain.push_back(genesis);
    print_block();

    }

    std::cout<<"PROOF OF WORK : "<<std::endl;
    std::cout<<std::endl;
    std::vector<std::string>transaction_hashes;

    for(int i=0;i<data.size();i++)
    {
        transaction_hashes.push_back(data[i].thash);
    }
    std::string merkel=ComputeMerkleRoot(transaction_hashes);
    std::string previous = chain.back().block_hash;
    int nonce=0;
     std::string hash_b;
     std::string default_t="00";
     std::string laikinas;
     std::string laikinas_2;
     std::string abu;
     time_t pradzia;
    do{
    hash_b=kardinalus_pokyciai(merkel+previous+std::to_string(time(&pradzia))+std::to_string(nonce)+default_t);
    laikinas=hash_b.at(0);
    laikinas_2=hash_b.at(1);
    abu=laikinas+laikinas_2;
    std::cout<<hash_b<<" NONCE : "<<nonce<<std::endl;


    nonce++;
}while(abu!=default_t);

Block newBlock(hash_b,previous,merkel,pradzia,data,nonce,default_t);
chain.push_back(newBlock);
print_block();

}


void Blockchain::print_block()
{

        Block current_block=chain.back();
        std::cout<<std::endl;
        std::cout<<"Block ============================================================================"<<std::endl;
        std::cout<<std::endl;
        std::cout<<"Bloke atliktos transakcijos : "<<std::endl;
        for(int k=0;k<current_block.data.size();k++)
        {
            std::cout<<current_block.data[k].send_key<<" -> "<<current_block.data[k].receive_key<<" "<<current_block.data[k].amount<<" "<<current_block.data[k].timestamp<<" "<<current_block.data[k].thash<<std::endl;
        }
        std::cout<<std::endl;
        std::cout<<"Timestamp: "<<current_block.start<<std::endl;
        std::cout<<std::endl;
        std::cout<<"Block hash: "<<current_block.block_hash<<std::endl;
        std::cout<<std::endl;
        std::cout<<"Previous block Hash: "<<current_block.previous_hash<<std::endl;
        std::cout<<std::endl;
        std::cout<<"Merkel tree: "<<current_block.merkel<<std::endl;
        std::cout<<std::endl;
        std::cout<<"Nonce : "<<current_block.nonce<<std::endl;
        std::cout<<std::endl;
        std::cout<<"===================================================="<<std::endl;
        std::cout<<std::endl;


}
