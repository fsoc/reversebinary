/*
 * Implementation notes
 *  Why did I use a recursive algorithm? Just for fun!
 */

#include<stdio.h>

// Get mod2 of a word.
int len(int bits) {
    int len = 1;

    while (bits >>= 1) {
        len++;
    }

    return len;
}

// Recursive function that splits the bitstring in half and reverses the pieces.
int reverse(int bits, int length) {

    if (length > 1) {
        // check of odd-length bits
        if (length % 2 == 1) {
            int n = (length - 1) / 2;
            int mask = (1 << n) - 1;
            int middle = 1 & (bits >> n);
            int left = mask & (bits >> (n + 1)); 
            int right = mask & bits;

            int revleft = reverse(left, n);
            int revright = reverse(right, n);

            return (revright << (n + 1)) | (middle << n) | revleft;
        } else {
            int n = length / 2;
            int mask = (1 << n) - 1;
            int left = mask & (bits >> n); 
            int right = mask & bits;

            int revleft = reverse(left, n);
            int revright = reverse(right, n);

            return (revright << n) | revleft;
        }
    }
    return bits;
}

int main(int argc, char **argv){
    unsigned int word; 

    scanf("%d", &word);
    printf("%d", reverse(word, len(word)));

    return 0;
}

