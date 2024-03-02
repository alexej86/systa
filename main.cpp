#include <unistd.h>
#include "udp.hpp"
#include "SystaCompact_II.hpp"
#include "mqtt.hpp"

static ssize_t process(char * buffer, ssize_t len);

static Systa * pSysta;

/*!
 *
 */
int main() {

   pSysta = new SystaCompactII();

   udp_create();
   mqtt_create();

   while(1)
   {
      udp_receive(&process);
      mqtt_loop();

      usleep(10000); // reduce cpu load
   }

   udp_close();
   mqtt_close();

   return 0;
}

void new_value(const SystaValue &value)
{
   const std::string topic = "systa/" + value.get_name();
   const std::string payload = value.to_string();

   mqtt_publish(topic.c_str(), payload.c_str());
}

/*!
 *
 */
static ssize_t process(char * buffer, ssize_t len)
{
   struct ReceivePacket * pPacket = (struct ReceivePacket *) buffer;

   pSysta->parse_values(pPacket, new_value);

   // TODO generate response packet

   return 0;
}

