#ifndef BLOCK_H_INCLUDED
#define BLOCK_H_INCLUDED

#include "Transaction_data.h"

class Block{
    private:
        int index;
        std::string block_hash;
        std::string previous_hash;
        std::string generate_hash();



    public:
        Block(int idx, std::vector<Transaction_data> full, std::string prev_hash,std::string merkel_root);

        int get_index();
        std::string get_hash();
        std::string get_previous_hash();


        std::vector<Transaction_data> pilnas;
        std::string merkel;
        Transaction_data data;

        bool is_hash_valid();

};


#endif // BLOCK_H_INCLUDED
