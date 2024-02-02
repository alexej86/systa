
#ifndef UDP_HPP_INCLUDED
#define UDP_HPP_INCLUDED

#include <functional>
#include <stdio.h>

#define PORT 22460
#define BUFFER_SIZE 1024*64

/*!
 * @param      buf      Buffer
 * @param      len      Length of buffer
 * @return     nr of bytes to send back
 */
typedef std::function<ssize_t(char *, ssize_t)> Clbk;

int udp_create();
int udp_receive(Clbk callback);
int udp_close();

#endif
