#include "fcgiapp.h"

int main() {
  FCGX_Init();
  FCGX_Request req;
  FCGX_InitRequest(&req, 0, 0);
  while (FCGX_Accept_r(&req) >= 0) {
    FCGX_FPrintF(req.out, "Content-Type: text/html\n\n");
    FCGX_FPrintF(req.out, "\r\n");
    FCGX_FPrintF(req.out, "<html>\n");
    FCGX_FPrintF(req.out, " <head>\n");
    FCGX_FPrintF(req.out," <title>Hello, World!</title>\n");
    FCGX_FPrintF(req.out, " </head>\n");
    FCGX_FPrintF(req.out, " <body>\n");
    FCGX_FPrintF(req.out, " <h1>Hello, World!</h1>\n");
    FCGX_FPrintF(req.out, " </body>\n");
    FCGX_FPrintF(req.out, "</html>\n");
    FCGX_Finish_r(&req);
  }
  return 0;
}