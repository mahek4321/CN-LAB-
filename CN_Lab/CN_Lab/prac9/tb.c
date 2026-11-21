
#include <stdio.h>

int main() {
    int B, R, N;
    int P[100];
    int tokens = 0;
    int sent, dropped;
    int i;

    // Input
    printf("Enter bucket capacity B: ");
    scanf("%d", &B);

    printf("Enter token generation rate R: ");
    scanf("%d", &R);

    printf("Enter number of time units N: ");
    scanf("%d", &N);

    if (B <= 0 || R <= 0 || N <= 0 || N > 100) {
        printf("Invalid input.\n");
        return 1;
    }

    printf("Enter incoming packets for each time unit:\n");
    for (i = 0; i < N; i++) {
        printf("P[%d] = ", i + 1);
        scanf("%d", &P[i]);

        if (P[i] < 0) {
            printf("Invalid packet count.\n");
            return 1;
        }
    }

    printf("\nTime\tTokens\tIncoming\tSent\tDropped\tRemaining Tokens\n");
    printf("-----------------------------------------------------------------\n");

    // Token Bucket Algorithm
    for (i = 0; i < N; i++) {

        // Add tokens at fixed rate
        tokens = tokens + R;

        // Bucket cannot contain more than B tokens
        if (tokens > B)
            tokens = B;

        // Check whether enough tokens are available
        if (P[i] <= tokens) {
            sent = P[i];
            dropped = 0;

            // Consume tokens
            tokens = tokens - P[i];
        }
        else {
            // Send packets equal to available tokens
            sent = tokens;

            // Remaining packets are dropped
            dropped = P[i] - tokens;

            // All tokens are consumed
            tokens = 0;
        }

        printf("%d\t%d\t%d\t\t%d\t%d\t%d\n",
               i + 1,
               tokens + sent,
               P[i],
               sent,
               dropped,
               tokens);
    }

    return 0;
}
