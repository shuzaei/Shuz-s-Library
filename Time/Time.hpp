#ifndef def
#include "Shuzaei.hpp"
#endif

using namespace std::chrono;

#define start(a) auto a = system_clock::now();
#define elapsed(a) duration_cast<milliseconds>(system_clock::now() - a).count()