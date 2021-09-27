// ADS101 Algoritmer og datastrukturer for spill
// Dag Nylund, Høgskolen i Innlandet 2020
//
// Tidsmåling av binærsøk
// implementering av binary search for std::array
// - skal bruke den med arrayer av ulik lengde:
// 100   log_10(100)   = 2
// 1000  log_10(1000)  = 3
// 10000 log_10(10000) = 4
#include <iostream>
#include <iomanip>
//#include <array>
#include <cmath>
#include <algorithm>
#include <chrono>

// Oppretter en global konstant siden std::array krever konstant lengde
const unsigned long N{100000};
// Oppretter et stort nok antall løkker til å få signifikante målinger
const unsigned long LOOPS{10000};

// Binærsøk for arrayer med store tall
unsigned long binary_search(std::array<unsigned long, N>& a, unsigned long x)
{
    unsigned long indeks = -1;
    unsigned long n = static_cast<unsigned long>(a.size());
    unsigned long v{0}; unsigned long h{n-1};
    while (v<=h && indeks==-1)
    {
        auto midt = (v+h)/2;
        if (x == a[midt])
            indeks = midt;
        else if (x < a[midt])
            h = midt-1;
        else // x > a[midt]
            v = midt+1;
    }
    return indeks;
}

int main ()
{
    // Lager objekt med tallene fra 1 til N i stigende rekkefølge
    std::array<unsigned long, N> a;
    for (unsigned long i=0; i<N; i++) a.at(i)=i;


    auto start = std::chrono::high_resolution_clock::now(); // Starter klokka

    for (auto i=0; i<LOOPS; i++)
    {
        unsigned long tall = std::rand()%N;
        auto indeks = binary_search(a, tall);
    }
    auto slutt = std::chrono::high_resolution_clock::now(); // Stopper klokka

    std::chrono::duration<double> varighet = slutt-start;
    std::chrono::nanoseconds varighet_nano =
            std::chrono::duration_cast<std::chrono::nanoseconds >(varighet );

    // utskrift
    std::cout << "n = " << N << ", repetisjoner= " << LOOPS << std::endl;
    std::cout << "varighet i nanosekunder: " << varighet_nano.count()/LOOPS << std::endl;

    return 0;
}
