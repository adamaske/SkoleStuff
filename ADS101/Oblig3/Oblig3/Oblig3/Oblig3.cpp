#include <iostream>

int main()
{
    //Skriv en funksjon som regner ut gjennomsnittlig sorteringstid
    //når man generer og sorterer n tilferldige heltall for n = 10, 100, 1000, 10000
    //Funksjonen skal gjøre mange sortering for hver verdi av n. 
    //Bruk først innstikksortering og deretter flettesortering. Skriv ut resultatene


    //Gitt en array med tallene 17,14,5,7,12,1,16,29,13,4,8,18,22,2
    //Anta nå at tallene skal sorteres med mergesort. Sett opp en tabell som
    //viser hvordan hele sortering foregår, helt til at du har en ferdig sortert
    //array. Forklar med tekst i tilleg


    //Følgende kode er gitt
    /*
        struct Test{
            int key;
            std::string s;
            bool operator == (const Test& t2) const {return key == t2.key;}
        }
        template<>
        class hash<Test>{
        public:
            size_t operator() (const Test& t) const {
            return t.key % 7;
            }
            bool operator() (const Test& t1, const Test& t2{
            return t1.key == t2.key;
            }
        int main(int argc, char *argv[])
        {
            hash<Test> hashTabell;
            unordered_set<Test> uordnet_sett;
        */
        // Skriv kode for å sette inn poster med nøkler 12, 13, 20, 21, 1, 2, 3, 4, 5, 6
        //i uordnet_sett i opplistet rekkefølge

    //I denne oppgaven skal du bruke kode som er gitt til slutt i oppgaven, uten endringer
    //a) Implenter funksjonene Node::setting_kant(), Graf::settinn_node() og Graf::finn_node().
    //I sistnevnte funksjon skal du benytte den interne struktren til å søke etter en node med gitt navn
    //Funksjonen skal returneere en peker til noden dersom den fins, og nullptr ellers.
    //b)1.Impleterer funksjonen Graf::settinn_kant()
    //2.Lag en testgraf i main() med noder {A, B, C, D og E} og kanter:
    //{AB(1.0), AC(2.0), BC(2.0), CD(3.0), DE(1.0), AE(5,0) CE(4,0)
    /*
    include  <iostream>
    #include <list>
    #include <queue>
  
    struct Kant;
    struct Node{
        char m_navn;
        bool m_besokt;
        std::list<Kant>            
        m_kanter;
        Node(char navn): m_navn(navn), m_besokt(false){ }
        void  settinn_kant(const Kant &kant);
    };

    struct Kant{
        float m_vekt;
        Node* m_tilnode;
        Kant(float vekt, Node* tilnode) : m_vekt(vekt), m_tilnode(tilnode){ };
        bool  operator  >  (const  Kant& k)const {return m_vekt > k.m_vekt; };
    };

    struct Graf{
    std::list<Node*> noder;
    Graf() {  };
    Node* finn_node(char navn);
    void  settinn_node(char navn);
    void settinn_kant(char fra_navn, char til_navn,float vekt);
    float mst();
    };
    */
    return 0;
}
