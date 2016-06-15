/* 
 * File:   server.c
 * Autore: Antonio Kocaqi
 *
 * Creato il 15 Maggio 2016
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string.h>

/**
 *           STEPS PRINCIPALLI
 * 1.Creazione socket con la funziona  socket()
 * 2.Bind del socket usando la funzione bind()
 * 3.In listening per connessioni usando la funzione listen().
 * 4.Accettazione connessioni con la funzione accept().
 * 5.Send e receive dei dati usando le system calls read() e write()
 */
int main(int argc, char** argv) {
   fprintf(stdout, "------------------------------------------\n");
   fprintf(stdout, "  Elenco Telefonico Remoto: Server        \n");
   fprintf(stdout, "------------------------------------------\n");
    
   int welcomeSocket, newSocket;
   char buffer[1024];
   struct sockaddr_in serverAddr;
   struct sockaddr_storage serverStorage;
   socklen_t addr_size;
   
/* 1.creazione socket con la funziona  socket() */
   // creazione socket con 3 argomenti: IP, stream socket e protocollo di default, ovvero TCP
   welcomeSocket = socket(PF_INET, SOCK_STREAM, 0);
  
  // settaggio address family, ovvero Internet
  serverAddr.sin_family = AF_INET;
  // settaggio porta da usare
  serverAddr.sin_port = htons(8181);
  // settaggio indirizzo server, ovvero localhost perche gli voglio far girare sia server che client nella stessa macchina
  serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
  // altre info neccessarie per la creazione del socket
  memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);  

/* 2.Bind del socket usando la funzione bind() */
  bind(welcomeSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr));

/* 3.In listening per connessioni usando la funzione listen(). */
  // socket in ascolto con massima 5 connessione alla coda
  if(listen(welcomeSocket,5)==0)
    printf("Server in ascolto...\n");
  else
    printf("Errore server: raggiunto il numero massimo di connessioni...\n");

 /* 4.Accettazione connessioni con la funzione accept() */
  addr_size = sizeof serverStorage;
  newSocket = accept(welcomeSocket, (struct sockaddr *) &serverStorage, &addr_size);

 /* 5. Send e receive dei dati usando le system calls read() e write() */
  strcpy(buffer,"Toni budalla\n");
  send(newSocket,buffer,13,0);

 /* 6. Struttura dati elenco_telefonico: nome,cognome,telefono */
       
    return (EXIT_SUCCESS);
}

