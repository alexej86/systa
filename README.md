# systa
Reads parameters from Paradigma SystaCompact II water heater and provides them to HomeAssistant

# goal
I want to create a binary, which reads various parameters from the Paradigma SystaCompact II water header and provide them to HomeAssistant via well known interface.
I know, that there are many solutions which already can read systaXXX devices using UDP protocol, but I have an old version of this heater which is not compatible
with existing solutions. I think that the "remoteportal" feature is just not activated in my water heater, and I do not know how to activate it. I found some hints 
in the internet that the early variants, which does not have the MAC-address on the type label, can not be activated for remoteportal.
But I saw in wireshark, that the water heater already sends some data over udp to paradigma.remoteportal.de in the "0-frame" and I already was able to decode some
values.
Any help and suggestions about how the values can be sent to HomeAssistant are appreciated.
