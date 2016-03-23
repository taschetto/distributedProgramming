all:		stream-clnt stream-svc

stream-clnt:	stream-clnt.c stream.h
		@gcc -o stream-clnt stream-clnt.c

stream-svc:	stream-svc.c stream.h
		@gcc -o stream-svc stream-svc.c -lpthread

clean:
		@rm -f stream-clnt stream-svc *~

info:
		@echo "(c) Roland Teodorowitsch (22 mar. 2016)"

