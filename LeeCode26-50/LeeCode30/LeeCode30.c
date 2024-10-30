// /***************************************************
//  * Date:2024/10/30  �ٷ���� 
//  * ��Ŀ����:
// ����һ���ַ��� s ��һ���ַ������� words�� words �������ַ��� ������ͬ��
//  s �е� �����Ӵ� ��ָһ������  words �������ַ���������˳�����������������Ӵ���
// ���磬��� words = ["ab","cd","ef"]�� ��ô "abcdef"�� "abefcd"��"cdabef"�� "cdefab"��"efabcd"�� 
// �� "efcdab" ���Ǵ����Ӵ��� "acdbef" ���Ǵ����Ӵ�����Ϊ�������κ� words ���е����ӡ�
// �������д����Ӵ��� s �еĿ�ʼ������������� ����˳�� ���ش𰸡�

// ʾ�� 1��
// ���룺s = "barfoothefoobarman", words = ["foo","bar"]
// �����[0,9]
// ���ͣ���Ϊ words.length == 2 ͬʱ words[i].length == 3�����ӵ����ַ����ĳ��ȱ���Ϊ 6��
// �Ӵ� "barfoo" ��ʼλ���� 0������ words ���� ["bar","foo"] ˳�����е����ӡ�
// �Ӵ� "foobar" ��ʼλ���� 9������ words ���� ["foo","bar"] ˳�����е����ӡ�
// ���˳���޹ؽ�Ҫ������ [9,0] Ҳ�ǿ��Եġ�

// ʾ�� 2��
// ���룺s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
// �����[]
// ���ͣ���Ϊ words.length == 4 ���� words[i].length == 4�����Դ����Ӵ��ĳ��ȱ���Ϊ 16��
// s ��û���Ӵ�����Ϊ 16 ���ҵ��� words ���κ�˳�����е����ӡ�
// �������Ƿ���һ�������顣

// ʾ�� 3��
// ���룺s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
// �����[6,9,12]
// ���ͣ���Ϊ words.length == 3 ���� words[i].length == 3�����Դ����Ӵ��ĳ��ȱ���Ϊ 9��
// �Ӵ� "foobarthe" ��ʼλ���� 6������ words ���� ["foo","bar","the"] ˳�����е����ӡ�
// �Ӵ� "barthefoo" ��ʼλ���� 9������ words ���� ["bar","the","foo"] ˳�����е����ӡ�
// �Ӵ� "thefoobar" ��ʼλ���� 12������ words ���� ["the","foo","bar"] ˳�����е����ӡ�
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
