#include <iostream>
#include <array>
#include <chrono>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <queue>

struct Kant;
struct Node {
    char m_navn;
    bool m_besokt;
    std::list<Kant>
        m_kanter;
    Node(char navn) : m_navn(navn), m_besokt(false) { }
    void  settinn_kant(const Kant& kant);
};

struct Path {
public:
    std::vector<Kant*> edges;
    double cost;
    bool operator > (const Path& OtherPath) const { return cost > OtherPath.cost; }
};
struct Kant {

    float m_vekt;
    Node* m_tilnode;
    Kant(float vekt, Node* tilnode) : m_vekt(vekt), m_tilnode(tilnode) { };
    bool  operator  >  (const  Kant& k)const { return m_vekt > k.m_vekt; };
};

struct Graf {
    std::list<Node*> noder;
    Graf() {  };
    Node* finn_node(char navn);
    void  settinn_node(char navn);
    void settinn_kant(char fra_navn, char til_navn, float vekt);
    float mst();
};

struct Test
{
    int key;
    std::string s;
    bool operator == (const Test& t2) const { return key == t2.key; }
};

template<>
class std::hash<Test>
{
public:
    size_t operator() (const Test& t) const {
        return t.key % 7;
    }
    bool operator() (const Test& t1, const Test& t2) {
        return t1.key == t2.key;
    }
};
template<typename T, size_t N>
void InsertionSort(T(&arr)[N]);

template<typename T, size_t N>
void MergeSort(T(&arr)[N]);
void InsertIntoUnorderSet(std::unordered_set<Test> &set, int key, std::string s);
void Dijkstra(Graf* g, Node* start, Node* end);
int main()
{
    //Skriv en funksjon som regner ut gjennomsnittlig sorteringstid
    //når man generer og sorterer n tilferldige heltall for n = 10, 100, 1000, 10000
    //Funksjonen skal gjøre mange sortering for hver verdi av n. 
    //Bruk først innstikksortering og deretter flettesortering. Skriv ut resultatene
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
    std::cout << std::endl;
    //Gitt en array med tallene 17,14,5,7,12,1,16,29,13,4,8,18,22,2
    //Anta nå at tallene skal sorteres med mergesort. Sett opp en tabell som
    //viser hvordan hele sortering foregår, helt til at du har en ferdig sortert
    //array. Forklar med tekst i tilleg
    int array1[] = { 17, 14, 5, 7, 12, 1, 16, 29, 13, 4, 8, 18, 22, 2 };
    MergeSort(array1);
    for (int i = 0; i < sizeof(array1) / sizeof(*array1); i++)
    {
        std::cout << array1[i] << ", ";
    }
    std::cout << std::endl;


    //Følgende kode er gitt
    // Skriv kode for å sette inn poster med nøkler 12, 13, 20, 21, 1, 2, 3, 4, 5, 6
    //i uordnet_sett i opplistet rekkefølge
    std::hash<Test> hashTabell;
    std::unordered_set<Test> uordnet_sett;
    InsertIntoUnorderSet(uordnet_sett, 12, "tolv");
    InsertIntoUnorderSet(uordnet_sett, 13, "tretten");
    InsertIntoUnorderSet(uordnet_sett, 20, "tjue");
    InsertIntoUnorderSet(uordnet_sett, 21, "tjueen");
    InsertIntoUnorderSet(uordnet_sett, 1, "en");
    InsertIntoUnorderSet(uordnet_sett, 2, "to");
    InsertIntoUnorderSet(uordnet_sett, 3, "tre");
    InsertIntoUnorderSet(uordnet_sett, 4, "fire");
    InsertIntoUnorderSet(uordnet_sett, 5, "fem");
    InsertIntoUnorderSet(uordnet_sett, 6, "seks");


    //a) Implenter funksjonene Node::settinn_kant(), Graf::settinn_node() og Graf::finn_node().
    //I sistnevnte funksjon skal du benytte den interne struktren til å søke etter en node med gitt navn
    //Funksjonen skal returneere en peker til noden dersom den fins, og nullptr ellers.
    
    Graf* g = new Graf();
    g->settinn_node('a');
    g->settinn_node('b');
    g->settinn_node('c');
    g->settinn_node('d');
    g->settinn_node('e');
    g->settinn_kant('a', 'b', 1);
    g->settinn_kant('a', 'c', 2);
    g->settinn_kant('b', 'c', 2);
    g->settinn_kant('c', 'd', 3);
    g->settinn_kant('d', 'e', 1);
    g->settinn_kant('a', 'e', 5);
    g->settinn_kant('c', 'e', 4);

    Dijkstra(g, g->finn_node('a'), g->finn_node('d'));
    //b)
    // 1.Impleterer funksjonen Graf::settinn_kant()
    //2.Lag en testgraf i main() med noder {A, B, C, D og E} og kanter:
    //{AB(1.0), AC(2.0), BC(2.0), CD(3.0), DE(1.0), AE(5,0) CE(4,0)
    //Bruk djikstras algorytme på dette
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

void InsertIntoUnorderSet(std::unordered_set<Test> &set, int key, std::string s)
{
    Test t;
    t.key = key;
    t.s = s;

    set.insert(t);
}

void Node::settinn_kant(const Kant& kant)
{
    for (auto& k : m_kanter) {
        if (k.m_tilnode = kant.m_tilnode) {
            //har allerede kant til denne noden
            return;
        }
    }
    m_kanter.push_back(kant);
}

void Graf::settinn_node(char navn)
{
    Node* n = new Node(navn);
    for (auto& node : noder) {
        if (node->m_navn == navn) {
            //Har allerede noden
            return;
        }
    }
    noder.push_back(n);
}

Node* Graf::finn_node(char navn)
{
    for (auto& node : noder) {
        if (node->m_navn == navn) {
            return node;
        }
    }
    return nullptr;
}

void Graf::settinn_kant(char fra_navn, char til_navn, float vekt)
{
    Node* n = finn_node(fra_navn);
    
    if (!n) {
        settinn_node(fra_navn);
    }
    n = finn_node(fra_navn);

    Node* n2 = finn_node(til_navn);

    if (!n2) {
        settinn_node(til_navn);
    }
    n2 = finn_node(til_navn);

    Kant* k = new Kant(vekt, n2);
    n->settinn_kant(*k);
}
void Dijkstra(Graf* g, Node* start, Node* end) {
    std::priority_queue<Kant> pq;

    std::priority_queue<Path, std::vector<Path>, std::greater<Path>> apq;

    Path startPath;
    Kant startKant(0.0, start);
    startPath.edges.push_back(&startKant);
    startPath.cost = 0;
    apq.push(startPath);

    while (!apq.empty() && !end->m_besokt) {
        auto path = apq.top();
        apq.pop();
        if (!end->m_besokt) {
            for (auto& kant : end->m_kanter) {
                Path p;
                p.edges.push_back(&kant);
                apq.push(p);
            }
            end->m_besokt = true;
        }
    }

    
}
