# Gestione di un'area chiusa di parcheggio.

L'obiettivo di questo lavoro e' creare un primo prototipo dell'architettura logica del sistema parcheggio. Il prototipo deve essere facilmente estendibile, aperto per le modifiche future e pronto per essere adattato  in base ai requisiti di un sistema “reale”.

![Alt text](/uml/classDiagram.png?raw=true "Diagramma strutturale")

Come si vede dal diagramma l'applicazione puo' essere  divisa in tre principali moduli logici:  Sensor, Gate, Controller.

*Sensor*: e' una classe che realizza la logica del singolo sensore, tutte le implementazioni sucessive dei sensori “reali” dovrebbero estendere o utilizzare questa classe. Sensor manda una notifica al Gate quando il valore del sensore cambia attraverso l'interfaccia SensorListener. 

*Gate*: realizza l'interfaccia SensorListener  e, a partire dall'input provieniente dai due sensori, gestisce le uscite e le entrate nel parcheggio. L'immagine  a lato con FSM illustra  come lo stato di Gate dipende dall'input dei sensori.
La mutua esclusione dei sensori viene gestita attraverso mutex.


![Alt text](/uml/fsm.png?raw=true "Gate FSM")

*Controller*: realizza l'interfaccia GateListner atraverso cui riceve eventi di entrata e uscita dal parcheggio. Utilizzando gli input ricevuti dai diversi Gate, gestisce il semaforo e la comunicazione  seriale. Per gestire l'eventuale mutua esclusione degli eventi provenienti dai diversi Gate, all'interno del controller viene utilizzato  mutex.

*SerialCommunicator*: trasforma uint32_t in quattro caratteri ASCII, e costruisce il messaggio richiesto con STX e ETX configurabili all' interno della classe.

#Conclusione: 
Utilizzando questa architettura e' possibile dividere l'implementazione del sistema fra 3 team di sviluppatori  indipendenti, in quanto i sottosistemi logici Sensor, Gate  e Controller non dipendono l'uno dall'altro. Questi sottosistemi possono essere sviluppati e testati separatamente, e' importante tuttavia  tenere stabili le interfacce SensorListener e GateListener.

Un ulteriore vantaggio di questa architettura e' che Controller non dipende dal numero del Gate e' quindi  possibile utilizzare tale sistema nei parcheggi con qualsiasi numero di Gate.


#PS
La soluzione esclude il caso in cui due veicoli entrino in un Gate nello stesso momento  in entrambe le direzioni, occupando un sensore ciascuno.

MainParking.cpp -> configurazione e simulazione
