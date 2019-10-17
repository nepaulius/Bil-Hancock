#include <stdio.h>
#include <ctime>
#include <string>
#include <iostream>

#include "Block.h"
#include "Blokc_chain.h"
#include "Kodadvimas_2.cpp"


#include <vector>


Blockchain::Blockchain()
{
    Block genesis = create_genesis_block();
    chain.push_back(genesis);
}

std::vector<Block> Blockchain::get_chain()
{
    return chain;
}

Block Blockchain::create_genesis_block()
{
std::time_t current;

std::vector<Transaction_data> genesis_vec;
Transaction_data d(0,"Genesis","Genesis",time(&current),"1");
genesis_vec.push_back(d);

Block genesis(0,genesis_vec,"0","0");

return genesis;
}


Block *Blockchain::get_latest_block()
{
    return &chain.back();
}


void Blockchain::addBlock(std::vector<Transaction_data>pilnas)
{
    int index = (int)chain.size();
    std::string latest_hash;
    if((int)chain.size()>0)
    {
         latest_hash=get_latest_block()->get_hash();

    }
    else  latest_hash="0";

    std::vector<std::string>hashes;
    for(int k=0;k<pilnas.size();k++)
    {
        hashes.push_back(pilnas[k].thash);
    }

    std::string merkel_root=ComputeMerkleRoot(hashes);
    Block new_block(index, pilnas, latest_hash,merkel_root);
    chain.push_back(new_block);

}
bool Blockchain::is_chain_valid()
{
    std::vector<Block>::iterator it;
    int chainLen = (int)chain.size();


    for(it=chain.begin();it!=chain.end();++it)
    {
     Block currentBlock = *it;

     if(!currentBlock.is_hash_valid())
     {
         return false;
     }
     else if(it!=chain.begin())
     {
         Block previous_block = *(it-1);
         if(currentBlock.get_previous_hash()!=previous_block.get_hash())
         {
             return false;
         }
     }
    }
    return true;
}

void Blockchain::print_chain()
{
    std::vector<Block>::iterator it;

    for(it=chain.begin();it<chain.end();++it)
    {
        Block current_block= *it;
        std::cout<<"Block ============================================================================"<<std::endl;
        std::cout<<std::endl;
        std::cout<<"Index : "<<current_block.get_index()<<std::endl;
        std::cout<<std::endl;
        std::cout<<"Bloke atliktos transakcijos : "<<std::endl;
        for(int k=0;k<current_block.pilnas.size();k++)
        {
            std::cout<<current_block.pilnas[k].send_key<<" -> "<<current_block.pilnas[k].receive_key<<" "<<current_block.pilnas[k].amount<<" "<<current_block.pilnas[k].timestamp<<" "<<current_block.pilnas[k].thash<<std::endl;
        }
         std::cout<<std::endl;
        std::cout<<"Block hash: "<<current_block.get_hash()<<std::endl;
        std::cout<<std::endl;
        std::cout<<"Previous block Hash: "<<current_block.get_previous_hash()<<std::endl;
        std::cout<<std::endl;
        std::cout<<"Merkel tree: "<<current_block.merkel<<std::endl;
        std::cout<<std::endl;
        std::cout<<"Is block valid : "<<current_block.is_hash_valid()<<std::endl;

    }
}
