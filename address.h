#ifndef ADDRESS_H
#define ADDRESS_H

#include <QString>
class Address
{
private:
    QString city,street,house,corpus;
public:
    Address(const QString& city,const QString& street,
            const QString& house, const QString& corpus);
    QString getCity()const;
    QString getStreet()const;
    QString getHouse()const;
    QString getCorpus()const;
};

#endif // ADDRESS_H
