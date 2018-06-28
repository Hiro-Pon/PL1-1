int j = 10;
// (A)
for(var i=0; i < 100; i++) {
  // (B)
  char * str = NULL;
  if (i % 2 == 0)
    continue; // (1)
  if (i == j)
    break;     // (2)
  switch(i) {
  case 0:
    str = "zero";
    break;    // (3)
  case 1:
    str = "one";
  default:
    str = "others";
  // (C)
  }
  // (D)
  printf("%s\n", str); // (4)
  // (E)
}
// (F)
