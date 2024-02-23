
#include <iostream>
#include "systa.hpp"


/*!
 *
 */
Systa::Systa()
{
   // do something
}

/*!
 *
 */
void Systa::register_value(uint16_t id, SystaValue value)
{
   this->m_values.emplace(id, value);
}

/*!
 *
 */
bool Systa::get_value(uint16_t id, SystaValue & value)
{
   bool ret = false;

   const auto pos = m_values.find(id);
   if (pos != m_values.end())
   {
      value = pos->second;
      ret = true;
   }

   return ret;
}

std::string SystaValue::to_string(int32_t val)
{
   std::string str = this->m_name + ":";

   switch (this->m_type)
   {
   case eVALUE_TYPE_INT:
      str += std::to_string(val);
      break;
   case eVALUE_TYPE_INT_10:
      str += std::to_string(val / 10);
      break;
   case eVALUE_TYPE_FLOAT_10:
      str += std::to_string(((float) val) / 10.0);
      break;
   case eVALUE_BETRIEBSART:
   {
      // 0=Heiprogramm 1, 1=Heiprogramm 2, 2=Heiprogramm 3, 3=Dauernd Normal, 4=Dauernd Komfort, 5=Dauernd Absenken
      switch (val)
      {
      case 0:
         str += "Heizprogramm 1";
         break;
      case 1:
         str += "Heizprogramm 2";
         break;
      case 2:
         str += "Heizprogramm 3";
         break;
      case 3:
         str += "Dauernd Normal";
         break;
      case 4:
         str += "Dauernd Komfort";
         break;
      case 5:
         str += "Dauernd Absenken";
         break;
      default:
         str += "Betriebsart unbekannt";
         break;
      }
      break;
   }
   case eVALUE_UNKNOWN:
   default:
      str += "[";
      str += std::to_string(val) + "|";
      str += std::to_string(val / 10) + "|";
      str += std::to_string(((float) val) / 10.0) + "]";
      break;
   }

   return str;
}

/*!
 *
 */
void Systa::push_values(struct ReceivePacket * pRecvPacket)
{
   for (size_t i = 0; i < NR_OF_VALUES; i++)
   {
      SystaValue value;
      if (!this->get_value(i, value))
      {
         // set to default if not in the list
         value = SystaValue("unknown value " + std::to_string(i), eVALUE_UNKNOWN);
      }

      std::cout << value.to_string(pRecvPacket->Values[i]) << std::endl;
   }
}
