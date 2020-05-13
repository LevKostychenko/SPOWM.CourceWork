#ifndef UDPHEADER_H
#define UDPHEADER_H

struct UDPHeader
{
    unsigned short source_port;
    unsigned short dest_port;
    unsigned short udp_length;
    unsigned short udp_checksum;
};

#endif // UDPHEADER_H
