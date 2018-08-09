typedef struct {
  double total;
  long cnt;
} do_end_arg_t;

typedef struct {
  void (*f)(do_end_arg_t *);
  do_end_arg_t *f_arg;
} do_work_arg_t;


void init_work();
void do_work(void*);
void end_work(do_end_arg_t *);

double get_dbl();
