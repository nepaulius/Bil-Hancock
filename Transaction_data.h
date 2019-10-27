#ifndef TRANSACTION_DATA_H_INCLUDED
#define TRANSACTION_DATA_H_INCLUDED

struct Transaction_data{

    int amount;
    std::string send_key;
    std::string receive_key;
    long long int timestamp;
    std::string thash;

    Transaction_data(){};

    Transaction_data(int amt,std::string sender,std::string receiver,long long int time,std::string th)
    {
        amount=amt;
        send_key=sender;
        receive_key=receiver;
        timestamp=time;
        thash=th;
    };

};


#endif // TRANSACTION_DATA_H_INCLUDED
