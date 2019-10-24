#include <bitset>
#include <sstream>
#include <vector>
#include <iomanip>
#include <string>

char genRandom2(int keist)
{


    char simboliai[] ="ABCDEF6789012345abcdefA";
    int iSecret;
    iSecret = keist%23;

    return simboliai[iSecret];
}
std::string kardinalus_pokyciai(std::string tekstas)
{

    std::string pagrindas="!!!!!!!!!!!!!!!!!!";
    long long int raideliuSriuba=0;


    for(int i=0;i<tekstas.size();i++)
    {
        raideliuSriuba=raideliuSriuba+(int(tekstas[i])*(i+1));
    }

    std::string tarpinis=std::to_string(tekstas.size())+std::to_string(raideliuSriuba);

    pagrindas.erase(0,tarpinis.size());

    std::string pradzia=std::to_string(tekstas.size());

    std::string geras=pradzia+pagrindas;

    std::string raides=std::to_string(raideliuSriuba);

    geras.insert(geras.size()/2+1,raides);

    std::string suminis = std::bitset< 32 >(raideliuSriuba).to_string();

    for(int j=0;j<suminis.size();j++)
    {
        if(suminis[j]=='1')
           {
            for(int k=geras.size()/2+1;k>=0;k--)
                {
                    int pridedam=int(geras[k])+geras[k+1]%geras.size();
                    char a=pridedam;
                    geras[k]=a;

                }
           }
        else if(suminis[j]=='0')
           {
            for(int k=geras.size()/2+1;k<geras.size();k++)
                {
                    int pridedam2=int(geras[k])-geras[k-1]%geras.size();
                    char a2=pridedam2;
                    geras[k]=a2;
                }
            }
    }

    std::stringstream ss;
    std::string hashas;
    int16_t vertimas;


    for(int j=0;j<geras.size();j++)
    {
        vertimas=int(geras[j]);
        ss <<std::setfill ('0') << std::setw(sizeof(int))<< std::hex << vertimas;
        hashas=ss.str();
    }
    std::string tikr;
    unsigned int x;
    int golas=0;
    std::vector <int> KO;


    for(int p=0;p<hashas.size();p++)
    {
        if(hashas[p]=='f'||hashas[p]=='0'||hashas[p]=='a'||hashas[p]=='b')
            golas++;
        KO.push_back(static_cast<int>(hashas[p])*(p+1));
    }
        for(int k=0;k<KO.size();k++)
    {

tikr+=genRandom2((KO[k]+golas)*int(hashas.back()));
    }

    return tikr;
}
