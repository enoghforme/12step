/* Based on a test case contributed by Nicola Pero.  */

#include <string.h>
#include <stdlib.h>

#ifdef __NEXT_RUNTIME__
#import <Foundation/NSString.h>
#else
#include <objc/NXConstStr.h>
#endif

int main(int argc, void **args)
{
  if ([@"this is a string" length] != strlen ("this is a string"))
    abort ();
  return 0;
}
