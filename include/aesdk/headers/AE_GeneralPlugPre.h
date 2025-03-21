
/* This file should be included after all headers, but before the definition of any suites
or data structures.
*/
#ifdef _WIN32
    #pragma warning(push)
    #pragma warning(disable : 4103)
#endif
#include <adobesdk/config/PreConfig.h>
#ifdef _WIN32
    #pragma warning(pop)
#endif

#ifdef __cplusplus
extern "C" {
#endif

#ifdef _AE_GENERAL_PLUG_PRE___
#error "AE_GeneralPlugPre.h not balanced"
#endif

#define _AE_GENERAL_PLUG_PRE___