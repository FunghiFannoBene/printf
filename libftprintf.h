#ifdef LIBFTPRINTF_H
#define LIBFTPRINTF_H

typedef struct pf
{
	void *type;
	void *writing;
	struct pf next*;
}			printtype;

int ft_printf(const char *, ...);

//Ricerca della % per poi inserire la variabile if %% deve evitare di andare a prendere la variabile.
//RECUPERARE IL NUMERO DI PERCENTUALI TRANNE CHE LE DOPPIE %
//int ft_printf(const char *, ...);
//RITORNA INT PERCHE VUOLE RITORNARE LA LUNGHEZZA TOTALE DEI CARATTERI MENTRE VERRA' SCRITTA DIRETTAMENTE A SCHERMO CON IL WRITE.
// RITORNA DEGLI INDIRIZZI A OGNI % copiare con memcpy dalla variabile del parametro alla posizione di memoria della %
// PRENDERE IL PRIMO PARAMETRO DELLA STRINGA E A OGNI % CREARE UNA MEMORIA VUOTA DOVE VERRANO COPIATE LE VARIABILI.
// QUINDI RIUNIRE IL TUTTO IN UNA STRINGA UNICA SCRIVERLA E RITORNARE LA LUNGHEZZA DELLA STRINGA.
// SE NON CI SONO VARIABILI MA CI SONO LE % DEVE STAMPARE L'INDIRIZZO DI MEMORIA.
// SE LE % SONO INFERIORI ALLE VARIABILI, SKIPPA TUTTE LE VARIABILI CONSEGUENTI E STAMPA SOLO FINO A N NUMERO DI %.
// ASSENZA DI STRINGA NEL PARAMETRO NON STAMPA NIENTE.
// NEL CASO CI SIANO PIU "" MA SONO PARI, STAMPA COME SE FOSSE UN UNICA STRINGA, SE SONO DISPARI RITORNA ERRORE IN QUALSIASI CASO SE VOGLIO STAMPARE
// '"'  lo slash deve essere precedente a ogni " per stamparla. senno ritorna errore. devo: error: missing terminating " character.
// NEL CASO CI SIANO SOLO PARAMETRI 'VARIABILI' DEVE STAMPARE SOLO LA PRIMA VARIABILE (in stringa), non accettera' altri parametri.
// LA PERCENTUALE SOLITARIA NON VALE COME % ma vale come richiesta di leggere all interno della struttura e verificare quale dei tipi corrisponde. 
//se scritta singolarmente non stampa niente.
// se si scrive senza virgolette, stampa solo la prima variabile o da errore se non esiste.
// SI PUO STAMPARE UNA STRINGA ANCHE CON LE SOLE VIRGOLETTE.
// IL NULLO TERMINA LA STRINGA A PRESCIDERE DA QUALSIASI COSA.
// ESCAPE UNICO IN STRINGA = error: missing terminating " character Escape con caratteri non autorizzati stampa l'indirzzo di memoria o la sua funzione stessa 
//se ha una funzione senno viene skippata e stampa il carattere conseguente
//solo virgole no
//VUOTO ERRORE.
// METTENDO LA VARIABILE SOLITARIA , STAMPA SOLO SE E' DI TIPO STRINGA. RITORNA ERRORE SE E' ALTRO.


type
//%c stampa l'ultima lettera.


BONUS

//

GESTIONE DEL PUNTO

GESTIONE DELLO 0

GESTIONE DEL -

GESTIONE DELLO SPAZIO

GESTIONE DEL +

GESTIONE DEL #

#endif