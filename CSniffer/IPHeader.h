#ifndef IPHEADER_H
#define IPHEADER_H
struct IPHeader
{
     unsigned char ver_len;		// версия и длина заголовка
     unsigned char tos;			// тип сервиса
     unsigned short length;		// длина всего пакета
     unsigned short id;			// Id
     unsigned short flgs_offset;		// флаги и смещение
     unsigned char ttl;			// время жизни
     unsigned char protocol;		// протокол
     unsigned short xsum;			// контрольная сумма
     unsigned long src;			// IP-адрес отправителя
     unsigned long dest;			// IP-адрес назначения
     unsigned short *params;		// параметры (до 320 бит)
     unsigned char *data;			// данные (до 65535 октетов)
};

#endif // IPHEADER_H
