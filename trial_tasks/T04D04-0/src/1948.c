// Copyright 2022 <Nikolay Kiryanov>

# include <stdio.h>

int devision(int what_to_devide, int devider);
int max_prime_devider(int number);

int main(void) {
    int x, final_prime;

    scanf("%d", &x);
    final_prime = max_prime_devider(x);

    if ( final_prime != -1 ) {
        printf("%d\n", final_prime);
    } else {
        printf("n/a\n");
    }
}

int devision(int what_to_devide, int devider) {
    int extra, result;

    extra = what_to_devide;
    while ( extra > 0 ) {
        extra = extra - devider;
    }

    if ( extra == 0 ) {
        result = 1;
    } else {
        result = 0;
    }

    return result;
}

int max_prime_devider(int number) {
    int i, j, num_i_deviders, is_j_devider;
    int final_prime;

    final_prime = -1;

    if ( number < 0 )
        number = -number;
    if ( number == 1)
        final_prime = 1;

    i = number;
    while ( final_prime == -1 && i >= 1 ) {
        if ( devision(number, i) == 1 ) {
           num_i_deviders = 0;
           for (j = 1; j <= i; j++) {
               is_j_devider = devision(i, j);
               num_i_deviders = num_i_deviders + is_j_devider;
           }

           if ( num_i_deviders == 2 )
               final_prime = i;
       }
       --i;
    }
    return final_prime;
}

