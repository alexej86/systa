
#include "SystaCompact_II.hpp"




SystaCompactII::SystaCompactII()
{
   Systa::register_value(9,   {"Systa counter", eVALUE_TYPE_INT});
   Systa::register_value(152, {"Außentemperatur", eVALUE_TYPE_FLOAT_10});
   Systa::register_value(153, {"BRAUCHWASSER_TEMP_IST", eVALUE_TYPE_FLOAT_10});
   Systa::register_value(154, {"Vorlauftemperatur_Kessel", eVALUE_TYPE_FLOAT_10});
   Systa::register_value(155, {"Ruecklauftemperatur_Kessel", eVALUE_TYPE_FLOAT_10});
   Systa::register_value(162, {"Betriebsart", eVALUE_BETRIEBSART});
   Systa::register_value(174, {"Fusspunkt", eVALUE_TYPE_INT_10});
   Systa::register_value(176, {"Steilheit", eVALUE_TYPE_FLOAT_10});
   Systa::register_value(178, {"Vorlauftemperatur_max", eVALUE_TYPE_FLOAT_10});
   Systa::register_value(179, {"Heizgrenze_Betrieb", eVALUE_TYPE_INT_10});
   Systa::register_value(180, {"Heizgrenze_Absenken", eVALUE_TYPE_INT_10});
   Systa::register_value(181, {"Frostschutz", eVALUE_TYPE_INT_10});
   Systa::register_value(182, {"Vorhaltezeit_aufheizen", eVALUE_UNKNOWN});
   Systa::register_value(194, {"Brauchwassertemperatur_normal", eVALUE_TYPE_INT_10});
   Systa::register_value(195, {"Brauchwassertemperatur_comfort", eVALUE_TYPE_INT_10});
   Systa::register_value(212, {"Nachlaufzeit_Pumpe", eVALUE_UNKNOWN});
   Systa::register_value(213, {"Sperrzeit_Taster", eVALUE_UNKNOWN});
   Systa::register_value(214, {"Schaltdifferenz_Pumpe_PZ", eVALUE_TYPE_INT_10});
}
