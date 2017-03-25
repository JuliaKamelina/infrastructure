int* mult(int* a, int size) {
  if (a == nullptr || size == 1) return 0;

  int* out = new int[size];
  int tmp1 = 1;
  int tmp2 = 1;
  for (int i = 0; i < size; i++) {
    out[i] = 1;
  }

  for (int i = 0; i < size; i++) {
    out[i] *= tmp1;
    tmp1 *= a[i];

    out[size - 1 -i] *= tmp2;
    tmp2 *= a[size - 1 -i];
  }
  return out;
}
