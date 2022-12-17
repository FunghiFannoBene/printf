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

//specifier	Output	Example
	d or i	Signed decimal integer	392
	u	Unsigned decimal integer	7235
	o	Unsigned octal	610
	x	Unsigned hexadecimal integer	7fa
	X	Unsigned hexadecimal integer (uppercase)	7FA
	f	Decimal floating point, lowercase	392.65
	F	Decimal floating point, uppercase	392.65
	e	Scientific notation (mantissa/exponent), lowercase	3.9265e+2
	E	Scientific notation (mantissa/exponent), uppercase	3.9265E+2
	g	Use the shortest representation: %e or %f	392.65
	G	Use the shortest representation: %E or %F	392.65
	a	Hexadecimal floating point, lowercase	-0xc.90fep-2
	A	Hexadecimal floating point, uppercase	-0XC.90FEP-2
	c	Character	a
	s	String of characters	sample
	p	Pointer address	b8000000
	n	Nothing printed.
	The corresponding argument must be a pointer to a signed int.
	The number of characters written so far is stored in the pointed location.	
	%	A % followed by another % character will write a single % to the stream.	%

GESTIONE DEL  WIDTH (*) AGGIUNGE UN PARAMETRO ALLA FUNZIONE GESTITE COME LE VARIABILI
// in caso il valore da stampare sia un int (o simile), ricordarsi di porre il limte max di int cioe':1658683391
//	PER I NUMERI POSITIVI e di: -1658683391 per I NUMER INEGATIVI CON SPECIFIER "i" o "d"; in caso invece di 
// specifier "u" il limite e' di 1658683391 per i positivi e 2636283905 per i negativi, il LIMITE PER I NEGATIVI
// NON HA SEGNO POICHE' "u" definisce gli 'unsigned int' traducibili come VALORI ASSOLUTI.
// il width accetta solo  un int o una variabile di tipo int che non hanno valore massimo, se il valore e' negativo,
//i caratteri mancanti vengon aggiunti dopo il valore richiamto dallo specifier.



type
//%c stampa l'ultima lettera.


BONUS
funzioni utili:
	-itoa

//

GESTIONE DEL PUNTO
//con il punto si definisce per gli specifier:d, i, o, u, x, X il numero minimo di numeri da stampare
//se il valore da stampare e' inferiore al numero minimo, vengono aggiunti degli zero prima
//per gli specifier: A, e, E, f, F il numero definisce il numero di decimali da stampare dopo la virgola
// per gli specifier: g, G si stabilisce il numero massimo si cifre da stampare del numero
// per lo specifier s: stabilisce il numero massimo di carattreri da stampare.

GESTIONE DELLO 0
Left-pads the number with zeroes (0) instead of spaces when padding is specified (see width sub-specifier).
	
GESTIONE DEL -
gestisce la distribuzione dei caratteri all'interno del parametro width, parametro gestito all'interno della funzione

GESTIONE DELLO SPAZIO
//se non viene inserito un segno (tra la percentuale e lo specifier), viene aggiunto uno spazio

GESTIONE DEL +
//+
//Forces to precede the result with a plus or minus sign (+ or -) even for positive numbers. By default, 
//only negative numbers are preceded with a -ve sign.

😎️GESTIONE DEL #
//usata con o, x, X

FUNZIONI VARIADICHE 
// per implementare funzioni variadiche nel codice va inclusa la libreria stdarg.h
//le funzioni variadiche sono funzioni che accettano un mumero infinito  di argomenti
//va definita un va_list che va aperta con va_start e chiusa con va_end
// va_start(va_list ap, parametro_n) serve a dare a va_list il parametro da cui partire, di per se
//va start indica ad un parametro ap di puntare alla posizione di memoria successiva a quella del
// proprio parametro_n
// va_arg(va_list ap, tipo) restituisce il valore contenuto all-indirizzo di ap, castando il tipo che
// passo come argomento


#endif
