#include <Windows.h>
#include <rindow/matlib.h>
#include "vclib.h"
static char msg_function_not_found[]  = "rindow_matlib_d_tanh not found\n";
typedef void (CALLBACK* PFNrindow_matlib_d_tanh)( /* rindow_matlib_d_tanh */
    int32_t            /* n */,
    double *            /* x */,
    int32_t            /* incX */
);
static PFNrindow_matlib_d_tanh _g_rindow_matlib_d_tanh = NULL;
void rindow_matlib_d_tanh(
    int32_t            n,
    double *            x,
    int32_t            incX
)
{
    if(_g_rindow_matlib_d_tanh==NULL) {
        _g_rindow_matlib_d_tanh = rindow_load_rindowmatlib_func("rindow_matlib_d_tanh"); 
        if(_g_rindow_matlib_d_tanh==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_rindow_matlib_d_tanh(
        n,
        x,
        incX    
    );
}
