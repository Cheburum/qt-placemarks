#include "address.h"

Address::Address(const QString& city,const QString& street,
                 const QString& house, const QString& corpus):
    city(city),street(street),house(house),corpus(corpus)
{
}

QString Address::getCity()const{
    return city;
}
QString Address::getStreet()const{
    return street;
}

QString Address::getHouse()const{
    return house;
}
QString Address::getCorpus()const{
    return corpus;
}
