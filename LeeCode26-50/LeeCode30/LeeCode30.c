// /***************************************************
//  * Date:2024/10/30  官方题解 
//  * 题目描述:
// 给定一个字符串 s 和一个字符串数组 words。 words 中所有字符串 长度相同。
//  s 中的 串联子串 是指一个包含  words 中所有字符串以任意顺序排列连接起来的子串。
// 例如，如果 words = ["ab","cd","ef"]， 那么 "abcdef"， "abefcd"，"cdabef"， "cdefab"，"efabcd"， 
// 和 "efcdab" 都是串联子串。 "acdbef" 不是串联子串，因为他不是任何 words 排列的连接。
// 返回所有串联子串在 s 中的开始索引。你可以以 任意顺序 返回答案。

// 示例 1：
// 输入：s = "barfoothefoobarman", words = ["foo","bar"]
// 输出：[0,9]
// 解释：因为 words.length == 2 同时 words[i].length == 3，连接的子字符串的长度必须为 6。
// 子串 "barfoo" 开始位置是 0。它是 words 中以 ["bar","foo"] 顺序排列的连接。
// 子串 "foobar" 开始位置是 9。它是 words 中以 ["foo","bar"] 顺序排列的连接。
// 输出顺序无关紧要。返回 [9,0] 也是可以的。

// 示例 2：
// 输入：s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
// 输出：[]
// 解释：因为 words.length == 4 并且 words[i].length == 4，所以串联子串的长度必须为 16。
// s 中没有子串长度为 16 并且等于 words 的任何顺序排列的连接。
// 所以我们返回一个空数组。

// 示例 3：
// 输入：s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
// 输出：[6,9,12]
// 解释：因为 words.length == 3 并且 words[i].length == 3，所以串联子串的长度必须为 9。
// 子串 "foobarthe" 开始位置是 6。它是 words 中以 ["foo","bar","the"] 顺序排列的连接。
// 子串 "barthefoo" 开始位置是 9。它是 words 中以 ["bar","the","foo"] 顺序排列的连接。
// 子串 "thefoobar" 开始位置是 12。它是 words 中以 ["the","foo","bar"] 顺序排列的连接。
// /***************************************************/

// typedef struct {
//     char key[32];
//     int val;
//     UT_hash_handle hh;
// } HashItem;

// int* findSubstring(char * s, char ** words, int wordsSize, int* returnSize){    
//     int m = wordsSize, n = strlen(words[0]), ls = strlen(s);
//     int *res = (int *)malloc(sizeof(int) * ls);
//     int pos = 0;
//     for (int i = 0; i < n; i++) {
//         if (i + m * n > ls) {
//             break;
//         }
//         HashItem *diff = NULL;
//         char word[32] = {0};
//         for (int j = 0; j < m; j++) {
//             snprintf(word, n + 1, "%s", s + i + j * n);
//             HashItem * pEntry = NULL;
//             HASH_FIND_STR(diff, word, pEntry);
//             if (NULL == pEntry) {
//                 pEntry = (HashItem *)malloc(sizeof(HashItem));
//                 strcpy(pEntry->key, word);
//                 pEntry->val = 0;
//                 HASH_ADD_STR(diff, key, pEntry);
//             } 
//             pEntry->val++;            
//         }
//         for (int j = 0; j < m; j++) {
//             HashItem * pEntry = NULL;
//             HASH_FIND_STR(diff, words[j], pEntry);
//             if (NULL == pEntry) {
//                 pEntry = (HashItem *)malloc(sizeof(HashItem));
//                 strcpy(pEntry->key, words[j]);
//                 pEntry->val = 0;
//                 HASH_ADD_STR(diff, key, pEntry);
//             } 
//             pEntry->val--;
//             if (pEntry->val == 0) {
//                 HASH_DEL(diff, pEntry);
//                 free(pEntry);
//             }
//         }
//         for (int start = i; start < ls - m * n + 1; start += n) {
//             if (start != i) {
//                 char word[32];
//                 snprintf(word, n + 1, "%s", s + start + (m - 1) * n);
//                 HashItem * pEntry = NULL;
//                 HASH_FIND_STR(diff, word, pEntry);
//                 if (NULL == pEntry) {
//                     pEntry = (HashItem *)malloc(sizeof(HashItem));
//                     strcpy(pEntry->key, word);
//                     pEntry->val = 0;
//                     HASH_ADD_STR(diff, key, pEntry);
//                 } 
//                 pEntry->val++;
//                 if (pEntry->val == 0) {
//                     HASH_DEL(diff, pEntry);
//                     free(pEntry);
//                 }
//                 snprintf(word, n + 1, "%s", s + start - n);
//                 pEntry = NULL;
//                 HASH_FIND_STR(diff, word, pEntry);
//                 if (NULL == pEntry) {
//                     pEntry = (HashItem *)malloc(sizeof(HashItem));
//                     strcpy(pEntry->key, word);
//                     pEntry->val = 0;
//                     HASH_ADD_STR(diff, key, pEntry);
//                 } 
//                 pEntry->val--;
//                 if (pEntry->val == 0) {
//                     HASH_DEL(diff, pEntry);
//                     free(pEntry);
//                 }
//             }
//             if (HASH_COUNT(diff) == 0) {
//                 res[pos++] = start;
//             }
//         }
//         HashItem *curr, *tmp;
//         HASH_ITER(hh, diff, curr, tmp) {
//             HASH_DEL(diff, curr);  
//             free(curr);      
//         }
//     }
//     *returnSize = pos;
//     return res;
// }
