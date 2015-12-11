#include <stdio.h>

#include "kernel.hpp"

using namespace raft;

std::size_t kernel::kernel_count( 0 );

/** default **/
kernel::kernel() : kernel_id( kernel::kernel_count )
{
   kernel::kernel_count++;
};

/** existing memory **/
kernel::kernel( void * const ptr, 
                const std::size_t nbytes ) : 
   input(  this, ptr, nbytes ),
   output( this, ptr, nbytes ),
   kernel_id( kernel::kernel_count )
{
}

kernel::~kernel()
{

}


std::size_t
kernel::get_id()
{
   return( kernel_id );
}

raft::kernel& 
kernel::operator []( const std::string &&portname )
{
   (this)->enabled_port = portname;
   return( (*this) );
}
raft::kernel& 
kernel::operator []( const std::string portname   )
{
   (this)->enabled_port = portname;
   return( (*this) );
}

std::size_t
kernel::addPort()
{
   return( 0 );
}
   
void 
kernel::lock()
{
   /** does nothing, just need a base impl **/
   return;
}

void 
kernel::unlock()
{
   /** does nothing, just need a base impl **/
   return;
}

const std::string&
kernel::getEnabledPort()
{
    return( enabled_port );
}

//std::string
//kernel::getName()
//{
//   int status( 0 );
//   const std::string name_a( 
//      abi::__cxa_demangle( typeid( *(this) ).name(), 0, 0, &status ) );
//
//}
