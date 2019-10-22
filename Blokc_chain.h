#ifndef BLOKC_CHAIN_H_INCLUDED
#define BLOKC_CHAIN_H_INCLUDED

#include <vector>


class Blockchain{
public:

std::vector<Block> chain;
Block create_genesis_block();
void addBlock(std::vector<Transaction_data> data);
void print_block();

};

#endif // BLOKC_CHAIN_H_INCLUDED
