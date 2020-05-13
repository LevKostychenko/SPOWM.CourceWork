#ifndef TCPHEADER_H
#define TCPHEADER_H

struct TCPHeader
{
    unsigned short source_port;
    unsigned short dest_port;
    unsigned int sequence;
    unsigned int acknowledge;

    unsigned char ns :1;
    unsigned char reserved_part1:3;
    unsigned char data_offset:4;

    unsigned char fin :1;
    unsigned char syn :1;
    unsigned char rst :1;
    unsigned char psh :1;
    unsigned char ack :1;
    unsigned char urg :1;

    unsigned char ecn :1;
    unsigned char cwr :1;

    unsigned short window;
    unsigned short checksum;
    unsigned short urgent_pointer;
};

#endif // TCPHEADER_H
