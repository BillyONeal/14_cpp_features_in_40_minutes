a();
{
    int var = get_val();
    if (var < 42) {
        printf("%d", var);
    }
    // var doesn't 'escape' into the enclosing scope
}
b();
