#include <bus.h>
#include <cart.h>
u8 bus_read(u16 address)
{
    if(address < 0x8000)
    {
        return cart_read(address);
    }

    not_impl
}

void bus_write(u16 address,u8 value)
{
    if(address < 0x8000)
    {
        cart_write(address,value); //Mapping
    }

    not_impl
}
