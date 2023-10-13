#include <stdio.h>

void generate_combinations(int score) {
    printf("possible combinations of scoring plays:\n");
    for (int td = 0; td * 6 <= score; td++) {
        for (int td2pt = 0; td2pt <= 1 && td2pt * 8 <= score - td * 6; td2pt++) {
            for (int td1fg = 0; td1fg <= 1 && td1fg * 7 <= score - td * 6 - td2pt * 8; td1fg++) {
                for (int fg = 0; fg * 3 <= score - td * 6 - td2pt * 8 - td1fg * 7; fg++) {
                    for (int safety = 0; safety * 2 <= score - td * 6 - td2pt * 8 - td1fg * 7 - fg * 3; safety++) {
                        if (td * 6 + td2pt * 8 + td1fg * 7 + fg * 3 + safety * 2 == score) {
                            printf("%d TD", td);
                            if (td2pt > 0) {
                                printf(" + %d 2pt", td2pt);
                            }
                            if (td1fg > 0) {
                                printf(" + %d FG", td1fg);
                            }
                            if (fg > 0) {
                                printf(", %d %dpt FG", fg, 3);
                            }
                            if (safety > 0) {
                                printf(", %d Safety", safety);
                            }
                            printf("\n");
                        }
                    }
                }
            }
        }
    }
}

int main() {
    int score;
    while (1) {
        printf("Enter 0 or 1 to STOP\n");
        printf("Enter the NFL score: ");
        scanf("%d", &score);
        if (score <= 1) {
            break;
        }
        generate_combinations(score);
    }
    return 0;
}
