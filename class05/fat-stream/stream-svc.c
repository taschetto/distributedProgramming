/* Arquivo: stream-svc.c (Roland Teodorowitsch; 22 mar. 2016) */

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h> 
#include <pthread.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "stream.h"

double fatorial(int n);

double fatorial(int n)
{
	double res;

	res = 1.0;
	while	(n>=2) {
		res *= n;
		--n;
	}
  sleep(1);
	return res;
}

void* servidor(void* in)
{
  int clnt_socket;
	int			numero;
	double			val_fat;

  clnt_socket = *(int*)in;
	while (1) {
		read(clnt_socket, &numero, sizeof(int));
		if	(numero <= 0)
			break;
       		val_fat = fatorial(numero);
		write(clnt_socket, &val_fat, sizeof(double));
	}
	close(clnt_socket);

}

int main(int argc, char *argv[])
{
	struct sockaddr_in	svc_address;
	struct sockaddr_in	clnt_address;
	int			svc_socket,clnt_socket;
	socklen_t		clnt_len,svc_len;
  pthread_t t;

	svc_socket = socket(AF_INET, SOCK_STREAM, 0);
	if	(svc_socket < 0)  {
		fprintf(stderr,"%s: erro em socket(): %s\n",argv[0],strerror(errno));
		exit(1);
	}
	svc_len = sizeof(svc_address);
	bzero((char *)&svc_address,svc_len);
	svc_address.sin_family = AF_INET;
	svc_address.sin_addr.s_addr = INADDR_ANY;
	svc_address.sin_port = htons(SOCKET_PORT);
	if	(bind(svc_socket,(struct sockaddr *)&svc_address,svc_len) < 0)  {
		fprintf(stderr,"%s: erro em bind(): %s\n",argv[0],strerror(errno));
		exit(1);
	}
	listen(svc_socket, 5);
	while	(1)  {
		clnt_socket = accept (svc_socket,(struct sockaddr *)&clnt_address, &clnt_len);
		if	(clnt_socket < 0)  {
			fprintf(stderr,"%s: erro em accept(): %s\n",argv[0],strerror(errno));
			exit(1);
		}
    if (pthread_create(&t, NULL, servidor, (void*)&clnt_socket) != 0) {
      fprintf(stderr,"%s: erro em pthread_create(): %s\n", argv[0],strerror(errno));
      close(clnt_socket);
    }
	}
	return 0;
}

