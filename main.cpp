#include <unistd.h>
#include "udp.hpp"
#include "SystaCompact_II.hpp"

static ssize_t process(char * buffer, ssize_t len);

static Systa * pSysta;

/*!
 *
 */
int main() {

   pSysta = new SystaCompactII();

   udp_create();

   while(1)
   {
      udp_receive(&process);

      usleep(10000); // reduce cpu load
   }

   udp_close();

   return 0;
}

/*!
 *
 */
static ssize_t process(char * buffer, ssize_t len)
{
   struct ReceivePacket * pPacket = (struct ReceivePacket *) buffer;

   pSysta->push_values(pPacket);

   // TODO generate response packet

   return 0;
}
