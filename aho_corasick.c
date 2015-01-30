#include "aho_corasick.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void stream_test(char *T, int n, char **P, int *m, int num_patterns, int *correct) {
    ac_state state = ac_build(P, m, num_patterns);
    ac_result result = ac_result_build();
    int j;
    for (j = 0; j < n; j++) {
        ac_stream(state, T[j], j, result);
        assert(correct[j] == result->j);
    }
    ac_free(state);
    ac_result_free(result);
}

int main(void) {
    int n = 30, *m = malloc(sizeof(int));
    m[0] = 5;
    int *correct = malloc(n * sizeof(int));
    correct[0] = 8; correct[1] = 13;
    int *output = malloc(100 * sizeof(int));
    correct = realloc(correct, n * sizeof(int));
    correct[0]  = -1; correct[1]  = -1; correct[2]  = -1; correct[3]  = -1; correct[4]  = -1; correct[5]  = -1;
    correct[6]  = -1; correct[7]  = -1; correct[8]  = -1; correct[9]  = -1; correct[10] = -1; correct[11] = -1;
    correct[12] = 12; correct[13] = -1; correct[14] = -1; correct[15] = -1; correct[16] = -1; correct[17] = 17;
    correct[18] = -1; correct[19] = -1; correct[20] = -1; correct[21] = -1; correct[22] = -1; correct[23] = -1;
    correct[24] = -1; correct[25] = -1; correct[26] = -1; correct[27] = -1; correct[28] = -1; correct[29] = 29;
    char **P = malloc(sizeof(char*));
    P[0] = malloc(sizeof(char) * m[0]);
    strcpy(P[0], "ababb");
    stream_test("ababaabbababbababbaaababaababb", n, P, m, 1, correct);
    m = realloc(m, sizeof(int) * 2);
    P = realloc(P, sizeof(char*) * 2);
    m[1] = 8;
    P[1] = malloc(sizeof(char) * (m[1] + 1));
    strcpy(P[1], "ababaabb");
    correct[0]  = -1; correct[1]  = -1; correct[2]  = -1; correct[3]  = -1; correct[4]  = -1; correct[5]  = -1;
    correct[6]  = -1; correct[7]  = 7; correct[8]  = -1; correct[9]  = -1; correct[10] = -1; correct[11] = -1;
    correct[12] = 12; correct[13] = -1; correct[14] = -1; correct[15] = -1; correct[16] = -1; correct[17] = 17;
    correct[18] = -1; correct[19] = -1; correct[20] = -1; correct[21] = -1; correct[22] = -1; correct[23] = -1;
    correct[24] = -1; correct[25] = -1; correct[26] = -1; correct[27] = -1; correct[28] = -1; correct[29] = 29;
    stream_test("ababaabbababbababbaaababaababb", n, P, m, 2, correct);
    free(correct);
    free(output);
    printf("All tests succeeded!\n");
    return 0;
}