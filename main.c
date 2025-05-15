#include "BinSTree.h"


int main() {
    BinTree morseTree = Nil;
    int choice;
    char input[100], result[500];
    
    BuildMorseTree(&morseTree);
    // Menu utama
    do {
        printf("\n===== PROGRAM MORSE TREE =====\n");
        printf("1. Insert node\n");
        printf("2. Print Tree\n");
        printf("3. Traversal PreOrder\n");
        printf("4. Traversal InOrder\n");
        printf("5. Traversal PostOrder\n");
        printf("6. Traversal LevelOrder\n");
        printf("7. Search Node Tree\n");
        printf("8. Jumlah Daun/Leaf\n");
        printf("9. Mencari Kedalaman Node Tree\n");
        printf("10. Membandingkan 2 Node Tree\n");
        printf("11. Konversi Teks ke Morse\n");
        printf("12. Konversi Morse ke Teks\n");
        printf("13. Tampilkan Kode Morse Semua Karakter\n");
        printf("14. Konversi File Teks ke Morse\n"); // Menu baru
        printf("15. Exit\n");
        printf("Pilihan: ");
        scanf("%d", &choice);
        getchar(); // Ambil karakter newline
        
        switch (choice) {
            case 1:{
                // Insert node
                    printf("\n== Insert Node ==\n");

                    // Input info node baru
                    printf("Input info node: ");
                    char newInfo[MAX_STRING];
                    fgets(newInfo, sizeof(newInfo), stdin);
                    newInfo[strcspn(newInfo, "\n")] = 0; // Hapus newline

                    if (IsEmpty(morseTree)) {
                        morseTree = Alokasi(newInfo);
                        printf("Node '%s' berhasil ditambahkan sebagai root\n", newInfo);
                    } else {
                        // Input parent
                        printf("Input node parent: ");        
                        char parentInfo[MAX_STRING];
                        fgets(parentInfo, sizeof(parentInfo), stdin);
                        parentInfo[strcspn(parentInfo, "\n")] = 0;

                        // Cari parent node 
                        BinTree current = morseTree;
                        BinTree parent = Nil;
                        int found = 0;

                        BinTree stack[100];
                        int top = -1;
                        stack[++top] = current;

                        while (top >= 0) {
                            current = stack[top--];

                            if (strcmp(Info(current), parentInfo) == 0) {
                                parent = current;
                                found = 1;
                                break;
                            }

                            if (Right(current) != Nil)
                                stack[++top] = Right(current);

                            if (Left(current) != Nil)
                                stack[++top] = Left(current);
                        }

                        if (!found) {
                            printf("Parent node '%s' tidak ditemukan!\n", parentInfo);
                        } else {
                            // Cek jumlah anak
                            int childCount = 0;
                            if (Left(parent) != Nil) childCount++;
                            if (Right(parent) != Nil) childCount++;

                            if (childCount < 2) {
                                char direction;
                                if (childCount == 0) {
                                    printf("Posisi (titik untuk kiri/dash untuk kanan) [./- ]: ");
                                    scanf(" %c", &direction);
                                    getchar(); // Buang newline

                                    if (direction == '.') {
                                        parent->left = Alokasi(newInfo);
                                        printf("Node '%s' berhasil ditambahkan sebagai anak kiri (.) dari '%s'\n", newInfo, parentInfo);
                                    } else if (direction == '-') {
                                        parent->right = Alokasi(newInfo);
                                        printf("Node '%s' berhasil ditambahkan sebagai anak kanan (-) dari '%s'\n", newInfo, parentInfo);
                                    } else {
                                        printf("Posisi tidak valid! Gunakan . untuk kiri atau - untuk kanan.\n");
                                    }
                                } else {
                                    // Sudah punya 1 anak
                                    if (Left(parent) == Nil) {
                                        parent->left = Alokasi(newInfo);
                                        printf("Node '%s' berhasil ditambahkan sebagai anak kiri (.) dari '%s'\n", newInfo, parentInfo);
                                    } else {
                                        parent->right = Alokasi(newInfo);
                                        printf("Node '%s' berhasil ditambahkan sebagai anak kanan (-) dari '%s'\n", newInfo, parentInfo);
                                    }
                                }
                            } else {
                                printf("Error: node dalam binary tree tidak boleh memiliki lebih dari 2 anak!\n");
                            }
                        }
                    }
            
                }
            break;
        
            case 2:
                // Print Tree
                printf("\n== Print Tree ==\n");
                if (IsEmpty(morseTree)) {
                    printf("Tree kosong!\n");
                } else {
                    PrintTree(morseTree, 0);
                }
            break;
                
            case 3:
                // Traversal PreOrder
                printf("\n== PreOrder Traversal ==\n");
                if (IsEmpty(morseTree)) {
                    printf("Tree kosong!\n");
                } else {
                    PreOrder(morseTree);
                    printf("\n");
                }
            break;
                
            case 4:
                // Traversal InOrder
                printf("\n== InOrder Traversal ==\n");
                if (IsEmpty(morseTree)) {
                    printf("Tree kosong!\n");
                } else {
                    InOrder(morseTree);
                    printf("\n");
                }
                break;
                
            case 5:
                // Traversal PostOrder
                printf("\n== PostOrder Traversal ==\n");
                if (IsEmpty(morseTree)) {
                    printf("Tree kosong!\n");
                } else {
                    PostOrder(morseTree);
                    printf("\n");
                }
            break;
                
            case 6:
                // Implementasi level order traversal (BFS)
                printf("\n== LevelOrder Traversal ==\n");
                if (IsEmpty(morseTree)) {
                    printf("Tree kosong!\n");
                } else {
                    // Implementasi sederhana BFS dengan array sebagai queue
                    BinTree queue[100];
                    int front = 0, rear = 0;
                    
                    queue[rear++] = morseTree;
                    
                    while (front < rear) {
                        BinTree current = queue[front++];
                        printf("%s ", Info(current));
                        
                        if (Left(current) != Nil) {
                            queue[rear++] = Left(current);
                        }
                        
                        if (Right(current) != Nil) {
                            queue[rear++] = Right(current);
                        }
                    }
                    printf("\n");
                }
            break;   

            case 7:
                // Search Node Tree
                printf("Masukkan Node yang dicari: ");
                char strSearch[100];
                fgets(strSearch, sizeof(strSearch), stdin);
                strSearch[strcspn(strSearch, "\n")] = '\0'; // Hapus newline

                if (Search(morseTree, strSearch)) {
                    printf("Node %s ditemukan dalam tree\n", strSearch);
                } else {
                    printf("Node %s tidak ditemukan dalam tree\n", strSearch);
                }
            break;
                
            case 8:
                // Jumlah Daun/Leaf
                printf("\n== Jumlah Daun ==\n");
                printf("Jumlah daun pada tree: %d\n", nbDaun(morseTree));
            break;
                
            case 9:
                // Mencari Kedalaman Node Tree
                printf("\n== Kedalaman Tree ==\n");
                printf("Kedalaman tree: %d\n", Depth(morseTree));
            break;
                
            case 10:
                // Membandingkan 2 Node Tree
                printf("\n== Membandingkan 2 Node ==\n");

                char str1[MAX_STRING], str2[MAX_STRING];

                printf("Masukkan node pertama: ");
                scanf(" %s", str1);
                getchar();

                printf("Masukkan node kedua: ");
                scanf(" %s", str2);
                getchar();

                int lvl1 = Level(morseTree, str1);
                int lvl2 = Level(morseTree, str2);

                if (lvl1 == 0) {
                    printf("Node %s tidak ditemukan dalam tree\n", str1);
                } else if (lvl2 == 0) {
                    printf("Node %s tidak ditemukan dalam tree\n", str2);
                } else {
                    if (lvl1 < lvl2) {
                        printf("Node %s lebih dekat ke root daripada node %s\n", str1, str2);
                    } else if (lvl1 > lvl2) {
                        printf("Node %s lebih dekat ke root daripada node %s\n", str2, str1);
                    } else {
                        printf("Kedua node sama jauhnya dari root\n");
                    }
                }
            break;
                
            case 11:
                // Konversi Teks ke Morse
                printf("\n== Konversi Teks ke Morse ==\n");
                if (IsEmpty(morseTree)) {
                    printf("Tree kosong! Buat tree terlebih dahulu.\n");
                } else {
                    printf("Masukkan teks: ");
                    fgets(input, sizeof(input), stdin);
                    input[strcspn(input, "\n")] = 0; // Hapus newline
                    
                    textToMorse(morseTree, input, result);
                    printf(" Morse: %s\n", result);
                }
            break;
                
            case 12:
                // Konversi Morse ke Teks
                printf("\n== Konversi Morse ke Teks ==\n");
                if (IsEmpty(morseTree)) {
                    printf("Tree kosong! Buat tree terlebih dahulu.\n");
                } else {
                    printf("Masukkan kode Morse (pisahkan dengan spasi): ");
                    fgets(input, sizeof(input), stdin);
                    input[strcspn(input, "\n")] = 0; // Hapus newline
                    
                    morseToText(morseTree, input, result);
                    printf("Teks: %s\n", result);
                }
            break;
                
            case 13:
                // Tampilkan semua kode Morse
                printf("\n== Tabel Kode Morse ==\n");
                if (IsEmpty(morseTree)) {
                    printf("Tree kosong! Buat tree terlebih dahulu.\n");
                } else {
                    printf("Kode Morse untuk setiap karakter:\n");
                    char emptyCode[1] = "";
                    printMorseCode(morseTree, emptyCode, 0);
                }
            break;
                
            case 14:
                 // Konversi File Teks ke Morse
            break;
            
            case 15:
                // Exit logic
                printf("Terima kasih telah menggunakan program Morse Tree!\n");
            break;
        }
        
    } while (choice != 15);
    
  return 0;
}
