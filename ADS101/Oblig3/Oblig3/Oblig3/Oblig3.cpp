#include <iostream>
#include <array>
#include <chrono>
struct test
{
    int key;
    std::string s;
    bool operator == (const test& t2) const { return key == t2.key; }
};

template<>
class std::hash<test>
{
    size_t operator() (const test& t) const {
        return t.key % 7;
    }
    bool operator() (const test& t1, const test& t2) {
        return t1.key == t2.key;
    }
};
template<typename T, size_t N>
void InsertionSort(T(&arr)[N]);

template<typename T, size_t N>
void MergeSort(T(&arr)[N]);
int main()
{
    //Skriv en funksjon som regner ut gjennomsnittlig sorteringstid
    //n�r man generer og sorterer n tilferldige heltall for n = 10, 100, 1000, 10000
    //Funksjonen skal gj�re mange sortering for hver verdi av n. 
    //Bruk f�rst innstikksortering og deretter flettesortering. Skriv ut resultatene
    int a[10];
    int b[100];
    int c[1000];
    int d[10000];
    for (int i = 0; i < sizeof(a) / sizeof(*a); i++)
    {
        a[i] = rand() % 100;
    }
    for (int i = 0; i < sizeof(b) / sizeof(*b); i++)
    {
        b[i] = rand() % 1000;
    }
    for (int i = 0; i < sizeof(c) / sizeof(*c); i++)
    {
        c[i] = rand() % 10000;
    }
    for (int i = 0; i < sizeof(d) / sizeof(*d); i++)
    {
        d[i] = rand() % 100000;
    }
    InsertionSort(a);
    InsertionSort(b);
    InsertionSort(c);
    InsertionSort(d);
    MergeSort(a);
    MergeSort(b);
    MergeSort(c);
    MergeSort(d);
    for (int i = 0; i < sizeof(a) / sizeof(*a); i++)
    {
        std::cout << a[i] << ", ";
    }
    //Gitt en array med tallene 17,14,5,7,12,1,16,29,13,4,8,18,22,2
    //Anta n� at tallene skal sorteres med mergesort. Sett opp en tabell som
    //viser hvordan hele sortering foreg�r, helt til at du har en ferdig sortert
    //array. Forklar med tekst i tilleg


    //F�lgende kode er gitt
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
        }
       }
        */
        // Skriv kode for � sette inn poster med n�kler 12, 13, 20, 21, 1, 2, 3, 4, 5, 6
        //i uordnet_sett i opplistet rekkef�lge

    //I denne oppgaven skal du bruke kode som er gitt til slutt i oppgaven, uten endringer
    //a) Implenter funksjonene Node::setting_kant(), Graf::settinn_node() og Graf::finn_node().
    //I sistnevnte funksjon skal du benytte den interne struktren til � s�ke etter en node med gitt navn
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

template<typename T, size_t N>
void InsertionSort(T(&arr)[N])
{
    auto start = std::chrono::high_resolution_clock::now();

    for (auto i = 1; i < sizeof(arr) / sizeof(*arr); i++)
    {
        //Gets the current
        auto hjelp = arr[i];
        //If the the prevois element is larger, move it behind
        for (auto j = i - 1; j >= 0 && arr[j] > hjelp; j--)
        {
            arr[j + 1] = arr[j];
            arr[j] = hjelp;
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> totalTime = end - start;
    std::chrono::nanoseconds totalTimeNano = std::chrono::duration_cast<std::chrono::nanoseconds>(totalTime);

    totalTime += totalTimeNano;
    int time = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    std::cout << "With " << N << " elements, it took " << totalTime.count() << " seconds to sort them doing the selection sort alagorithm." << std::endl;
}

template<typename T, size_t N>
void MergeSort(T(&arr)[N]) {

    auto start = std::chrono::high_resolution_clock::now();

    int i, j, k, lower1, lower2, size, upper1, upper2;
    std::array<int, N> hjelp;
    size = 1;
    while (size < N) {
        lower1 = 0;
        k = 0;
        while (lower1 + size < N) {
            upper1 = lower1 + size - 1;
            lower2 = upper1 + 1;
            upper2 = (lower2 + size - 1 < N) ? lower2 + size - 1 : N - 1;
            for (i = lower1, j = lower2; i<=upper1 && j<=upper2; k++)
            {
                if (arr[i] < arr[j]) {
                    hjelp[k] = arr[i++];
                }
                else {
                    hjelp[k] = arr[j++];
                }
            }
            for (; i <= upper1; k++) {
                hjelp[k] = arr[i++];
            }
            for (; j <= upper2; k++) {
                hjelp[k] = arr[j++];
            }
            lower1 = upper2 + 1;
            
        }
        for (i = lower1; k < N; i++) {
            hjelp[k++] = arr[i];
        }
        for (i = 0; i < N; i++) {
            arr[i] = hjelp[i];
        }
        size = size * 2;
    }
    

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> totalTime = end - start;
    std::chrono::nanoseconds totalTimeNano = std::chrono::duration_cast<std::chrono::nanoseconds>(totalTime);

    totalTime += totalTimeNano;
    int time = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    std::cout << "With " << N << " elements, it took " << totalTime.count() << " seconds to sort them doing the selection sort alagorithm." << std::endl;
}


