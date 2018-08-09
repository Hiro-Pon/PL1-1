#include <threads.h>
#include "p4_1_util.h"

void my_work(do_end_arg_t *arg) {
  // (1) Call get_dbl() repeatedly until it returns 1.0
  // (2) Sum all the return values of get_dbl()
  // (3) Count the number of calls to get_dbl()
  // (4) Return the results of 2 and 3 via arg
}

// Define a function that is called by a new thread

int main() {
  init_work(); // unmodifiable code
  do_end_arg_t arg[2];
  // (5) Create a new thread
  do_work(&(do_work_arg_t){ .f=my_work, .f_arg=&arg[1] }); // don't need to change this call
  // (6) Wait for completion of the new thread
  end_work(arg); // unmodifiable code
}
