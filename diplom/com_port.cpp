#include "com_port.h"

class com_portData : public QSharedData
{
public:

};

com_port::com_port() : data(new com_portData)
{

}

com_port::com_port(const com_port &rhs) : data(rhs.data)
{

}

com_port &com_port::operator=(const com_port &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

com_port::~com_port()
{

}
