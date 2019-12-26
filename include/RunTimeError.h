//
// Created by caffe on 2019/12/25.
//

#ifndef MYCNET_RUNTIMEERROR_H
#define MYCNET_RUNTIMEERROR_H

#include "EnvMsg.h"
#include <string>
#ifdef windows
#define perrmsg(errmsg) _wsystem(L"color 04"); \
printf("Error Occurs: \"%s\" \"%s()\" line %d: %s.\n", \
__FILE__,__FUNCTION__,__LINE__,errmsg);
#endif

#ifdef linux
#define perrmsg(errmsg) _wsystem(L"color 04"); \
printf("Error Occurs: \"%s\" in function %s() in line %d that %s\n", \
__FILE__,__FUNCTION__,__LINE__,errmsg);
#endif

using namespace std;
#endif //MYCNET_RUNTIMEERROR_H
