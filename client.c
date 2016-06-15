/* 
 * File:   client.c
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
 * 1.creazione socket con la funziona  socket()
 * 2.connetti il socket al server con la funzione connect()
 * 3.leggi il messaggio dal server nel buffer
 * 4.stampa su output il messaggio ricevuto dal server
 * 
 */
int main(int argc, char** argv) {
    
   /* Menu' di benvenuto - client */
   fprintf(stdout, "-----------------------------------------\n");
   fprintf(stdout, "  Elenco Telefonico Remoto: Client       \n");
   fprintf(stdout, "-----------------------------------------\n");    
    
   int clientSocket;
   char buffer[1024];
   struct sockaddr_in serverAddr;
   socklen_t addr_size;

  /* 1.creazione socket con la funziona  socket() */
  // creazione socket con 3 argomenti: IP, stream socket e protocollo di default, ovvero TCP
  clientSocket = socket(PF_INET, SOCK_STREAM, 0);
  
  // settaggio address family, ovvero Internet
  serverAddr.sin_family = AF_INET;
  // settaggio porta da usare
  serverAddr.sin_port = htons(8181);
  // settaggio indirizzo server, ovvero localhost perche gli voglio far girare sia server che client nella stessa macchina
  serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
  // altre info neccessarie per la creazione del socket
  memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);  

  /* 2.connetti il socket al server con la funzione connect() */
  addr_size = sizeof serverAddr;
  connect(clientSocket, (struct sockaddr *) &serverAddr, addr_size);

  /* 3. leggi il messaggio dal server nel buffer */
  recv(clientSocket, buffer, 2048, 0);

  /* 4. Stampa su output il messaggio ricevuto dal server */
  printf("Messaggio dal server: %s \n",buffer);   
    
  /**
   * aggiungi_record() 
   * La funzione aggiungi_record() ti permette di aggiungere un record all'elenco telefonico (operazione
   * accessibile solo ad utenti autorizzati)
   */
    
    return (EXIT_SUCCESS);
}

