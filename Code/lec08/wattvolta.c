/* Nested calls: main -> Watt -> Volta */
int Volta(int q, int r) {
    int k, m;
    /* ... */
    return k;
}

int Watt(int a) {
    int w;
    w = Volta(w, 10);
    return w;
}

int main() {
    int a, b;
    b = Watt(a);
    b = Volta(a, b);
    return 0;
}
