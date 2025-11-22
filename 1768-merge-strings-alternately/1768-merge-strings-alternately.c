

// char* mergeAlternately(char* word1, char* word2) {
//     int i = 0, j = 0;
//     int sizeofA = sizeof(word1) / sizeof(word1[0]);
//     int sizeofB = sizeof(word2) / sizeof(word2[0]);
//     // int n = sizeofA + sizeofB;
//     char* merged = (char*)malloc(sizeof(char) * (strlen(word1) + strlen(word2) + 1));
//     int k = 0;
//     while (i < sizeofA && j < sizeofB) {
//         merged[k] = word1[i];
//         i++;
//         k = k + 1;
//         merged[k] = word2[j];
//         j++;
//         k = k + 1;
//     }

//     if (i == sizeofA) {
//         while (j < sizeofB) {
//             merged[k] = word2[j];
//             j++;
//             k++;
//         }
//     }

//     else {
//         while (i < sizeofA) {
//             merged[k] = word2[i];
//             i++;
//             k++;
//         }
//     }

//     return merged;
// }


char* mergeAlternately(char* word1, char* word2) {

    int i = 0;
    int j = 0;

    char* temp =
        (char*)malloc(sizeof(char) * (strlen(word1) + strlen(word2) + 1));

    while (word1[i] != '\0' && word2[i] != '\0') {
        temp[j++] = word1[i];
        temp[j++] = word2[i];
        i++;
    }

    if (word1[i] == '\0') {
        while (word2[i] != '\0') {
            temp[j++] = word2[i++];
        }
    } else {
        while (word1[i] != '\0') {
            temp[j++] = word1[i++];
        }
    }
    temp[j] = '\0';
    return temp;
}