/* Arquivo: stream_clnt.c (Roland Teodorowitsch; 22 mar. 2016) */

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include "stream.h"

int main(int argc, char *argv[])
{
	struct		hostent *hostinfo;
	struct		sockaddr_in address;
	int		sockfd,numero,result,i;
	double		val_fat;
	socklen_t	addr_len;

	if	(argc<3)  {
		fprintf(stderr,"Uso:\n%s <nome_do_servidor> <numero>...\n\n",argv[0]);
		exit(1);
	}
	hostinfo = gethostbyname(argv[1]);
	if	(!hostinfo)  {
		fprintf(stderr,"%s: erro em gethostbyname().\n",argv[0]);
		exit(1);
	}
	if	(hostinfo->h_addrtype!=AF_INET)  {
		fprintf(stderr,"%s: \"%s\" nao e' uma maquina IP.\n",argv[0],argv[1]);
		exit(1);
	}
	addr_len = sizeof(address);
	bzero((char *)&address,addr_len);
	address.sin_family = AF_INET;
	bcopy((char *)hostinfo->h_addr,(char *)&address.sin_addr.s_addr,hostinfo->h_length);
	address.sin_port = htons(SOCKET_PORT);
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	result = connect (sockfd, (struct sockaddr *)&address, addr_len);
	if	(result == -1)  {
		fprintf(stderr,"%s: erro em connect(): %s\n",argv[0],strerror(errno));
		exit(1);
	}
	for	(i=2;i<argc;++i) {
		numero = atoi(argv[i]);
		write(sockfd,&numero,sizeof(int));
		read(sockfd,&val_fat,sizeof(double));
		printf ("%d! = %lf\n",numero,val_fat);
	}
	numero = 0;
	write(sockfd,&numero,sizeof(int));
	close(sockfd);
	return 0;
}

