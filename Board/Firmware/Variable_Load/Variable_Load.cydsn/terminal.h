#ifndef __terminal_h__
#define __terminal_h__
  #include <stdbool.h>
  void goToPos(int x, int y);
  void cls(void);
  void init(void);
  bool putString(const char *buffer);
  
#endif
