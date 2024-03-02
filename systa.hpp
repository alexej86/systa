

#ifndef SYSTA_HPP_INCLUDED
#define SYSTA_HPP_INCLUDED

#include <stdint.h>
#include <map>
#include <string>
#include <functional>

#define NR_OF_VALUES 256

struct __attribute__((__packed__)) ReceivePacket
{
   uint8_t  macAddr[6];
   uint16_t counter;
   uint8_t  reserved1[8];
   uint8_t  packetType;
   uint8_t  reserved2[7];
   int32_t  Values[NR_OF_VALUES];
}; // 1048 bytes

enum VALUE_TYPE
{
   eVALUE_UNKNOWN,
   eVALUE_TYPE_INT,
   eVALUE_TYPE_INT_10,
   eVALUE_TYPE_FLOAT_10,
   eVALUE_BETRIEBSART
};

/*!
 *
 */
class SystaValue
{
private:
   std::string m_name;
   enum VALUE_TYPE m_type;
   int32_t m_value;

public:
   SystaValue() { /* default constructor */};
   SystaValue(std::string name, enum VALUE_TYPE type)
   {
      this->m_name = name;
      this->m_type = type;
   };
   ~SystaValue() = default;

   std::string get_name() const { return m_name; };
   std::string to_string() const;

   void Set(int32_t value) { this->m_value = value; };
};

//
typedef std::map<uint16_t, SystaValue> SystaValues;


typedef std::function<void(const SystaValue &value)> NewValueCallback;

/*!
 *
 */
class Systa
{
private:
   SystaValues m_values;

protected:
   void register_value(uint16_t id, SystaValue value);

public:
   Systa();
   ~Systa() = default;

   bool get_value(uint16_t id, int32_t i32_value, SystaValue & value);

   //! @todo rename function
   void parse_values(struct ReceivePacket * pRecvPacket, NewValueCallback clbk);
};


#endif // SYSTA_HPP_INCLUDED
